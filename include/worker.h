/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:00:52
 * @LastEditTime: 2024-09-18 23:03:10
 */

#pragma once // 只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次，防止头文件被重复引用。
#include <iostream>
#include <string>
using namespace std;

class Worker         // 职工抽象类
{
public:
    Worker();

    ~Worker();

    // 显示个人信息
    virtual void showInfo() = 0;    // 纯虚函数
    
    // 获取岗位名称
    virtual string getDeptName() = 0;

    int m_Id;           // 职工编号
    string m_Name;      // 职工姓名
    int m_DeptId;       // 职工所在部门名称编号

    

private:

};