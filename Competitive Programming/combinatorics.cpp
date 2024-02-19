using ll = long long;
const int N = 2e6 + 1, mod = 1e9 + 7;
int fact[N], invFact[N];

int binpow (int x, int n) {
   x %= mod;  
   int res = 1;
   while (n) {
      if (n % 2)  
         res = ((ll)res * x) % mod;
      x = ((ll)x * x) % mod;
      n /= 2;  
   }
   return res;
}

int inv (int x) {
   return binpow(x, mod - 2, mod);
}

void precompute () {
   fact[0] = invFact[0] = 1;
   for (int i = 1; i < (int)N; i++) {
      fact[i] = (int)((i * (ll)fact[i - 1]) % mod);
      invFact[i] = inv(fact[i], mod - 2, mod);
   }
}

int choose (int x, int y) {
   if(x < y) return 0;
   return (int)((((fact[x] * (ll)invFact[y]) % mod) * invFact[x - y]) % mod);
}


// for smaller n or for cases where modulo is not invertible, we can compute nCr directly 
vector<vector<int>> choose(n + 1, vector<int>(n + 1);  
for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i) choose[i][j] = 1;
        else choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
}
