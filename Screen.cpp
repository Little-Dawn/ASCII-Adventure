#include "Screen.h"

Screen::Screen()//Ĭ�ϳ�ʼ��screen
{
	for (int i = 0; i < width + 3; i++)//��ʼ������
	{
		m_screen[i][0] = '#';
		m_screen[i][height + 1] = '#';
	}

	for (int i = 0; i < height + 2; i++)//��ʼ������
	{
		m_screen[0][i] = '#';
		m_screen[width + 1][i] = '#';
		m_screen[width + 2][i] = '\n';
	}

	for (int i = 1; i < height + 1; i++)//��ʼ���ڲ��ռ�
	{
		for (int j = 1; j < width + 1; j++)
		{
			m_screen[j][i] = ' ';
		}
	}
//	show("Successfully Initialized!","--------------------------------");
}
//���캯��

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
//��ӡȫ�������ʵ�֣�����Message�к�״̬��

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
//�ı�screen����һ���ַ���ʵ�֣������ַ����꣨#���ڣ���Ŀ���ַ�

void Screen::clear(int x, int y)
{
	change(x, y,' ');
}
//���һ�������ϵ��ַ�