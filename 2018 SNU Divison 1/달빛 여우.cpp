#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long int lld;
const lld inf = 1e18;
int n,m;
vector<pair<int,int> > arr[4444];
lld vis[2][4444][2];
void tmr(int type){
    for(int e=0;e<4444;e++) for(int q=0;q<2;q++) vis[type][e][q]=inf;
	vis[type][1][0]=0;
	priority_queue<pair<lld,pair<int,int> > > q;
	q.push(make_pair(0,make_pair(1,0)));
	while(!q.empty()){
		lld now = q.top().second.first,tt=q.top().second.second,dist = -q.top().first;
		q.pop();
		if(vis[type][now][tt%2]<dist) continue;
		for(int e=0;e<arr[now].size();e++){
			int next=arr[now][e].first;
			lld ndist = arr[now][e].second;
			lld ddist = dist;
			if(type==0){
				if(tt%2==0) ddist+=(ndist/2);
				else ddist+=(ndist*2);
			}else{
				ddist +=ndist;
			}
			if(vis[type][next][(tt+1)%2]>ddist){
				vis[type][next][(tt+1)%2]=ddist;
                int kk = tt;
                if(type==0) kk++;
				q.push(make_pair(-ddist,make_pair(next,kk)));
			}
		}
	}
}
int main() {
	// your code goes here
	scanf("%d%d",&n,&m);
	for(int e=0;e<m;e++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		arr[a].push_back(make_pair(b,c*2));
		arr[b].push_back(make_pair(a,c*2));
	}
	tmr(0);
	tmr(1);
	int tot=0;
	for(int e=1;e<=n;e++) {
		if(min(vis[0][e][0],vis[0][e][1])>min(vis[1][e][0],vis[1][e][1])) tot++;
	}
	printf("%d",tot);
	return 0;
}