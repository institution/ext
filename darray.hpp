#pragma once

#include <vector>
#include "aga2.hpp"


namespace darray {


	template <class T, class U>
	struct darray2 {
		std::vector<T> p;
		v2<U> dim;

		darray2() = default;
		darray2(v2<U> dim) { resize(dim); }

		void resize(v2<U> dim) {
			p.resize(dim[0] * dim[1]);
			this->dim = dim;
		}
		
		v2<U> get_dim() const { return dim; }
		
		size_t size() const { return p.size(); }
		T & operator[](size_t i) { return p[i]; }
		
		T const& at(size_t i) const { return p.at(i); }
		T & at(size_t i) { return p.at(i); }
		
		
		T const& operator()(v2<U> pos) const { 
			assert(0 <= pos[0]);
			assert(0 <= pos[1]);			
			assert(pos[0] < dim[0]);
			assert(pos[1] < dim[1]);
			return p.at(pos[0] + pos[1] * dim[0]); 
		}
			
		T & operator()(v2<U> pos) { 
			assert(0 <= pos[0]);
			assert(0 <= pos[1]);
			assert(pos[0] < dim[0]);
			assert(pos[1] < dim[1]);
			return p.at(pos[0] + pos[1] * dim[0]); 
		}
	};



}
