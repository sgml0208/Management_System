/*
 * @Description:      管理类头文件   https://www.bilibili.com/video/BV1et411b73Z/?p=149&spm_id_from=pageDriver&vd_source=5c495e3ef87d1f3de4b8a79a6b9360a1
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:51:49
 * @LastEditTime: 2024-09-21 21:33:34
 */


/*
管理类负责的内容如下:
    与用户的沟通菜单界面
    对职工增删改查的操作
    与文件的读写交互
*/

#pragma once // 只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次，防止头文件被重复引用。
#include <iostream>
#include "worker.h"
#include <fstream>
#define FILENAME "../workerData.txt"
using namespace std;

class WorkerManager
{
public:
    // 职工总人数
    int m_workerNum;

    // 职工数组指针: 存放指向子类对象的指针
    Worker **m_workerArray;

    // 文件是否为空
    bool m_isFileEmpty;

    WorkerManager();

    ~WorkerManager();

    // 展示菜单功能
    void showMenu();

    // 退出系统
    void exitSystem();

    // 添加职工
    void addWorker();

    // 获取统计的职工人数
    int get_workerNum();

    // 初始化职工
    void initWorker();

    // 保存数据到文件
    void saveData();

private:
};


