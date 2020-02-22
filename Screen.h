#pragma once
#ifndef SCREEN_00_H_
#define SCREEN_00_H_

#include <iostream>
#include <string>
using namespace std;

const int width = 30;//内部宽度
const int height = 16;//内部高度

class Screen
{
private:
	char m_screen[width + 3][height + 2] = {};//width+3是 两列# 和 一列\n ，height+2是 两行#
public:
	Screen();//构造函数
	void show(string str1,string str2);//打印全部界面的实现，输入Message行和状态栏
	void change(int x, int y, char ch);//改变screen其中一个字符的实现，输入字符坐标（#框内）和目标字符
	void clear(int x, int y);//清除一个坐标上的字符
};
#endif // !SCREEN_00_H_