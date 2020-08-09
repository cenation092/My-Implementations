// nCr in O(n)


int fac[1000001];

int power( int a, int b ){
    int ans = 1;
    while( b > 0 ){
        if( b&1 )ans = ( ans * a ) % mod;
        a = ( a * a ) % mod;
        b /= 2;
    }
    return ans;
}

int nCr(int n, int r){
    int N = fac[n];
    int R = fac[r];
    int N_R = fac[n-r];
    R *= N_R;
    R %= mod;
    int inv = power(R, mod-2);
    return (inv * N) % mod;
}

void faC(){
    fac[0] = 1;
    for( int i = 1; i <= 10; i++ ){
        fac[i] = fac[i-1] * i;
        fac[i] %= mod;
    }
}
