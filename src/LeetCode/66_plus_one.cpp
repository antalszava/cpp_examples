class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int dsize = digits.size() - 1;
        
        if (digits[dsize] < 9){
            digits[dsize]++;
            return digits;
        }
        
        for (int i = dsize; i >= 0; i--){
            if (digits[i] == 9){
                digits[i] = 0;
            }
            else {
                digits[i]++;
                break;
            }
        }
        
        if (digits[0] == 0){
            digits.insert(digits.begin(),1);
        }
            
        return digits;
    }
};
