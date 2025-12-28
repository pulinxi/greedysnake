
#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

class node
{
public:

	SDL_FRect snake_rect = { 0,0,0,0 };
	node* next = NULL;

};

