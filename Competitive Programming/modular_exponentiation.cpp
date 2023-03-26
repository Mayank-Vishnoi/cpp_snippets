using ll = long long;
const int mod = 1e9 + 7;

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
