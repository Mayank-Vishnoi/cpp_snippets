// min
auto good = [&] (int x) {
   // return bool;
};
int l = 0, r = n, m;
while (r - l > 1) {
   m = l + (r - l) / 2;
   good (m) ? r = m : l = m;
}
cout << r << '\n';

// max
auto good = [&] (int x) {
   // return ;
};
int l = 0, r = n + 1, m;
while (r - l > 1) {
   m = l + (r - l) / 2;
   good (m) ? l = m : r = m;
}
cout << l << '\n';
