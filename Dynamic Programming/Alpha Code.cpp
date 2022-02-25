#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int Count(string s){
    int n = s.length();
    int dp[n+1];
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
        if(s[n-i]=='0')
        {
            dp[i] = 0;
            continue;
        }
        dp[i] = dp[i-1]%mod;
        
        int num = (s[n-i]-'0')*10 + (s[n-i+1]-'0');
        
        if(num>= 10 and num<=26){
            
            dp[i] = (dp[i] + dp[i-2]%mod)%mod;
        }
    }
    
    return dp[n];
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    cin.get();
    while(t--){
        string s;
        cin>>s;
        cout<<Count(s)<<endl;
    }
    return 0;
}
