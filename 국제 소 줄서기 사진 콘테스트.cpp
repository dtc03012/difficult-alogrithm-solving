#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
const int mod =1e5+1;
set<int> dp[2*111111];
int arr[111111],arr2[111111],seg[4*2*111111],start=1;
int main() {
	// your code goes here
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<=n;e++){
		if(arr[e]==0) arr2[e]=arr2[e-1]-1;
		else arr2[e]=arr2[e-1]+1;
	}
	for(int e=0;e<=n;e++) dp[arr2[e]+mod].insert(e);
	while(222222>start) start*=2;
	for(int e=0;e<=n;e++){
		set<int>::iterator it = dp[arr2[e]+mod].begin();
		int now=*it;
		it = dp[arr2[e]+mod].end();
		int now2=*(--it);
		seg[start+arr2[e]+mod]=now2-now;
	}
	for(int e=start-1;e>=1;e--) seg[e]=max(seg[e*2],seg[e*2+1]);
	printf("%d\n",seg[1]);
	for(int ee=0;ee<m;ee++){
		int k;
		scanf("%d",&k);
		if(arr[k]==arr[k+1]){
			printf("%d\n",seg[1]);
		}else{
			int ff=arr2[k],now,now2,ss=arr2[k];
			if(arr[k]==0&&arr[k+1]==1){
				ss+=2;
				arr2[k]+=2;
			}else if(arr[k]==1&&arr[k+1]==0){
				ss-=2;
				arr2[k]-=2;
			}
			dp[ff+mod].erase(k);
			dp[ss+mod].insert(k);
			set<int>::iterator it;
			if(dp[ff+mod].size()==0) seg[start+ff+mod]=0;
			else{
				it=dp[ff+mod].begin();
				now=*it;
				it=dp[ff+mod].end();
				now2=*(--it);
				seg[start+ff+mod]=now2-now;
			}
			for(int e=(start+ff+mod)/2;e>=1;e/=2) seg[e]=max(seg[e*2],seg[e*2+1]);
			if(dp[ss+mod].size()==0) seg[start+ss+mod]=0;
			else{
				it=dp[ss+mod].begin();
				now=*(it);
				it=dp[ss+mod].end();
				now2=*(--it);
				seg[start+ss+mod]=now2-now;
			}
			for(int e=(start+ss+mod)/2;e>=1;e/=2) seg[e]=max(seg[e*2],seg[e*2+1]);
			printf("%d\n",seg[1]);
		}
		swap(arr[k],arr[k+1]);
	}
	return 0;
}