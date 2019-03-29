#include "Player.h"

Player::Player()
{
	_playerhandler = new PlayerHandler();
	_playerhandler->SetPlayer(this);
	ChangeState(new StandState(_playerhandler));

	_allow[JUMPING] = true;
	_allow[ATTACKING_SIT] = true;
	_allow[ATTACKING_STAND] = true;
	_allow[CLIMBING] = false;
}
void Player::Allow(State state, bool flag)
{
	_allow[state] = flag;
}
void Player::Update(DWORD dt)
{
}

void Player::Render()
{
	State ani = _curState;
	animations[ani]->FlipHorizontal(isReverse);
	animations[ani]->Render(x, y);
}

void Player::SetState(State state)
{
	switch (state)
	{
	case STANDING:
		vx = 0;
		_curState = STANDING;
		break;
	case RUNNING:
		vx = NINJA_WALKING_SPEED;
		_curState = RUNNING;
		nx = 1;
		isReverse = false;
		break;
	case RUNNING_RIGHT:
		vx = NINJA_WALKING_SPEED;
		_curState = RUNNING;
		nx = -1;
		isReverse = true;
		break;
	case JUMPING:
		if (y == 100)
			vy = -NINJA_JUMPING_SPEED_Y;
		_curState = JUMPING;
		break;
	case SITTING:
		_curState = SITTING;
		break;
	case ATTACKING_STAND:
		_curState = ATTACKING_STAND;
		break;
	default:
		break;
	}

}

void Player::ChangeAnimation(State state)
{
	SetState(state);
	_curanimation = _animations[state];
}

void Player::ChangeState(PlayerState * newState)
{
	_playerhandler->SetState(newState);
	_state = newState->GetName();
	ChangeAnimation(_state);
}

void Player::HandleKeyboard(map<int, bool> keyCode)
{
	_playerhandler->GetState()->HandleKeyboard(keyCode);
}

void Player::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_A:
		ChangeState(new AttackState(_playerhandler));
		break;
	case DIK_LEFT||DIK_RIGHT:
		ChangeState(new RunState(_playerhandler));
		break;
	case DIK_DOWN:
		ChangeState(new SitState(_playerhandler));
		break;
	case DIK_SPACE:
		ChangeState(new JumpState(_playerhandler));
		break;
	}
}


