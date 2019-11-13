class Solution {
public:
    int maximumProduct(vector<int>& nums) {


      //better would be single for loop and then find two smallest and three largest, then use the method below without sort
      
        std::sort(nums.begin(),nums.end()); 
        if (nums[nums.size() - 1] > 0){
            if (nums[0] < 0){
                int prod_1 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
                int prod_2 = nums[0]*nums[1]*nums[nums.size()-1];
                return (prod_2 > prod_1) ? prod_2 : prod_1;
            }
            else {
                return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
            }
        }
        else {
            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        }
        
    }
};
