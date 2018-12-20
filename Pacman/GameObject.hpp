#pragma once

class GameObject {
public:
	GameObject();
	void interact();
	void move(float x, float y);
	virtual ~GameObject();
private:
	void _setPrevCoords();

	int _x;
	int _y;
};

