class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // initialize max heap using stones
        priority_queue<int> maxHeap;
        for(int s: stones) {
            maxHeap.push(s);
        }

        while(maxHeap.size() >= 2) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(b < a) {
                maxHeap.push(a-b);
            }
        }
        if(maxHeap.size() == 0) return 0;
        return maxHeap.top();
    }
};
