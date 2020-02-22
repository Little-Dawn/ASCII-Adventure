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
	string m_bar;//状态栏
	int m_x, m_y;
	int m_atk, m_def, m_maxhp, m_hp, m_maxmp, m_mp;
	int m_time;
	int m_direction;//1234对应wasd,上左下右,0对应无方向
	Screen* m_screen;//接收一个Screen类用来显示

	void set_bar() //内联，刷新状态栏
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
	//内联，刷新状态栏

public:
	Chara(Screen* screen,string name,int x, int y, int hp, int maxhp, int mp, int maxmp, int atk, int def);//初始化，强制性的
	void show(string str);//str显示在Message栏，可以写剧情，同时打印Message栏，状态栏和screen
	void error();//发生错误的时候使用的输出，本质上是show()的简单运用
	void act(string str);//这个位置是玩家全部操作，主要处理读取输入的问题，相应的函数具体实现全部扔到外部
	void move();//走动的实现，act的一部分
	void dash();//冲刺的实现，act的一部分
};

#endif // !CHARA_00_H_

