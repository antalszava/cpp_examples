class Solution {
public:
    
    bool isHappy(int n) {
        
        if (n == 1) return true;

        int happy = 0;
        int num = n;
        
        while(1){
            int temp = num;
            int sum = 0;
            
            while (temp != 0){
                int dig = temp % 10;
                sum += dig*dig;
                temp /= 10;
            }
            
            if (sum == 1) return true;
            if (sum == n) return false;
            num = sum;
        }
        
        return false;
            
    }
};



int main(int argc, char *argv[])
{
  std::cout << Solution().addBinary("11","1") << std::endl;
  return 0;
}

