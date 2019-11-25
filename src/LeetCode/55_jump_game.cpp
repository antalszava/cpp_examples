
using namespace std;

class Solution {
public:
    
    enum class State { unknown, bad, good };
    vector<State> memo;
    
    bool canJumpFromPosition(int position, vector<int> & nums){
        if (memo[position] != State::unknown){
            return memo[position] == State::good ? true : false;
        }
        
        int furthestJump = position + nums[position] > nums.size() - 1 ? nums.size() - 1 : position + nums[position];
        
        for (int np = position + 1; np <= furthestJump; np++){
            if (canJumpFromPosition(np, nums)){
                memo[position] = State::good;
                return true;
            }
        }
        
        memo[position] = State::bad;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size());
        for (auto &i : memo){
            i = State::unknown;
        }
        memo[nums.size()-1] = State::good;
        return canJumpFromPosition(0,nums);        
    }
};
