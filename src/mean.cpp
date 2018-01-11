#include "mean.hpp"
#include <iostream>

using namespace std;

namespace data_analysis {

Mean::Mean(int window_size) :
    window_size(window_size){

    sum.setZero();
    sqrt_sum.setZero();
}

void Mean::update(const base::VectorXd& input_data, base::VectorXd& mean, base::VectorXd& std_dev){
    if(window_size == numeric_limits<int>::max()){
        sum += input_data;
        n_data++;
        mean = sum / (double)n_data;

        sqrt_sum += (input_data - mean) * (input_data - mean);
        std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
    }
    else{
        if((int)queue.size() < window_size) // Fill the queue, if it is not filled yet
            queue.push_back(input_data);
        else{ // Shift queue up
            for(size_t i = 1; i < queue.size(); i++)
                queue[i-1] = queue[i];
            queue[queue.size()-1] = input_data;
        }

        sum.setZero();
        sqrt_sum.setZero();
        n_data = queue.size();

        for(size_t i = 0; i < queue.size(); i++)
            sum += queue[i];
        mean = sum / (double)n_data;

        for(size_t i = 0; i < queue.size(); i++)
            sqrt_sum += (queue[i] - mean) * (queue[i] - mean);
        std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
    }
}

}


