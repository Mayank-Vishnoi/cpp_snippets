// you can use bitset<> to save memory
const int N = 1e6;
vector<bool> is_prime; 
vector<int> primes;

void sieve () {
  is_prime.assign(N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
     if (is_prime[i]) {
        for (int p = i * i; p <= N; p += i) {
           is_prime[p] = false;
        }
     }
  }
  for (int i = 1; i <= N; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}
