/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:06:16
 * @LastEditTime: 2024-09-18 23:15:17
 */


#pragma once 
#include <iostream>
#include "worker.h"
using namespace std;

class Employee : public Worker        // 普通职工类
{
public:
    Employee(int id, string name, int deptId);

    ~Employee();

    // 显示个人信息
    virtual void showInfo();    
    
    // 获取职工岗位名称
    virtual string getDeptName();
    

private:

};