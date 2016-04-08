#pragma once

#include "aga2.hpp"

namespace geo2 {

	template <class U>
	using v2 = aga2::Mv1<U>;


	template <class T>
	T limit(T val, T min, T max) {
		if (val < min) return min;
		if (val > max) return max;
		return val;
	}


	template <class T>
	bool in_bound(T val, T pos, T end) {
		return pos <= val and val < end;
	}


	template <class U>
	bool in_bounds(v2<U> val, v2<U> pos, v2<U> end) {
		return
			in_bound(val[0], pos[0], end[0])
			and
			in_bound(val[1], pos[1], end[1]);
	}

	template <class T>
	struct b2 {

		v2<T> pos, dim;

		b2() = default;

		b2(v2<T> pos, v2<T> dim):
			pos(pos), dim(dim)
		{}

		b2(T x, T y, T w, T h):
			pos(x,y), dim(w,h)
		{}

		b2(b2 const& box):
			pos(box.pos), dim(box.dim)
		{}

		v2<T> end() const {
			return pos + dim;
		}

	};


	template <class T>
	v2<T> vmul(v2<T> a, v2<T> b) {
		return v2<T>(a[0]*b[0], a[1]*b[1]);
	}

	template <class T>
	v2<T> vdiv(v2<T> a, v2<T> b) {
		return v2<T>(a[0]/b[0], a[1]/b[1]);
	}
	
	template <class T>
	v2<T> calc_align(b2<T> par, v2<T> dim, v2<float> align = v2<float>(0.5, 0.5)) {
		return v2<T>(v2<float>(par.pos) + vmul(v2<float>(par.dim - dim), align));
	}
	
	

}
