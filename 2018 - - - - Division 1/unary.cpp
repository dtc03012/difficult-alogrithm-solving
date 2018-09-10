#include <iostream>
using namespace std;
typedef long long int lld;
const lld mod = 998244353;
lld pw(lld a,lld b){
	if(b==0) return 1;
	if(b==1) return a;
	lld now = pw(a,b/2);
	if(b%2) return (((now*now)%mod)*a)%mod;
	return (now*now)%mod;
}
int main(void){
	int a,b,c=0,d=0;
	cin >> a >> b;
	for(int e=0;e<a;e++){
		if(e%2==0) c--;
		else d++;
	}
	if(b<c||b>d){
		cout << "0";
		return 0;
	}
	lld kk =1,pp=b-c,rr=1;
	for(int e=2;e<=a;e++) kk=(kk*e)%mod;
	for(int e=1;e<=a-pp;e++) rr=(rr*e)%mod;
	for(int e=1;e<=pp;e++) rr=(rr*e)%mod;
	cout << (kk*pw(rr,mod-2))%mod;
}