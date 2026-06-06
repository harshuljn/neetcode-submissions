class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n = nums.size();
      vector<int> sortedSquareNums(n);
      int i = 0, j = n-1;
      int k = n-1;
      while(k >= 0) {
        if(abs(nums[i]) > abs(nums[j])) {
          sortedSquareNums[k] = nums[i]*nums[i];
          i++;
        } else {
          sortedSquareNums[k] = nums[j]*nums[j];
          j--;
        }
        k--;
      }
      return sortedSquareNums;
    }
};