#include "ECS.h"

void Entity::addGroup(Group mGroup) noexcept
{
	groupBitset[mGroup] = true;
	manager.addToGroup(this, mGroup);
}