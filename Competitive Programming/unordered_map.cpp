struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
      x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
      return x ^ (x >> 31);
   }
   size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
   }
};

unordered_map<int, int, custom_hash> mp;


// for unordered_map<pair<int, int>, int> or unordered_set<pair<int, int>> 
struct HASH {
   size_t operator() (const pair<int,int> &x) const {
      return (size_t) x.first * 37U + (size_t) x.second;
   }
};


// for vector<int> as a key
namespace std {
    template<>struct hash<vector<int>> {
        size_t operator() (vector<int> const& v) const{
          unsigned long long h = 0;
          for (auto &x : v)
            h <<= 32, h ^= hash<int>()(x), h = hash<long long>()(h);
          return h;
        }
    };
}
