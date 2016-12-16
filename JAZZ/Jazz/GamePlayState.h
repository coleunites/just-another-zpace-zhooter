#ifndef GAMEPLAYSTATE_HEADERGAURD
#define GAMEPLAYSTATE_HEADERGAURD

#include "AppState.h"

#include "Player.h"
#include "Enemy.h"
#include "HUD.h"

class GamePlayState : public AppState
{
public:
	GamePlayState(GameContext & gameContext);
	virtual ~GamePlayState();

	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual bool Update(const float deltaTime, AppStates & nextAppState) override;

private:
	Player mPlayer;
	Enemy mEnemy;
	HUD mHud;
};

#endif
