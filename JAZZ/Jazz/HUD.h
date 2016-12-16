#ifndef HUD_HEADERGAURD
#define HUD_HEADERGAURD

namespace SGE
{
	class SGE_Sprite;
}

#include <string>

class HUD
{
public:
	HUD();
	~HUD();

	void Load(const unsigned int lives, const char* textureName);
	void UnLoad();
	void Render(); 

	void UpdateNumLives(const unsigned int lives);

private:
	SGE::SGE_Sprite * mLivesSprites;
	unsigned int mNumLivesSprites;
	unsigned int mCurNumLives;
	std::string mTextureName;
};

#endif
