#include <bits/stdc++.h>
using namespace std;

long long computeProfit(vector<long long> profit, int positiveSize)
{
    
    long long extraProfit = 0;
    for(int i = 0; i < positiveSize; i++) {
        extraProfit += profit[i];
    }
    return extraProfit;
}

int computePositiveSize(vector<long long>profit)
{
    int sz = profit.size();
    for(int i = 0; i < sz; i++) {
        if(profit[i] < 0) return i;
    }
    return sz;
}

long long computeAnsForCornerCase(long long actualSum, vector<long long>profit)
{
    int sz = profit.size();
    long long extraProfit = 0;
    for(int i = 0; i < sz; i++) extraProfit += profit[i];
    return max(actualSum, actualSum + extraProfit);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n;
        long long x, actualSum = 0;
        vector<long long>v(n);
        
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            actualSum += v[i];
        }
        cin >> k >> x;
        
        vector<long long>profit(n);
        for(int i = 0; i < n; i++) {
            long long elementWithXor = v[i] ^ x;
            profit[i] = elementWithXor - v[i];
        }
        sort(profit.rbegin(), profit.rend());
        
        if(k == n) {
            cout << computeAnsForCornerCase(actualSum, profit) << endl;
            continue;
        }
        
        int positiveSize = computePositiveSize(profit);
        
        if(positiveSize % 2 == 0 || (k & 1)) {
            cout << max(actualSum, actualSum + computeProfit(profit, positiveSize)) << endl;
        } 
        else {
            long long extraProfit = 0;
            for(int i = 0; i < positiveSize - 1; i++) extraProfit += profit[i];
            
            //by now there will be one positive element left
            long long takeOneLeft = 0;
            if(positiveSize < n && positiveSize - 1 >= 0) {
                takeOneLeft += (profit[positiveSize] + profit[positiveSize - 1]); 
            }
            cout << max(actualSum + extraProfit, actualSum + extraProfit + takeOneLeft) << endl;
        }
    }
    return 0;
}
