class Solution {
public:
   bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int curRow = 0, curCol = matrix[0].size()-1;
	while(curRow < matrix.size() && curCol >= 0) {
		int curElement = matrix[curRow][curCol];
		if(curElement > target) curCol--;
		else if(curElement < target) curRow++;
		else return true;
	}
	return false;
}
};
