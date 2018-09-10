#include <iostream>
#include <string>
#include <queue>
using namespace std;
queue<int> q;
int error=0;
int main() {
	// your code goes here
	string a;
	cin >> a;
	for(int e=0;e<a.size();e++){
		if(a[e]=='A'){
			if(q.size()==0){
				error++;
				break;
			}
			int now =q.front();
			q.pop();
			if(q.size()==0){
				error++;
				break;
			}
			int now2=q.front();
			q.pop();
			if(a[now]!='P'||a[now2]!='P'){
				error++;
			}else{
				if(e==a.size()-1||a[e+1]!='P'){
					error++;
				}else{
					q.push(now);
					e++;
				}
			}
		}else{
			q.push(e);
		}
	}
	if(q.size()==1&&error==0){
		int now =q.front();
		if(a[now]=='P'){
			cout << "PPAP";
			return 0;
		}
	}
	cout << "NP";
	return 0;
}