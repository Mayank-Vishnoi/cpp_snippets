const int N = 1e6;
vector<int> lp, pr;

void sieve() {
   lp.assign(N + 1, 0);
   for (int i = 2; i <= N; i++) {
      if (!lp[i]) {
         lp[i] = i;
         pr.push_back(i);
      }
      for (int j = 0; i * pr[j] <= N; j++) {
         lp[i * pr[j]] = pr[j];
         if (pr[j] == lp[i]) {
            break;
         }
      }
   }
}

vector<int> factorisation (int n) {
   vector<int> f;
   while (n > 1) {
      f.push_back(lp[n]);
      n /= lp[n];
   }
   return f;
}
