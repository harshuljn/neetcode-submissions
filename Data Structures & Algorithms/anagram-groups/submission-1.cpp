class Solution {
public:
    string transformToKey(string str) {
	vector<int> count(26, 0);
	for(char ch: str) {
		count[ch-'a'] += 1;
	}
	
	string key = "";
	for(int num: count) {
		key += ',' + to_string(num);
	}
	
	return key;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, vector<string>> res;
	vector<vector<string>> ans;
	for(const string &str: strs) {
		string key = transformToKey(str);
		res[key].push_back(str);
	}
	
	for(const auto &pair: res) {
		ans.push_back(pair.second);
	}
	return ans;
}
};
