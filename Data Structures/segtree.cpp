struct item {
   // define the element for segtree
};

struct segtree {
   int size;
   item neutral;
   vector<item> values;

   void init (int n) {
      // set identity element
      size = 1;
      while (size < n) size *= 2;
      values.assign(2 * size, neutral); 
   }

   item merge (item a, item b) {
      // define associative operation
   } 

   item single (int v) {
      // return item for a single element
   }

   void build (vector<int> &a, int x, int lx, int rx) {
      if (rx - lx == 1) {
         if (lx < (int)a.size()) {
            values[x] = single(a[lx]); 
            return;
         }
      }
      int m = (lx + rx) / 2;
      build(a, 2 * x + 1, lx, m);
      build(a, 2 * x + 2, m, rx);
      values[x] = values[2 * x + 1] + values[2 * x + 2];
   }

   // builds the segtree in O(n)
   void build (vector<int> &a) {
      build(a, 0, 0, size);
   }

   void set (int i, int v, int x, int lx, int rx) {
      if (rx - lx == 1) {
         values[x] = single(v);
         return;
      }
      int m = (lx + rx) / 2;
      if (i < m) {
         set(i, v, 2 * x + 1, lx, m);
      } else {
         set(i, v, 2 * x + 2, m, rx);
      }
      values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
   }

   // set a[i] = v; 
   void set (int i, int v) {
      set(i, v, 0, 0, size); 
   }

   item calc (int l, int r, int x, int lx, int rx) {
      if (lx >= r || l >= rx) {
         return neutral;
      }   
      if (lx >= l && rx <= r) {
         return values[x];
      }
      int m = (lx + rx) / 2;
      item _1 = calc(l, r, 2 * x + 1, lx, m);
      item _2 = calc(l, r, 2 * x + 2, m, rx); 
      return merge(_1, _2);
   }

   // return value for segment [l, r)
   item calc (int l, int r) {
      return calc(l, r, 0, 0, size);
   }
}; 
