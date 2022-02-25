/*
     Given an integer h, find the possible number of balanced binary trees of height h. Return the count.
     Number can be huge, so return output modulus 10^9 + 7.
     
*/
#include<iostream>
using namespace std;
#define mod 1000000007

//Recursive Approach
int treecount_rec(int n){
	if(n<=1)
		return 1;

	int a = treecount_rec(n-1);
	int b = treecount_rec(n-2);

	int x = (int)(((long)a*a)%mod);
	int y = (int)((2*((long)a)*b)%mod);

	return (x+y)%mod;
}

//Memoization - Top Down Approach
int helper(int n, int *ans){
	if(n<=1)
		return 1;

	if(ans[n]!=-1)
		return ans[n];

	int a = helper(n-1,ans);
	int b = helper(n-2,ans);

	int x = (int)(((long)a*a)%mod);
	int y = (int)((2*((long)a)*b)%mod);

	ans[n] = (x+y)%mod;
	return ans[n];
}
int treecount_mem(int n){
	int *ans = new int[n+1];

	for(int i=0;i<=n;i++){
		ans[i] = -1;
	}

	return helper(n,ans);
}

//Dynamic Programming - Bottom Up approach
int treecount_dp(int n){
	int *ans = new int[n+1];

	ans[0] = 1;
	ans[1] = 1;

	for(int i=2;i<=n;i++){
		int a = ans[i-1];
		int b = ans[i-2];

		int x = (int)(((long)a*a)%mod);
		int y = (int)((2*((long)a)*b)%mod);

		ans[i] = (x+y)%mod;
	}

	return ans[n];
}
int main(){
	int n;
	cin>>n;

	cout<<treecount_rec(n)<<endl;
	cout<<treecount_mem(n)<<endl;
	cout<<treecount_dp(n)<<endl;
	return 0;
}
