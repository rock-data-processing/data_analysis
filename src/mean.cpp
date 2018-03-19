#include "mean.hpp"
#include <iostream>

using namespace std;

namespace data_analysis {

Mean::Mean(int window_size) :
    queue(Queue(window_size)),
    n_data(0){
}

void Mean::update(const base::VectorXd& input_data, base::VectorXd& mean, base::VectorXd& std_dev){
    if(queue.queueSize() == numeric_limits<int>::max()){
        if(sum.size() == 0)
            sum.setConstant(input_data.size(), 0);
        if(sqrt_sum.size() == 0)
            sqrt_sum.setConstant(input_data.size(), 0);

        sum += input_data;
        n_data++;
        mean = sum / (double)n_data;

        sqrt_sum += (input_data - mean).cwiseProduct(input_data - mean);
        if(n_data > 1)
            std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
        else
            std_dev.setZero(input_data.size());
    }
    else{
        queue.pushShift(input_data);

        sum.setConstant(input_data.size(), 0);
        sqrt_sum.setConstant(input_data.size(), 0);

        n_data = queue.size();

        for(int i = 0; i < n_data; i++)
            sum += queue[i];
        mean = sum / (double)n_data;

        for(int i = 0; i < n_data; i++)
            sqrt_sum += (queue[i] - mean).cwiseProduct(queue[i] - mean);
        if(n_data > 1)
            std_dev = (sqrt_sum / ((double)n_data-1)).cwiseSqrt();
        else
            std_dev.setZero(input_data.size());
    }
}

}


