#include "SitState.h"

SitState::SitState(PlayerHandler * _playerhandler)
{
	_playerhandler = _playerHandler ;
}

State SitState::GetName()
{
	return SITTING;
}
