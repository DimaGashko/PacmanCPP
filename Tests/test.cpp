#include "pch.hpp"

#include "SFML/Graphics.hpp"

#include "../Pacman/GameObject.hpp"

TEST(pgGameObject, init) {
	pg::GameObject obj1();
	EXPECT_EQ(1, 1);
}

