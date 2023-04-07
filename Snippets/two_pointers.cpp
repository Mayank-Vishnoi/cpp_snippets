// less than
int l = 0, r = 0;
// ll x = 0;
for (; r < n; r++) {
   add(r);
   while (!good()) {
      remove(l);
      l++;
   }
   // update result
}

// greater than or equal 
int l = 0, r = 0;
// ll x = 0;
for (; r < n; r++) {
   add(r);
   while (good_after_removal()) {
      remove(l);
      l++;
   }
   if (good()) {
      // update result
   }
}
