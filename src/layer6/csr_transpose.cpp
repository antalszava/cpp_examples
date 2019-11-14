#include <vector>
#include <iostream>

struct CSR_matrix {

  std::vector<int> Am;
  std::vector<int> Im;
  std::vector<int> Jm;
  int nm;
};

struct CRN {
  int column;
  int row;
  int num;
};


std::vector<CRN> crn_transcribe_and_transpose(const CSR_matrix & csr)
{
  std::vector<int> Im_temp = csr.Im;
  std::vector<CRN> crn;
  for (int i = 0; i < csr.Am.size(); ++i) {
    int num = csr.Am[i];
    int col = csr.Jm[i];
    int row;
    if (num == 6) {
      std::cout << num << " " << col << "" << std::endl;
    }
    for (int j = 1; j < Im_temp.size(); ++j) {
      if (num == 6){
	std::cout << Im_temp[j] << std::endl;
      }
      if (Im_temp[j] != 0) {
        row = j - 1;
        Im_temp[j] -= 1;
        break;
      }
    }
    CRN crn_new;
    crn_new.column = row;
    crn_new.row = col;
    crn_new.num = num;
    crn.push_back(crn_new);
  }
  return crn;
}


// CSR_matrix
void tranpose(CSR_matrix csr){

  // CSR_matrix csr;
  // csr.Am = {1, 8, 1, 3, 6};
  // csr.Im = {0, 0, 3, 4, 5};
  // csr.Jm = {0, 1, 3, 2, 1};
  // csr.nm = 5;
  // std::vector<CRN> crn = crn_transcribe_and_transpose(csr);
  
  // std::vector<CRN> crn_trans = crn_transpose(crn);
  //sort crn_trans by columns then rows
  // return csr_transcribe(crn);
  
}


int main(int argc, char *argv[])
{

  CSR_matrix csr;
  csr.Am = {1, 8, 1, 3, 6};
  csr.Im = {0, 0, 3, 4, 5};
  csr.Jm = {0, 1, 3, 2, 1};
  csr.nm = 5;
  std::vector<CRN> crn = crn_transcribe_and_transpose(csr);
  // for (auto i: crn){
    // std::cout << i.row << " " << i.column << " " << " " << i.num << std::endl;
  // }
  
  return 0;
}
