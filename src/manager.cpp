/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:18:57
 * @LastEditTime: 2024-09-18 23:19:00
 */


#include "manager.h"

Manager::Manager(int id, string name, int deptId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

void Manager::showInfo()
{
    cout << "职工编号:  " << this->m_Id
         << "\t\t职工姓名:  " << this->m_Name
         << "\t\t职工部门:  " << this->getDeptName()
         << "\t\t部门职责:  完成老板交给的任务" << endl;
}

string Manager::getDeptName()
{
    return string("经理");
}