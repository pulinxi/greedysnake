#define SDL_MAIN_USE_CALLBACKS 1  //使用sdl自带的回调机制代替main函数
#include "snake.h"
#include <SDL3/SDL_main.h>
#include "apple.h"


SDL_Window* win = NULL;
SDL_Renderer* rdr = NULL;
snake snake1 = snake();
int applenumber = 1;
apple apple1;




SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])//初始化
{
	
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		SDL_Log("SDL_Init() fail:%s", SDL_GetError());
		return SDL_APP_FAILURE;
	}
	if (!SDL_CreateWindowAndRenderer("snake", 1600, 1200, 0, &win, &rdr))
	{
		SDL_Log("win and renderer fail:%s", SDL_GetError());
		return SDL_APP_FAILURE;
	}
	apple1.appleinit(rdr, snake1);
	apple1.img_suf = IMG_Load("image/apple.png");
	if (!apple1.img_suf)
	{
		SDL_Log("img_suf fail:%s", SDL_GetError());
	}
	apple1.texture = SDL_CreateTextureFromSurface(rdr, apple1.img_suf);
	if (!apple1.texture)
	{
		SDL_Log("texture fail:%s", SDL_GetError());
	}
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS;
	}
	if(event->type==SDL_EVENT_KEY_DOWN)
	{
		if (event->key.key == snake1.up || event->key.key == snake1.down || event->key.key == snake1.right || event->key.key == snake1.left)
		{
			if (!(event->key.key == snake1.behind || event->key.key == snake1.front))
			{
				SDL_Log("%d",event->key.key);
				snake1.flag = event->key.key;
			}
		}
	}
	
	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
	if (!applenumber)
	{
		snake1.addlen();
	}
	snake1.goahead(snake1.flag);
	snake1.drawsnake(rdr);
	apple1.drawapple(rdr, snake1, applenumber);
	applenumber = snake1.iseatapple((int)apple1.apple_rect.x,(int)apple1.apple_rect.y);

	SDL_Delay(100);
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)//释放资源
{
	SDL_DestroyRenderer(rdr);
	SDL_DestroyWindow(win);
	snake1.~snake();
	SDL_DestroySurface(apple1.img_suf);
	SDL_DestroyTexture(apple1.texture);
	return;
}



