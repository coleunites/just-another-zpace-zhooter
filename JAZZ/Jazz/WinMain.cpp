#include <SGE.h>

#include "GameManager.h"

GameManager gameManager;

using namespace SGE;

void SGE_Initialize()
{
	gameManager.Load();
}

void SGE_Terminate()
{
	gameManager.Unload();
}

bool SGE_Update(float deltaTime)
{
	return gameManager.Update(deltaTime);
}

void SGE_Render()
{
	gameManager.Render();
}