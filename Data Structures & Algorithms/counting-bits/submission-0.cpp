class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n+1, 0);
        for(int i = 0; i <= n; i++) {
            counts[i] = countOnes(i);
        }
        return counts;
    }

    int countOnes(int n) {
        int count = 0;
        while(n != 0) {
            if(n&1) count +=1;
            n = n >> 1;
        }
        return count;
    }
};
