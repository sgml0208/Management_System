/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:47:14
 * @LastEditTime: 2024-09-18 23:02:49
 */

#include <iostream>
#include <windows.h>
#include "workerManager.h"
using namespace std;

int main()
{
    // system("pause");  只能在windows系统才能用
    // 在Windows系统中，控制台默认使用的是系统本地编码（通常是GBK或GB2312），而源代码是使用UTF-8编码保存的，这会导致在控制台输出时出现乱码
    SetConsoleOutputCP(65001);  // 设置控制台输出编码为UTF-8
    WorkerManager wm;
    int choice = -1;
    while (true)
    {
        // 展示菜单
        wm.showMenu();
        cout << "Please input your choice:  ";
        cin >> choice;
        switch (choice)
        {
            case 0:          // 退出系统
                wm.exitSystem();
                return 0;
            case 1:          // 添加新职工
                break;
            case 2:          // 显示职工信息
                break;
            case 3:          // 删除离职职工
                break;
            case 4:          // 修改职工信息
                break;
            case 5:          // 查找职工信息
                break;
            case 6:          // 排序职工信息
                break;
            case 7:          // 清空所有文档
                break;
            default:
                // system("cls");  // 清屏，只显示本次输出的结果(只对于弹出终端窗口有效，在这vscode终端无效)
                break;
        }
            
    }

    
    return 0;
}

















