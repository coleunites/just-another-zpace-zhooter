#ifndef GAMEMANAGER_HEADERGAURD
#define GAMEMANAGER_HEADERGAURD

class GameManager
{

public:
	~GameManager() {}
	static GameManager & Instance();



private:
	GameManager() {}

	static GameManager * mInstance;
};

#endif
