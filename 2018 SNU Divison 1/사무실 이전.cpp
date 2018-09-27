#include <stdio.h>
#include <vector>
#define sz 333333
using namespace std;
typedef long long int lld;
const lld mod = 998244353;
lld tot=0;
lld arr[sz],num[sz],dp2[sz],dist[sz],n,m,k,seg[4*sz],lazy[4*sz],ch[sz],nnum[sz],fch[sz];
vector<int> kk[sz],dp;
int recur(int now,int left,int tots){
	num[now]++;
	dist[now] = tots;
	for(int e=0;e<kk[now].size();e++){
		int next=kk[now][e];
		if(next!=left){
			num[now]+=recur(next,now,tots+1);
		}
	}
	dp.push_back(now);
	return num[now];
}
void propa(int node,int start,int end){
	seg[node]=(seg[node]+lazy[node]*(nnum[end]-nnum[start-1]))%mod;
	if(start!=end){
		lazy[node*2]=(lazy[node*2]+lazy[node])%mod;
		lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%mod;
	}
	lazy[node]=0;
}
lld get(int node,int left,int right,int start,int end){
	if(lazy[node]!=0) propa(node,start,end);
	if(left>end||right<start) return 0;
	if(left<=start&&end<=right) return seg[node];
	return (get(node*2,left,right,start,(start+end)/2)+get(node*2+1,left,right,((start+end)/2)+1,end))%mod;
}
void update(int node,lld val,int left,int right,int start,int end){
	if(lazy[node]!=0) propa(node,start,end);
	if(left>end||right<start) return;
	if(left<=start&&end<=right){
		seg[node]=(seg[node]+val*(nnum[end]-nnum[start-1]))%mod;
		if(start!=end){
			lazy[node*2]=(lazy[node*2]+val)%mod;
			lazy[node*2+1]=(lazy[node*2+1]+val)%mod;
		}
		return;
	}
	update(node*2,val,left,right,start,(start+end)/2);
	update(node*2+1,val,left,right,((start+end)/2)+1,end);
	seg[node]=(seg[node*2]+seg[node*2+1])%mod;
}
void recur2(int now,int left,lld val){
	lld tval = val,ll=0,rr=0;
	if(now!=1){
		ll =dp2[now]-num[now]+1,rr=dp2[now];
		lld ov = get(1,1,n,1,n);
		lld ff = get(1,ll,rr,1,n);
		lld ss = ov-ff;
		tval = (tval-2*ff+2*ss)%mod;
        if(tval<0) tval+=mod;
		tval=(tval+k)%mod;
		update(1,1,1,n,1,n);
		update(1,-2,ll,rr,1,n);
	}
	for(int e=0;e<kk[now].size();e++){
		int next=kk[now][e];
		if(next!=left){
			recur2(next,now,tval);
		}
	}
	if(fch[now]){
		tot=(tot+tval)%mod;
	}
	if(now!=1){
		update(1,2,ll,rr,1,n);
		update(1,-1,1,n,1,n);
	}
}
int main() {
	// your code goes here
	scanf("%d",&n);
	for(int e=0;e<n-1;e++){
		int a,b;
		scanf("%d%d",&a,&b);
		kk[a].push_back(b);
		kk[b].push_back(a);
	}
	scanf("%d",&m);
	for(int e=0;e<m;e++){
		int a;
		scanf("%d",&a);
		fch[a]=1;
	}
	scanf("%d",&k);
	for(int e=0;e<k;e++){
		int a;
		scanf("%d",&a);
		ch[a]=1;
	}
	dp.push_back(-1);
	recur(1,-1,0);
	for(int e=1;e<=n;e++) if(ch[e]) tot=(tot+(dist[e]*dist[e]))%mod;
	lld rr= tot;
	for(int e=1;e<=n;e++){
		dp2[dp[e]]=e;
	}
	for(int e=1;e<=n;e++){
		nnum[e]=nnum[e-1];
		if(ch[dp[e]]) nnum[e]++;
	}
	for(int e=1;e<=n;e++) update(1,dist[dp[e]],e,e,1,n);
	recur2(1,-1,tot);
    lld now = tot-rr;
    if(now<0) now+=mod;
	printf("%lld",now);
	return 0;
}