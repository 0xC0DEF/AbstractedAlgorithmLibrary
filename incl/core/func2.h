//functions after include <arr.h>
#pragma once
#include "core/arr.h"

template<class T>int argmin(const Arr<T>& a){return min_element(a.begin(),a.end())-a.begin();}
template<class T>int argmax(const Arr<T>& a){return max_element(a.begin(),a.end())-a.begin();}
template<class T,class U=Arr<int>>map<T,U> classify(const Arr<T>& a){
	map<T,U> r;
	for(int i=0;i<sz(a);i++)
		r[a[i]].push_back(i);
	return r;
}
#if CPP20

template<class T=int,class... Ts> requires (!Iterable<T>) tuple<T,Ts...> input(){
	T x; cin>>x;
	if constexpr (sizeof...(Ts)==0) return mkt(x);
	else return tuple_cat(mkt(x),input<Ts...>());
}
template<class T=int,int n>std::array<T,n> input(){
	std::array<T,n> a;
	for(auto&i:a)
		i=get<0>(input<T>());
	return a;
}
string input(string& str){ cin>>str; return str; }
template<class T> requires (!Iterable<T>) T& input(T& a){ cin>>a; return a;}
template<class T> requires Iterable<T> T& input(T& a){ for(auto&i:a)input(i); return a; }
#else
	#define input() [](){int x;cin>>x;return mkt(x);}()
	// #define input(n) [](){Arr<int> a(n);for(auto&i:a)cin>>i;return a;}()
#endif
