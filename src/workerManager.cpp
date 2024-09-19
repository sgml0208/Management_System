/*
 * @Description:        管理类实现   https://www.bilibili.com/video/BV1et411b73Z/?p=149&spm_id_from=pageDriver&vd_source=5c495e3ef87d1f3de4b8a79a6b9360a1
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:53:52
 * @LastEditTime: 2024-09-19 23:27:50
 */

/*
管理类负责的内容如下:
    与用户的沟通菜单界面
    对职工增删改查的操作
    与文件的读写交互
*/

#include <windows.h>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

WorkerManager::WorkerManager()
{
    this->m_workerNum = 0; // 初始0个人
    this->m_workerArray = NULL;
}

void WorkerManager::showMenu() // 菜单
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

void WorkerManager::exitSystem()
{
    cout << "Successfully exited the system!" << endl;
}

void WorkerManager::addWorker()
{
    cout << "Please enter the number of worker to be added: ";        // 程序健壮性不行，输入非数字则死循环
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
                int id;         // 职工编号
                string name;    // 职工姓名
                int deptSelect; // 职工部门
                cout << "Please input No." << i + 1 << " new worker's id: ";      // 程序健壮性不行，输入非数字则死循环
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
            cout << endl
                 << "Add " << addNum << " workers successfully!" << endl;
            break;
        }
        else
        {
            cout << "The number of employees entered should be greater than 0!  please re-enter: ";
            cin >> addNum;
        }
    }
    system("pause");    // 按任意键继续
    system("cls");      // windows系统的清屏
}

WorkerManager::~WorkerManager()
{
}
