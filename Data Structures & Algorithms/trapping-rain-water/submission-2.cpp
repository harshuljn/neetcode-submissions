class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int preMax = 0;
        for(int i = 0; i < n; i++) {
            leftMax[i] = preMax;
            preMax = max(preMax, height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int j = n-2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j+1], height[j]);
        }

        int res = 0;

        for(int i = 0; i < n; i++) {
            res += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};
