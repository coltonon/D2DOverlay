// D2DOverlay Test Internal Host Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>
#include <tchar.h>
#include <iostream>

int main()
{
    HMODULE h = ::LoadLibrary(_T("D2DOverlay Test Internal.dll"));
    
    getchar();
    FreeLibrary(h);
    return 0;
}
