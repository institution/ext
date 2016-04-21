#pragma once

#include <vector>
#include "aga2.hpp"


namespace darray2 {

	template <class U>
	using v2 = aga2::Mv1<U>;


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
		
		v2<U> get_pos(T const& t) const 
		{
			auto delta = &t - &p[0];
			
			assert(delta < size());
			
			U y = delta / dim[0];
			U x = delta % dim[0];			
			return {x,y};
		}
		
		auto begin() { return p.begin(); }
		auto end() { return p.end(); }
		auto begin() const { return p.begin(); }
		auto end() const { return p.end(); }
		
		
		
		size_t size() const { return p.size(); }
		
		T const& operator[](size_t i) const { return p[i]; }
		T & operator[](size_t i) { return p[i]; }
		
		T const& at(size_t i) const { return p.at(i); }
		T & at(size_t i) { return p.at(i); }
		
		
		void for_each(std::function<void(T &)> block) {
			for (size_t i = 0; i < size(); i++)
			{
				block(p[i]);
			}			
		}
		
		void for_each(std::function<void(T const&)> block) const {
			for (size_t i = 0; i < size(); i++)
			{
				block(p[i]);
			}
		}
		
		
		void fill(T const& f) {
			for_each([&f](T & t){
				t = f;
			});
		}
		
		void resize(v2<U> dim, T const& f) {
			resize(dim);			
			fill(f);
		}
		
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
