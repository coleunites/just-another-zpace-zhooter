#include "GamePlayState.h"

#include "AppStates.h"
#include <SGE.h>

GamePlayState::GamePlayState(GameContext & gameContext)
	:AppState(gameContext)
{}

GamePlayState::~GamePlayState()
{}

void GamePlayState::Load()
{

}

void GamePlayState::Unload()
{

}

void GamePlayState::Render()
{

}

bool GamePlayState::Update(const float deltaTime, AppStates & nextAppState)
{
	nextAppState = AppStates::GamePlay;

	if ( SGE::Input_IsKeyPressed(SGE::Keys::ESCAPE))
	{
		return true;
	}

	return false;
}