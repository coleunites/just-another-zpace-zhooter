#include "AppStatesFactory.h"

#include "AppState.h"
#include "AppStates.h"
#include "FrontEndState.h"
#include "GameContext.h"
#include "GamePlayState.h"


AppState * AppStatesFactory::CreateAppState(const AppStates & desiredAppState, GameContext & gameContext)
{
	switch (desiredAppState)
	{
	case AppStates::FrontEnd:
		return new FrontEndState(gameContext);
			break;

	case AppStates::GamePlay:
		return new GamePlayState(gameContext);
		break;

	default:
		break;
	}

	return nullptr;
}