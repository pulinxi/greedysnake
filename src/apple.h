#pragma once
#include "snake.h"

class apple
{
public:
	SDL_Texture* texture = NULL;
	SDL_Surface* img_suf = NULL;
	SDL_FRect apple_rect = { 0,0,0,0 };
	int drawapple(SDL_Renderer *rdr,snake snake1,int kill);
	void appleinit(SDL_Renderer* rdr, snake snake1);
};
