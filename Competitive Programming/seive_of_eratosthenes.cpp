const int N = 1e6;
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
