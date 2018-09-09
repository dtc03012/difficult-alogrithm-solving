#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lld;
vector<lld> arr,r,dd;
lld tot=0,tot2=-1;
void recur(int d){
	if(d==0){
		vector<lld> kr = r;
		sort(kr.begin(),kr.end());
		lld rrr=0;
		for(int e=0;e<3;e++){
			if(e==0) rrr+=7*kr[e];
			rrr+=kr[e]*kr[e];
		}
		if(rrr>tot2){
			tot2=rrr;
			dd=kr;
		}
		return;
	}
	for(int e=0;e<3;e++){
		r[e]+=1;
		recur(d-1);
		r[e]-=1;
	}	
}
int main() {
	// your code goes here
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		tot=0;
		tot2=-1;
		arr.clear();
		r.clear();
		dd.clear();
		lld a,b,c,d;
		cin >> a >> b >> c >> d;
		arr.push_back(a);
		arr.push_back(b);
		arr.push_back(c);
		r=arr;
		sort(arr.begin(),arr.end());
		arr[2]+=d;
		for(int p=0;p<3;p++){
			if(p==0) tot+=arr[p]*7;
			tot+=(arr[p]*arr[p]);
		}
		int dr= d;
		dr=min(dr,5);
		recur(dr);
		lld rr2=0;
		dd[2]+=(d-dr);
		for(int p=0;p<3;p++){
			if(p==0) rr2+=dd[p]*7;
			rr2+=(dd[p]*dd[p]);
		}
		tot=max(tot,rr2);
		cout << tot << endl;
	}
	return 0;
}