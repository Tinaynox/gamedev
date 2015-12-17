#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class Wall
	: public GameObject
{
public:
	Wall();

	virtual void render( sf::RenderWindow* rw );

private:
};
