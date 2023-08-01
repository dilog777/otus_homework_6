#pragma once

#include <array>



template<std::size_t N>
class ArrayHash
{
public:
	auto operator()(const std::array<int, N> &array) const
	{
		std::size_t result = 0;
		for (const auto &value : array)
			result = result * 31 + std::hash<int> {}(value);

		return result;
	}
};