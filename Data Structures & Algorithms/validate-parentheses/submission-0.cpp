class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenMap = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        stack<char> charStack;
        for(char c: s) {
            if(parenMap.count(c) == 0) {
                charStack.push(c);
            }
            else {
                if(charStack.empty() || charStack.top() != parenMap[c]) return false;
                else {
                    charStack.pop();
                }
            }
        }
        return charStack.empty();
    }
};
