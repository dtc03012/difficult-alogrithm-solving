#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int lld;
lld arr[2*2*111111],seg[4*4*111111],start=1,st=0,dp[2*2*111111][30];
lld kk[20];
lld gcd(lld a,lld b){
	return b==0?a:gcd(b,a%b);
}
lld getsnum(int ll,int rr){
	int l = ll+start,r=rr+start;
	lld gg = -1;
	while(l<=r){
		if(l%2){
			if(gg==-1){
				if(seg[l]!=0) gg=seg[l];
			}else{
				if(seg[l]!=0) gg=gcd(gg,seg[l]);
			}
			l++;
		}
		if(r%2==0){
			if(gg==-1){
				if(seg[r]!=0) gg=seg[r];
			}else{
				if(seg[r]!=0) gg=gcd(gg,seg[r]);
			}
			r--;
		}
		l/=2;
		r/=2;
	}
	return gg;
}
int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	kk[0]=1;
	for(int e=1;e<20;e++) kk[e]=kk[e-1]*2;
	for(int e=0;e<n;e++) scanf("%lld",&arr[e]);
	for(int e=n;e<n*2;e++) arr[e]=arr[e-n];
	while(2*n>start) start*=2;
	for(int e=start;e<start+2*n;e++) seg[e]=arr[e-start];
	for(int e=start-1;e>=1;e--){
		if(seg[e*2+1]==0) seg[e]=seg[e*2];
		else seg[e]=gcd(seg[e*2],seg[e*2+1]);
	}
    if(getsnum(0,n-1)>1){
        for(int e=0;e<n;e++) printf("0\n");
        return 0;
    }
	for(int e=0;e<2*n-1;e++) for(int p=0;p<20;p++) dp[e][p] =-1;
	for(int e=0;e<2*n-1;e++) {
		int l =e-n+1,r=e,mid,rr=-1;
		if(l<0) l=0;
		if(e>0&&dp[e-1][1]!=-1) l=dp[e-1][1];
		while(l<=r){
			mid=(l+r)/2;
			if(getsnum(mid,e)==1){
				rr=max(rr,mid);
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if(rr>e-n) dp[e][1]=rr;
	}
	for(int e=1;e<2*n-1;e++){
		for(int p=2;p<20;p++){
			int now = dp[e][p-1];
			if(now>0){
				if(dp[now-1][p-1]>e-n){
					dp[e][p]=dp[now-1][p-1];
				}
			}
		}
	}
	for(int e=n-1;e<2*n-1;e++){
		int tot =0,wh=e;
		for(int p=19;p>=1;p--){
			if(wh<0) continue;
			if(dp[wh][p]>e-n){
				tot+=kk[p-1];
				wh=dp[wh][p]-1;
			}
		}
		printf("%d\n",tot);
	}
}