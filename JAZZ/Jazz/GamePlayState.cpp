#include "GamePlayState.h"

#include "AppStates.h"
#include <SGE.h>

using namespace SGE;

const float kPlayerSpeed = 500.0f;

GamePlayState::GamePlayState(GameContext & gameContext)
	: AppState(gameContext)
	, mPlayer(3)
{}

GamePlayState::~GamePlayState()
{}

void GamePlayState::Load()
{
	mPlayer.Load();
	mPlayer.SetSpeed(kPlayerSpeed);

	mEnemy.Load();
	mEnemy.SetPosition(SVector2(200.0f, 0.0f));
	mEnemy.SetSpeed(kPlayerSpeed * 0.5f);
	mEnemy.Activate();

	mHud.Load(mPlayer.GetLives(), "fighterLives.png");
}

void GamePlayState::Unload()
{
	mPlayer.Unload();
	mEnemy.Unload();
	mHud.UnLoad();
}

void GamePlayState::Render()
{
	mPlayer.Render();
	mEnemy.Render();
	mHud.Render();
}

bool GamePlayState::Update(const float deltaTime, AppStates & nextAppState)
{
	nextAppState = AppStates::GamePlay;

	mPlayer.Update(deltaTime);
	mEnemy.Update(deltaTime);



	if ( Input_IsKeyPressed(Keys::ESCAPE))
	{
		return true;
	}

	// test ti see if live counter works
	if (Input_IsKeyPressed(Keys::P))
	{
		mPlayer.Kill();
		mHud.UpdateNumLives(mPlayer.GetLives());
	}
	
	return false;
}