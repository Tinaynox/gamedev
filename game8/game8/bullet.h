#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Tank
class Bullet
	: public GameObject
{
public:
	Bullet();

	virtual void render( RenderSystem* rs );

	virtual void intersect( GameObject* object );

	void setImage( char symbol, ConsoleColor symbolColor, ConsoleColor bgColor );

	void setOwnerType( GameObjectType ownerType ){ m_ownerType = ownerType; }
	GameObjectType getOwnerType(){ return m_ownerType; }

private:
	ConsoleSymbolData m_image;
	GameObjectType m_ownerType;
};
