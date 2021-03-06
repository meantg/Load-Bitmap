#pragma once
#include "PlayerState.h"
#include "Player.h"

class StandState : public PlayerState
{
public:
	StandState(PlayerHandler * _playerhandler);
	void Update(float dt) {};
	void HandleKeyboard(map<int, bool> keyCode) {};
	State GetName();
};