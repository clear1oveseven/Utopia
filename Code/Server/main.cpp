#include <stdio.h>
#include "Utils/ConfigUtil.h"
#include "Game.h"

int main(int argc, char **argv)
{
	printf("hello world");

	int a = 0;
	ConfigUtil::Str2BaseValue("123", a);

	Game game;
	game.Init(nullptr);
	game.Awake(nullptr);
	game.Update(nullptr);
	game.Realse(nullptr);
}