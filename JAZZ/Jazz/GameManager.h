#ifndef GAMEMANAGER_HEADERGAURD
#define GAMEMANAGER_HEADERGAURD

#include "AppStates.h"
#include "GameContext.h"

class AppState;

//TODO:  change class name?

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Load();
	void Unload();
	void Render();
	bool Update(const float deltaTime);


private:
	AppStates mCurrentAppState;
	AppState * mAppState;
	GameContext mGameContext;
	bool mQuit;
};

#endif
