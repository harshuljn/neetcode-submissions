class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int num: nums) {
            numSet.insert(num);
        }

        int maxSeqLength = 0;
        for(int num: numSet) {
            if(isStartingOfSequence(num, numSet)) {
                int seqLength = calcSequenceLength(num, numSet);
                maxSeqLength = max(maxSeqLength, seqLength);
            }
        }
        return maxSeqLength;
    }

    bool isStartingOfSequence(int num, unordered_set<int> &numSet) {
        if(numSet.contains(num-1)) return false;
        return true;
    }

    int calcSequenceLength(int num, unordered_set<int> &numSet) {
        int length = 1;
        while(numSet.contains(++num)) length++;
        return length;
    }
};
