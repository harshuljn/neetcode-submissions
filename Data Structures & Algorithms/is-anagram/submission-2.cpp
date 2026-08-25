class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letterCount(26);
        for(char letter: s) {
            letterCount[letter-'a']++;
        }
        for(char letter: t) {
            letterCount[letter-'a']--;
        }
        for(int count: letterCount) {
            if(count != 0) return false;
        }
        return true;
    }
};
