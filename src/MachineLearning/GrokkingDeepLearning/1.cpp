#include <iostream>

double neural_network
(
 double input,
 double weight
)
{
  double prediction = input * weight;
  return prediction;  
}


int main(int argc, char *argv[])
{
  neural_network(8.5,0.1);
  return 0;
}
