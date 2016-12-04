#include "FrontEndState.h"

#include "AppStates.h"
#include <SGE.h>

FrontEndState::FrontEndState(GameContext & gameContext)
	:AppState(gameContext)
{}

FrontEndState::~FrontEndState()
{}

void FrontEndState::Load()
{
	const int kWindowWidth = SGE::IniFile_GetInt("WinWidth", 800);
	mFont.Load(65, false, false);

	float buttonSpriteHalfWidth = 0.0f;

	mButtonPlay.Load("button_on.png", "button_off.png");
	mButtonPlay.SetText("PLAY", 255, 255, 255);
	buttonSpriteHalfWidth = static_cast<float>(mButtonPlay.GetSpriteWidth()) * 0.5f;
	mButtonPlay.SetPosition(kWindowWidth * 0.5f - buttonSpriteHalfWidth, 400.0f);

	mButtonQuit.Load("button_on.png", "button_off.png");
	mButtonQuit.SetText("QUIT", 255, 255, 255);
	buttonSpriteHalfWidth = static_cast<float>(mButtonQuit.GetSpriteWidth()) * 0.5f;
	mButtonQuit.SetPosition(kWindowWidth * 0.5f - buttonSpriteHalfWidth, 500.0f);

	mCursor.Load("cursor.png");
}

void FrontEndState::Unload()
{
	mFont.Unload();
	mButtonPlay.Unload();
	mButtonQuit.Unload();
	mCursor.Unload();
}

void FrontEndState::Render()
{
	const int kWindowWidth = SGE::IniFile_GetInt("WinWidth", 800);
	mFont.Print("Just Another Zpace Zhooter", (int)(kWindowWidth * 0.15f), 100);
	mButtonPlay.Render();
	mButtonQuit.Render();
	mCursor.Render();
}

bool FrontEndState::Update(const float deltaTime, AppStates & nextAppState)
{
	nextAppState = AppStates::FrontEnd;

	mButtonPlay.Update(deltaTime);
	mButtonQuit.Update(deltaTime);
	mCursor.Update(deltaTime);

	if (mButtonPlay.IsPressed())
	{
		nextAppState = AppStates::GamePlay;
	}
	else if (mButtonQuit.IsPressed() || SGE::Input_IsKeyPressed(SGE::Keys::ESCAPE))
	{
		return true;
	}
	return false;
}