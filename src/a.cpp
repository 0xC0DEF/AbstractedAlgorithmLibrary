#include "core/base.h"
#define endl '\n'//Remove it when interactive
#define CHECK_INPUT 0
#define TC 1
#define TC_OUT_PREFIX ""//"Case #",ti,": "
signed main(){
	void solve();
	for(int ti=1,t=TC;ti<=t;ti++)
		print(TC_OUT_PREFIX),
		solve();
#if CHECK_INPUT
	assert(cin.get()=='\n');
	assert(cin.get()==EOF);
#endif
}
void solve(){
	println("hello",1,'2').flush();
}
