#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int a[N];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand (int l, int r) {
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

int arrange (int *a, int l, int r) {
   swap(a[rand(l, r)], a[r]); // random pivot
   int sp = -1;
   for (int i = l; i < r; i++) {
      if (sp == -1 && a[i] >= a[r]) {
         sp = i;
      }
      // make space for all smaller elements than our pivot, a[r] and swap at last
      if (a[i] < a[r] && sp != -1) {
         swap(a[sp], a[i]);
         sp++;
      }
   }
   if (sp != -1) {
      swap(a[r], a[sp]);
      return sp;
   } else {
      return r;
   }
}

void quick_sort (int *a, int l, int r) {
   if (l < r) {
      int p = arrange(a, l, r);
      quick_sort(a, l, p - 1);
      quick_sort(a, p + 1, r);
   }
}

int main() {
   int n;
   cin >> n;
   for (int i = 0; i < n; i++) cin >> a[i];
   quick_sort(a, 0, n - 1);
   for (int i = 0; i < n; i++) cout << a[i] << " ";
   return 0;
}
