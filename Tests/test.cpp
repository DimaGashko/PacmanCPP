#include "pch.h"

#include "PacmanGame.h"
#include "../Pacman/pg/PacmanGame.h"

TEST(pgPacmanGame, Init) {
	pg::PacmanGame game();



	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}