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

inline ComponentID getUniqueComponentID() noexcept
{
	static ComponentID lastID{ 0u };
	return lastID++;
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept
{
	static_assert 
}