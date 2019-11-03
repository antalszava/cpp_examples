#include <iostream>
#include <vector>

double check_move(int ri, int ci, int rf, int cf, int N){
        
  if(ri + rf >= 0 && ri + rf < N
     && ci + cf >= 0 && ci + cf < N){
    return 1.;
  }
  else {
    return 0.;
  }
        
}
    
double knightProbability(int N, int K, int r, int c, std::vector<std::vector<std::vector<double>>> & probs) {
  double check = 0.;
  if ( probs[K-1][r][c] > 0. ){
    return probs[K-1][r][c];
  }


  if (K != 1){
    for (int i = -1; i <= 1; i += 2){
      for (int j = -1; j <= 1; j+= 2){
	double check1 = check_move(r,c,i*2,j*1,N);
	if (check1 > 0){
	  probs[K-1][r][c] += knightProbability(N, K - 1, r + i*2, c + j*1,probs)/8.;
	  //check += check;
	}
	double check2 = check_move(r,c,i*1,j*2,N);
	if (check2 > 0){
	  probs[K-1][r][c] += knightProbability(N, K - 1, r + i*1, c + j*2,probs)/8.;
	  //check += check2;
	}
      }
    }
  }
  else {
    for (int i = -1; i <= 1; i += 2){
      for (int j = -1; j <= 1; j+= 2){
	probs[K-1][r][c] += check_move(r,c,i*2,j*1,N)/8.;
	probs[K-1][r][c] += check_move(r,c,i*1,j*2,N)/8.;

      }
    }     
  }

  return probs[K-1][r][c];
}


int main(int argc, char *argv[])
{
  int N = 10;
  int K = 13;
  int r = 5;
  int c = 3;
  std::vector<std::vector<std::vector<double>>> probs(K);
  for (int i = 0; i < K; i++){
      probs[i].resize(N);
    for (int j = 0; j < N; j++){
      probs[i][j].resize(N);
      for (int k = 0; k < N; k++){
	probs[i][j][k] = 0.;
      }
    }
  }
  std::cout << knightProbability(N,K,r,c,probs) << std::endl;
  return 0;
}

