#include <dlfcn.h>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cstring>
#include <vector>
#include<iostream>
#include "libGameLogic.h"

bool Player::CanJump() {
	return 1;
}

void Player::Chat(const char* msg) {
	if(strncmp("tp ", msg, 3) == 0){
		Vector3* new_pos = new Vector3();
		sscanf(msg+3, "%f %f %f", &(new_pos->x), &(new_pos->y), &(new_pos->z));
		this->SetPosition(*new_pos);
	}
	if(strncmp("pos", msg, 4) == 0) {
		Vector3 new_pos = this->GetPosition();
		float x_coor = new_pos.x;
		float y_coor = new_pos.y;
		float z_coor = new_pos.z;
		printf("x_coor:%f, y_coor:%f, z_coor:%f", x_coor, y_coor, z_coor);
		fflush(stdout);
	}
}

void World::Tick(float f) {
	ClientWorld* world = *(ClientWorld**)dlsym(RTLD_NEXT, "GameWorld");
	IPlayer* iplayer = world->m_activePlayer.m_object;
	Player* player = ((Player*)(iplayer));
	player->m_walkingSpeed = 99999;
	player->m_jumpSpeed = 999;
	player->m_jumpHoldTime = 99999;
}

int main(){

}
