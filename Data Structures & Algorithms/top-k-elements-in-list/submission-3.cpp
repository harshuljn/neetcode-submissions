class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> countMap;
	for(int num: nums) {
		countMap[num]++;
	}
	
	vector<vector<int>> elementsByCount(nums.size()+1);
	
	for(const auto &pair: countMap) {
		elementsByCount[pair.second].push_back(pair.first);
	}
	
	vector<int> res;
	for(int i = elementsByCount.size()-1; i >= 0; i--) {
		for(int num: elementsByCount[i]) {
			res.push_back(num);
			if(res.size() == k) return res;
		}
	}
	return res;
}
};
