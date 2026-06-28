class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> letterCount(26);

        for(char letter: text) {
            letterCount[letter-'a']++;
        }

        string inputWord = "balloon";
        unordered_map<char, int> inputWordLetterCount;
        for(char letter: inputWord) {
            inputWordLetterCount[letter]++;
        }

        int maxWords = 
        letterCount[inputWord[0]-'a']/inputWordLetterCount[inputWord[0]];

        for(auto letterCountPair: inputWordLetterCount) {
            char letter = letterCountPair.first;
            int count = letterCountPair.second;
            maxWords = min(maxWords, letterCount[letter-'a']/count);
        }
        return maxWords;
    }
};