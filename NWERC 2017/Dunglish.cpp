#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long int lld;
map<string,lld> cor,incor;
map<string,string> cors,incors;
string arr[22];
lld bitdp[1025*1025];
lld n,ttot;
void recur(int bit,lld tt){
	if(bitdp[bit]!=-1) return;
	bitdp[bit]=tt;
	for(int e=0;e<n;e++){
		if((bit&(1<<e))==0&&incor[arr[e]]>0){
			lld now =tt;
			if(now==-1){
				now=incor[arr[e]];
			}else{
				now=now*incor[arr[e]];
			}
			recur(bit|(1<<e),now);
		}
	}
}
int main() {
	// your code goes here
	cin >> n;
	for(int e=0;e<n;e++) cin >> arr[e];
	int q;
	cin >> q;
	for(int e=0;e<q;e++){
		string a,b,c;
		cin >> a >> b >> c;
		if(c=="correct"){
			cor[a]++;
			cors[a]=b;
		}else if(c=="incorrect"){
			incor[a]++;
			incors[a]=b;
		}
	}
	for(int e=0;e<1025*1025;e++) bitdp[e]=-1;
	lld tot=-1;
	for(int e=0;e<n;e++){
		if(tot==-1){
			tot=cor[arr[e]];
		}else{
			tot=tot*cor[arr[e]];
		}
	}
	if(tot==1){
		for(int e=0;e<n;e++){
			cout << cors[arr[e]] << " ";
		}
		cout << "\ncorrect";
		return 0;
	}
	recur(0,-1);
	int wh=-1;
	for(int e=1;e<1025*1025;e++){
		lld kk=bitdp[e];
		if(kk==-1) continue;
		wh=e;
		for(int p=0;p<n;p++){
			if((e&(1<<p))==0) kk*=cor[arr[p]];
		}
		ttot+=kk;
	}
	if(ttot==1){
		for(int e=0;e<n;e++){
			if((wh&(1<<e))==0) cout << cors[arr[e]] <<" ";
			else cout << incors[arr[e]] << " ";
		}
		cout << "\nincorrect";
		return 0;
	}
	cout << tot << " correct\n";
	cout << ttot << " incorrect";
	return 0;
} 
