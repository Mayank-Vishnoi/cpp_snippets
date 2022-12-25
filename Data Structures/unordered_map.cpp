// M is preferably a prime, ~N/5 for seperate chaining,  ~2*N for linear probing.
const int M = 97;

// Polynomial hash
int hashcode (string x) {
   ll h = 0;
   string temp = x;
   for (auto i : temp) { 
      h = i + (31 * h);
      h %= M; 
   }
   return h;
}

// Hash Function
int hashcode (ll value) {
   int digit, i = 1;
   ll sum = 0;
   while(value > 0) {
      digit = value % 10;
      sum += digit * i;
      sum %= M;
      value /= 10;
      i++;
   }
   return sum;
}

// Linear Probing
// Key is an object of type T, and value of type V.
template<typename T, typename V>
struct OpenAdresssingHashMap {
   // can maintain keys and values as pair too.
   vector<T> keys;
   vector<V> values;

   // You can't assign and compare objects with NULL in c++, use additional memory for this.
   vector<bool> assigned;

   // constructor
   public: 
      OpenAdresssingHashMap () {
         keys.resize(M);
         values.resize(M);
         assigned.assign(M, false);
      }

   // return the value corresponding to the given key
   V get (T key) { 
      for (int i = hashcode(key); assigned[i] != false; i = (i + 1) % M) {
         if (keys[i] == key) {
            return values[i];
         }
      }
      return NULL;
   }

   // insert a {key, value} pair if not already there, else update value
   void insert (T key, V value) {
      int i = hashcode(key);
      for (; assigned[i] != false; i = (i + 1) % M) {
         if (keys[i] == key) {
            values[i] = value;
            return;
         }
      }
      keys[i] = key;
      values[i] = value;
      assigned[i] = true;
   }

   // erase a entry by searching from key
   void erase (T key) { 
      for (int i = hashcode(key); assigned[i] != false; i = (i + 1) % M) {
         if (keys[i] == key) {
            assigned[i] = false;
            return;
         }
      }
   }
};


// Separate Chaining
template<typename T, typename V>
struct SeparateChainHashBT {
   // chain definition
   struct node { 
      T key;
      V value;
      node* next;
      node(T k, V v) {
         key = k;
         value = v;
         next = NULL;
      }
   };

   // array of chains
   vector<node*> st; 

   // constructor
   public: 
      SeparateChainHashBT () {
         st.resize((int)M); 
      }

   // return the value corresponding to the given key
   V get (T key) { 
      int i = hashcode(key);
      for (node* x = st[i]; x != nullptr; x = x->next) {
         if (key == x->key) {
            return x->value;
         }
      }
      return NULL;
   }

   // insert a {key, value} pair
   void insert (T key, V value) {
      int index = hashcode(key);
      node* x = st[index];
      node* head = st[index];
      if (x == NULL) {
         x = new node(key, value);
         st[index] = x;
         return;
      }
      while (x->next != nullptr) {
         if (x->key == key) {
            x->value = value;
            return;
         }
         x = x->next;
      }
      x->next = new node(key, value);
   }

   // erase a entry by searching from key
   void erase (T key) { 
      int index = hashcode(key);
      node* x = st[index];
      if (x->key == key) {
         st[index] = x->next;
         return;
      }
      node* prev = x;
      x = x->next;
      while  (x != nullptr) {
         if (x->key == key) {
            prev->next = x->next;
            free(x);
            return;
         }
         prev = x;
         x = x->next;
      }
   }
};
