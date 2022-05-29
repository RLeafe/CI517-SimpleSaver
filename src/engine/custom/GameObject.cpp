#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::GameObject(string name, int posX, int posY, int width, int height, int score)
{
	this->name = name;
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;

	this->score = score;
}

GameObject::GameObject(string name, int posX, int posY)
{
	this->name = name;
	this->posX = posX;
	this->posY = posY;
}

GameObject::~GameObject()
{
}