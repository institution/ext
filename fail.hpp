#pragma once

#include <stdlib.h>
#include <cassert>
#include "format.hpp"

namespace ext{


	template <class... Args>
	[[noreturn]] 
	void fail(char const* fmt, Args... args) {
		print(std::cerr, fmt, args...);
		assert(0);
		//exit(-1);
	}
	
	
}
