#include "Chara.h"//Chara.h里包含了<iostream>,<ctimes>,<string>,"Screen.h",并且应用名称空间std

int main()
{
	cout << "----                             Welcome to ASSCII Adventure!!                             ----\n"
		 << "----                          This is a game made by Eternal_Dawn                          ----\n"
		 << "----                                                                                       ----\n"
	 	 << "----                                     [How to play]                                     ----\n"
		 << "----(1)Create you own character, but you can only decide his/her name and initial location.----\n"
	 	 << "----(2)Please enter 'w'/ 'a'/ 's'/ 'd' and 'ENTER' on your keyboard to move around.        ----\n"
		 << "----   If you enter 'W'/ 'A'/ 'S'/ 'D' and 'ENTER', your character will 'dash around'.     ----\n"
		 << "----   PS: You can enter multiple characters in one line,they will be applied in order.    ----\n"
		 << "----(3)Enter '#' to quit.                                                                  ----\n"
		 << "----(4)HAVE FUN!                                                                           ----\n\n\n";

	cout << "                                    [Create your character]                                    \n\n"
		<< "                                          Name:________\b\b\b\b\b\b\b\b";
	string name = "Madeline";
	cin >> name;
	cout << "\n--Character's name is " << name << ".\n\n";

	cout << "                      X axis location:__( no less than 1 and no more than 30 )"
		<< "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	int x=1;
	cin >> x;
	if (x < 1 || x>30) { x = 1; }
	cout << "\n--X axis location is " << x << ".\n\n";

	cout << "                      Y axis location:__( no less than 1 and no more than 16 )"
		<< "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
	int y = 1;
	cin >> y;
	cin.get();//吃掉换行符
	if (y < 1 || y>16) { y = 1; }
	cout << "\n--Y axis location is " << y;

	clock_t temp = clock();
	while (clock() - temp < (clock_t)100);
	cout << ".\n\n\n\n\n                                      NOW LOADING......";

	temp = clock();
	while (clock() - temp < (clock_t)1000);
	cout << "......";

	temp = clock();
	while (clock() - temp < (clock_t)1000);
	cout << "\n\a";

	Screen screen1;
	Chara Madeline(&screen1,name,x,y,10,10,0,0,10,5);

	string str;		
	getline(cin, str);

	while (cin.fail() == false && str != "#")
	{
		Madeline.act(str);
		getline(cin, str);
	}

	cout << "Bye! See you!";
}