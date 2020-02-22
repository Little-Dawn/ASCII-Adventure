#include "Screen.h"

Screen::Screen()//默认初始化screen
{
	for (int i = 0; i < width + 3; i++)//初始化横行
	{
		m_screen[i][0] = '#';
		m_screen[i][height + 1] = '#';
	}

	for (int i = 0; i < height + 2; i++)//初始化纵列
	{
		m_screen[0][i] = '#';
		m_screen[width + 1][i] = '#';
		m_screen[width + 2][i] = '\n';
	}

	for (int i = 1; i < height + 1; i++)//初始化内部空间
	{
		for (int j = 1; j < width + 1; j++)
		{
			m_screen[j][i] = ' ';
		}
	}
//	show("Successfully Initialized!","--------------------------------");
}
//构造函数

void Screen::show(string str1, string str2)
{
	cout << "\n\n\n\n\n\n\n\n\n"
		 << "[Message] " + str1 << endl << str2 << endl;
	for (int i = 0; i < height + 2; i++) {
		for (int j = 0; j < width + 3; j++) {
			cout << m_screen[j][i];
		}
	}
}
//打印全部界面的实现，输入Message行和状态栏

void Screen::change(int x, int y, char ch)
{
	if (x<1 || x>width || y<1 || y>height)
	{
		show("!!! Invalid Input !!!/n","--------------------------------");
	}
	else
	{
		string str;
		str = ch;
		m_screen[x][y] = ch;
	}
}
//改变screen其中一个字符的实现，输入字符坐标（#框内）和目标字符

void Screen::clear(int x, int y)
{
	change(x, y,' ');
}
//清除一个坐标上的字符