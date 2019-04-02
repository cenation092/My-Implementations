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

vector<int> pre( string &s ){
	int n = s.size();
	vector<int> pi(n);
	for( int i = 1; i < n; i++ ){
		int j = pi[i-1];
		while( j > 0 && s[i] != s[j] ) j = pi[j-1];
		if( s[i] == s[j] )j++;// if current match
		pi[i] = j;
	}
	return pi;
}

vector<int> KMP(string &l, string &s ){
	int j = 0;
	vector<int> idx;
	int n = l.size();
	int m = s.size();
	vector<int> pi = pre(s);
	for( int i = 0; i < n; i++ ){
		while( j > 0 && l[i] != s[j] ){
			j = pi[j-1];
		}
		if( l[i] == s[j] )j++;
		if( j == m )idx.push_back(i-m+1);
	}
	return idx;
}

int main(){
	string large, small;
	cin >> large >> small;
	vector<int> idx = KMP(large, small);
	for( auto it : idx ){
		cout << it << " ";
	}
}