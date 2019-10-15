#include <iostream>
#include <vector>

std::vector<double> get_strategy(const std::vector<double> & regret_sum) {
  double normalizing_sum = 0;
  int num_actions = regret_sum.size();
  std::vector<double> strategy(num_actions);

  for (int a = 0; a < num_actions; a++){
    strategy[a] = regret_sum[a] > 0 ? regret_sum[a] : 0;
    normalizing_sum += strategy[a];
  }
  for (int a = 0; a < num_actions; a++){
    if (normalizing_sum > 0){
      strategy[a] /= normalizing_sum;
    }
    else {
      strategy[a] = 1.0/num_actions;
    }
  }
  return strategy;
}

int get_action(const std::vector<double> & strategy){
  double r = (double)rand() / (double)RAND_MAX;//random number;
  int a = 0;
  // std::cout << "r = " << r << std::endl;
  double cumulative_probability = 0;
  while (a < strategy.size()  - 1){
    // std::cout << "a = " << a << std::endl;
    cumulative_probability += strategy[a];
    // std::cout << "cum prob = " << cumulative_probability  << std::endl;
    if (r < cumulative_probability)
      break;
    a++;
  }
  return a;
}

void train(int iterations){
  
  std::vector<double> strategy = {0.4,0.3,0.3};
  std::vector<double> opp_strategy = {1.0,0.0,0.0};
  std::vector<double> strategy_sum = {0., 0., 0.};
  std::vector<double> regret_sum = {0., 0., 0.};
  std::vector<double> action_utility = {0., 0., 0.};
  double strategy_cumsum = 0.;

  int num_actions = strategy.size();
  
  for (int i = 0; i < iterations; i++){
    int my_action = get_action(strategy);
    int opp_action = get_action(opp_strategy);

    //we set this up to be circular 0 = ROCK, 1 = PAPER, 2 = SCISSORS
    //this would be a draw if we chose opp_action
    action_utility[opp_action] = 0;

    //if we chose the one after opps decision then we would win
    action_utility[opp_action == num_actions - 1 ? 0 : opp_action + 1] = 1;

    //if we chose the one before opps decision then we would lose
    action_utility[opp_action == 0 ? num_actions - 1 : opp_action - 1] = -1;

    for (int a = 0; a < num_actions; a++){
      regret_sum[a] += action_utility[a] - action_utility[my_action];
    }

    strategy = get_strategy(regret_sum);

    for (int i = 0; i < num_actions; i++){
      strategy_sum[i] += strategy[i];
      strategy_cumsum += strategy[i];
    }

    for (int i = 0; i < num_actions; i++){
      std::cout << strategy_sum[i] / strategy_cumsum << " ";
    }
    std::cout << std::endl;
  }
  
}


int main(int argc, char *argv[])
{

  train(10000);
  
  return 0;
}
