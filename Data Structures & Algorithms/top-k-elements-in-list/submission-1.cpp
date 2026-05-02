class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	    unordered_map<int, int> countMap;
	    for(int num: nums) {
		    countMap[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;
        for(const auto &pair: countMap) {
            maxHeap.push({pair.second, pair.first});
        }

        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return res;
    }
};
