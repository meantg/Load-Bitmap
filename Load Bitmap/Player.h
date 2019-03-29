#pragma once
#include "Object.h"
#include "PlayerHandler.h"
#include "PlayerState.h"
#include "AttackState.h"
#include <map>

class Player : public Object
{
protected:
	float vx, vy, nx, width, height;
	LPANIMATION _curanimation;
	unordered_map<State, LPANIMATION> _animations;
	unordered_map<State, bool> _allow;
	PlayerHandler *_playerhandler;
	State _state;
	bool isReverse = false;

public:
	Player();
	~Player() {};

	void Allow(State state, bool flag);
	void Update(DWORD dt);
	void Render();
	void SetState(State state);


	void SetWidth(float _width) { width = _width; }
	void SetHeight(float _height) { height = _height; }
	State GetState() { return _state; }

	void ChangeAnimation(State state);
	void ChangeState(PlayerState* newState);

	void HandleKeyboard(map<int, bool> keyCode);
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
};