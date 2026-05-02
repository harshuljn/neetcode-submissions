class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> countMap;
	for(int num: nums) {
		countMap[num]++;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	
	for(const auto &pair: countMap) {
		minHeap.push({pair.second, pair.first});
		if(minHeap.size() > k) minHeap.pop();
	}
	
	vector<int> res;
	while(!minHeap.empty()) {
		res.push_back(minHeap.top().second);
		minHeap.pop();
	}
	
	return res;
}
};
