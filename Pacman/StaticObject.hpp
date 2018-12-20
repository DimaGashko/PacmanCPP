#pragma once
class StaticObject {
public:
	StaticObject();
	void interact();
	virtual void move(float x, float y) = 0;
	virtual ~StaticObject();
private:
	void _setPrevCoords();

	int _x;
	int _y;
};

