class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check column

        for (int i = 0; i < 9; i++) {
            vector<int> check(10, 0);
            for (int j = 0; j < 9; j++) {
                if(board[i][j]=='.') continue; 

                if (check[board[i][j] - '0'] > 0)
                    return false;
                check[board[i][j] - '0']++;
            }
            fill(check.begin(), check.end(), 0);
        }

        // check row
        for (int i = 0; i < 9; i++) {
            vector<int> check(10, 0);
            for (int j = 0; j < 9; j++) {
                if(board[j][i]=='.') continue; 

                if (check[board[j][i] - '0'] > 0)
                    return false;
                check[board[j][i] - '0']++;
            }
            fill(check.begin(), check.end(), 0);
        }

        // 1st row of boxes
        for (int sj = 0; sj < 9; sj += 3) {
            int st = 0;
            vector<int> check(10, 0);
            for (int i = st; i < st + 3; i++) {
                for (int j = sj; j < sj + 3; j++) {
                    if (board[i][j] == '.')
                        continue;
                    if (check[board[i][j] - '0'] > 0)
                        return false;
                    check[board[i][j] - '0']++;
                }
            }
        }

        // 2nd row of boxes
        for (int sj = 0; sj < 9; sj += 3) {
            int st = 3;
            vector<int> check(10, 0);
            for (int i = st; i < st + 3; i++) {
                for (int j = sj; j < sj + 3; j++) {
                    if (board[i][j] == '.')
                        continue;
                    if (check[board[i][j] - '0'] > 0)
                        return false;
                    check[board[i][j] - '0']++;
                }
            }
        }

        // 3rd row of boxes
        for (int sj = 0; sj < 9; sj += 3) {
            int st = 6;
            vector<int> check(10, 0);
            for (int i = st; i < st + 3; i++) {
                for (int j = sj; j < sj + 3; j++) {
                    if (board[i][j] == '.')
                        continue;
                    if (check[board[i][j] - '0'] > 0)
                        return false;
                    check[board[i][j] - '0']++;
                }
            }
        }

        return true;
    }
};