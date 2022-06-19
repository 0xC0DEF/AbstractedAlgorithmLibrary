#pragma once
#include "core/base.h"

//usecase: BOJ5896
template<class T, class CMP, class ...Rest> struct Ordering{
	static const int cmpcnt=1+sizeof...(Rest);
	multiset<T,CMP> a;
	Ordering<T,Rest...> b;
	Ordering(CMP cmp, Rest... rest):a(cmp),b(rest...){}
	int size()const{return a.size();}
	void add(const T& x){a.insert(x);b.add(x);}
	void del(const T& x){a.erase(a.find(x));b.del(x);}
	T front(int idx, int cur=0){return cur==idx?*head(a):b.front(idx,cur+1);}
	T back(int idx, int cur=0){return cur==idx?*tail(a):b.back(idx,cur+1);}
	optional<T> lb(int idx, const T& x, int cur=0){
		if(cur!=idx)
			return b.lb(idx,x,cur+1);
		auto it=a.lb(x);
		return it==a.end()?optional<T>():*it;
	}
	optional<T> ub(int idx, const T& x, int cur=0){
		if(cur!=idx)
			return b.ub(idx,x,cur+1);
		auto it=a.ub(x);
		return it==a.end()?optional<T>():*it;
	}
	auto cmptor(int idx,int cur=0){
		return cur==idx
			?function<T(const T&,const T&)>(a.key_comp())
			:b.cmptor(idx,cur+1);
	}
};
template<class T, class CMP> struct Ordering<T,CMP>{
	static const int cmpcnt=1;
	multiset<T,CMP> a;
	Ordering(CMP cmp):a(cmp){}
	int size()const{return a.size();}
	void add(const T& x){a.insert(x);}
	void del(const T& x){a.erase(a.find(x));}
	T front(int idx, int cur=0){return *head(a);}
	T back(int idx, int cur=0){return *tail(a);}
	optional<T> lb(int idx, const T& x, int cur=0){
		auto it=a.lb(x);
		return it==a.end()?optional<T>():*it;
	}
	optional<T> ub(int idx, const T& x, int cur=0){
		auto it=a.ub(x);
		return it==a.end()?optional<T>():*it;
	}
	auto cmptor(int idx,int cur=0){return a.key_comp();}
};