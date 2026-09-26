class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxArea = 0;
        while(left < right) {
            int curArea = min(heights[left], heights[right]) * (right-left);
            maxArea = max(maxArea, curArea);
            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxArea;
    }
};
