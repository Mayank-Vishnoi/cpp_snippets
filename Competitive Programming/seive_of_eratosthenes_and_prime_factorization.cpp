const int N = 1e6;

int spf[N]; // smallest prime factor for each number
void sieve() {
   spf[1] = 1;
   for (int i = 2; i < N; i++)
      spf[i] = i;
   for (int i = 2; i * i < N; i++)
     if (spf[i] == i) 
         for (int j = i * i; j < N; j += i)
            if (spf[j] == j)
               spf[j] = i;
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

bool isPrime(int x) {
   return spf[x] != x;
}

// if you just want a list of primes 
bitset<N + 1> p;
vector<int> pr;
void sieve () {
   p.flip();
   p[0] = p[1] = 0;
   for (int i = 2; i * i <= N; i++) 
      if (p[i]) 
         for (int j = i * i; j <= N; j += i) 
            p[j] = 0;
   for (int i = 1; i <= N; i++) 
      if (p[i]) 
         pr.push_back(i);
}
