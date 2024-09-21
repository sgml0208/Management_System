/*
 * @Description:        管理类实现   https://www.bilibili.com/video/BV1et411b73Z/?p=149&spm_id_from=pageDriver&vd_source=5c495e3ef87d1f3de4b8a79a6b9360a1
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:53:52
 * @LastEditTime: 2024-09-21 22:36:45
 */

/*
管理类负责的内容如下:
    与用户的沟通菜单界面
    对职工增删改查的操作
    与文件的读写交互
*/

#include <windows.h>
#include <iomanip> // setw(16)
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 读文件

    // 情况1：文件不存在，创建文件
    if (!ifs.is_open()) // 文件是否打开成功
    {
        // cout << "The file does not exist!" << endl;
        // 初始化属性
        this->m_workerNum = 0;
        this->m_workerArray = NULL; // 初始化数组指针为空
        this->m_isFileEmpty = true;
        ifs.close();
        return;
    }

    // 情况2：文件存在，但文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "The file is empty!" << endl;
        this->m_workerNum = 0;
        this->m_workerArray = NULL; // 初始化数组指针为空
        this->m_isFileEmpty = true;
        ifs.close();
        return;
    }

    // 情况3：文件存在，且文件不为空
    int num = this->get_workerNum(); // 职工人数
    // cout << "The number of all workers is " << num << endl;
    this->m_workerNum = num; // 更新成员属性
    this->m_workerArray = new Worker *[this->m_workerNum];
    this->initWorker();        // 将文件中的数据存到上一行的数组中

    // test code
    // for (int i = 0; i < this->m_workerNum; i++)
    // {
    //     cout << setw(16) << this->m_workerArray[i]->m_Id 
    //          << setw(20) << this->m_workerArray[i]->m_Name
    //          << setw(16) << this->m_workerArray[i]->m_DeptId << endl;
    // }
}


void WorkerManager::showMenu() // 显示菜单
{
    cout << "************************************************" << endl;
    cout << "************* 欢迎使用职工管理系统 *************" << endl;
    cout << "**************** 0.退出管理系统 ****************" << endl;
    cout << "**************** 1.添加职工信息 ****************" << endl;
    cout << "**************** 2.显示职工信息 ****************" << endl;
    cout << "**************** 3.删除离职职工 ****************" << endl;
    cout << "**************** 4.修改职工信息 ****************" << endl;
    cout << "**************** 5.查找职工信息 ****************" << endl;
    cout << "**************** 6.按照编号排序 ****************" << endl;
    cout << "**************** 7.清空所有文档 ****************" << endl;
    cout << "************************************************" << endl;
    cout << endl;
}


void WorkerManager::exitSystem() // 退出系统
{
    cout << "Successfully exited the system!" << endl;
}


void WorkerManager::saveData() // 保存数据到文件
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 以输出的方式打开文件
    ofs << left;                  // 左对齐

    // 将每个人的数据写入文件
    for (int i = 0; i < this->m_workerNum; i++)
    {
        ofs << setw(16) << this->m_workerArray[i]->m_Id // setw(10): 设置宽度为10个字符宽
            << setw(20) << this->m_workerArray[i]->m_Name
            << setw(16) << this->m_workerArray[i]->m_DeptId << endl;
    }
    ofs.close();
}


void WorkerManager::initWorker()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int deptId;
    int index = 0;     
    while (ifs >> id && ifs >> name && ifs >> deptId)
    {
        Worker *worker = NULL;
        // 根据不同部门id创建不同对象
        if (deptId == 1)            // 普通职工
            worker = new Employee(id, name, deptId);
        else if (deptId == 2)       // 经理
            worker = new Manager(id, name, deptId);
        else                        // 老板
            worker = new Boss(id, name, deptId);
        
        // 将对象存放在数组中
        this->m_workerArray[index++] = worker;
    }
    ifs.close();

}


void WorkerManager::addWorker() // 添加职工信息
{
    cout << "Please enter the number of worker to be added: "; // 程序健壮性不行，输入非数字则死循环
    int addNum = 0;
    cin >> addNum;
    while (true)
    {
        if (addNum > 0) // 添加职工
        {
            // 计算新空间大小 = 原记录人数 + 新增人数
            int newSize = this->m_workerNum + addNum;
            // 开辟新空间
            Worker **newSpace = new Worker *[newSize];
            // 将原空间的数据拷贝到新空间
            if (this->m_workerArray != NULL)
            {
                for (int i = 0; i < this->m_workerNum; i++)
                    newSpace[i] = this->m_workerArray[i];
            }
            // 接着将新数据添加到新空间
            for (int i = 0; i < addNum; i++)
            {
                int id;                                                      // 职工编号
                string name;                                                 // 职工姓名
                int deptSelect;                                              // 职工部门
                cout << "Please input No." << i + 1 << " new worker's id: "; // 程序健壮性不行，输入非数字则死循环
                cin >> id;
                cout << "Please input No." << i + 1 << " new worker's name: ";
                cin >> name;
                cout << "There are three types of departments here: \t 1.employee \t 2.manager \t 3.boss" << endl;
                cout << "Please select No." << i + 1 << " new worker's department: ";
                cin >> deptSelect;

                Worker *worker = NULL;
                switch (deptSelect)
                {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
                }

                // 将创建的职工信息保存在数组中
                newSpace[this->m_workerNum + i] = worker;
            }
            // 释放原有空间
            delete[] this->m_workerArray;
            // 更改新空间的指向
            this->m_workerArray = newSpace;
            // 更新新的总职工人数
            this->m_workerNum = newSize;
            // 更新文件不为空
            this->m_isFileEmpty = false;
            // 保存职工数据信息到文件
            this->saveData();
            cout << endl
                 << "Add " << addNum << " workers and save successfully!" << endl;

            break;
        }
        else
        {
            cout << "The number of employees entered should be greater than 0!  please re-enter: ";
            cin >> addNum;
        }
    }
    system("pause"); // 按任意键继续
    system("cls");   // windows系统的清屏
}


int WorkerManager::get_workerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int deptId;
    int num = 0; // 记录人数
    while (ifs >> id && ifs >> name && ifs >> deptId)
        num++;
    ifs.close();
    return num;
}


WorkerManager::~WorkerManager()
{
    if (this->m_workerArray != NULL) // 堆区数据最好手动开辟手动释放
    {
        delete[] this->m_workerArray;
        this->m_workerArray = NULL;
    }
}
