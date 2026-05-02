class Solution {
private:
    int findArea(vector<int> &heights, int leftIdx, int rightIdx) {
        if(rightIdx <= leftIdx) return 0;
        return min(heights[leftIdx], heights[rightIdx]) * (rightIdx - leftIdx);
    }
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxArea = 0;
        while(left < right) {
            maxArea = max(maxArea, findArea(heights, left, right));
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxArea;
    }
};


/*
    [1, 7, 2, 5, 4, 7, 3, 6]
    maxArea = 0
    
    area = (min(1, 6)) * (7-0) = 7
    maxArea = 7;

    area = 6 * (7-1) = 36



*/