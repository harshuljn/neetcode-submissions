class Solution {
public:
    bool check(vector<int>& nums) {
      if(nums.size() <= 2) return true;
      int numBreakPoints = 0;
      for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[i-1]) numBreakPoints++;
      }
      if(numBreakPoints == 1) return nums.back() <= nums[0];
      else return numBreakPoints == 0;
    }
};