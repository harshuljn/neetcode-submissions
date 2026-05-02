class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> countMap;
	for(int num: nums) {
		countMap[num]++;
	}
	
	vector<pair<int, int>> countVector;
	for(auto const &pair: countMap) {
		countVector.push_back(make_pair(pair.second, pair.first));
	}
	
	sort(countVector.begin(), countVector.end());
	vector<int> res;
	int n = countVector.size();
	for(int i = 0; i < k; i++) {
		res.push_back(countVector[n-1-i].second);
	}
	return res;
}
};
