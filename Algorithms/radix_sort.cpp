void countingSort (int* a, int n, int place) {
   const int max = 10;
   int output[n];
   int count[max];
 
   for (int i = 0; i < max; ++i)
      count[i] = 0;
 
   for (int i = 0; i < n; i++)
      count[(a[i] / place) % 10]++;
 
   for (int i = 1; i < max; i++)
      count[i] += count[i - 1];
 
   for (int i = n - 1; i >= 0; i--) {
      output[count[(a[i] / place) % 10] - 1] = a[i];
      count[(a[i] / place) % 10]--;
   }
 
   for (int i = 0; i < n; i++)
      a[i] = output[i];
}

void radix_sort (int* a, int n) {
   int mx = -1;
   for (int i = 0; i < n; i++) {
      mx = max(mx, a[i]);
   }
   for (int place = 1; mx / place > 0; place *= 10)
      countingSort(a, n, place);
}
