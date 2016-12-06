#include "GameManager.h"

GameManager * GameManager::mInstance = nullptr;

GameManager & GameManager::Instance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager;
	}

	return *mInstance;
}
