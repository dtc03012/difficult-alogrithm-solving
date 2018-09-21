#include <iostream>
using namespace std;
typedef long long int lld;
int kk[11][12118],vis[11][12118],a,b,st,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ch[6]={1,0,0,1,0};
lld tot =0,rtot=0;
bool tmr(int y,int x,int tt){
	if(x>=0&&x<b&&y>=0&&y<tt) return true;
	return false;
}
void recur(int y,int x,int ee,int nn){
	if(nn==5){
		tot++;
		return;
	}
	for(int e=0;e<4;e++){
		int nexty=y+dy[e];
		int nextx=x+dx[e];
		if(tmr(nexty,nextx,ee)&&vis[nexty][nextx]==0){
			for(int q=0;q<5;q++){
				if(nn==q){
					if(kk[nexty][nextx]==ch[q]){
						vis[nexty][nextx]=1;
						recur(nexty,nextx,ee,nn+1);
						vis[nexty][nextx]=0;		
					}
				}
			}
		}
	}
}
int main() {
	// your code goes here
	cin >> a >> b;
	for(int e=0;e<10;e++){
		for(int p=0;p<b;p++){
			if(st==0) kk[e][p]=1;
			if(st>=1&&st<=2) kk[e][p]=0;
			if(st==3) kk[e][p]=1;
			if(st==4) kk[e][p]=0;
			st++;
			if(st>=5) st=0;
		}
	}
	lld lleft = 0;
	if(a>=10){
		for(int e=0;e<10;e++){
			for(int p=0;p<b;p++){
				if(kk[e][p]==1){
					recur(e,p,10,1);
				}
			}
		}
		lld kkr = tot;
		tot = 0 ;
		for(int e=0;e<5;e++){
			for(int p=0;p<b;p++){
				if(kk[e][p]==1){
					recur(e,p,5,1);
				}
			}
		}
		lld krk = tot;
		while(a>=10){
			rtot+=(kkr-krk);
			a-=5;
		}
	}
	tot=0;
	for(int e=0;e<a;e++){
		for(int p=0;p<b;p++){
			if(kk[e][p]==1){
				vis[e][p]=1;
				recur(e,p,a,1);
				vis[e][p]=0;
			}
		}
	}
	rtot+=tot;
	cout << rtot << endl;
	return 0;
}