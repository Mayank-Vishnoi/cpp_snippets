// returns first index of match in the pattern P in the test string T
int kmp(const string &T, const string &P) {
  if (P.empty()) return 0;

  vector<int> pi(P.size(), 0);
  for (int i = 1, k = 0; i < P.size(); ++i) {
    while (k && P[k] != P[i]) k = pi[k - 1];
    if (P[k] == P[i]) ++k;
    pi[i] = k;
  }

  for (int i = 0, k = 0; i < T.size(); ++i) {
    while (k && P[k] != T[i]) k = pi[k - 1];
    if (P[k] == T[i]) ++k;
    if (k == P.size()) return i - k + 1;
  }

  return -1;
}