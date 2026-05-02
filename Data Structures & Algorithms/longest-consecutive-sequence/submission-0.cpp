class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        sort(nums.begin(), nums.end());
        int curSeqLen = 1;
        int longestSeqLen = 1;
        int prev = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > prev+1) {
                curSeqLen = 1;
                prev = nums[i];
                continue;
            }
            else {
                if(nums[i] == prev+1) {
                    curSeqLen += 1;
                    longestSeqLen = max(longestSeqLen, curSeqLen);
                    prev = nums[i];
                }
            }
        }
        return longestSeqLen;
    }
};
