


// one way
int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while(i+1 < nums.size()){
            if(nums[i+1] == nums[i])
                nums.erase(nums.begin()+i);
            else
                i++;
        }
        return nums.size();
    }


int removeDuplicates(vector<int> & nums) {
    if (nums.length == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.length; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}
