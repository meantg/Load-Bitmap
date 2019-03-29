#pragma once
#include "PlayerState.h"
#include "Player.h"
#include "ClimbState.h"
#include "JumpState.h"
#include "RunState.h"
#include "SitState.h"
#include "StandState.h"

class AttackState : public PlayerState
{
private: 
	State _curState;
	State _atkState;
	bool _reverse;
public:
	AttackState(PlayerHandler * _playerhandler);
	void Update(float dt) ;
	void HandleKeyboard(map<int, bool> keyCode) ;
	State GetName();
};