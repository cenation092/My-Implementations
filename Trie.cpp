#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define watch3(a,b,c) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<endl;
#define watch2(a,b) cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<< endl;
#define hitAi ios::sync_with_stdio(0); in.tie(0); out.tie(0);
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

// single node of a trie
struct node{
    int fre;
    node *ar[26];
    node(){
        fre = 1;
        for( int i = 0; i < 26; i++ ){
            ar[i] = NULL;
        }
    }
};

// complexity O(s.size())
// to add a string in a trie
void add(node *root, string s, int idx ){
    if( idx == s.size() )return;
    if( root->ar[s[idx]-'a'] != NULL ){
        root->ar[s[idx]-'a']->fre++;
    }
    else{
        root->ar[s[idx]-'a'] = new node();
    }
    add(root->ar[s[idx]-'a'], s, idx+1);
}

// complexity O(s.size())
// to count a number of prefix s exits 
int count(node *root, string s, int idx ){
    if( idx == s.size() )return root->fre;
    if( root->ar[s[idx]-'a'] != NULL ){
        return count(root->ar[s[idx]-'a'], s, idx+1);
    }
    return 0;
}

int main(){
	int n;
    cin >> n;
    node *root = new node();
    while( n-- ){
        string q, s;
        cin >> q >> s;
        if( q == "add" ){
            add(root, s, 0);
        }
        else{
            cout << count(root, s, 0) << "\n";
        }
    }
}