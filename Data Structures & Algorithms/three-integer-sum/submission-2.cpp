class Solution {
public:
// [-1, -1, -1, 0, 1, 2, -4]
// [[-1, -1, 2], [-1, 0, 1], [-1, -1, 2]]
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> resSet;
        
        for(int i = 0; i < nums.size(); i++) {
            int j = i+1, k = nums.size()-1;
            int target = -nums[i];
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum == target) {
                    resSet.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                }
                else if(sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> res(resSet.begin(), resSet.end());
        return res;
    }
};
