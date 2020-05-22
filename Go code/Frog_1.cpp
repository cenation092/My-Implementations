#include"bits/stdc++.h"
using namespace std;

#define endl "\n"
#define int long long

int ar[1000000];
int dp[1000000];

int f( int i, int n ){
    if( i == n )return 0;
    if( dp[i] != -1 )return dp[i];
    int cost = abs(ar[i] - ar[i+1]) + f(i+1, n);
    if( i+2 <= n ){
        cost = min(cost, abs(ar[i]-ar[i+2]) + f(i+2, n));
    }
    return dp[i] = cost;
}

int32_t main(){
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> ar[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, n);
} 
