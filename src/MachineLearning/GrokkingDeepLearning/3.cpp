double w_sum(
	     const std::vector & weights,
	     const std::vector & x
	     )
{
  double sum = 0.;
  for (size_t i = 0; i < a.size(); i++){
    sum += weights[i]*x[i];
  }
  return sum;
}


std::vector<double> vect_mat_mul(std::vector<double> vect,
				 std::vector<std::vector<double>> mat)
{
  std::vector<double> output;
  for (int i = 0; i < vect.size(); i++){
    output[i] = w_sum(vect, matrix[i]);
  }
}

double neural_network(
		      const std::vector & input,
		      const std::vector & weights
		      )
{
  double pred = w_sum(input, weights);
  return pred;
}


int main(int argc, char *argv[])
{


  std::vector<double> input = {1.2,3.0,4.5};
  std::vector<double> weights = {1.2,3.0,4.5};
  double pred = neural_network(input, weights);

  
  return 0;
}
