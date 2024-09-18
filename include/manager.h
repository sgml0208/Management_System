/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:17:53
 * @LastEditTime: 2024-09-18 23:17:53
 */


#pragma once 
#include <iostream>
#include "worker.h"
using namespace std;

class Manager : public Worker        // 经理类
{
public:
    Manager(int id, string name, int deptId);

    ~Manager();

    // 显示个人信息
    virtual void showInfo();    
    
    // 获取岗位名称
    virtual string getDeptName();
    

private:

};