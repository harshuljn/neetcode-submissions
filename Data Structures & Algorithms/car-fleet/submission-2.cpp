class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs(n);
        for(int i = 0; i < n; i++) {
            pairs[i] = {position[i], speed[i]};
        }
        sort(pairs.begin(), pairs.end());
        stack<double> durations;
        for(auto p: pairs) {
            double duration=double(target-p.first)/p.second;
            cout << duration << " ";
            durations.push(duration);
        }
        int fleets = 0;
        while(!durations.empty()) {
            double curTop = durations.top();
            durations.pop();
            while(!durations.empty() && curTop >= durations.top()) {
                durations.pop();
            }
            fleets++;
        }
        return fleets;
    }
};
