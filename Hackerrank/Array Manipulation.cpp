#include <bits/stdc++.h>
using namespace std;

long long ar[10000001];

int main()
{
    int n,m;
    cin >> n >> m;
    long long sum=0,max=0;
    memset(ar,0,sizeof(ar));
    while(m--){
    	int a , b;
        long long k;
    	cin >> a >> b >> k;
    	ar[a]+=k;
        if(b+1<=n)ar[b+1]-=k;
    }
    for(int i=1;i<=n;i++){
    	ar[i] += ar[i-1];
        if(max<ar[i]) max=ar[i];
	}
	cout << max;
    return 0;
}