class Solution {
public:
  bool canJump(vector<int> nums) {
    if (nums.size() == 1)
        return 1;
      
    if (nums[0] == 0)
        return 0;
      
    if (nums.size() == 2){
        return nums[0] > 0;
    }
      
    if (nums.size() == 3){
        return nums[0] > 1 || nums[1] > 0;
    }
      
    int farthest = 0;
    for (int i = 0; i <= farthest && i < nums.size(); ++i) {
      if (i + nums[i] > farthest){
	    farthest = i+nums[i];
      }
    }
    return farthest >= nums.size() - 1;
    }
};
