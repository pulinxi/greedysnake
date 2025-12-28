#include "snake.h"

#define pi 3.1415926535


snake::snake()
{
	//蛇的初始状态设置
	front = right;
	behind = left;
	flag = front;


	first = new node;
	tail = new node;
	node* p = NULL;
	float i = 5;
	first->next = NULL;
	while (i > 0)
	{
		p = new node;
		p->snake_rect = { 50 * i,0,50,50 };
		p->next = first->next;
		first->next = p;
		if (i == 5)
		{
			tail->next = p;
		}
		i--;
	}
	
}

//snake::~snake()
//{
//	node* p = first->next;
//	while (p != NULL)
//	{
//		node* work = NULL;
//		work = p;
//		p = p->next;
//		delete work;
//	}
//}

void snake::drawsnake(SDL_Renderer *rdr)
{
	SDL_SetRenderDrawColor(rdr, 255, 255, 255, 255);
	SDL_RenderClear(rdr);
	double time = (double)SDL_GetTicks() / 1000.0;
	/*如果这里用int time = SDL_GetTicks()/1000的话，
	由于整形除法会自动舍去小数，
	导致time只可以等于1，2，3等，使得颜色转化不够丝滑*/
	float r, g, b;
	r = SDL_sin(time + SDL_PI_D) * 0.5 + 0.5;//通过正弦函数来控制渲染器的rgb值，以达到时渲染器颜色可以顺畅的改变的效果
	g = SDL_sin(time + 2 * SDL_PI_D / 3) * 0.5 + 0.5;
	b = SDL_sin(time + 4 * SDL_PI_D / 3) * 0.5+ 0.5;
	SDL_SetRenderDrawColorFloat(rdr, r, g, b, 255);
	node* p = first->next;
	while (p != NULL)//通过工作只针的前进不断渲染下一个矩形
	{
		SDL_RenderFillRect(rdr,&(p->snake_rect));
		p = p->next;
	}
	//此处无需present，画苹果的时候会present
	//SDL_RenderPresent(rdr);
	return;
}

void snake::goahead(Uint32 flag)
{
	if (flag == right)
	{
		//根据拐弯方向将蛇的尾巴放到蛇的头部
		node* p = first->next;
		first->next = p->next;
		p->next = (tail->next)->next;
		(tail->next)->next = p;
		p->snake_rect.x = (tail->next)->snake_rect.x + 50.0;//新头的横坐标是旧头加50
		p->snake_rect.y = (tail->next)->snake_rect.y;
		tail->next = p;
		front = right; 
		behind = left;
	}
	else if (flag == left)
	{
		//根据拐弯方向将蛇的尾巴放到蛇的头部
		node* p = first->next;
		first->next = p->next;
		p->next = (tail->next)->next;
		(tail->next)->next = p;
		p->snake_rect.x = (tail->next)->snake_rect.x - 50.0;//新头的横坐标是旧头-50
		p->snake_rect.y = (tail->next)->snake_rect.y;
		tail->next = p;
		front = left;
		behind = right;
	}
	else if (flag == down)
	{
		//根据拐弯方向将蛇的尾巴放到蛇的头部
		node* p = first->next;
		first->next = p->next;
		p->next = (tail->next)->next;
		(tail->next)->next = p;
		p->snake_rect.y = (tail->next)->snake_rect.y + 50.0;//新头的纵坐标是旧头加50
		p->snake_rect.x = (tail->next)->snake_rect.x;
		tail->next = p;
		front = down;
		behind = up;
	}
	else
	{
		//根据拐弯方向将蛇的尾巴放到蛇的头部
		node* p = first->next;
		first->next = p->next;
		p->next = (tail->next)->next;
		(tail->next)->next = p;
		p->snake_rect.y = (tail->next)->snake_rect.y - 50.0;//新头的纵坐标是旧头减50
		p->snake_rect.x = (tail->next)->snake_rect.x;
		tail->next = p;
		front = up;
		behind = down;
	}
	return;

}

int snake::iseatapple(int x,int y)
{
	if ((int)tail->next->snake_rect.x == x && (int)tail->next->snake_rect.y == y)
	{
		return 0;//如果迟到了苹果则返回0
	}
	return 1;
}

void snake::addlen()
{
	node* p = new node;
	p->snake_rect = { 0,0,50,50 };//不用在意新加节点的坐标，画蛇的时候回定义；；；
	p->next = first->next;
	first->next = p;
	return;
}