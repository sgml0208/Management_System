/*
 * @Description:
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:47:14
 * @LastEditTime: 2024-09-17 10:31:59
 */

#include <iostream>
#include <windows.h>
#include "workerManager.h"

int main()
{
    // 在Windows系统中，控制台默认使用的是系统本地编码（通常是GBK或GB2312），而源代码是使用UTF-8编码保存的，这会导致在控制台输出时出现乱码
    SetConsoleOutputCP(65001);  // 设置控制台输出编码为UTF-8
    WorkerManager wm;
    wm.showMenu();

    std::cout << "Press Enter to continue..."; //通用请求暂停程序
    std::cin.get();  // 等待用户按下 Enter 键
    
    // system("pause");  只能在windows系统才能用

    return 0;
}

















