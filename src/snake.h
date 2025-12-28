

#pragma once
#include "node.h"

class snake
{
private:
	

	


public:
	const Uint32 up = SDLK_W;
	const Uint32 down = SDLK_S;
	const Uint32 left = SDLK_A;
	const Uint32 right = SDLK_D;//这四个是用来规定上下左右分别对应键盘哪个按键
	Uint32 flag = NULL;
	Uint32 front = NULL;//蛇的当前朝向
	Uint32 behind = NULL;

	//两个指针分别指向蛇头和蛇尾
	node* first = NULL;
	node* tail = NULL;


	snake();//构造函数
	~snake() {};
	void drawsnake(SDL_Renderer *rdr);//画蛇
	void goahead(Uint32 flag);//蛇的移动
	int iseatapple(int x,int y);
	void addlen();
};

