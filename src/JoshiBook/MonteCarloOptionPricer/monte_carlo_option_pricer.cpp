#include <iostream>
#include <random>
#include <cmath>

double
compute_payoff
(
 double expiry,
 double strike_price,
 double spot_price,
 double volatility,
 double r_interest,
 size_t num_of_paths
)
{
  double variance = volatility*volatility*expiry;
  double root_variance = sqrt(variance);
  double running_sum = 0.;
  
  double fixed_spot = spot_price*exp(r_interest*expiry -0.5*variance);

  // printf("running_sum = %f\n", running_sum);
  // printf("fixed_spot = %.15f\n", fixed_spot);
  // printf("spot_price = %f\n", spot_price);
  // printf("r_interest = %f\n", r_interest);
  // printf("expiry = %f\n", expiry);
  // printf("variance = %f\n", variance);
  // printf("num_of_paths = %f\n", num_of_paths);

  std::default_random_engine generator;
  generator.seed(1);
  std::normal_distribution<double> distribution(0.0,1.0);
  
  for (size_t i = 0; i < num_of_paths; i++){
    double normal_deviate = distribution(generator);

     // printf("normal_deviate = %f\n", normal_deviate);

    double new_spot = fixed_spot*exp(root_variance*normal_deviate);
    double payoff = new_spot - strike_price;
    // printf("new_spot = %f\n", new_spot);
    // printf("payoff = %f\n", payoff);
    running_sum += payoff > 0 ? payoff : 0;
    // printf("running_sum = %f\n", running_sum);

    printf("i, nd, new_spot = %d, %f, %f\n",
	   i, normal_deviate, new_spot);
  }

  double mean = running_sum / (double)num_of_paths;
  mean *= exp(-r_interest*expiry);
  return mean;
}


int main(int argc, char *argv[])
{
  double end_expiry = 100;
  double strike_price = 100;
  double spot_price = 100;
  double volatility = .4;
  double r_interest = .06;

  size_t num_of_steps = 100;
  double expiry_dt = end_expiry/num_of_steps;
  size_t num_of_paths = 10;

  // for (int step = 0; step < num_of_steps; step++){
    double payoff
      =
      compute_payoff
      (
       end_expiry,
       strike_price,
       spot_price,
       volatility,
       r_interest,
       num_of_paths
       );
    std::cout << end_expiry << " " << payoff << std::endl;
  // }
        
  return 0;
}
