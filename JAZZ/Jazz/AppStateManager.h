#ifndef APPSTATEMANAGER_HEADERGAURD
#define APPSTATEMANAGER_HEADERGAURD

#include "AppStates.h"
#include "GameContext.h"

class AppState;

class AppStateManager
{
public:
	AppStateManager();
	~AppStateManager();

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
