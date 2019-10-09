#include <iostream>

double neural_network(double input, double weight){
  return weight*input;
}


int main(int argc, char *argv[])
{
  double weight = 0.5;
  double goal_pred = 0.8;
  double input = 2;
  double alpha = 0.1;

  for (size_t i = 0; i < 20; i++){   
    double pred = neural_network(input, weight);
    double error = (pred-goal_pred);
    error *= error;
    double derivative = (pred-goal_pred)*input;
    weight = weight - derivative*alpha;
    std::cout << "error = " << error << std::endl;
  }
  
  
  return 0;
}
