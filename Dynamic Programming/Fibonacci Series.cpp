// Fibonacci Series - 0 1 1 2 3 5 8 13 21 34 55 89 -----
#include<iostream>
using namespace std;

//Recursive Approach
int fib_rec(int n){
	//base case
	if(n<=1)
	   return n;

	//recursive case
	return fib_rec(n-1)+fib_rec(n-2);

}

//Memoization - Top Down Approach
int fib_helper(int n, int *ans){

	if(n<=1){
		return n;
	}
	if(ans[n]!=-1){
		return ans[n];
	}

	ans[n] = fib_helper(n-1,ans) + fib_helper(n-2,ans);
	return ans[n];
}
int fib_mem(int n){

	int *ans = new int[n+1];
	for(int i=0;i<=n;i++)
		ans[i] = -1;

	return fib_helper(n,ans);
}


//Dynamic Programming
int fib_dp(int n){
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;

	for(int i=2;i<=n;i++){
		ans[i] = ans[i-1] + ans[i-2];
	}

	return ans[n];
}
int main(){
	int n;
	cin>>n;
	cout<<fib_rec(n)<<endl;
	cout<<fib_mem(n)<<endl;
	cout<<fib_dp(n)<<endl;
	return 0;
}
