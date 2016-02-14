#pragma once 


#include "format.hpp"
#include "geo2.hpp"
#include "geo3.hpp"
#include "aga2.hpp"
#include "filesys.hpp"
#include "random.hpp"
#include "darray2.hpp"
#include "fail.hpp"

namespace ext {
	using namespace geo2;
	
	
	
	using darray2::darray2;
	
	template <class T>
	using v2 = aga2::Mv1<T>;
	
	
}
