#include "Function.h"

#pragma region Init
void Init()
{
#pragma region character
	Player* player = new Player;
	player->shape[0] = "  o  ";
	player->shape[1] = " /|\\  ";
	player->shape[2] = " / \\ ";
	Weapon* playerWeapon = new Weapon;
	playerWeapon->x = player->x + 2;
	playerWeapon->y = player->y - 2;
	Skill* normal = new Skill;

	normal->Text = "기본공격";
#pragma endregion
}