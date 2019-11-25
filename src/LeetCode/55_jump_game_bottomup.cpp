class Solution {
public:
    
    enum class State { unknown,  good };
    vector<State> memo;

    bool canJump(vector<int>& nums) {
        memo.resize(nums.size());
        for (auto &i : memo){
            i = State::unknown;
        }
        memo[nums.size()-1] = State::good;

	for (int i = nums.siz() - 2; i >= 0; i--){
	  int furthestJump = i + nums[i] > nums.size() - 1 ? nums.size() - 1 : i + nums[i];
	  for (int j = i + 1; j <= furthestJump; j++){
	    if (memo[j] == State::good){
	      memo[i] = State::good;
	      break;
	    }
	  }
	}
	
        return memo[0] == State::good;     
    }
};



