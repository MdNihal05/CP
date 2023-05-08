 bool bin_search(vector<int> arr){
   int l = 0, r = n;
   while (r-l > 1) {
       int m = (l + r) / 2;
 
       if (predicate(m))
           l = m;
       else
           r = m;
   }
}
//l will be last true
// r will be first false
