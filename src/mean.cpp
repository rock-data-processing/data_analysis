#include "mean.hpp"
#include <iostream>

using namespace std;

namespace data_analysis {

Mean::Mean(int window_size) :
    queue(Queue(window_size)){

    sum.setZero();
    sqrt_sum.setZero();
}

void Mean::update(const base::VectorXd& input_data, base::VectorXd& mean, base::VectorXd& std_dev){
    if(queue.queueSize() == numeric_limits<int>::max()){
        sum += input_data;
        n_data++;
        mean = sum / (double)n_data;

        sqrt_sum += (input_data - mean) * (input_data - mean);
        std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
    }
    else{
        queue.pushShift(input_data);

        sum.setZero();
        sqrt_sum.setZero();

        for(size_t i = 0; i < queue.size(); i++)
            sum += queue[i];
        mean = sum / (double)queue.size();

        for(size_t i = 0; i < queue.size(); i++)
            sqrt_sum += (queue[i] - mean) * (queue[i] - mean);
        std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
    }
}

}


