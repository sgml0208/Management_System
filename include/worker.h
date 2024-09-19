/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:00:52
 * @LastEditTime: 2024-09-19 22:49:12
 */

#pragma once // 只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次，防止头文件被重复引用。
#include <iostream>
#include <string>
using namespace std;

class Worker // 职工抽象类      不需要worker.cpp
{
public:
    // Worker();

    // ~Worker();

    // virtual ~Worker() = default; // 添加虚析构函数, 这里已经定义了虚析构函数为默认实现，不用再在.cpp文件中实现具体析构函数

    // 显示个人信息
    virtual void showInfo() = 0; // 纯虚函数

    // 获取岗位名称
    virtual string getDeptName() = 0;

    int m_Id;      // 职工编号
    string m_Name; // 职工姓名
    int m_DeptId;  // 职工所在部门名称编号

private:
};