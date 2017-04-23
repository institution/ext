#pragma once 


#include "format.hpp"
#include "geo2.hpp"
#include "geo3.hpp"
#include "aga2.hpp"
#include "filesys.hpp"
#include "random.hpp"
#include "darray.hpp"
#include "fail.hpp"
#include "bitop.hpp"

namespace ext {
	using namespace geo2;
	
	
	using darray::darray1;
	using darray::darray2;
	using darray::darrayN;
	
	template <class T>
	using v2 = aga2::Mv1<T>;
	
	
	
}

