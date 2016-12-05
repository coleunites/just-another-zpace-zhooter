#ifndef GAMEOBJECT_HEADERGAURD
#define GAMEOBJECT_HEADERGAURD

#include <SGE_Math.h>
#include <SGE_Graphics.h>

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update(const float deltaTime) = 0;

	SGE::SVector2 GetPosition() const;
	void SetPosition(const SGE::SVector2 pos);
	void SetSprite(const char * spriteName);

protected:
	SGE::SVector2 mPos;
	SGE::SGE_Sprite mSprite;
};

#endif
