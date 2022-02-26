/*

	Type 0 - sum from l to r (both inclusive)
	Type 1 - update arr[idx] by adding value x to it
	Type 2 - update arr[idx] by making it x
	
*/
#include<iostream>

using namespace std;

void update(int *bit, int i, int val, int n){

		for( ; i <= n ; i += (i&(-i)) ){

			bit[i] += val;

		}
	}

	int sum(int *bit, int i){
		
		int ans = 0;

		for( ; i > 0 ; i -= (i&(-i)) ){
			ans += bit[i];
		}

		return ans;
	}
	int query(int *bit, int l, int r){

		return (sum(bit,r) - sum(bit,l-1));

	}
int main(){
	int n;
	cin>>n;

	int *arr = new int[n+1];
	int *bit = new int[n+1];

	for(int i=0;i<=n;i++){
		bit[i] = 0;
	}

	for(int i=1;i<=n;i++){
		cin>>arr[i];

		//updating/building fenwick tree
		update(bit,i,arr[i],n);
	}

	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int type, a, b;
		cin>>type>>a>>b;

		if(!type){
			cout<<query(bit,a,b)<<endl;
		}
		else{
			int val = (type==1) ? b : (b-arr[a]);
			update(bit,a,val,n);
		}
	}
	return 0;
}
