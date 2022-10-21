class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        /*
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
  for (int i = 0; i < rows; i++) {
    //checking if 0 is present in the 0th column or not
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
    if (col0 == 0) {
      matrix[i][0] = 0;
    }

  }
        */
         int row = matrix.size() , col = matrix[0].size();
         int colInitializer = 1;
        for(int i = 0; i< row; i++){
            if(matrix[i][0] == 0)   colInitializer = 0;
                for(int j = 1; j<col; j++){
// ab agar kisi bhi index per zero milta hai to main ushki col or row ke first element ko zero ker dunga mere bhai bus ye yaad rkhna 
                    if(matrix[i][j] == 0)
                    {   matrix[i][0] =  0;
                        matrix[0][j] = 0;
                        }
                }
        }
//         ab reverse travers krenge same matrix mein
        for(int i = row-1; i>=0; i--){
//             zeroth col traverse nhi krenge kyuki wo handle humara colInitializer ker lega
            for(int j = col-1; j >= 1; j-- ){
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                    matrix[i][j]= 0;
               
            }
             if(colInitializer == 0){
                    matrix[i][0] = 0;
                }
        }
    }
};