#pragma once
#include "PlayerHandler.h"
#include <map>
#include "Object.h"

class PlayerState
{
protected:
	PlayerHandler* _playerHandler;
public:
	PlayerState() {};
	virtual ~PlayerState() { if (_playerHandler) delete _playerHandler; }
	PlayerState(PlayerHandler* playerhandler) { _playerHandler = playerhandler; };

	virtual State GetName() = 0;
	virtual void HandleKeyboard(std::map<int, bool> keyCode) = 0;
	virtual void Update(float dt) = 0;
};