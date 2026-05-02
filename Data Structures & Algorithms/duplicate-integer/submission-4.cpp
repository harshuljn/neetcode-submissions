class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        unordered_set<int> s;
        for(int i = 0; i < arr.size(); i++) {
            if(s.find(arr[i]) != s.end()) return true;
            s.insert(arr[i]);
        }
        return false;
    }
};