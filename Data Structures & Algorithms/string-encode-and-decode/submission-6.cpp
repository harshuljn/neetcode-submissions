class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(string str: strs) {
            encoded_string += to_string(str.length()) + "#" + str;
        }
        cout << encoded_string << endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        while(i < s.length()) {
            int j = i;
            while(s[j] != '#') j++;
            int strLength = stoi(s.substr(i, j));
            cout << "strLength = " << strLength << endl;
            cout << "i = " << i << endl;
            cout << "j = " << j << endl;
            i = j+1;
            decoded_strs.push_back(s.substr(i, strLength));
            i = i + strLength;
        }
        return decoded_strs;
    }
};
