class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int duplicate, missing;
      for(int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i])-1;
        if(nums[index] < 0) {
          duplicate = index + 1;
          continue;
        }
        nums[index] *= -1;
      }

      for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
          missing = i + 1;
          break;
        }
      }

      return {duplicate, missing};
    }
};