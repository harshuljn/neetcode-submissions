class Solution {
public:
int longestConsecutive(vector<int>& nums) {
	unordered_set<int> numSet(nums.begin(), nums.end());
	
	int maxLen = 0;
	for(auto num: numSet) {
		if(numSet.find(num-1) != numSet.end()) continue;
		else {
			int curLen = 1;
			while(numSet.find(++num) != numSet.end()) {
				curLen++;
			}
			maxLen = max(maxLen, curLen);
		}
	}
	return maxLen;
}
};
