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
  for (int i = 0; i < data.size(); i++){4
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

double tanh_deriv(double tanhx){
  return 1 - tanhx*tanhx;
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
    layer_1[l] = tanh(layer_1[l]/255.);
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

    double alpha = 2;
    int iterations = 300;
    int hidden_layer_size = 100;
    int pixels_per_image = 784;
    int num_labels = 10;

    std::vector<std::vector<double>> weights_0_1(pixels_per_image);
    for (int i = 0; i < pixels_per_image; i++){
      weights_0_1[i].resize(hidden_layer_size);
      for (int j = 0; j < hidden_layer_size; j++){
    	// weights_0_1[i][j] = 0.1*sin((i+j)*M_PI/4.);// 0.2*((double)rand()/(double)RAND_MAX)-0.1;
    	weights_0_1[i][j] =  0.02*((double)rand()/(double)RAND_MAX)-0.01;
	// w01_sum += weights_0_1[i][j];
	}
    }

    std::vector<std::vector<double>> weights_1_2(hidden_layer_size);
    for (int i = 0; i < hidden_layer_size; i++){
      weights_1_2[i].resize(num_labels);
      for (int j = 0; j < num_labels; j++){
    	// weights_1_2[i][j] = 0.1*tanh((i+j)*M_PI/4.);// 0.2*((double)rand()/(double)RAND_MAX)-0.1;
    	weights_1_2[i][j] = 0.2*((double)rand()/(double)RAND_MAX)-0.1;
	}
    }

    int num_batches = 10;
    int batch_size = 100;
    int num_training_images = batch_size*10;

    
    std::cout << std::setprecision(20);
    std::vector<std::vector<double>> layer_1(batch_size);
    std::vector<std::vector<double>> layer_2(batch_size);
    std::vector<std::vector<double>> layer_2_delta(batch_size);
    std::vector<std::vector<double>> layer_1_delta(batch_size);
    std::vector<std::vector<double>> tanh_deriv_layer_1(batch_size);
    std::vector<std::vector<double>> dropout_mask(batch_size);

    for (int l = 0; l < batch_size; l++){
      dropout_mask[l].resize(hidden_layer_size);
      layer_1_delta[l].resize(hidden_layer_size);
      tanh_deriv_layer_1[l].resize(hidden_layer_size);
    }
    
    for (int l = 0; l < batch_size; l++){
      layer_2_delta[l].resize(num_labels);
      layer_2[l].resize(num_labels);
    }



    for (int k = 0; k < 300; k++){
      double error = 0.;
      int correct_count = 0;
      std::cout << "iteration " << k << std::endl;
      for (int batch = 0; batch < num_batches; batch++){


	for (int i = 0; i < batch_size; i++){
	  layer_1[i] = matrix_multiplication(dataset.training_images[i + batch*batch_size],weights_0_1);
	}

	for (int l= 0; l < batch_size; l++){
	  for (int j = 0; j < hidden_layer_size; j++)
	    layer_1[l][j] = tanh(layer_1[l][j]/255.);
	}
	
	if (using_dropout){
	  for (int l= 0; l < batch_size; l++){
	    for (int j = 0; j < hidden_layer_size; j++){
	    dropout_mask[l][j] = (2.0*(double)rand() > (double)RAND_MAX);
	    layer_1[l][j] *= dropout_mask[l][j]; //2 comes from the fact that the sum will be 1/2 after the dropout
	    layer_1[l][j] *= 2; //2 comes from the fact that the sum will be 1/2 after the dropout


	    }
	  }	
	}

	for (int l= 0; l < batch_size; l++){
	  for (int j = 0; j < hidden_layer_size; j++){	
	    tanh_deriv_layer_1[l][j] = tanh_deriv(layer_1[l][j]);
	    if (using_dropout){
	      tanh_deriv_layer_1[l][j] *= dropout_mask[l][j];
	    }
	  }
	}

	for (int i = 0; i < batch_size; i++){
	  layer_2[i] = softmax(matrix_multiplication(layer_1[i],weights_1_2));
	  for (int l = 0; l < num_labels; l++){
	    layer_2_delta[i][l] = -(layer_2[i][l] - training_1hot_labels[batch*batch_size + i][l]);


	    error += layer_2_delta[i][l]*layer_2_delta[i][l];
	    layer_2_delta[i][l] /= ((double)batch_size*(double)hidden_layer_size);
	  }

	  correct_count += check_prediction(layer_2[i], training_1hot_labels[batch*batch_size + i]);
	}

	for (int i = 0; i < batch_size; i++){

	  layer_1_delta[i] = vector_component_mult(matrix_multiplication(layer_2_delta[i], weights_1_2, 1 /*tranpose*/), tanh_deriv_layer_1[i] /*really tanh_deriv(layer_1)*/);
	  for (int l = 0; l < num_labels; l++){
	    for(int j = 0; j < hidden_layer_size; j++){
	      weights_1_2[j][l] += alpha * layer_1[i][j]*layer_2_delta[i][l];
	    }
	  }

	  for (int l = 0; l < hidden_layer_size; l++){
	    for(int j = 0; j < pixels_per_image; j++){
	      weights_0_1[j][l] += alpha * unsigned(dataset.training_images[i + batch*batch_size][j])*layer_1_delta[i][l]/255.0;
	    }
	  }

	}

      }
      if (k % 10 == 0){
      	std::cout << std::setprecision(5);
      	std::cout << "iter = " << k;
      	std::cout << ", Train error = " << error/(double)num_training_images;
      	std::cout << ", Train acc = " << correct_count/(double)num_training_images;

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
    }
    return 0;
}

