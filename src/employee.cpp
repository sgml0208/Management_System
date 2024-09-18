/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:09:27
 * @LastEditTime: 2024-09-18 23:16:30
 */

#include "employee.h"

Employee::Employee(int id, string name, int deptId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

void Employee::showInfo()
{
    cout << "职工编号:  " << this->m_Id
         << "\t\t职工姓名:  " << this->m_Name
         << "\t\t职工部门:  " << this->getDeptName()
         << "\t\t部门职责:  完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
    return string("员工");
}