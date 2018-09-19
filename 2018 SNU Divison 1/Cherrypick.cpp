#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int arr[1001][1001],dp[1001][1001][32],dp2[1001][1001][32];
int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) for(int p=0;p<n;p++) scanf("%d",&arr[e][p]);
	for(int e=0;e<n;e++){
		for(int q=1;q<32;q++){
			for(int p=0;p<n;p++){
				if(q==1){
					dp[e][p][q]=arr[e][p];
					dp2[e][p][q]=arr[p][e];
				}
				else{
					int rr = q/2,xx=q-(q/2);
					dp[e][p][q]=max(dp[e][p][rr],dp[e][p+rr][xx]);
					dp2[e][p][q]=max(dp2[e][p][rr],dp2[e][p+rr][xx]);
				}
			}
		}
	}
	for(int e=0;e<n;e++){
		for(int p=0;p<n;p++){
			int rr=-1;
			for(int q=1;q<32;q++){
				int lx=max(0,p-q+1),rx=min(n-1,p+q-1),ly=max(0,e-q+1),ry=min(n-1,e+q-1);
				int t1=(rx-lx+1)/2,t2=(rx-lx+1-t1),f1=(ry-ly+1)/2,f2=(ry-ly+1-f1);
				rr=max(rr,max(dp[ly][lx][t1],dp[ly][lx+t1][t2])-q*q);
				rr=max(rr,max(dp[ry][lx][t1],dp[ry][lx+t1][t2])-q*q);
				rr=max(rr,max(dp2[lx][ly][f1],dp2[lx][ly+f1][f2])-q*q);
				rr=max(rr,max(dp2[rx][ly][f1],dp2[rx][ly+f1][f2])-q*q);
			}
			printf("%d ",rr);
		}
		printf("\n");
	}
	return 0;
}