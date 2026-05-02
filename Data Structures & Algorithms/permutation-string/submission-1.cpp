class Solution {
public:
bool checkInclusion(string s1, string s2) {
	if(s1.length() > s2.length()) return false;
	vector<int> s1Count(26), s2Count(26);
	for(int i = 0; i < s1.length(); i++) {
		s1Count[s1[i]-'a'] += 1;
		s2Count[s2[i]-'a'] += 1;
	}
	int matches = 0;
	for(int i = 0; i < 26; i++) {
		if(s1Count[i] == s2Count[i]) matches++;
	}
	if(matches == 26) return true;
	int l = 0, r = s1.length()-1;
	while(r != s2.length()-1) {
		int index = s2[l]-'a';
		s2Count[index] -= 1;
		if(s2Count[index] == s1Count[index]) matches++;
		else if(s2Count[index] == s1Count[index]-1) matches--;
		l++;
		
		r++;
		index = s2[r]-'a';
		s2Count[index] += 1;
		if(s2Count[index] == s1Count[index]) matches++;
		else if(s2Count[index] == s1Count[index]+1) matches--;
		
		if(matches == 26) return true;
	}
	return false;
}
};
