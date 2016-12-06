#include "AppStateManager.h"

#include "AppState.h"
#include "AppStatesFactory.h"

// TODO: Add in Asserts NOTE: find places to put asserts by searching for ASSERT HERE

AppStateManager::AppStateManager()
	: mAppState(nullptr)
	, mCurrentAppState(AppStates::Invalid)
	, mQuit(false)
{

}

AppStateManager::~AppStateManager()
{
	//ASSERT HERE
}

void AppStateManager::Load()
{
	//ASSERT HERE
	mCurrentAppState = AppStates::FrontEnd;
	mAppState = AppStatesFactory::CreateAppState(AppStates::FrontEnd, mGameContext);

	mAppState->Load();
}

void AppStateManager::Unload()
{
	//ASSERT HERE
	mAppState->Unload();

	delete mAppState;
	mAppState = nullptr;

	mCurrentAppState = AppStates::Invalid;
}

void AppStateManager::Render()
{
	//ASSERT HERE
	mAppState->Render();
}

bool AppStateManager::Update(const float deltaTime)
{
	AppStates nextAppState = AppStates::Invalid;

	mQuit = mAppState->Update(deltaTime, nextAppState);

	if (nextAppState != mCurrentAppState)
	{
		mCurrentAppState = nextAppState;
		
		mAppState->Unload();

		delete mAppState;
		mAppState = nullptr;

		mAppState = AppStatesFactory::CreateAppState(nextAppState, mGameContext);
		mAppState->Load();
	}

	return mQuit;
}