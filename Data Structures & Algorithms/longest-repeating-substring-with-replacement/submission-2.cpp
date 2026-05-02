class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCountMap;
        int res = 0;
        int maxFreq = 0;
        int l = 0, r = 0;
        while(r < s.size()) {
            charCountMap[s[r]]++;
            maxFreq = max(maxFreq, charCountMap[s[r]]);
            
            while((r-l+1) - maxFreq > k) {
                charCountMap[s[l]]--;
                l++;
            }
            
            res = max(res, (r-l+1));
            r++;
        }
        return res;
    }
};
