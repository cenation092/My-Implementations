#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;
#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;
#define hitAi ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define watch(a) cerr <<#a<<": "<<a<<endl; 
#define __gcd(a, b) __algo_gcd(a, b)
#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<array>
#include<cstdio>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<cstring>
#include <climits>
#include <fstream>
#include<iostream>
#include<algorithm>
#include <functional>
#define mp make_pair
using namespace std;

int main(){
    string my = "hello";
    string s;
    cin >> s;
    int j = 0;
    for( auto i : s ){
        if( i == my[j] )j++;
    }
    if( j >= my.size() )cout << "YES";
    else cout << "NO";
}