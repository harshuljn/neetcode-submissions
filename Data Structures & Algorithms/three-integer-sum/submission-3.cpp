class Solution {
public:
// [-1, -1, -1, 0, 1, 2, -4]
// [[-1, -1, 2], [-1, 0, 1], [-1, -1, 2]]
        vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
		        if(i > 0 && nums[i-1] == nums[i]) continue;
            int j = i+1, k = nums.size()-1;
            int target = -nums[i];
            while(j < k) {
                int sum = nums[j] + nums[k];
                if(sum > target) {
	                k-=1;
                } else if (sum < target) {
	                j += 1;
                } else {
	                res.push_back({nums[i], nums[j], nums[k]});
	                j += 1;
	                while(nums[j] == nums[j-1] && j < k) j++;
                }
                
            }
        }
        return res;
    }
};
