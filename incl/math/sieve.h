#pragma once
#include "core.h"

Arr<char> sieve_primes(int n) {
	n++;
	Arr<char> s(n,1);s[0]=s[1]=0;
	for(i64 i=2;i*i<n;i++)
		if(s[i])
			for(i64 j=i*i;j<n;j+=i)
				s[j]=0;
	return s;
}
Arr<int> primes(int n) {
	n++;
	auto s=sieve_primes(n);
	Arr<int> r;
	for(int i=0;i<n;i++)
		if(s[i]) r.emplace_back(i);
	return r;
}
//NOTE: Arr<Arr<int>>가 병목이라면 https://www.acmicpc.net/source/30452059 이거처럼 최적화 가능
Arr<Arr<int>> sieve_divs(int n) {
	n++;
	Arr<Arr<int>> r(n);
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j+=i)
			r[j].emplace_back(i);
	return r;
}
//NOTE: minfac[p]=p
Arr<int> sieve_minfac(int n) {
	n++;
	Arr<int> s(n);
	for(i64 i=2;i<n;i++)
		if(!s[i])
			for(i64 j=i;j<n;j+=i)
				if(!s[j])
					s[j]=i;
	return s;
}
Arr<int> sieve_eutot(int n) { return {};}
