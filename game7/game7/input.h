#pragma once


/////////////////////////////////////
// Include
#include "Windows.h"


/////////////////////////////////////
// Functions
bool IsKeyDown( int virtualKeyCode )
{	
	short keyState = GetAsyncKeyState( virtualKeyCode );
	return ( ( keyState & 0x8000 ) > 0 );
}
