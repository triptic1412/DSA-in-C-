#include<iostream>

using namespace std;

void update(int *arr, int *BIT, int i, int val, int n){

	for( ; i <= n ; i += (i & (-i)) ){

		BIT[i] += val;

	}
}

int query(int *BIT, int i){

	int sum = 0;

	for( ; i > 0 ; i -= (i & (-i)) ){

		sum += BIT[i];

	}

	return sum;
}
int main(){

	int n;
	cin>>n;

	int *arr = new int[n+1];
	int *BIT = new int[n+1];

	for( int i = 1 ; i <= n ; i++ ){
		arr[i] = 0;
		BIT[i] = 0;
	}

	for( int i = 1 ; i <= n ; i++ ){
		cin>>arr[i];
		update(arr,BIT,i,arr[i],n);
	}

	int queries;
	cin>>queries;

	for( int i = 1 ; i <= queries ; i++ ){

		int type;
		cin>>type;

		if(type==0){

			int idx,val;
			cin>>idx>>val;
			update(arr,BIT,idx,val,n);
      
		}
		else{
      
			int l,r;
			cin>>l>>r;
			cout<<( query(BIT,r) - query(BIT,l-1) )<<endl;
      
		}
		
	}

	return 0;
}
