void countingSort (int* a, int n, int place) {
   const int max = 10;
   int output[n];
   int count[max]; // auxilary O(n) space
 
   for (int i = 0; i < max; ++i)
      count[i] = 0;
 
   for (int i = 0; i < n; i++)
      count[(a[i] / place) % 10]++;
 
   for (int i = 1; i < max; i++)
      count[i] += count[i - 1];
   
   // right to left for stable sorting
   // if two elements have same digits at current place value then they should maintain order as they appear originally before sorting them according to this digit place value only.
   for (int i = n - 1; i >= 0; i--) {
      output[count[(a[i] / place) % 10] - 1] = a[i];
      count[(a[i] / place) % 10]--;
   }
 
   for (int i = 0; i < n; i++)
      a[i] = output[i];
}

//  Do digit by digit sort starting from least significant digit to most significant digit.
void radix_sort (int* a, int n) {
   int mx = -1;
   for (int i = 0; i < n; i++) {
      mx = max(mx, a[i]);
   }
   for (int place = 1; mx / place > 0; place *= 10)
      countingSort(a, n, place);
}

// There are more sorts, just knowing a little about them would give you the idea.

// Bucket sort - divides the unsorted array elements into several groups called buckets. Each bucket is then sorted by using any of the suitable sorting algorithms or recursively applying the same bucket algorithm.

// Heap Sort - Given an array of data, first, we build a heap and then turn it into a sorted list by calling deleteMin. The running time of the algorithm is O(n log n).
