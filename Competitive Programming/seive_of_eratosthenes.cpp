const int N = 1e6;
bitset<N + 1> p; // whether or not i is prime
vector<int> pr; // list of primes

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

// smallest prime factor for each number
int spf[N];
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
