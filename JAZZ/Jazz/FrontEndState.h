#ifndef FRONTENDSTATE_HEADERGAURD
#define FRONTENDSTATE_HEADERGAURD

#include "AppState.h"
#include <SGE.h>

class FrontEndState : public AppState
{
public:
	FrontEndState(GameContext & gameContext);
	virtual ~FrontEndState();

	virtual void Load() override;
	virtual void Unload() override;
	virtual void Render() override;
	virtual bool Update(const float deltaTime, AppStates & nextAppState) override;

private:
	SGE::SGE_Font mFont;
	SGE::SGE_Button mButtonPlay;
	SGE::SGE_Button mButtonQuit;
	SGE::SGE_Cursor mCursor;
};

#endif
