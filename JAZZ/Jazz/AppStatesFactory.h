#ifndef APPSTATESFACTORY_HEADERGAURD
#define APPSTATESFACTORY_HEADERGAURD

class AppState;
enum class AppStates;
class GameContext;

class AppStatesFactory
{
public:
	static AppState * CreateAppState(const AppStates & desiredAppState, GameContext & gameContext);
};

#endif

