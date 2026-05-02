class Solution {
private:
    bool isRowValid(vector<vector<char>>& board, int row) {
        vector<bool> isNumPresent(10, false);
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == '.') {
                continue;
            } else {
                int num = board[row][j] - '0';
                if(isNumPresent[num]) return false;
                isNumPresent[num] = true;
            }
        }
        return true;
    }

    bool isColumnValid(vector<vector<char>>& board, int col) {
        vector<bool> isNumPresent(10, false);
        for(int j = 0; j < 9; j++) {
            if(board[j][col] == '.') {
                continue;
            } else {
                int num = board[j][col] - '0';
                if(isNumPresent[num]) return false;
                isNumPresent[num] = true;
            }
        }
        return true;
    }

    bool isSubMatrixValid(vector<vector<char>>& board, int row, int col) {
        vector<bool> isNumPresent(10, false);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int rowNum = row+i;
                int colNum = col+j;
                
                if(board[rowNum][colNum] == '.') {
                    continue;
                } else {
                    int num = board[rowNum][colNum] - '0';
                    if(isNumPresent[num]) return false;
                    isNumPresent[num] = true;
                }
            }
        }
        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(!isRowValid(board, i)) return false;
        }

        for(int i = 0; i < 9; i++) {
            if(!isColumnValid(board, i)) return false;
        }

        for(int i = 0; i < 9; i+=3) {
            for(int j = 0; j < 9; j+=3) {
                if(!isSubMatrixValid(board, i, j)) return false;
            }
        }

        return true;
    }
};
