/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:20:25
 * @LastEditTime: 2024-09-18 23:20:28
 */


#pragma once 
#include <iostream>
#include "worker.h"
using namespace std;

class Boss : public Worker        // 老板类
{
public:
    Boss(int id, string name, int deptId);

    ~Boss();

    // 显示个人信息
    virtual void showInfo();    
    
    // 获取岗位名称
    virtual string getDeptName();
    

private:

};