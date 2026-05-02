class Solution {
private: 
    bool allElementsZero(const vector<int> &arr) {
        for(int num: arr) {
            if(num != 0) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> charCount(26, 0);
        for(int i = 0; i < s1.length(); i++) {
            charCount[s1[i]-'a'] += 1;
            charCount[s2[i]-'a'] -= 1;
        }
        if(allElementsZero(charCount)) return true;
        int l = 0, r = s1.length()-1;
        while(r != s2.length()-1) {
            charCount[s2[l]-'a']++;
            l++, 
            r++;
            charCount[s2[r]-'a']--;
            if(allElementsZero(charCount)) return true;
        }
        return false;
    }
};
