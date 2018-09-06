#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[11111];
vector<int> inf[11111];
pair<int,int> arr2[333];
vector<int> kk;
int vis[11111][2],n;
vector<int> gogo(int dd){
	for(int e=0;e<11111;e++) for(int q=0;q<2;q++) vis[e][q]=987654321;
	queue<pair<int,int> > q;
	for(int e=0;e<kk.size();e++){
		q.push(make_pair(kk[e],0));
		vis[kk[e]][0]=0;
	}
	while(!q.empty()){
		int now =q.front().first,num=q.front().second;
		q.pop();
		for(int e=0;e<inf[now].size();e++){
			int next=inf[now][e];
			if(vis[next][(num+1)%2]>num+1){
				vis[next][(num+1)%2]=num+1;
				q.push(make_pair(next,num+1));
			}
		}
	}
	vector<int> rr;
	for(int e=1;e<=n;e++){
		if(vis[e][dd%2]<=dd) rr.push_back(e);
	}
	return rr;
}
int main() {
	// your code goes here
	int m,q,k;
	scanf("%d%d%d%d",&n,&m,&q,&k);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=0;e<m;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		inf[a].push_back(b);
		inf[b].push_back(a);
	}
	for(int e=0;e<q;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		arr2[e]=make_pair(a,b);
	}
	sort(arr2,arr2+q);
	kk.push_back(1);
	int left = 0;
	for(int e=0;e<q;e++){
		kk = gogo(arr2[e].first-left);
		vector<int> rr;
		for(int ee=0;ee<kk.size();ee++) if(kk[ee]!=arr2[e].second) rr.push_back(kk[ee]);
		kk = rr;
		left = arr2[e].first;
	}
	kk = gogo(k-left);
	int mm = -1,qq=0;
	for(int e=0;e<kk.size();e++){
		if(arr[kk[e]]>mm){
			mm=arr[kk[e]];
			qq=1;
		}else if(arr[kk[e]]==mm){
			qq++;
		}
	}
	if(mm==-1){
		cout << mm;
	}else{
		cout << mm << " " <<qq << endl;
	}
	return 0;
}