#pragma once
#ifndef CHARA_00_H_
#define CHARA_00_H_
#include "Screen.h"
#include <ctime>

const clock_t move_t = 400;
const clock_t dash_t1 = 150;
const clock_t dash_t2 = 60;

class Chara
{
private:
	string m_name;
	string m_bar;//״̬��
	int m_x, m_y;
	int m_atk, m_def, m_maxhp, m_hp, m_maxmp, m_mp;
	int m_time;
	int m_direction;//1234��Ӧwasd,��������,0��Ӧ�޷���
	Screen* m_screen;//����һ��Screen��������ʾ

	void set_bar() //������ˢ��״̬��
	{
		string temp_dir;
		switch (m_direction)
		{
		case 1:temp_dir = "UP"; break;
		case 2:temp_dir = "LEFT"; break;
		case 3:temp_dir = "DOWN"; break;
		case 4:temp_dir = "RIGHT"; break;
		default:temp_dir = "NONE";
		}
		m_bar = "|Chara:" + m_name + "|" +
			"LOC:(" + to_string(m_x) + "," + to_string(m_y) + ")|" +
			"HP:" + to_string(m_hp) + "/" + to_string(m_maxhp) + "|" +
			"MP:" + to_string(m_mp) + "/" + to_string(m_maxmp) + "|" +
			"ATK:" + to_string(m_atk) + "|" +
			"DEF:" + to_string(m_def) + "|" +
			"DIRECTION:" + temp_dir + "|"+
			"TIME:" + to_string(m_time) + "|";
	}
	//������ˢ��״̬��

public:
	Chara(Screen* screen,string name,int x, int y, int hp, int maxhp, int mp, int maxmp, int atk, int def);//��ʼ����ǿ���Ե�
	void show(string str);//str��ʾ��Message��������д���飬ͬʱ��ӡMessage����״̬����screen
	void error();//���������ʱ��ʹ�õ��������������show()�ļ�����
	void act(string str);//���λ�������ȫ����������Ҫ�����ȡ��������⣬��Ӧ�ĺ�������ʵ��ȫ���ӵ��ⲿ
	void move();//�߶���ʵ�֣�act��һ����
	void dash();//��̵�ʵ�֣�act��һ����
};

#endif // !CHARA_00_H_

