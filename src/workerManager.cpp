/*
 * @Description:        管理类实现   https://www.bilibili.com/video/BV1et411b73Z/?p=149&spm_id_from=pageDriver&vd_source=5c495e3ef87d1f3de4b8a79a6b9360a1
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:53:52
 * @LastEditTime: 2024-09-19 07:42:12
 */

/*
管理类负责的内容如下:
    与用户的沟通菜单界面
    对职工增删改查的操作
    与文件的读写交互
*/

#include "workerManager.h"
using namespace std; 

WorkerManager::WorkerManager()
{
}

void WorkerManager::showMenu()        // 菜单
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

WorkerManager::~WorkerManager()
{
    
}

