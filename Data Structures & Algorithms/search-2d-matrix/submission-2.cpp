class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        while(left < right){
            int middle = left + (right - left / 2);
            if(matrix[middle][0] < target){
                left = middle;
            }else if(matrix[middle][0] > target){
                right = middle - 1;
            }else{
                return true;
            }
            // cout << left << " : " << right << "\n";
        }
        int targetRow = left;
        left = 0;
        right = matrix[targetRow].size()-1;
        while(left < right){
            int middle = left + (right - left / 2);
            if(matrix[targetRow][middle] < target){
                left = middle;
            }else if(matrix[targetRow][middle] > target){
                right = middle - 1;
            }else{
                return true;
            }
        }
        return matrix[targetRow][left] == target;
    }
};
