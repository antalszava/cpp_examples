//works
int digitsCount(int d, int low, int high) {
  if (d != low - 1)
    return countdigits(d, low-1, high, false);
  else
    return countdigits(d, low, high, false);  

}


int countdigits(int d, int low, int high, bool inner) {
    if (high == 0)
        return (d == 0) ? 1 : 0;

    if (low > 0)
        return countdigits(d, 0, high, false) - countdigits(d, 0, low, false);

    int n = floor(log10(high));
    int m = floor((high + 1) / pow(10, n));
    int r = high - m * pow(10, n);
    return
        (max(m, 1) * n * pow(10, n-1)) +                             // (1)
        ((d < m) ? pow(10, n) : 0) +                                 // (2)
        (((r >= 0) && (n > 0)) ? countdigits(d, 0, r, true) : 0) +   // (3)
        (((r >= 0) && (d == m)) ? (r + 1) : 0) +                     // (4)
        (((r >= 0) && (d == 0)) ? countpaddingzeros(n, r) : 0) -     // (5)
        (((d == 0) && !inner) ? countleadingzeros(n) : 0);           // (6)
}

int countleadingzeros(int n) {
      int tmp= 0;
      while(n>0){
         tmp= pow(10, n)+tmp;
         --n;
         }
         return tmp;
         }

int countpaddingzeros(int n, int r) {
    return (r + 1) * std::max(0., n - std::max(0., floor(log10(r))) - 1);
}
