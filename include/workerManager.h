/*
 * @Description:      管理类头文件   https://www.bilibili.com/video/BV1et411b73Z/?p=149&spm_id_from=pageDriver&vd_source=5c495e3ef87d1f3de4b8a79a6b9360a1
 * @Author:  shang guan meng luo
 * @version:
 * @Date: 2024-07-24 07:51:49
 * @LastEditTime: 2024-09-09 09:46:31
 */

/*
管理类负责的内容如下:
    与用户的沟通菜单界面
    对职工增删改查的操作
    与文件的读写交互
*/

#pragma once // 只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次，防止头文件被重复引用。
#include <iostream>
using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    ~WorkerManager();

    // 展示菜单功能
    void showMenu();

private:
};


