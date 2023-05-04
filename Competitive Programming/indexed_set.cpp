#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

Tree<int> t;
cout << t.order_of_key(x) << endl;
cout << *t.find_by_order(y) << endl;

// Read more on https://codeforces.com/blog/entry/11080

// Other applications: supporting elements less than x in a set
struct left_right_array {
   Tree<int> free;
   explicit left_right_array (int n) { for (int i = 0; i < n; i++) free.insert(i); }
   void set (int k) { free.erase(k); }
   void unset (int k) { free.insert(k); }
   int free_left (int i) { return (int)free.order_of_key(i + 1); }
   int free_right (int i) { return (int)free.size() - free_left(i); }
};
