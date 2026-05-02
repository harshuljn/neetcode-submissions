class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0, curMin = 0;
        int maxSum = nums[0], minSum = nums[0];
        int total = 0;
        for(int i = 0; i < nums.size(); i++) {
            curMax = max(curMax + nums[i], nums[i]);
            curMin = min(curMin + nums[i], nums[i]);

            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);

            total += nums[i];
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};