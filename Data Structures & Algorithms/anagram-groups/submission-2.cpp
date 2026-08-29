class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyStringsGroupMap;
        for(auto str: strs) {
            keyStringsGroupMap[convertToKey(str)].push_back(str);
        }

        vector<vector<string>> result;
        for(auto keyStringsPairItr: keyStringsGroupMap) {
            result.push_back(keyStringsPairItr.second);
        }

        return result;
    }

    string convertToKey(string str) {
        vector<int> letterCount(26);
        for(char letter: str) {
            letterCount[letter-'a']++;
        }
        string key = "";
        for(int i = 0; i < 26; i++) {
            key += to_string(letterCount[i]) + "_";
        }
        return key;
    }
};
