/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-09-18 23:21:03
 * @LastEditTime: 2024-09-18 23:21:03
 */


#include "boss.h"

Boss::Boss(int id, string name, int deptId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = deptId;
}

void Boss::showInfo()
{
    cout << "职工编号:  " << this->m_Id
         << "\t\t职工姓名:  " << this->m_Name
         << "\t\t职工部门:  " << this->getDeptName()
         << "\t\t部门职责:  给经理及员工发布任务" << endl;
}

string Boss::getDeptName()
{
    return string("老板");
}