class Solution {
public:
    bool check(vector<int>& nums) {
      if(nums.size() <= 2) return true;
      int rotation = 0;
      for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[i-1]) {
          rotation = i;
          break;
        } 
      }
      cout << "rotation is " << rotation << endl;
      if(rotation == 0) return true;
      int i = rotation;
      while(i+1 < nums.size()) {
        if(nums[i+1] < nums[i]) return false;
        i++;
      }
      return nums.back() <= nums[0];
    }
};