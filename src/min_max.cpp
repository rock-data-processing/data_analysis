#include "min_max.hpp"

using namespace std;

namespace data_analysis {

MinMax::MinMax(int window_size) :
    window_size(window_size){

    min =  std::numeric_limits<double>::infinity();
    max = -std::numeric_limits<double>::infinity();
}

void MinMax::update(base::VectorXd &input_data, double& _min, double &_max){

    if(window_size == numeric_limits<int>::max()){
        min = std::min(input_data.minCoeff(), min);
        max = std::max(input_data.maxCoeff(), max);
    }
    else{
        if(queue.size() < window_size) // Fill the queue, if it is not filled yet
            queue.conservativeResize(queue.rows()+1, queue.cols());
        else // Shift queue up
            queue.block(0, 0, queue.rows() - 1, queue.cols()) = queue.block(1, 0, queue.rows(), queue.cols());

        queue.block(queue.rows()-1,0,queue.rows(), queue.cols()) = input_data.transpose();
        min = queue.minCoeff();
        max = queue.maxCoeff();
    }

    _min = min;
    _max = max;
}

}
