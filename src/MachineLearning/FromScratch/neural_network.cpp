#include <iostream>
#include <vector>
#include "mnist_reader.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>
template <typename T>
void print_vector
(
 const std::vector<T> & data
){
  for (auto i: data){
    std::cout << i << std::endl;
  }
}



template <typename T>
void print_matrix
(
 const std::vector<std::vector<T>> & data
)
{  
  int rows = data.size();
  int cols = data[0].size();
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << data[i][j] << std::endl;
    }
  }
}



template <typename T>
void print_mnist_image_data
(
 const std::vector<T> & data
)
{
  for (int i = 0; i < data.size(); i++){
    double num = data[i];
    if (num < 10)
      std::cout << "  " << num << "  ";
    else if (num < 100)
      std::cout << "  " << num << " ";
    else
      std::cout << " " << num << " ";
    
    if (i % 28 == 0)
      std::cout << "\n";
  }
}


template <>
void print_mnist_image_data
(
 const std::vector<uint8_t> & data
)
{
  for (int i = 0; i < data.size(); i++){
    double num = unsigned(data[i]);
    if (num < 10)
      std::cout << "  " << num << "  ";
    else if (num < 100)
      std::cout << "  " << num << " ";
    else
      std::cout << " " << num << " ";
    
    if (i % 28 == 0)
      std::cout << "\n";
  }
}


template<typename T>
std::vector<double> matrix_vector_multiply
(
 const std::vector<std::vector<double>> & Mij,
 const std::vector<T> & xj,
 int transpose_Mij = 0
)
{
  std::vector<double> Mijxj(Mij.size(), 0);
  if (transpose_Mij == 0){
  for (int i = 0; i < Mij.size(); i++){
    for (int j = 0; j < xj.size(); j++){
      Mijxj[i] += Mij[i][j]*(xj[j]);
    }
  }
  }
  else {
  for (int i = 0; i < Mij.size(); i++){
    for (int j = 0; j < xj.size(); j++){
      Mijxj[i] += Mij[j][i]*(xj[j]);
    }
  }
  }
  return Mijxj;
}

template <>
std::vector<double> matrix_vector_multiply
(
 const std::vector<std::vector<double>> & Mij,
 const std::vector<uint8_t> & xj,
 int transpose_Mij
)
{
  std::vector<double> Mijxj(Mij.size());
  for (int i = 0; i < Mij.size(); i++){
    Mijxj[i] = 0.;
  }

  if (transpose_Mij == 0){
  for (int i = 0; i < Mij.size(); i++){
    for (int j = 0; j < xj.size(); j++){
      // std::cout << unsigned(xj[j]) << " ";
      // std::cout << (Mijxj[i]) << " ";
      // std::cout << (Mij[i][j]) << std::endl;
      Mijxj[i] += Mij[i][j]*unsigned(xj[j]);
    }
  }
  }
  else {
  for (int i = 0; i < Mij.size(); i++){
    for (int j = 0; j < xj.size(); j++){
      // std::cout << unsigned(xj[j]) << " ";
      // std::cout << (Mijxj[i]) << " ";
      // std::cout << (Mij[i][j]) << std::endl;
      Mijxj[i] += Mij[j][i]*unsigned(xj[j]);
    }
  }
  }
  return Mijxj;
}


double relu(double x){
  if (x >= 0)
    return x;
  else
    return 0;
}

double relu_deriv(double x){
  if (x >= 0)
    return 1;
  else
    return 0;
}

std::vector<double> softmax(const std::vector<double> & x){
  std::vector<double> soft(x.size());
  double sum = 0.;
  for (int i = 0; i < x.size(); i++){
    soft[i] = exp(x[i]);
    sum += soft[i];
  }
  for (int i = 0; i < x.size(); i++){
    soft[i] /= sum;
  }
  return soft;
}

std::vector<double> vector_component_mult(const std::vector<double> & x,
					  const std::vector<double> & y)
{
  std::vector<double> z(x.size());
  for (int i = 0; i < x.size(); ++i) {
    z[i] = x[i]*y[i];
 }
  return z;
}


std::vector<double> matrix_multiplication(const std::vector<uint8_t> &x,
					  const std::vector<std::vector<double>> &M
					  ){
  std::vector<double> y(M[0].size());
  for (int j = 0; j < y.size(); j++){
    y[j] = 0.;
    for (int i = 0; i < x.size(); i++){
      y[j] += unsigned(x[i])*M[i][j];
    }
  }
  return y;
}


std::vector<double> matrix_multiplication(const std::vector<double> &x,
					  const std::vector<std::vector<double>> &M,
					  int transpose = 0
					  ){
  // std::vector<double> y(M[0].size());
  if (!transpose){
      std::vector<double> y(M[0].size());
  for (int j = 0; j < y.size(); j++){
    y[j] = 0.;
    for (int i = 0; i < x.size(); i++){
      y[j] += x[i]*M[i][j];
    }
  }
  return y;
  }
  else {
    std::vector<double> y(M.size());
  for (int j = 0; j < y.size(); j++){
    y[j] = 0.;
    for (int i = 0; i < x.size(); i++){
      y[j] += x[i]*M[j][i];
    }
  }
  return y;
  }
}


std::vector<double> predict(
			    const std::vector<uint8_t> & image,
			    const std::vector<std::vector<double>> & weights_0_1,
			    const std::vector<std::vector<double>> & weights_1_2
			    )
{
  std::vector<double> layer_1 = matrix_multiplication(image,weights_0_1);
  for (int l= 0; l < layer_1.size(); l++){
    layer_1[l] = relu(layer_1[l]/255.);
  }
  return matrix_multiplication(layer_1,weights_1_2);
}

double compute_error
(
 const std::vector<double> & prediction,
 const std::vector<double> & real 
)
{
  double error = 0.;
  for (int j = 0; j < prediction.size(); j++){
    double diff = -(prediction[j] - real[j]);
    error += diff*diff;	  
  }
  return error;
}

int check_prediction
(
 const std::vector<double> & prediction,
 const std::vector<double> & real
)
{
  double prediction_max = 0.;
  int prediction_max_i = 0;
  double real_max = 0.;
  int real_max_i = 0;
  for (int m = 0; m < prediction.size(); m++){
    if (prediction[m] > prediction_max){
      prediction_max = prediction[m];
      prediction_max_i = m;
    }
    if(real[m] > real_max){
      real_max = real[m];
      real_max_i = m;
    }
  }
  return (prediction_max_i == real_max_i);
}


void print_sum(const std::vector<double> x, std::string label){
  double sum = 0.;
  for (int i = 0; i < x.size(); i++){
    sum += x[i];
  }
  std::cout << label << " sum = " << sum << std::endl;
}


void print_sum(const std::vector<uint8_t> x, std::string label){
  double sum = 0.;
  for (int i = 0; i < x.size(); i++){
    sum += unsigned(x[i]);
  }
  std::cout << label << " sum = " << sum << std::endl;
}

int main(int argc, char *argv[])
{

  int using_dropout = 0;
  if(argc > 1){
    using_dropout = atoi(argv[1]);
  }

  std::cout << "using_dropout = " << using_dropout << std::endl;
  
    mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t> dataset =
      mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>
      ("./");



    std::vector<std::vector<double>> training_1hot_labels(dataset.training_labels.size());
    for (int i = 0; i < dataset.training_labels.size(); i++){
      training_1hot_labels[i].resize(10);
      for (int j = 0; j < 10; j++){
	training_1hot_labels[i][j] = 0;
      }
      training_1hot_labels[i][dataset.training_labels[i]] = 1;
    }

    std::vector<std::vector<double>> test_1hot_labels(dataset.test_labels.size());
    for (int i = 0; i < dataset.test_labels.size(); i++){
      test_1hot_labels[i].resize(10);
      for (int j = 0; j < 10; j++){
	test_1hot_labels[i][j] = 0;
      }
      test_1hot_labels[i][dataset.test_labels[i]] = 1;
    }


    double alpha = 0.005;
    int iterations = 300;
    int hidden_layer_size = 100;
    int pixels_per_image = 784;
    int num_labels = 10;
    int batch_size = 100;


// Returns 1 for input > 0;
// relu = lambda x:(x>=0) * x
// returns 0 otherwise
// relu2deriv = lambda x: x>=0
    // for (int i = 0; i < dataset.training_images.size(); i++){
      // for (int j = 0; j < dataset.training_images[i].size(); j++){
	// dataset.training_images[i][j] /= 255;
      // }
    // }

    // double w01_sum = 0.;
    std::vector<std::vector<double>> weights_0_1(pixels_per_image);
    for (int i = 0; i < pixels_per_image; i++){
      weights_0_1[i].resize(hidden_layer_size);
      for (int j = 0; j < hidden_layer_size; j++){
    	// weights_0_1[i][j] = 0.1*sin((i+j)*M_PI/4.);// 0.2*((double)rand()/(double)RAND_MAX)-0.1;
    	weights_0_1[i][j] =  0.2*((double)rand()/(double)RAND_MAX)-0.1;
	// w01_sum += weights_0_1[i][j];
	}
    }

    // std::cout << "w01_sum = " << w01_sum << std::endl;
    // std::cout << std::setprecision(10);
    // double w12_sum = 0.;
    std::vector<std::vector<double>> weights_1_2(hidden_layer_size);
    for (int i = 0; i < hidden_layer_size; i++){
      weights_1_2[i].resize(num_labels);
      for (int j = 0; j < num_labels; j++){
    	// weights_1_2[i][j] = 0.1*tanh((i+j)*M_PI/4.);// 0.2*((double)rand()/(double)RAND_MAX)-0.1;
    	weights_1_2[i][j] = 0.2*((double)rand()/(double)RAND_MAX)-0.1;
	// std::cout << "weights_1_2 " << i << " " << j << " = " << weights_1_2[i][j] << std::endl;
	// w12_sum += weights_1_2[i][j];
	}
    }

    // std::cout << "w12_sum = " << w12_sum << std::endl;
    
    std::cout << std::setprecision(20);
    for (int k = 0; k < 300; k++){
      double error = 0.;
      int correct_count = 0;
      std::cout << "iteration " << k << std::endl;
      for (int i = 0; i < 1000; i++){

	// print_sum(dataset.training_images[i], "layer 0");
	
	std::vector<double> layer_1 = matrix_multiplication(dataset.training_images[i],weights_0_1);
	for (int l= 0; l < layer_1.size(); l++){
	  layer_1[l] = relu(layer_1[l]/255.);
	}

	// print_sum(layer_1, "layer_1");
	
	std::vector<double> dropout_mask(layer_1.size());
	if (using_dropout){
	  // dropout_mask = create_dropout_mask(layer_1.size());
	  // dropout_mask = { 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 };
	  // print_sum(dropout_mask, "dropout_mask");
	  for (int l= 0; l < layer_1.size(); l++){
	    // std::cout << 2.0*rand() << " " << RAND_MAX << " " << std::endl;
	    // std::cout << (rand() > RAND_MAX) << std::endl;
	    dropout_mask[l] = (2.0*(double)rand() > (double)RAND_MAX);
	    layer_1[l] *= dropout_mask[l]; //2 comes from the fact that the sum will be 1/2 after the dropout
	    layer_1[l] *= 2; //2 comes from the fact that the sum will be 1/2 after the dropout
	  }	
	}

	// print_vector(dropout_mask);
	
	// print_sum(layer_1, "layer_1");

	std::vector<double> layer_2 = matrix_multiplication(layer_1,weights_1_2);
	std::vector<double> layer_2_delta(layer_2.size());

	for (int j = 0; j < layer_2.size(); j++){
	  layer_2_delta[j] = -(layer_2[j] - training_1hot_labels[i][j]);
	  error += layer_2_delta[j]*layer_2_delta[j];	  
	}

	// print_sum(layer_2, "layer_2");
	// print_sum(layer_2_delta, "layer_2_delta");
	
	double layer_2_max = 0.;
	int layer_2_max_i = 0;
	double onehot_max = 0.;
	int onehot_max_i = 0;
	for (int m = 0; m < layer_2.size(); m++){
	  if (layer_2[m] > layer_2_max){
	    layer_2_max = layer_2[m];
	    layer_2_max_i = m;
	  }
	  if(training_1hot_labels[i][m] > onehot_max){
	    onehot_max = training_1hot_labels[i][m];
	    onehot_max_i = m;
	  }
	}
	correct_count += (layer_2_max_i == onehot_max_i);

	

	
	std::vector<double> relu_deriv_layer_1(layer_1.size());
	// double rdl1_sum = 0.;
	for (int l = 0; l < layer_1.size(); l++){
	  relu_deriv_layer_1[l] = relu_deriv(layer_1[l]);

	  if (using_dropout){
	    relu_deriv_layer_1[l] *= dropout_mask[l];
	  }
	  // rdl1_sum +=	  relu_deriv_layer_1[l];
	}
	// std::cout << "relu_deriv_layer_1 sum = " << rdl1_sum << std::endl;

	// std::vector<double> test = matrix_multiplication(layer_2_delta, weights_1_2, 1 /*tranpose*/);
	// double test_sum = 0.;
	// for (int l = 0; l < test.size(); l++){
	//   test_sum += test[i];
	// }
	// std::cout << " test_sum = " << test_sum << std::endl;

	
	std::vector<double> layer_1_delta = vector_component_mult(matrix_multiplication(layer_2_delta, weights_1_2, 1 /*tranpose*/), relu_deriv_layer_1 /*really relu_deriv(layer_1)*/);
	// print_sum(layer_1_delta, "layer_1_delta");
	// double l1d_sum = 0.;
	// for (int l = 0; l < layer_1_delta.size(); ++l) {
	//   l1d_sum += layer_1_delta[l];
	// }
	// std::cout << "layer 1 delta sum = " << l1d_sum << std::endl;



	
	// double weights_1_2_sum = 0.;
	for (int l = 0; l < num_labels; l++){
	  for(int j = 0; j < hidden_layer_size; j++){
	    weights_1_2[j][l] += alpha * layer_1[j]*layer_2_delta[l];
	    // weights_1_2_sum += weights_1_2[j][l];
	  }
	}
	// std::cout << "weights_1_2_sum = " << weights_1_2_sum << std::endl;
	
	// double max_temp = -1;
	// double weights_0_1_sum = 0.;
	for (int l = 0; l < hidden_layer_size; l++){
	  for(int j = 0; j < pixels_per_image; j++){
	    weights_0_1[j][l] += alpha * unsigned(dataset.training_images[i][j])*layer_1_delta[l]/255.0;
	    // weights_0_1_sum += weights_0_1[j][l];
	  }
	}
	// std::cout << "weights_0_1_sum = " << weights_0_1_sum << std::endl;

	

	// print_matrix(weights_1_2);
	// std::cout << "\n\n";
	// std::cout << "max element weights 0 1 = " << max_temp << std::endl;
	// print_matrix(weights_0_1);
	
	// break;
	// std::cout << "training image = " << i << std::endl;
      }
      if (k % 10 == 0){
	// std::cout << "\n\n";
	std::cout << std::setprecision(5);
	std::cout << "iter = " << k;
	std::cout << ", Train error = " << error/1000.0;
	std::cout << ", Train acc = " << correct_count/1000.0;

	int test_count = 0;
	double test_error = 0.0;
	for (int t = 0; t < test_1hot_labels.size(); t++){
	  std::vector<double> pred = predict(dataset.test_images[t], weights_0_1, weights_1_2);
	  test_count += check_prediction(pred, test_1hot_labels[t]);
	  test_error += compute_error(pred, test_1hot_labels[t]);
	}
	std::cout << ", Test error = " << test_error/test_1hot_labels.size();
	std::cout << ", Test acc = " << test_count/(double)test_1hot_labels.size();	
	std::cout << "\n";
	std::cout.flush();
      }
      // std::cout << "correct count = " << correct_count << std::endl;
    }
    return 0;
}

