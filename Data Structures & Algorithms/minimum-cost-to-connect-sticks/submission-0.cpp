class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1) return 0;
        
        // Convert sticks into a min heap
        auto cmp = [](int a, int b) {return a > b;};
        priority_queue<int, vector<int>, decltype(cmp)> min_heap(sticks.begin(), sticks.end(), cmp);

        int cost = 0;

        // iterate heap
        while(min_heap.size() > 1){
            // get top two elements
            int stick1 = min_heap.top(); 
            min_heap.pop();

            int stick2 = min_heap.top(); 
            min_heap.pop();

            int newStick = stick1 + stick2;

            // merge and add cost
            cost += (newStick);

            // push merged sticked into the min heap
            min_heap.push(newStick);
        }


        return cost;
    }
};
