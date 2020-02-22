#include "Chara.h"

void wait(clock_t delay);

Chara::Chara(Screen* screen, string name, int x, int y, int hp, int maxhp, int mp, int maxmp, int atk, int def)
{
	if (x > 0 && x < width && y>0 && y < height && 
		hp>0 && maxhp > 0 && mp > -1 && maxmp > -1 
		&& (maxhp + 1) > hp&& maxmp + 1 > mp&& atk > -1 && def > -1)
	{
		m_name = name;
		m_screen = screen;
		m_x = x;
		m_y = y;
		m_atk = atk;
		m_def = def;
		m_maxhp = maxhp;
		m_hp = hp;
		m_maxmp = maxmp;
		m_mp = mp;
		m_time = 0;
		m_direction = 0;
		set_bar();
		show("The adventure of " + m_name + " begins!");
	}
	else
	{
		m_name = "!!!ERROR!!!";
		m_screen = screen;
		m_x = 1;
		m_y = 1;
		m_atk = 0;
		m_def = 0;
		m_maxhp = 0;
		m_hp = 0;
		m_maxmp = 0;
		m_mp = 0;
		m_time = 0;
		set_bar();
		show("!!!ERROR!!!");
	}
}
//初始化，强制性的

void Chara::show(string str)
{
	(*m_screen).change(m_x, m_y, '@');
	(*m_screen).show(str,m_bar);
}
//str显示在Message栏，可以写剧情，同时打印Message栏，状态栏和screen

void Chara::error() 
{
	show(m_name + " doesn't know what to do ,cuz your input is invalid.");
}
//发生错误的时候使用的输出，本质上是show()的简单运用

void Chara::act(string str)
{
	int strs = size(str);
	if (str == "")
	{
		show("Well, it is no use entering an empty line.");
	}
	for (int i = 0; i < strs; i++)
	{
		switch (str[i])
		{
		case 'w':
			m_direction = 1;
			move();
			break;
		case 'a':
			m_direction = 2;
			move();
			break;
		case 's':
			m_direction = 3;
			move();
			break;
		case 'd':
			m_direction = 4;
			move();
			break;
		case 'W':
			m_direction = 1;
			dash();
			break;
		case 'A':
			m_direction = 2;
			dash();
			break;
		case 'S':
			m_direction = 3;
			dash();
			break;
		case 'D':
			m_direction = 4;
			dash();
			break;
		default:
			string temp_str;
			temp_str = (char)str[i];
			show(m_name + " doesn't know what to do with the character '" + temp_str + "'.");
		}

	}
}
//这个位置是玩家全部操作，主要处理读取输入的问题，相应的函数具体实现全部扔到外部

void Chara::move()
{
	m_time++;
	m_screen->clear(m_x, m_y);

	switch (m_direction)
	{
	case 1:if (m_y < 2) { error(); return; }
		  else { wait(move_t); m_y--; }; break;
	case 2:if (m_x < 2) { error(); return; }
		  else { wait(move_t); m_x--; }; break;
	case 3:if (m_y > height - 1) { error(); return; }
		  else { wait(move_t); m_y++; }; break;
	case 4:if (m_x > width - 1) { error(); return; }
		  else { wait(move_t); m_x++; }; break;
	default:error();
	}
	set_bar();
	show(m_name + " moves around.");
}
//走动的实现，act的一部分

void Chara::dash()
{
	m_time++;
	switch (m_direction)
	{
	case 1:
		if (m_y < 3) { error(); return; }
		else
		{
			cout << "\a";
			m_screen->change(m_x, m_y - 1, '@'); 
			m_y = m_y - 2;
			set_bar();
			wait(dash_t1);//第一个延迟时间，两次冲刺间隔时间
			show(m_name + " dashes UP.");
			//以上是画出冲刺路径

			wait(dash_t2);//第二个延迟时间，延迟路径保留时间
			m_screen->clear(m_x, m_y + 1); 
			m_screen->clear(m_x, m_y + 2);
			show(m_name + " dashes UP.");
			//以上是显示终点
			break;
		}
		
	case 2:
		if (m_x < 4) { error(); return; }
		else
		{
			cout << "\a";
			m_screen->change(m_x-1, m_y, '@');
			m_screen->change(m_x - 2, m_y, '@');
			m_x = m_x - 3;
			set_bar();
			wait(dash_t1);//第一个延迟时间，两次冲刺间隔时间
			show(m_name + " dashes LEFT.");
			//以上是画出冲刺路径

			wait(dash_t2);//第二个延迟时间，延迟路径保留时间
			m_screen->clear(m_x+1, m_y);
			m_screen->clear(m_x+2, m_y);
			m_screen->clear(m_x+3, m_y);
			show(m_name + " dashes LEFT.");
			//以上是显示终点
			break;
		}

	case 3:
		if (m_y > height - 2) { error(); return; }
		else
		{
			cout << "\a";
			m_screen->change(m_x, m_y + 1, '@');
			m_y = m_y + 2;
			set_bar();
			wait(dash_t1);//第一个延迟时间，两次冲刺间隔时间
			show(m_name + " dashes DOWN.");
			//以上是画出冲刺路径

			wait(dash_t2);//第二个延迟时间，延迟路径保留时间
			m_screen->clear(m_x, m_y - 1);
			m_screen->clear(m_x, m_y - 2);
			show(m_name + " dashes DOWN.");
			//以上是显示终点
			break;
		}

	case 4:
		if (m_x > width - 3) { error(); return; }
		else
		{
			cout << "\a";
			m_screen->change(m_x + 1, m_y, '@');
			m_screen->change(m_x + 2, m_y, '@');
			m_x = m_x + 3;
			set_bar();
			wait(dash_t1);//第一个延迟时间，两次冲刺间隔时间
			show(m_name + " dashes RIGHT.");
			//以上是画出冲刺路径

			wait(dash_t2);//第二个延迟时间，延迟路径保留时间
			m_screen->clear(m_x - 1, m_y);
			m_screen->clear(m_x - 2, m_y);
			m_screen->clear(m_x - 3, m_y);
			show(m_name + " dashes RIGHT.");
			//以上是显示终点
			break;
		}

	default:error();
	}
}
//冲刺的实现，act的一部分

void wait(clock_t delay)
{
	clock_t start = clock();
	while (clock() - start < delay);
}
//一个延时函数，只在Chara.cpp用，用于编写act