#pragma once
#ifndef SCREEN_00_H_
#define SCREEN_00_H_

#include <iostream>
#include <string>
using namespace std;

const int width = 30;//�ڲ����
const int height = 16;//�ڲ��߶�

class Screen
{
private:
	char m_screen[width + 3][height + 2] = {};//width+3�� ����# �� һ��\n ��height+2�� ����#
public:
	Screen();//���캯��
	void show(string str1,string str2);//��ӡȫ�������ʵ�֣�����Message�к�״̬��
	void change(int x, int y, char ch);//�ı�screen����һ���ַ���ʵ�֣������ַ����꣨#���ڣ���Ŀ���ַ�
	void clear(int x, int y);//���һ�������ϵ��ַ�
};
#endif // !SCREEN_00_H_