#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <cassert>
#include <type_traits>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

namespace Internal
{
	inline ComponentID getUniqueComponentID() noexcept
	{
		// static means:
		// Every time we call this function it will 
		// refer to the same 'lastID' instance
		static ComponentID lastID{ 0u };
		return lastID++;
	}
}

// We create a function that returns an unique ComponentID based
// upon the type passed.
template <typename T> inline
ComponentID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value,
		"T must inherit from Component");

	static ComponentID typeID{ Internal::getUniqueComponentID() };
	return typeID;
}

// Define a maximum number of components and groups
constexpr std::size_t maxComponents{ 32 };
constexpr std::size_t maxGroups{ 32 };

// Typedef an `std::bitset` for components and groups:
using ComponentBitset = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;

// Typedef an `std::array` for them
using ComponentArray = std::array<Component*, maxComponents>;


class Component
{
public:
	Entity* entity;

	// Let's add a virtual `init` method to our Component
	// class that will be called after the component is
	// added to an entity.
	virtual void init() {}

	virtual void update(float mFT) {}
	virtual void draw() {}

	virtual ~Component() {}
};

class Entity
{
private:
	// The entity need a reference to its manager
	Manager& manager;

	bool alive{ true };
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitset componentBitset;

	GroupBitset groupBitset;

public:
	Entity(Manager& mManager) : manager(mManager) {}

	void update(float mFT)
	{
		for (auto& c : components) c->update(mFT);
	}
	void draw()
	{
		for (auto& c : components) c->draw();
	}

	bool isAlive() const { return alive; }
	void destroy() { alive = false; }

	template <typename T>
	bool hasComponent() const
	{
		return componentBitset[getComponentTypeID<T>()];
	}

	// Groups will be handled at runtime, not compile-time:
	// therefore we will pass groups as a function argument
	bool hasGroup(Group mGroup) const noexcept
	{
		return groupBitset[mGroup];
	}

	void addGroup(Group mGroup) noexcept;
	void delGroup(Group mGroup) noexcept { groupBitset[mGroup] = false;	}


	// Now, we'll define a method that allows us to add components
	// to our entity.
	// We'll take advantage of C++11 variadic templates and emplacement
	// to directly construct our components in place.
	// `T` is the component type. `TArgs` is a parameter pack of
	// types used to construct the component.
	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		assert(!hasComponent<T>());

		// Allocating the component of type `T`
		// on the heap, by forwarding the passed arguments
		// to its constructor.
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this; // set component's entity to the current instance
		// We will wrap the raw pointer into a smart one,
		// so that we can emplace it into our container and
		// to make sure we do not leak any memory. 
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[getComponentTypeID<T>()] = c;
		componentBitset[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template <typename T>
	T& getComponent() const
	{
		assert(hasComponent<T>());
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return *reinterpret_cast<T*>(ptr);
	}
};

class Manager
{
private:
	std::vector<std::unique_ptr<Entity>> entities;

	// Store entities in group buckets in array.
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;

public:
	void update(float mFT)
	{
		for (auto& e : entities) e->update(mFT);
	}
	void draw()
	{
		for (auto& e : entities) e->draw();
	}

	void addToGroup(Entity* mEntity, Group mGroup)
	{
		groupedEntities[mGroup].emplace_back(mEntity);
	}

	std::vector<Entity*>& getEntitiesByGroup(Group mGroup)
	{
		return groupedEntities[mGroup];
	}

	void refresh()
	{
		// We need to remove dead entities and entities
		// with incorrect groups from the buckets.
		for (auto i(0u); i < maxGroups; ++i)
		{
			auto& v(groupedEntities[i]);

			v.erase(std::remove_if(std::begin(v), std::end(v),
				[i](Entity* mEntity)
				{
					return !mEntity->isAlive() || !mEntity->hasGroup(i);
				}),
			std::end(v));
		}

		entities.erase(
			std::remove_if(std::begin(entities), std::end(entities),
				[](const std::unique_ptr<Entity>& mEntity)
				{
					return !mEntity->isAlive();
				}),
			std::end(entities));
	}

	std::vector<Entity*>& getGroup(Group mGroup)
	{
		return groupedEntities[mGroup];
	}

	Entity& addEntity()
	{
		Entity* e(new Entity(*this));
		std::unique_ptr<Entity> uPtr{ e };
		entities.emplace_back(std::move(uPtr));
		return *e;
	}
};