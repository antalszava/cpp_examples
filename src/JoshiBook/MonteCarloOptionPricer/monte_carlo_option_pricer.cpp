#include <iostream>


double monte_carlo_option_mean
(
 double expiry,
 double strike,
 double spot,
 double vol,
 double r,
 unsigned long number_of_paths
)
{
  double variance = vol*vol*expiry;
  double root_variance = sqrt(variance);
  double ito_correction = -0.5*variance;

  double moved_spot = spot*exp(r*expiry + itocorrection);
  double this_spot;
  double running_sum;

  for (unsigned long i = 0; i < number_of_paths; i++){
    double this_gaussian = get_one_gaussian_by_box_muller();
    this_spot = moved_spot*exp(root_variance*this_gaussian);
    double this_payoff = this_spot - strike;
    this_payoff = this_payoff > 0 ? this_payoff : 0;
    running_sum += this_payoff;
  }

  double mean = running_sum / number_of_paths;
  mean *= exp(-r*expiry);
  return mean;
}

int main()
{

  double expiry;
  double strike;
  double spot;
  double vol;
  double r;
  size_t number_of_paths;
  double result = monte_carlo_option_mean(expiry,strike,spot,vol,r,number_of_paths);

  std::cout << "The price is " << result << "\n";
  
  return 0;
}
