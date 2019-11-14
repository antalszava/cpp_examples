class Solution {
public:
    void swap(int i, int j, int i2, int j2, vector<vector<int>> & matrix){
        if (i == i2 && j == j2) return;
        int temp1 = matrix[i][j];
        matrix[i][j] = matrix[i2][j2];
        matrix[i2][j2] = temp1;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        //row i goes to col col_size - 1 - i
        //inplace transpose
        //move columns
        for (int i = 0; i < matrix.size(); i++){
            int j = 0;
            while (j < i){
                swap(i,j,j,i,matrix);
                j++;
            }
        }
        
        for (int i = 0; i < matrix.size(); i++){
           for (int j = matrix[0].size()/2; j < matrix[0].size(); j++){
                swap(i,j,i,matrix[0].size() - 1 - j, matrix);
            }
        }
     
    }
};
