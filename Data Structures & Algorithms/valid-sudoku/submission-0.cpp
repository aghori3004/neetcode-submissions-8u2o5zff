class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<char, unordered_map<int, unordered_set<char>>> grandMap;

        vector<char> gName = {'r', 'c', 'b'};

        for(char c : gName){
            for(int i = 0; i<9; i++){
                grandMap[c][i].insert(0);
            }
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if (board[i][j] == '.') continue;
                else{
                    if(grandMap['r'][i].find(board[i][j]) != grandMap['r'][i].end()) return false;
                    else grandMap['r'][i].insert(board[i][j]);

                    if(grandMap['c'][j].find(board[i][j]) != grandMap['c'][j].end()) return false;
                    else grandMap['c'][j].insert(board[i][j]);
                    
                    int bNum = (i / 3) * 3 + (j / 3);

                    if(grandMap['b'][bNum].find(board[i][j]) != grandMap['b'][bNum].end()) return false;
                    else grandMap['b'][bNum].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};
