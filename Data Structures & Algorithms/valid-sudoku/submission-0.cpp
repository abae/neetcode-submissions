class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> rowHash(9);
        vector<set<char>> colHash(9);
        vector<set<char>> gridHash(9);

        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                char spot = board[i][j];
                if(spot == '.'){
                    continue;
                }
                if(rowHash[i].contains(spot)){
                    return false;
                }
                if(colHash[j].contains(spot)){
                    return false;
                }
                int gridNum = int(j / 3) + (3 * int(i / 3));
                if(gridHash[gridNum].contains(spot)){
                    return false;
                }
                rowHash[i].insert(spot);
                colHash[j].insert(spot);
                gridHash[gridNum].insert(spot);
            }
        }
        return true;
    }
};
