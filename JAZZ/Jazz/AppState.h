#ifndef APPSTATE_HEADERGAURD
#define APPSTATE_HEADERGAURD

class GameContext;
enum class AppStates;

class AppState
{
public:
	AppState(GameContext & gameContext);
	virtual ~AppState();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual bool Update(const float deltaTime, AppStates & nextAppState) = 0;

protected:
	GameContext & mGameContext;
};

#endif // !APPSTATE_HEADERGAURD
