// Priority queue (max heap) implementation by flattening a binary tree. 
struct binary_heap {
   int* arr;
   int pos;
   int cur_size;
   public:
      binary_heap() {
         arr = new int[(int)1e5];
         pos = 1;
         cur_size = 0;
         arr[0] = INT_MAX;
      }
   void add (int x) {
      // add a node to the binary heap in O(logN)
      arr[pos] = x;
      pos++;
      int t = pos - 1;
      while (arr[t] >= arr[t/2]) {
         swap(arr[t], arr[t/2]);
         t /= 2;
      }
      cur_size++;
   }  
   int peek () {
      // Finding the max item is O(1).
      if (cur_size == 0) {
         exit(1);
      }
      return arr[1];
   } 
   void remove () {
      // Removing the maximum item from the heap in O(logN).
      pos--;
      swap(arr[1], arr[pos]);
      arr[pos] = -1;
      int t = 1;
      while (arr[t] <= max(arr[2*t], arr[2*t + 1])) {
         if (arr[2*t] > arr[2*t + 1]) {
            swap (arr[t], arr[2*t]);
            t *= 2;
         } else {
            swap(arr[t], arr[2*t+1]);
            t *= 2;
            t++;
         }
      }
      cur_size--;
   }
   bool empty () {
      return (!cur_size);
   }
   int size () {
      return cur_size;
   }
};
