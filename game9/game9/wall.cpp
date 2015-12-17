/////////////////////////////////////
// Include
#include "wall.h"


/////////////////////////////////////
// Class Wall
Wall::Wall()
{
	m_type = GameObjectType_Wall;
}


void Wall::render( sf::RenderWindow* rw )
{
	GameObject::render( rw );
}