class Solution {
public:
    int countPrimes(int n) {
        
        if (n < 3)
            return 0;
        
        int count = 1;
        int div_max = sqrt(n);
        
        
        for (int i = 3; i < n; i+=2){
            for (int j = 2; j <= div_max; j+=1){
                if (i % j == 0 && j != i){
                    count--;
                    break;
                }
            }
            count++;
        }
        return count;
    }
};

