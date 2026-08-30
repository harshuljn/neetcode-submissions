class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for(int num: nums) {
            countMap[num]++;
        }

        vector<pair<int, int>> sortedCountMap;
        for(auto countPair: countMap) {
            sortedCountMap.push_back(make_pair(countPair.second, countPair.first));
        }
        sort(sortedCountMap.begin(), sortedCountMap.end());

        vector<int> ans;
        int n = sortedCountMap.size();
        for(int i = 0; i < k; i++) {
            ans.push_back(sortedCountMap[n-1-i].second);
        }

        return ans;
    }
};
