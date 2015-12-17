#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class Base
	: public GameObject
{
public:
	Base();

	virtual void render( sf::RenderWindow* rw );
};
