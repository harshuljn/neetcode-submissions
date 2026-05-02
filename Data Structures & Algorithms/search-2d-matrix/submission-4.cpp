class Solution {
    int binarySearchRow(vector<vector<int>>& matrix, int target) {
        int start = 0, end = matrix.size() - 1;
        int cols = matrix[0].size();

        while(start <= end) {
            int mid = (start + end) / 2;

            if(target > matrix[mid][cols - 1]) {
                start = mid + 1;
            } else if(target < matrix[mid][0]) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int binarySearchColumn(vector<vector<int>>& matrix, int target, int row) {
        int start = 0, end = matrix[row].size() - 1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(matrix[row][mid] == target) return mid;
            else if(matrix[row][mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int rowNum = binarySearchRow(matrix, target);
        if(rowNum == -1) return false;

        int colNum = binarySearchColumn(matrix, target, rowNum);
        return colNum != -1;
    }
};
