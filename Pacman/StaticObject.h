#pragma once
class StaticObject {
public:
	StaticObject();
	void interact();
	virtual void move(float x, float y) = 0;
	virtual ~StaticObject();
private:
	void _setPrevCoords();
};

