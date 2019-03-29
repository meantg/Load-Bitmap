#include "AttackState.h"

AttackState::AttackState(PlayerHandler* _playerhandler)
{
	_playerHandler = _playerhandler;
	_curState = _playerHandler->GetState()->GetName();
	_playerHandler->GetPlayer()->Allow(JUMPING, false);

	if (_curState == SITTING)
	{
		_atkState = ATTACKING_SIT;
	}
	else
	{
		_atkState = ATTACKING_STAND;
	}
}

void AttackState::HandleKeyboard(map<int, bool> keyCode)
{
	if (!keyCode[DIK_DOWN] && _curState == SITTING)
		_curState = STANDING;
}

State AttackState::GetName()
{
	return _atkState;
}

void AttackState::Update(float dt)
{

}
