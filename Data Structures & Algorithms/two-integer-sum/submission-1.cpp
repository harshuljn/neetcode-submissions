class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndexMap;
        for(int i = 0; i < nums.size(); i++) {
            int curNum = nums[i];
            if(numIndexMap.find(target-curNum) != numIndexMap.end()) {
                return {numIndexMap[target-curNum], i};
            }
            numIndexMap[curNum] = i;
        }
        return {-1, -1};
    }
};
