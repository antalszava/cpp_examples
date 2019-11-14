// https://www.geeksforgeeks.org/sparse-matrix-representations-set-3-csr/
#include <algorithm> 
#include <iostream> 
#include <vector> 

using namespace std; 
typedef std::vector<int> vi;   
typedef vector<vector<int>> matrix; 
  
// Utility Function to print a Matrix 
void printMatrix(const matrix& M) 
{ 
  int m = M.size(); 
  int n = M[0].size(); 
  for (int i = 0; i < m; i++) { 
    for (int j = 0; j < n; j++)  
      cout << M[i][j] << " ";         
    cout << endl; 
  } 
} 
  
// Utility Function to print A, IA, JA vectors 
// with some decoration. 
void printVector(const vi& V, char* msg) 
{   
    cout << msg << "[ "; 
    for_each(V.begin(), V.end(), [](int a) { 
        cout << a << " "; 
    }); 
    cout << "]" << endl; 
} 

struct CSR_MAT {
  vi A;
  vi IA;
  vi JA;
  int m;
  int n;
};


void transpose_inplace
(
 matrix & mat
){
  for (int i = 0; i < mat.size(); i++){
    for (int j = 0; j < i; j++){
      int temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
  }
}

matrix desparsify
(
 const CSR_MAT & csr_mat
)
{
  int m = csr_mat.m;
  int n = csr_mat.n;
  
  matrix M; M.resize(m);
  for (int i = 0; i < m; i++)
    M[i].resize(n);

  std::cout << "m = " << m << std::endl;
  int counter = 0;
  for (int i = 0; i < m; i++){
    int temp_counter = 0;
    int num_nonzero_on_row = csr_mat.IA[i+1] - csr_mat.IA[i];
    while (temp_counter < num_nonzero_on_row){
      int col = csr_mat.JA[counter + temp_counter];
      int row = i;
      int val = csr_mat.A[counter + temp_counter];
      M[row][col] = val;
      temp_counter++;
    }
    counter+=temp_counter;
  }
  
  return M;
}

// Generate the three vectors A, IA, JA  
CSR_MAT sparsify(const matrix& M) 
{ 
    int m = M.size(); 
    int n = M[0].size(), i, j; 
    vi A; 
    vi IA = { 0 }; // IA matrix has N+1 rows 
    vi JA; 
    int NNZ = 0; 
  
    for (i = 0; i < m; i++) { 
        for (j = 0; j < n; j++) { 
            if (M[i][j] != 0) { 
                A.push_back(M[i][j]); 
                JA.push_back(j); 
  
                // Count Number of Non Zero  
                // Elements in row i 
                NNZ++; 
            } 
        } 
        IA.push_back(NNZ); 
    } 
  
    printMatrix(M); 
    printVector(A, (char*)"A = "); 
    printVector(IA, (char*)"IA = "); 
    printVector(JA, (char*)"JA = ");
    CSR_MAT csr;
    csr.m = m;
    csr.n = n;
    csr.A = A; csr.IA = IA; csr.JA = JA;
    return csr;
} 
  
// Driver code 
int main() 
{ 
    matrix M = { 
        { 0, 0, 0, 0, 1 }, 
        { 5, 8, 0, 0, 0 }, 
        { 0, 0, 3, 0, 0 }, 
        { 0, 6, 0, 0, 1 }, 
    }; 
  
    CSR_MAT csr = sparsify(M);
    matrix M2 = desparsify(csr);
    std::cout << std::endl;
    printMatrix(M2);
    std::cout << std::endl;
    transpose_inplace(M2);
    printMatrix(M2);
    std::cout << std::endl;
    CSR_MAT csr2 = sparsify(M2);
  
    return 1;
}
