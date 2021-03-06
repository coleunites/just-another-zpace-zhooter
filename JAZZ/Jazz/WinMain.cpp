#include <SGE.h>

#include "AppStateManager.h"

AppStateManager appStateManager;

using namespace SGE;

// TODO: get rid of magic numbers

void SGE_Initialize()
{
	appStateManager.Load();
}

void SGE_Terminate()
{
	appStateManager.Unload();
}

bool SGE_Update(float deltaTime)
{
	return appStateManager.Update(deltaTime);
}

void SGE_Render()
{
	appStateManager.Render();
}