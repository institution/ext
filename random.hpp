#pragma once

#include <random>

namespace ext {
	template<int32_t A, int32_t B>
	int roll()
	{
		static std::default_random_engine e{std::random_device()()};
		static std::uniform_int_distribution<int> d{A, B};

		return d(e);
	}
}



	
	
