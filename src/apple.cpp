#include "apple.h"




int apple::drawapple(SDL_Renderer *rdr,snake snake1,int kill)
{
	if(kill==0)
	{ 
		while (true)
		{
			int apple_x = (int)SDL_rand(32);
			int apple_y = (int)SDL_rand(24);
			node* p = snake1.first->next;
			int flag = 0;
			while (p != NULL)
			{
				if (p->snake_rect.x == apple_x * 50 && p->snake_rect.y == apple_y*50)
				{
					flag = 1;
					break;
				}
				p = p->next;
			}
			if (!flag)
			{
				apple_rect = { (float)apple_x * 50,(float)apple_y * 50,50,50 };
				break;
			}
		}
		SDL_RenderTexture(rdr, texture, NULL, &apple_rect);
		SDL_RenderPresent(rdr);
		kill = 1;
	}
	else
	{
		SDL_RenderTexture(rdr, texture, NULL, &apple_rect);
		SDL_RenderPresent(rdr);
	}
	return kill;
}


void apple::appleinit(SDL_Renderer* rdr, snake snake1)
{
	while (true)
	{
		int apple_x = (int)SDL_rand(32);
		int apple_y = (int)SDL_rand(24);
		node* p = snake1.first->next;
		int flag = 0;
		while (p != NULL)
		{
			if (p->snake_rect.x == apple_x * 50 && p->snake_rect.y == apple_y * 50)
			{
				flag = 1;
				break;
			}
			p = p->next;
		}
		if (!flag)
		{
			apple_rect = { (float)apple_x * 50,(float)apple_y * 50,50,50 };
			break;
		}
	}
}