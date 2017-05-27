// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>

// TODO:  在此处引用程序需要的其他头文件
#include <iostream>
#include <list>
#include <vector>
#include <time.h>
#include "stdlib.h"
#include "AStar.h"
using namespace std;
typedef list <Point> path;
typedef list <list <Point>> PathSet;
#include <Windows.h>	//这个头文件在Linux下需要删除，测试所用