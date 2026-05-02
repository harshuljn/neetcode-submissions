class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> numsMap;
	int n = nums.size();
	for(int i = 0; i < n; i++) {
		int comp = target-nums[i];
		if(numsMap.find(comp) != numsMap.end()) {
			return {numsMap[comp], i};
		}
		numsMap[nums[i]] = i;
	}
	return {-1, -1};
}
};
