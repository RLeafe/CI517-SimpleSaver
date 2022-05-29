#ifndef __MY_GameObject_H__
#define __MY_GameObject_H__

#include "../EngineCommon.h"

#include <vector>

using std::vector;
using std::string;

class GameObject {
	friend class XCube2Engine;
	private:
	public:
		string name;
		int posX, posY, width, height;
		int score;

		GameObject();
		GameObject(string name, int posX, int posY, int width, int height, int score);
		GameObject(string name, int posX, int posY);
		~GameObject();
};

#endif