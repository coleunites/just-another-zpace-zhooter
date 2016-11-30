#include <SGE.h>

using namespace SGE;

bool quit = false;

void SGE_Initialize()
{
}

void SGE_Terminate()
{
}

bool SGE_Update(float deltaTime)
{
	if (Input_IsKeyPressed(Keys::ESCAPE))
	{
		quit = true;
	}
	return quit;
}

void SGE_Render()
{

}