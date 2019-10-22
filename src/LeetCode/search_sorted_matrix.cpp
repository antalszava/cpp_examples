    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //    if(matrix.size() == 0 || matrix[0].size() == 0){return false;}
    //    int diag = -1;
   //     for (int i = 0; i < matrix.size(); i++){
   //         if (target <= matrix[i][i]){
  //              diag = i;
  //          }
  //      }
 //       if (diag == -1)
 //           return false;
        
//        for (int i = 0; i <= diag; i++){
 //           auto iter = std::find(matrix[i].begin(),matrix[i].begin()+diag+1,target);
 //           if (iter != matrix[i].begin()+diag+1)
  //              return true;
  //      }
  //      return false;
        
        for (auto i : matrix){
            auto iter = std::find(i.begin(),i.end(),target);
            if (iter != i.end())
                return 1;
        }
        
        //return 0;
        //if(matrix.size() == 0){return false;}
        //int row = 0;
        //int col = matrix[0].size() - 1;
        //while (row < matrix.size() && col >= 0){
        //    if (matrix[row][col] == target){
        //        return true;
        //    }
        //   else if (matrix[row][col] > target){
        //        col--;
        //    }
        //    else {
        //        row++;
        //    }            
        // }
         return false;
    }
