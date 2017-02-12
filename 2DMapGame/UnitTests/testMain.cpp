#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Block.h"

TEST_CASE("Collision Test", "[Collision]")
{
	WallBlock mainBlock(1, 1);
	WallBlock topLeft(0, 0);
	WallBlock top(1, 0);
	WallBlock topRight(2, 0);
	WallBlock middleLeft(0, 1);
	WallBlock middle(1, 1);
	WallBlock middleRight(2, 1);
	WallBlock bottomLeft(0, 2);
	WallBlock bottom(1, 2);
	WallBlock bottomRight(2, 2);

	REQUIRE(mainBlock.collision(&topLeft) == false);
	REQUIRE(mainBlock.collision(&top) == false);
	REQUIRE(mainBlock.collision(&topRight) == false);
	REQUIRE(mainBlock.collision(&middleLeft) == false);
	REQUIRE(mainBlock.collision(&middle) == true);
	REQUIRE(mainBlock.collision(&middleRight) == false);
	REQUIRE(mainBlock.collision(&bottomLeft) == false);
	REQUIRE(mainBlock.collision(&bottom) == false);
	REQUIRE(mainBlock.collision(&bottomRight) == false);
}