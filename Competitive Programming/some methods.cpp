// size_t is like unsigned long int but usually not interchangable as the return type of some inbuilt functions.
size_t pos = str.find("live");
string str3 = str.substr(pos);


#include <regex>
s = regex_replace(s, regex("WUB"), " ");  // replaces WUB with " ".

regex pattern("tuna");
cout << std::regex_replace(str, pattern, "");


cout << bitset<32>((int)n) << "\n";
bitset<M> bset(string("1100")); //initialise, M is a const
dbg(bset);
// space-efficient method of storing array of bool values
// use bitwise operations and set, reset, count, size, flip functions
// set[1] starts from right end 0 index;)


array<int, 25> arr; // same as int arr[25];
array<vector<int>, 5>>  //static arrays of dynamic arrays 
vector<array<int, 5>>   //dynamic arrays of static arrays
array<int, 2> a[mxN];  
set<array<int, 2>> s; 

auto it = s.lower_bound({t+1, 0}); // with pair
s.erase(it);


// taking input as a string
getline(cin, s); // stores nothing as "\n" is also a valid string
getline(cin, s);

cin.ignore();
// must be there when using getline(cin, s) for speed up

while (getline(cin, s)) {
   // go inside with each newline
   // end on flushing or ctrl + c
}


inline std::string trim(std::string & str) {
   // return size_t to first pos of not occurence and erase deletes 2 characters next from it.
   str.erase(0, str.find_first_not_of(' ')); //prefixing spaces
   str.erase(str.find_last_not_of(' ') + 1); //surfixing spaces
   return str;
}


// Using template types 
template<typename T>
void pop_front(std::vector<T>& vec) {
   assert(!vec.empty());
   vec.erase(vec.begin());
}


count(a.begin(), a.end(), a[k - 1]);
//int count(Iterator first, Iterator last, T &val), Returns count of occurrences of value in range [begin, end]

bool ok[N];
cout << count(ok + 1, ok + n, true) << "\n";


reverse(a + L, a + R + 1);


#define rall(a) a.rbegin(), a.rend()


map<T1, T2> mp;
cout << mp.lower_bound((T1)t) -> first; //search for key


// for setting max precision
cout<<setprecision(numeric_limits<float>::digits10 + 1) << d;


vector<int> vec = {1, 2, 3, 4, 5, 12, 15, 17, 20};
if (binary_search(all(vec), key)) {
   // true if an element occurs in a sorted sequence
}

binary_search(all(v), p); // vector<pair<int, int>> v, pair<int, int> p; for O(logN) lookup without maintaining sets.


set<int> S(all(a));
//Create a set from a vector directly :)


// end up with sorted list with duplicates removed., can also use for strings!
sort(all(vec));
vec.resize(unique(all(vec)) - vec.begin());
//std::unique(begin, end) goes from begin to end, removes consecutive duplicates and returns the end of the resulting iterator range.
// Works even for vector<vector<int>> ;)


// lambda functions!
// M1 - use them inline to save code lines
auto get_subset_sums = [&](int l, int r) -> vector<ll> {
	int len = r - l + 1;
	vector<ll> res;
	for (int i = 0; i < (1 << len); i++) {
		ll sum = 0;
		for (int j = 0; j < len; j++) {
			if (i & (1 << j)) {
				sum += a[l + j];
			}
		}
		res.push_back(sum);
	}
	return res;
};

// M-2, explicit declaration to avoid useless parameters but slighly more overhead (recursion depth)! (and hence runtime)
function<bool(int, int)> dfs = [&](int u, int c) {
   if (color[u] != -1)
      return color[u] == c;
   color[u] = c;
   for (auto [v, w] : adj[u])
      if (!dfs(v, c ^ w))
         return false;
   return true;
};


//When you work with STL containers like vector, you can use move function to just move container, not to copy it all!
vector<int> w = move(v);


std::string to_string(int value); // Converts a numeric value to std::string.
int stoi( const std::string& str, std::size_t* pos = 0, int base = 10); // Interprets a signed integer value in the string str.


(p + q - 1) / q == ⌈p/q⌉
// LHS same as ceiling division, even better in fact, p != 0

// Use floor when divident is int and divisor is float and you need a integer answer
floor(a[i] / x);


.compare() // lexicographical
// str1.compare(str2);
// A return value of 0 indicates that the two strings compare as equal.
// A positive value means that the compared string is longer, or the first non-matching character is greater.
// A negative value means that the compared string is shorter, or the first non-matching character is lower.


// Implementing binary search as linear search with larger steps
bool search(int x[], int n, int k) {
   int p = 0;
   for (int a = n; a >= 1; a /= 2) {
      while (p + a < n && x[p + a] <= k) p += a;
   }
   return x[p] == k;
}


template <typename T>
struct Point {
   T x, y;
   Point(T _x, T _y) : x(_x), y(_y) {}
   // then just simply declare as Point p1 (x1, y1); \ Point p2(x2, y2); and so on ..
   // constructor
   Node(T1 x, T2 y)
   {
      this->x = x;
      this->y = y;
   }
   Point& operator+(const Point& rhs){ // operator overloading
      x += rhs.x;
      y += rhs.y;
      return *this;
   }
   friend ostream& operator<<(ostream& os, const Point& p) {
      return os << "(" << p.x << ", " << p.y << ")";
   }
};


// Use struct instead of class. Rationale: It defaults to public, and you don't need encapsulation in competitive programming!
struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
};
int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}
int intersection = max(min(b, d) - max(a, c), 0);
// geometry basics,  without many cases approach


// Use emplace and emplace_back for containers when dealing with pairs and tuples. Rationale:
(elem1, elem2, ...) // instead of 
({elem1, elem2, ...}).


// fastest way to convert a binary string to base 10 value.
unsigned long long val = bitset<64>(s).to_ullong();


std::fill_n(arr, 25, 0) or std::fill(arr, arr + 25, 0).
fill(limit + s, limit + a + s, b); 
fill_n(dp[0], N * N, INF);


// this erases the first three elements; O(n)
v.erase(v.begin(), v.begin() + 3); 


tuple<type1, type2, ..., typeN> t;  
make_tuple(a, b, c, ..., d);
get<i>(t); //Returns the i'th element of the tuple t. Can also be used to change the element of a tuple. 'i' must be constant value here.
tuple<int,int,int> t{3, 4, 5};
int i = 1; cout << get<i>(t);
tie(a, b, c, ..., d) = t //: Assigns a, b, c, ..., d to the elements of the tuple t accordingly or the vice versa.
string s1, s2; int x;
tie(s1, s2, x) = tp2;
int a = 3, b = 4, c = 5;
tuple<int, int, int> t = tie(a, b, c);
tuple<string, string, int> tp2 = make_tuple("Hello", "world", 100);


// Just a quick tip: if input is given as +3, -7, ... you could just cin >> (int), as it will ignore character.


std::set<int>::iterator it = s.begin();
std::advance(it, s.size() / 2);
// to get the median/middle element of a set
advance (it, step);

vector<int> vals(8);
iota(all(vals), 0); 
//set vals to 0 1 ... 7


s.erase(0); // [2, 4]
// if the element to be removed does not exist, nothing happens


// whenever you mentioned m[k] it will all a ordered pair {k, 0} into the current set of {key, value}.
// erase(key) removes the map entry associated with the specified key.


//  you are free to change the values in a map when iterating over it 
void iterate_insert() {
   map<int,int> m; m[0] = 0; //starts with a single key
   for (auto& p: m) { //adds keys in the loop until the key 10
   	if (p.xx == 10) break;
   	p.yy = 5;
   	m[p.xx + 1] = 0;
   }
}    // [(0, 5), (1, 5) ... (9, 5), (10, 0)]


// incrementing "it" after element at it has been erased from the map might not produce the intended result.
// it might not give a error(segmentation fault) so be careful for WA when you do this.
// to do the intended, that is, to remove every third entry from a map; use this ->
void iterate_remove_ok() {
	map<int,int> m; for (int i = 0; i < 10; ++i) m[i] = i;
	int cnt = 0;
	for (auto it = begin(m), next_it = it; it != end(m); it = next_it) {
		++next_it;
		cout << "CURRENT KEY: " << it -> first << "\n";
		++cnt;
		if (cnt % 3 == 0) {
			m.erase(it);
		}
	}
}   


// member function 
void swap (map &x);
// Exchanges the content of the container by the content of x
m.swap(M); // is same as
M.swap(m); // and
swap(m, M);


// Just a tip, In each move, we can increase all n-1 elements by one. We should never choose to increase our max 
// element, so we choose to increase other elements except our current max element. Instead of that, we can choose to decrease max element by one,
// so the difference between elements is still the same.


return accumulate(a.begin(), a.end(), 0) - *min_element(a.begin(), a.end()) * a.size();
// Note: accumulate calculates the sum


// Using custom comparator for priority queue
struct comp {
   bool operator() (pii const& p1, pii const& p2) {
      if (p1.xx > p2.xx) {
         return true;
      } else if (p1.xx == p2.yy) {
         return (p1.yy < p2.yy);
      } else {
         return false;
      }
   }
};
priority_queue<pii, vector<pii>, comp> pq;


// `operator==` is required to compare keys in case of a hash collision
bool operator==(const Node &p) const {
   return x == p.x && y == p.y;
}


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// add these lines at the top of your code to optimise the O(n^2) solution to work under limits, does help in some cases :)


random_shuffle(v.begin(), v.end());
random_shuffle(a, a + n); // returns nothing, reorders elements.


/*
The function lower_bound(x) returns an iterator to the smallest element in the
set whose value is at least x, and the function upper_bound(x) returns an iterator
to the smallest element in the set whose value is larger than x. In both functions,
if such an element does not exist, the return value is end. These functions are
not supported by the unordered_set structure which does not maintain the order
of the elements.
*/


/* One limitation of ordered sets is that we can't efficiently access the kth largest element in the set,
or find the number of elements in the set greater than some arbitrary x.
In C++, these operations can be handled using a data structure called an order statistic tree, trie, fenwick trees */


// Priority queues are simpler and faster than sets, so you should use them instead whenever possible.


/* Like sets, Ordered map also allows:
lower_bound: returns the iterator pointing to the lowest entry not less than the specified key
upper_bound: returns the iterator pointing to the lowest entry strictly greater than the specified key respectively. */
map<int, int> m;
m[3] = 5; // [(3, 5)]
m[11] = 4; // [(3, 5); (11, 4)]
m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n'; // 10 491
cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n'; // 11 4
m.erase(11); // [(3, 5); (10, 491)]


multiset::count()
// the count() method returns the number of times an element is present in the multiset.
// However, this method takes time linear in the number of matches so you shouldn't use it in a contest.


prev(it, n);
/* Since, lists support bidirectional iterators, which can be incremented only by using ++ and – – operator.
So, if we want to advance the iterator by more than one position, then std::next and if we want to decrement the iterator, then std::prev can be extremely useful. */


// Use s.begin() to access lowest element of set and s.rbegin() to access its highest().


// Using set with custom comparators in C++

// Method 1) Overloading the less than operator (<) automatically generates the functor less<Edge>
// Similarly, overloading (>) automatically generates the functor greater<Edge>.
struct Edge {
	int a,b,w;
	bool operator>(const Edge& y) const { return w > y.w; }
   // usign const and &: The advantage is that it ensures that you are unable to modify the contents of a and b,
   // and they are passed as reference only, not the whole objects. (performace improvement)
};
set<Edge, greater<Edge>> v;

// These already exists for primitive types.
set<int, greater<int>> a;
map<int, string, greater<int>> b;
priority_queue<int, vector<int>, greater<int>> c;
sort(v.begin(), v.end(), greater<int>()); // can use anywhere where compartor is needed

// Overloading the less than operator:
// It works with objects only, for primitive types use a comparator function!
bool operator<(const Edge& x, const Edge& y) { return x.w < y.w;} // if overloaded outside the class

struct Edge {
	int a,b,w;
	friend bool operator<(const Edge& x, const Edge& y) { return x.w < y.w; }
};
vector<Edge> v;
sort(v.begin(), v.end());

bool cmp(int a, int b) {
   return occurrences[a] < occurrences[b];
}
sort(data.begin(), data.end(), cmp);

// Method 2) defining operator()() 
struct cmp {
   bool operator()(const Edge& x, const Edge& y) const { // const is must, as all comparator operators
      return x.w < y.w;
   }
};
set<Edge, cmp> s;
priority_queue<Edge, vector<Edge>, cmp> pq;


// Method 3) using decltype
bool cmp (const Edge& x, const Edge& y) {
   return x.w < y.w;
}
set<Edge, decltype(&cmp)> v(cmp);


// Method 4) With lambda expressions
auto cmp = [](const Edge& x, const Edge& y) { return x.w < y.w; };
set<Edge,bool(*)(const Edge&,const Edge&)> v(cmp);

// M5 - using std::function
struct Foo {};
bool Compare(Foo, Foo) { return true; }
std::priority_queue<Foo, std::vector<Foo>, std::function<bool(Foo, Foo)>> pq(Compare);


// If you want to preserve the relative order of equivalent elements, use stable_sort().
// The final order of equivalent elements will be the same as their initial order before being sorted.


// Where attack is std::vector<int> defined outside main method. will assume respective sizes 
vector<int> a = attack, b = defence, c = ciel;


v.insert(it, anothervector.begin(), anothervector.end());


auto it = lower_bound(all(v), x.front(), greater<int>());


//  C++17 feature known as structured binding declaration
tuple<int, double, string> a = {1, 2.0, "3"};
auto [x, y, z] = a; // x = 1, y = 2.0, z = "3"
auto& [rx, ry, rz] = a; // rx -> get<0>(a), ry -> get<1>(a), rz -> get<2>(a)


tuple q{1, 2.0, "3", 4LL}; //class template argument deduction. 


// equal_range returns both pointers that lower_bound and upper_bound returns.
auto r = equal_range(array, array + n, x);
cout << r.second - r.first << "\n";


priority_queue <int, vi, greater<int>> pq; // min-heap

sort(all(a), greater<pair<int, int>>());

t[i] = s[a[i].yy]; // assigning pairs

dp[i] = dp[i - 1]; //2d dp, assigning all dp[i - 1][summation(j)] previous states


// Comparing digits of two numbers a and b: Every digit problem without doing StringtoInt or reverse conversions.
static int aa[N], bb[N];
int n, m, i, j;
n = 0;
while (a > 0)
	aa[n++] = a % 10, a /= 10;
m = 0;
while (b > 0)
	bb[m++] = b % 10, b /= 10;   


// If both the sum of two arrays and multiplication of two arrays is same then they must be permutations of each other.


// When you need to create a min/max heap but want to remove elements not only from at the top,
// The best solution is to use std::set. Sets provide methods which allow it to be used both as a min/max heap (or a priority queue).
// Furthermore sets also allow random deletion.
std::set<int> pq;
//accessing the smallest element(use as min heap)
*pq.begin();
//accessing the largest element (use as max heap)
*pq.rbegin();


vector<int> ans(a.begin() + 0, a.begin() + k);
// Inititalizing a vector using another vector in STL


vector<tuple<int, int, int>> edges;
edges.push_back({1, 2, 5});
// and so on ... is the edge list representation of graph.


// Implementation handy
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};
for (int i = 0; i < 4; i++){
	frontier.push({r + R_CHANGE[i], c + C_CHANGE[i]});
}


// Initialising a 2d matrix
char grid[mxN][mxN];
bool visited[mxN][mxN];
vector<pii> v[mxN][mxN];
memset(grid, '.', sizeof(grid));
memset(visited, false, sizeof(visited));
memset(v, {}, sizeof(v));


pref_min[i] = min(pref_min[i - 1], a[i]); // prefix-min array
pref_max[i] = max(pref_max[i - 1], b[i]); // prefix-max array


// map is much faster than multiset especially when would use count a lot.
// And if you don't care about order use unordered_map like <ll, int> for even faster results.


map<string, vector<string>> d; // is okay~
vector<pair<string, vector<string>>> v; // so is this!


// Initializing
map<char, pair<int, int>> dir {
	{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'W', {0, -1}}
};


int color_count[26] = {0}; // memset_shorthand


// Used to simply check if a long double is an integer or not
double intpart;
modf(value, &intpart) == 0.0
// Or
abs(intpart) == floor(intpart)


/* Coordinate Compression*/
vector<int> d = a;
sort(d.begin(), d.end());
d.resize(unique(d.begin(), d.end()) - d.begin());
for (int i = 0; i < n; ++i) {
  a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
}
//original value of a[i] can be obtained through d[a[i]]

// In 2-dimensions
typedef pair<int,int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second; }
sort(P, P+N);
for (int i=0; i<N; i++) P[i].first = i+1;
sort(P, P+N, ycomp);
for (int i=0; i<N; i++) P[i].second = i+1;


/*Geometry*/
double PI = 2 * acos(0.0);
cout << fixed << setprecision(9) << (1 / tan(PI / (2 * n))) << "\n";


vector<int> p; // in global
p.assign(n, 0); // in main(); instead of resize which may only initialize with 0.
// Always use arr.clear() before arr.resize() learnt it the hard way.
set<int> p({0}); // initializing a vector/set



int round(float x); // return closest integral value to a float value.


/*
-> is the shortcut (type it) for snippets in VSCode
*/


/* just one weird idea
pass one loop with 0 and i for minima / maxima
pass another loop with that id and rest all for total minima ...
*/


/*Counting
Any element ith index in the array will occur (i + 1) * (N - i) times in all the possible subarrays of it.
*/


string t = s;  
string ch(1, s[mid]);   // middle character in this case
t.insert(mid, ch); 


// 2^30 > 1e9

// 256 MB = 1e7 integers stored, 1GB = 1e9 ints


/*masking string to int and reading function*/
// C++17(64)
auto read = [&](){   
	string t;
	cin >> t;
	int mask = 0;
	for(auto i = 0; i < n; ++i) {
		if (t[i] == '1'){
			mask |= 1 << i;
		}
	}
	return mask;
};
for(auto i = 0; i < m; ++i){
	++cnt[read()];
}

auto check = [&] (int x, int y) -> bool {
   if (x < n && x >= 0 && y < m && y >= 0 && A[x][y] != 1) {
      return true;
   }
   return false;
};


/* Calculate suffix-array containing maximum value for index i, i+1, i+2, ... n-1 in arr[i] */
maxSuffArr[n] = 0;
for (int i = n - 1; i >= 0; --i)
   maxSuffArr[i] = max(maxSuffArr[i + 1], arr[i]);


deque<int> d;
d.push_front(3); // [3]
d.push_front(4); // [4, 3]
d.push_back(7); // [4, 3, 7]
d.pop_front(); // [3, 7]
d.push_front(1); // [1, 3, 7]
d.pop_back(); // [1, 3]
// it supports{O}(1)  insertions and deletions from both the front and the back of the deque. 
// You can also access deques in constant time like an array in constant time with the [] operator.
// For example, to access the element i for some deque dq, do dq[i].


/*
Here ^ is power, Euler's totient function is number of coprimes with m for [0, 1. 2 ... m-1]

φ(n) = Prod(pi^(ai - 1) * (pi - 1)) from i = 1 to k, where k are the number of prime factors of n.
Again, refer https://cp-algorithms.com/algebra/phi-function.html

x^(φ(m)) mod m = 1 when x and m are coprime.

a^p ≡ a (mod p) always holds for a prime p.
a^(p-1) ≡ 1 (mod p) when a, p are coprime.
a ^ b ≡ a ^ (b mod (p − 1)) (mod p)

(a / b) mod m = (a * (b ^ -1)) mod m
(x ^ -1 = x ^ (φ(m) - 1), => x^(m - 2) when m is prime.
 
If m is not coprime with n, then m % n can't be 1.
if m % n == p then p must be coprime with n. And, ((m / p) % n == 1). 

If p + q = (p - q) ^ 3 take mod p => q(q^2 + 1) mod p = 0 or p | q(q^2 + 1).

Wilson's theorem, n is prime iff (n - 1)! ≡ -1 (mod n)

x^n mod m = (x mod m)^n mod m
*/


//Benq template for modular arithmetic
const int MOD = 1e9 + 7;
struct mi {
    int v; explicit operator int() const { return v; }
   mi() { v = 0; }
   mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
   if ((a.v += b.v) >= MOD) a.v -= MOD; 
   return a;
}
mi& operator-=(mi& a, mi b) { 
   if ((a.v -= b.v) < 0) a.v += MOD; 
   return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
   assert(p >= 0);
   return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }

mi a = 1e8, b = 1e8, c = 1e8;
cout << (int) (a * b * c) << "\n"; // 49000000


// Almost all of this page is significantly hard to comprehend and seems useful...
https://cp-algorithms.com/algebra/phi-function.html


// updates a to max(a, b) and returns one if a is changed else returns 0 or false. 
bool ckmax(int& a, const int& b) {
	return a < b ? a = b, 1 : 0;
}
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0;
}



best[s] = min(best[s], option);
// where best[i], option is a pair<int, int> 


void setIO(string name = "") {
   cin.tie(0) -> sync_with_stdio(0);
   if (sz(name)) {
      freopen((name + ".in").c_str(), "r", stdin);
      freopen((name + ".out").c_str(), "w", stdout);
   }
}


bool isPrime(int n) {
   if (n <= 1)
      return false;
   if (n <= 3)
      return true;
   if (n % 2 == 0 || n % 3 == 0)
      return false;
   for (int i = 5; i * i <= n; i = i + 6)
      if (n % i == 0 || n % (i + 2) == 0)
         return false;
   return true;
}
// Alternatively, find a list of all primes (sieve) and check upto floor(sqrt(n)) if any of them divides then composite else prime.


bool isPerfectSquare(long double x) {
   if (x >= 0) {
      long long sr = sqrt(x);
      return (sr * sr == x);
   }
   return false;
}


int divisors(long long n) {
   int count = 0;
   for (int i = 1; i * i <= n; i++) {
      if (n % i == 0)
         count += 2;
   }
   if (n / m == m && n % m == 0)
      count--;
   return count;
}
 

// Finding second max value in a cooler way.
for (int& x : a) {
   if (r_max <= x) {
      r_max2 = r_max;
      r_max = x;
   } else if (r_max2 <= x) {
      r_max2 = x;
   }
} 


bool isPalindrome(string s){
   if( equal(s.begin(), s.begin() + s.size()/2, s.rbegin()) )	return true;
   return false;
}


string Replacement(string S, string T, string r) {
   // replace t in s by r ;)
   string R;
   for (int i = 0; i < S.size(); i++) {
      R += S[i];
      if (R.size() >= T.size() && R.substr(R.size() - T.size()) == T) {
         R.resize(R.size() - T.size());
         R += r;
      }
   }
   return R;
}


bool isSubSequence(int m, int n) { 
   bool ok = false;
   for (int i = 0, j = 0; i < n; ++i) {
      if (j < m && s[i] == t[j]) ++j;
      if (j == m) ok = true;
   }
   return ok;
}


// Iterating over every contiguous subarray in increasing order of length 
for (int j = 0; j <= n; j++) {
   for (int i = 0; i < n - j; i++) {
      for (int k = i + 1; k <= i + j; k++) {
         // 
      }
   }
}

// Order
for (int i = n - 1; i >= 0; i--) {
   for (int j = i + 1; j < n; j++) {
      for (int k = i + 1; k < j; k++) {
         // 
      }
   }
}

// This!
for (int len = 1; len <= n; len++) {
   for (int i = 0; i + len <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
         // 
      }
   }
}


// Standard combinatorial computations, nCk = n-1Ck + n-1Ck-1
for(int i = 0; i <= n; i++) {
   for(int j = 0; j <= i; j++) {
      if (j == 0 || j == i) nCr[i][j] = 1;
      else nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
   }
}

// Although note that, when n is larger than 1e3; it's better not to waste memory and directly calculate ncr by n! * inv((n-i)! * i!), precalculate facts 
pow[0] = 1;
for (int i = 1; i <= n; i++) {
   pow[i] = (pow[i - 1] * k) % mod;
}   


// p[i][i] = 1; dp[i][i] = 1; p[i][i] = 1, dp[i][i] = 1;
p[i][i] = dp[i][i] = 1;


if (a != b) {
   // where a and b are pair<int, int>; 
}


// O/1 BFS: Similar to Dijkstra's as notice that queue remains sorted at all the times.
vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
   int v = q.front();
   q.pop_front();
   for (auto edge : adj[v]) {
      int u = edge.first;
      int w = edge.second;
      if (d[v] + w < d[u]) {
         d[u] = d[v] + w;
         if (w == 1)
            q.push_back(u);
         else
            q.push_front(u);
      }
   }
}



queue<pair<pair<int, int>, int>> bq;
bq.push({{p, q}, r});
int a = bq.front().xx.xx, b = bq.front().xx.yy, c = bq.front().yy; bq.pop(); 


string ans;
ans.push_back('U');


for(int i = 0; i < n; i++) a[i] = 0; //reset a[i]
// This is linear in n and not in the array size unlike memset!
// if not want hand-written, 
memset(a, 0, n * sizeof(a[0]));


// checking if no element is negative.
bool noNegative = none_of(a.begin(), a.end(), [](int x) {
   return x < 0; 
});

// checking if any element is negative.
bool anyNegative = any_of(a.begin(), a.end(), [](int x) {
  return x < 0;
});


// checking if all elements are odds
bool allOdds = all_of(a.begin(), a.end(), [](int x) { 
  return x % 2 != 0; 
});


// STL
string in = '1234567890';
string out;
// copy_n: returns iterator in the destination range, pointing past the last element copied if count>0 or result otherwise.
copy_n(in.begin(), 4, back_inserter(out)); // back_insert_iterator which can be used to add elements to the end of the container c
cout << out; // "1234"
vector<int> v_in(128);
iota(v_in.begin(), v_in.end(), 1);
vector<int> v_out(v_in.size());
copy_n(v_in.cbegin(), 100, v_out.begin());   // A const_iterator to the beginning of the sequence,  just like the iterator returned by vector::begin,
// but it cannot be used to modify the contents it points to, even if the vector object is not itself const.
cout << accumulate(v_out.begin(), v_out.end(), 0); // 5050


void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (rand() % 2) {
        father[rootB] = rootA;
    } else {
        father[rootA] = rootB;
    }
}


elem > (n * (n / 2))
// Use below instead, 
elem * 2 > n * n 


bool dfs(int v, int p) {
   // returns true if cycle found 
   vis[v] = true;
   parent[v] = p;
   for (int u : adj[v]) {
      if (u == p) continue;
      if (!vis[u]) {
         if (dfs(u, v)) return true;
      } else {
         ev = v;
         sv = u;
         return true;
      }   
   }
   return false;
}


int n[2], m[2]; vector<int> g[2][1001];// Cleaner implementation of a multigraph question
bitset<2001> dp[2][1001]; // much faster ))
possible |= (bset[j] << i); // turn bits i to the right of set bits in bset[j]. 


assert(dp[u] <= m);
if (!(--indegree[v.xx]))   bfs.push(v.xx);
max(a, b + (i == s[j] - 'a' ? 1 : 0));


// rename symbol feature in VS code to edit name in only the same scope


// ternary search alternative implementation
while (r - l > 1) {
   int m = l + (r - l) / 2;
   if (A[m] > A[m + 1]) {
      r = m;
   } else { 
      l = m + 1;
   }
}


https://codeforces.com/edu/course/2/lesson/6/4


// There is always a number divisible by a digit x within every 10 numbers, edu 122 A


https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html (can skip shell sort)
https://www.cs.usfca.edu/~galles/visualization/CountingSort.html
https://www.cs.usfca.edu/~galles/visualization/RadixSort.html


void radix_sort(int* a, int n) {
   // have to pass size as an argument
}


node* temp = new node(); // allocates memory, no need to use malloc and shit


void multiply(int mat[2][2],int m[2][2]){
   int temp[2][2];
   temp[0][0] = mat[0][0] * m[0][0] + mat[0][1] * m[1][0];
   temp[0][1] = mat[0][0] * m[0][1] + mat[0][1] * m[1][1];
   temp[1][0] = mat[1][0] * m[0][0] + mat[1][1] * m[1][0];
   temp[1][1] = mat[1][0] * m[0][1] + mat[1][1] * m[1][1];
   mat[0][0] = temp[0][0];
   mat[0][1] = temp[0][1];
   mat[1][0] = temp[1][0];
   mat[1][1] = temp[1][1];
}


void mat_power(int mat[2][2], int n) {
   if(n == 1) return;
   // Matrix exponentiation, same concept as binary exponentiation
   mat_power(mat, n / 2);
   multiply(mat,mat);
   int m[2][2] = {
      {1,1},
      {1,0}
   };   
   if(n % 2)
	   multiply(mat, m);
}


int fact(ll n) {
	return n ? (n * fact(n - 1)) % mod : 1;
}


// The difference between twice the unit digit of the given number and the remaining part of the given number should be a divisible by 7.
// If the difference is divisible by 11, then the original number is also divisible by 11


/*
Each even integer n > 2 can be represented as a sum n = a + b so that both a and b are primes.
There is always a prime between numbers n^2 and (n+1)^2, where n is any positive integer.
*/


vector<int> factors(int n) {
   vector<int> f;
   for (int x = 2; x * x <= n; x++) {
      while (n % x == 0) {
         f.push_back(x);
         n /= x;
      }
   }
   if (n > 1)
      f.push_back(n);
   return f;
}


clock_t start, end;
start = clock();
// fun()
end = clock();
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
dbg(time_taken);


int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } //path compression one-liner


// DSU alternate implementation
const int N = 2e5 + 5;
int n, par[N], rnk[N];
int get (int x) { return (par[x] == x) ? x : get(par[x]); }
void unite (int u, int v) {
   int x = get(u), y = get(v);
   if (x == y) return;
   if (rnk[x] < rnk[y]) swap(x, y);
   par[y] = x;
   if (rnk[x] == rnk[y])   rnk[x]++;
}
void dsu (int n) {
   for (int i = 1; i <= n; i++) {
      par[i] = i;
      rnk[i] = 1; 
   }
}


struct Pos {
	int pos;  
	bool used;  
	long long cost; 
};
auto cmp = [&] (const Pos& a, const Pos& b) { return a.cost > b.cost; }; // declaration 
std::priority_queue<Pos, vector<Pos>, decltype(cmp)> frontier(cmp); // creating a custom compartor for priority queue.
frontier.push(Pos{n, true, new_cost}); // creating instance of an struct object


d.resize(n, vector<int>(n));


// the solution is executed with error 'out of bounds' on the line 64*/
while( sum + v[i].xx > w)  i++;     
while (sum - w > v[i].xx)  i++;
// would prevent overflow


struct foo {
   int bar;
   foo() : bar(3) {}   //look, a constructor
   int getBar() { 
      return bar; 
   }
};
foo f;
int y = f.getBar(); // y is 3


https://docs.microsoft.com/en-us/cpp/cpp/destructors-cpp?view=msvc-170


template <typename T> 
struct array { 
  size_t x; 
  T *ary; 
}; 

template <typename T>
T myMax(T x, T y) {
   return (x > y)? x: y;
}
cout << myMax<char>('g', 'e') << endl;
cout << myMax('g', 'e') << endl; // compiler automatically determines the type


// typename and class are interchangeable in the basic case of specifying a template
template <class T, class U>
T GetMin (T a, U b) {
  return (a < b ? a : b);
}
int i, j;
long l;
i = GetMin<int,long> (j, l);
// or, more simply
i = GetMin (j, l);




//new allocates an amount of memory needed to store the object/array that you request. In this case n numbers of int.
int *array = new int[n]; //The pointer will then store the address to this block of memory
delete [] array; // this allocated block of memory will not be freed until this



/*AVL trees generally have a lower total runtime when there are many more lookups than inserts/deletes.
RB trees have a lower total runtime when there are many more inserts/deletes. */


// You can work with .pdf files and .txt files in this editor in a efficient way too!


struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
ListNode* tmp = new ListNode(value);


// Also called polynomial hash.
int hashcode (string s) {
   int hash = 0;
   for (int i = 0; i < sz(s); i++) {
      hash = s[i] + (31 * hash);
      // Equivalent to s[0]*31^L-1 + ... + s[L-1]*31^0 By horner's method.
   }
   return hash;
}


int hashcode (ll x) {
   return ((x & 0x7fffffff) % M);// make it positive by bitwise and from biggest int number then take mod
}


string a = "5sdsd";
string s = typeid(a).name();
cout << s << "\n"; // NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// i for int, x for long long


string gen_random(int len) {
   static const char alphanum[] =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";
   string tmp_s;
   tmp_s.reserve(len);
   for (int i = 0; i < len; ++i) {
      tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
   }
   return tmp_s;
}


int hashInt(int value){
   int digit, sum = 0, i = 1;
   while(value > 0){
      digit = value % 10;
      sum += digit * i;
      value /= 10;
      i++;
   }
   return sum % bucketSize;
}


!isalnum(s[i]) // checks if s[i] is a digit, lowercase or uppercase char.
isspace(s[i]) // true is s[i] == ' ';


// Same string, smaller to bigger substrings
for (int len = 2; len <= n; len++) {
   for (int i = 0; i + len - 1 < n; i++) {
      int j = i + len - 1;
      //
   } 
}


// assigns a to x, then return x;
return x = a;


auto comp = [] (const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
};
dp[i][j] = min(incl, excl, comp);


vector<string> v = {"..."};
if (find(v.begin(), v.end(), str) != v.end()) {}


// suffix s[i:], prefix s[:i] notations, actually comes from python.


/*
In some number theory problems, it helps to represent each number were
represented by a bitmask of its prime divisors. For example, the set {6,10,15}$can be represented by {011,101,110},
where the bits correspond to divisibility by [2, 3, 5]/
Now, 
Bitwise AND is GCD
Bitwise OR is LCM
Iterating over bits is iterating over prime divisors
Iterating over submasks is iterating over divisors
*/


/*initializing bitsets*/
bitset<60> x[mxN];
for (int i = 0, a; i < n; i++) {
   cin >> a;
   x[i] = a;
}


s ^= true; // talking NOT, my method  


// To avoid memory usage and avoiding hashmaps this is a way to check existence of pairs alternate to vis[x][y].
set<pair<int, int>> visited;


result = 1LL * result * k % 998'244'353; // string literals


string precision_2(double number) {
    int decimal_part = (number * 100) - ((ll)number * 100);
    if (decimal_part > 10) {
        return to_string((ll)number) + "." + to_string(decimal_part);
    } else {
        return to_string((ll)number) + ".0" + to_string(decimal_part);
    }
}

string temp = to_string(val); // val is a float


std::set<int> example = {1, 2, 3, 4};
for(int x: {2, 5}) {
   if(example.contains(x)) {
      std::cout << x << ": Found\n"; 
   } else {
      std::cout << x << ": Not found\n"; 
   }
}


if (a) // true when a is negative


// vector + sort + binary search is much faster than using set.
// set.count() is much faster than using map<int, bool>. conventional structures really do they meaningful use.


// implementation
using P = pair<long long, long long>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }


// When working with segment trees
// store array when doing range sum queries
// store difference array when doing range updates  


// C++ 20
// initialization + auto, sort by ranges
int n; cin >> n;
vector<pair<int, int>> a(n);
for (int i = 0; auto& [x, y]: a)
   cin >> x, y = i++;
ranges::sort(a);

// sort by weight
struct edge{ int v, u, w; };
vector<edge> e;
ranges::sort(e, {}, &edge::w);

// three-way comparisons
lhs <=> rhs
/*
(a <=> b) < 0 if lhs < rhs
(a <=> b) > 0 if lhs > rhs
(a <=> b) == 0 if lhs and rhs are equal/equivalent.
*/

// aggregated initialization
struct A { int x; int y; int z; };
 
A a{.y = 2, .x = 1}; // error; designator order does not match declaration order
A b{.x = 1, .z = 2}; // ok, b.y initialized to 0

struct A {
    string str;
    int n = 42;
    int m = -1;
};
 
A{.m = 21} // Initializes str with {}, which calls the default constructor
           // then initializes n with = 42
           // then initializes m with = 21

// the <bit> header
/* Take a look at functions
https://en.cppreference.com/w/cpp/header/bit
*/

// a lot more stuff in ranges library: views/iota/...


// labels in c++; 
// it shouldn't cross any initialization in the scope it's ending.
while (t--){
    cin>>n;
    for (int i=0;i<2*n;++i) cin>>a[i];
    sort(a,a+2*n,greater<int>());
    for (int i=0;i<n;++i){
        if (a[i*2]!=a[i*2+1]){
            cout<<"NO\n";
            goto cont;
        }
        b[i]=a[i*2];
    }
    for (int i=1;i<n;++i){
        if (b[i-1]==b[i]||(b[i-1]-b[i])%(2*(n-i))){
            cout<<"NO\n";
            goto cont;
        }
        d[i]=(b[i-1]-b[i])/2/(n-i);
    }
    for (int i=1;i<n;++i){
        b[n-1]-=2*i*d[i];
    }
    if (b[n-1]<=0||b[n-1]%(2*n)) cout<<"NO\n";
    else cout<<"YES\n";
    cont:;
}


// Binary Jumping
for (int j = 1; j <= K; j++) {
   for (int i = 0; i + (1 << j) <= N; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
   }
}

int j = lg[R - L + 1]; // precalculated powers of two
return min(st[L][j], st[R - (1 << j) + 1][j]);

for (int i = 1; (1 << i) <= n; i++) {
   for (int j = 0; j <= n; j++) {
      jump[i][j] = jump[i - 1][jump[i - 1][j]];
   }
}


int diff = h[a] - h[b]; 
for (int i = 20; i >= 0; i--) {
   if (diff & (1 << i)) {
      a = jump[i][a];
   }
}

ll n_hsh1 = 1, poly1 = 0, p_pow1 = 1;
// Compute polynomial hashes
poly1 = (poly1 * P + (h[i] - 'a')) % M1;
n_hsh1 = n_hsh1 * (P + n[i] - 'a') % M1;
// p_pow1 and p_pow2 will be used to **update** the polynomial hashes (rolling property)
p_pow1 = p_pow1 * P % M1;
// update maintain the hash over window
poly1 = (poly1 * P - p_pow1 * (h[i - (int)n.size()] - 'a') % M1 + (h[i] - 'a') + M1) % M1;
// Update product hashes using modular inverse
h_hsh1 = h_hsh1 * inv(P + h[i - (int)n.size()] - 'a', M1) % M1 * (P + h[i] - 'a') % M1;


merge(nodes[2 * v].begin(), nodes[2 * v].end(), nodes[2 * v + 1].begin(), nodes[2 * v + 1].end(), nodes[v].begin());
// Basically, std::merge takes 5 arguments: begin and end of one interval to merge, begin and end of the second interval to merge, and where to write the result.
// Keeps it sorted.



int pos = partition_point(vec.begin(), vec.end(), p) - vec.begin();
// Returns the first point where p(*it) is false.

 
generate(v.begin(), v.end(), rand); 

int nxt () {
   int x;
   cin >> x;
   return x;
}
int n = nxt();
vector<int> v(n);
generate(v.begin(), v.end(), nxt);
// Filling a vector with some values


if (int x = f(); is_good(x)) {
   use_somehow(x);
   // ...
}
// Cleanest way of including a variable in if statement. Possible since C++17


rotate(vec.begin(), vec.begin() + k, vec.end());
// to cyclically shift a vector by k places
// This function works in such a way that after rotate(begin, middle, end) the element *middle becomes
//  the first from begin to end.


int modulas (string &num) {
   int res = 0;
   for (int i = 0; i < sz(num); i++) {
      res = ((ll)res * 10 + (int)num[i] - '0') % mod;
   }  
  return res;
}


auto dfs = [&](auto&& self, int v) -> void {
  // use self inside lambda body instead of dfs:)
};
dfs(dfs, 0);
// Very important: For recursive declarations, trailing return type is required when compiler can’t deduce it, which is often the case.
// Like above definition is fine.
// or this, needs to be done:
auto dfs = [&] (auto &&self, int u, ...) {
   // ...	
   if (g[u].empty()) return;
   for (auto v : g[u]) {
     self(self, v, ...);
   }
};

// M-1
auto fib = [&] (auto&& self, int n) {  
   if (n < 2) return n; // there must be a return statement before calling self (typically to resolve all cases)
   return self(self, n - 1) + self(self, n - 2);
};
cout << fib(fib, n);

// M-2
#include <functional>
std::function<int(int)> fib;
fib = [&](int n) {
   if (n <= 1) return n;
   return fib(n - 1) + fib(n - 2);
};


auto& [xr, yr] = a; // xr refers to a[0], yr refers to a[1]

BitFields s;
auto& [b, d, p, q] = s;
std::cout << b << ' ' << d << ' ' << p << ' ' << q << '\n'; // [...]
b = 4, d = 3, p = 2, q = 1;
std::cout << s.b << ' ' << s.d << ' ' << s.p << ' ' << s.q << '\n'; // [4, 3, 2, 1]


// Compilation flags:
g++ -Wall -Wextra -O2 -std=c++17 -Wshadow -Wconversion -D_GLIBCXX_CONCEPT_CHECKS -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -DLOCAL
// if clang, add:
-fsanitize=address -fsanitize=undefined -ftrapv -fno-sanitize-recover -fstack-protector -fno-omit-frame-pointer

if (cnt[0] == 0) printf("-1\n"), exit(0); // control flow
 
int dp[71][70 * 70 + 1] = {[0 ... 70][0 ... 70 * 70] = INT_MAX}; // initializing arrays

queue<TreeNode*> bfs;//  is perfectly fine. When it is struct type* {}; you use struct type* s; s->val instead of s.val but code editor will fix that


auto reverse_bits = [] (int &n) {
   int rev = 0;
   while (n > 0) {
      rev <<= 1;
      if (n & 1) rev ^= 1;
      n >>= 1;
   }		   
   n = rev;
};


nth_element (RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// The function of this is that it rearranges the array in such a way such that the element at the nth position is the one which should be at that position if we sort the list from the first to last iterator. It uses the quick select method for this.

int n = nums.size();
nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
int median = nums[n/2];


for (auto i : a) for (int j = 0; j < 32; j++) bits[j] += !!(i & (1 << j));
// javascript trick xD


// Decorators and more
// https://github.com/codersanjeev/modern-cpp-tricks#decorators-in-c-and-multiple-parameters


cout << accumulate(a, a + 3, sum, myfun); // finds sum
std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>()); // writes them down
https://en.cppreference.com/w/cpp/algorithm/partial_sum


lower_bound(set.begin(), set.end(), value) // O(n)
set.lower_bound(value) // O(logn)
	
multiset.count() // Logarithmic in size and linear in the number of matches.
set.count() // Logarithmic in size
multiset.find() // Logarithmic in size
set.contains() // since C++20



sqrtl() // to compute square root of a long long number
	
	
// Accessing a map index can result in insertion. Thus accessing map index too much can result in MLE and TLE.
int a = mp[2]; // here 2 gets inserted in mp if it is not already there.



// Syntax for any random iterator (for example, with a vector and not a set), here end:
while (stk.size() >= 3 && stk[stk.size() - 2] + stk[stk.size() - 1] > stk[stk.size() - 3]) {
  stk.pop_back();
}
// A cleaner way of writing the same thing is this:
while (stk.size() >= 3 && end(stk)[-2] + end(stk)[-1] > end(stk)[-3]) {
  stk.pop_back();
}


// Free functions
size(v) // unsigned, bad ans on a.size() - 1 when a is empty
ssizev) // signed
begin(v), end(v), rbegin(v), rend(v)
empty(v)


// Variable declaration in loops/conditions after C++17
for (int i = -1; auto x : a) {
  i++;
  // do something
}

if (auto x = construct_object(); x.good() && !x.bad()) {
  // do something
}


// temporary container in for loop
for (auto x : "LRDU"s) { /* do something */ }
// Note that the s at the end makes it a string literal which is why it works, and const char* doesn't work because there is a \0 at the end of the literal.


// Header for mathematical constants in C++20 
#include <numbers>
// https://en.cppreference.com/w/cpp/header/numbers


midpoint(a, b) // C++20, for avoiding underflow overflow issues


a.push_back({1, 2});
a.emplace_back(1, 2);
emplace_front and emplace // do the same thing for their other counterparts (for example, in a deque, queue or priority_queue)


// C++ 20
bool res = str.starts_with("abc"s);
basic_string::ends_with()

string::contains() // check substring containment, C++ 23


// Ranges in C++ 20
namespace R = std::ranges;
namespace V = std::ranges::views;

//  You take integers in [1,6), multiply them by 2, reverse them, and take the first 3. 
int main() {
    for (auto x : V::iota(1, 6) | V::transform([](int x) { return x * 2; }) | V::reverse | V::take(3))
        std::cout << x << '\n';
}
// The | operator is defined for ranges and an operation on ranges that returns a range. 

// If r is a range, then for most STL containers, like std::vector, you can do something like
std::vector<int> a(r.begin(), r.end())


std::string s = "1010101010";
for (const auto word : V::split(s, '1')) {
	std::cout << std::string_view{begin(word), end(word)} << ' '; // 0 0 0 0 0
        // std::cout << word << ' '; won't work
}

#include <ranges>
#include <string_view>
#include <iomanip>

int main() {
    constexpr std::string_view words{"Hello^_^C++^_^20^_^!"};
    constexpr std::string_view delim{"^_^"};
    for (const auto word : std::views::split(words, delim))
        std::cout << std::quoted(std::string_view{word.begin(), word.end()}) << ' ';
}
// Output: "Hello" "C++" "20" "!"


