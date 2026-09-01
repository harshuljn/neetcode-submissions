class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefixProduct = 1;
        int suffixProduct = 1;
        for(int i = 0; i < n; i++) {
            result[i] *= prefixProduct;
            prefixProduct *= nums[i];

            result[n-1-i] *= suffixProduct;
            suffixProduct *= nums[n-1-i];
        }
        return result;
    }
};
