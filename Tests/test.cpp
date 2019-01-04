#include "pch.hpp"

#include "SFML/Graphics.hpp"

#include "../Pacman/GObject.hpp"

TEST(pgGameObject, init) {
	pg::GObject obj1();
	EXPECT_EQ(1, 1);
}

