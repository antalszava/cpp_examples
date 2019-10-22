    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        if (n == 1)
            return x;
        
        if (x < 0)
            return ((n % 2 != 0) ? -1 : 1)*exp(n*log(-x));
        
        return exp(n*log(x));
    }
