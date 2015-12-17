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

	virtual void render( sf::RenderWindow* rw );

	virtual void intersect( GameObject* object );

	void setOwnerType( GameObjectType ownerType ){ m_ownerType = ownerType; }
	GameObjectType getOwnerType(){ return m_ownerType; }

private:
	GameObjectType m_ownerType;
};
