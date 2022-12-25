// Remember you can replace sum with any associative operation and single elements with any struct!
template<class T> struct segtree {
   int size;
   vector<T> sums;

   void init (int n) {
      size = 1;
      while (size < n) size *= 2;
      sums.assign(2 * size, (T)0); // complete binary tree with each layer representing non-intersecting distribution of segments
   }

   // node = x, borders of the segment = [lx, rx - 1]
   void set (int i, int v, int x, int lx, int rx) {
      if (rx - lx == 1) {
         // leaf node
         sums[x] = v;
         return;
      }
      int m = lx + (rx - lx) / 2;
      if (i < m) {
         // left subtree
         set(i, v, 2 * x + 1, lx, m);
      } else {
         // right subtree
         set(i, v, 2 * x + 2, m, rx);
      }
      // recalculate the sum for this node
      sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
   }

   void set (int i, int v) {
      // starting from the root
      set(i, v, 0, 0, size); 
   }

   T sum (int l, int r, int x, int lx, int rx) {
      if (lx >= r || l >= rx) {
         // segment does not intersect with the query
         return 0;
      }   
      if (lx >= l && rx <= r) {
         // whole segment contributes
         return sums[x];
      }
      int m = lx + (rx - lx) / 2;
      T s1 = sum(l, r, 2 * x + 1, lx, m); // calculate from left subtree
      T s2 = sum(l, r, 2 * x + 2, m, rx); // calculate from right subtree
      return s1 + s2;
   }

   T sum (int l, int r) {
      return sum(l, r, 0, 0, size);
   }
}; 
