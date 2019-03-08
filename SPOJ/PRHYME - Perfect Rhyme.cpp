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

string ans = "";

struct node{
    int min1, min2;
    int fre;
    node *ar[26];
    node(){
        fre = 0;
        min1 = -1;
        min2 = -1;
        for( int i = 0; i < 26; i++ ){
            ar[i] = NULL;
        }
    }
};

void add(node *root, string s, int idx, int id ){
    if( idx == s.size() )return;
    int cur = s[idx] - 'a';
    if( root->ar[cur] == NULL ){
        root->ar[cur] = new node();
    }
    if( root->ar[cur]->min1 == -1 ){
        root->ar[cur]->min1 = id;
    }
    else if( root->ar[cur]->min2 == -1 ){
        root->ar[cur]->min2 = id;
    }
    root->ar[cur]->fre++;
    add(root->ar[cur], s, idx+1, id);
}

int find(node *root, string s, int idx, int id){
    if( id == -1 ){
        int cur = s[idx] - 'a';
        if( root->ar[cur] != NULL && idx < s.size()){
            return find( root->ar[cur], s, idx+1, id);
        }
        else{
            return root->min1;
        }
    }
    else{
        int cur = s[idx] - 'a';
        if( idx < s.size() ){
            if( root->ar[cur]->fre == 1 ){
                if( root->min1 == id )return root->min2;
                else return root->min1;
            }
            else{
                return find(root->ar[cur], s, idx+1, id);
            }
        }
        else{
            if( root->min1 == id )return root->min2;
            else return root->min1;
        }
    }
}

int main(){
    hitAi;
    node *root = new node();
    string s;
    int num = 1;
    set<string> ar;
    map<int, string> de;
    map<string, int> en;
    while(getline(cin, s) ){
        if(s.empty())break;
        ar.insert(s);
        en[s] = num;
        de[num] = s;
        num++;
    }
    for( auto it : ar ){
        num = en[it];
        reverse(it.begin(), it.end());
        add(root, it, 0, num);
    }
    while(getline(cin, s) ){
        if(s.empty())break;
        if( en.count(s) == 0 )num = -1;
        else num = en[s];
        reverse(s.begin(), s.end());
        ans = "";
        //watch(num);
        num = find(root, s, 0, num);
        cout << de[num] << "\n";
    }
}