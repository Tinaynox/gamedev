/////////////////////////////////////
// Include
#include "base.h"


/////////////////////////////////////
// Class GameObject
Base::Base()
{
	m_type = GameObjectType_Base;

	m_width = kBaseColumns;
	m_height = kBaseRows;

	m_health = kBaseHealth;
	m_destroyAfterDeath = false;
}


void Base::render( sf::RenderWindow* rw )
{
	sf::IntRect texRect = kBaseImage;
	texRect.top += (3 - m_health) * m_height * kPixelsPerCell;
	setTextureRect( texRect );

	GameObject::render( rw );
}