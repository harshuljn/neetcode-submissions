class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();
        int maxLen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> charIndexMap;
        
        while(r != s.length()) {
            char curChar = s[r];
            if(charIndexMap.find(curChar) != charIndexMap.end()){
                int newL = charIndexMap[curChar]+1;
                while(l < newL) {
                    charIndexMap.erase(s[l]);
                    l++;
                }
            }

            charIndexMap[curChar] = r;
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
