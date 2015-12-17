/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class GameObject
GameObject::GameObject()
{
	m_game = 0;
	m_type = GameObjectType_None;

	m_x = 0.0;
	m_y = 0.0;
	m_xSpeed = 0.0;
	m_ySpeed = 0.0;

	m_width = 1;
	m_height = 1;

	m_health = 1;
	m_destroyAfterDeath = true;
	m_invulnerable = false;

	m_physical = true;

	m_direction = Direction_Up;

	m_sprite = new sf::Sprite();
	m_sprite->setTexture( *g_atlas00 );
	setTextureRect( sf::IntRect() );
}

GameObject::~GameObject()
{
	if( m_sprite )
		delete m_sprite;
}

void GameObject::render( sf::RenderWindow* rw )
{
	if( m_sprite )
	{
		int row = int( m_y );
		int column = int( m_x ); 

		m_sprite->setPosition( column * kPixelsPerCell, row * kPixelsPerCell );

		rw->draw(*m_sprite);
	}
}

void GameObject::update( float dt )
{
	int oldRow = int( m_y );
	int oldColumn = int( m_x );

	float newY = m_y + m_ySpeed * dt;
	float newX = m_x + m_xSpeed * dt;

	int newRow = int( newY );
	int newColumn = int( newX );


	if( oldColumn != newColumn )
		m_game->moveObjectTo( this, newX, m_y );
	else
		m_x = newX;

	if( oldRow != newRow )
		m_game->moveObjectTo( this, m_x, newY );
	else
		m_y = newY;
}

void GameObject::intersect( GameObject* object )
{
	
}

void GameObject::doDamage( int damage )
{
	if( getInvulnerable() )
		return;

	if( m_health > damage )
		m_health -= damage;
	else
		m_health = 0;
}