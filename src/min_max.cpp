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
        if(queue.size() < window_size){ // Fill the queue, if it is not filled yet
            queue.push_back(input_data);
        }
        else{ // Shift queue up
            for(size_t i = 1; i < queue.size(); i++)
                queue[i-1] = queue[i];
            queue[queue.size()-1] = input_data;
        }

        for(size_t i = 0; i < queue.size(); i++){
            min = std::min(queue[i].minCoeff(), min);
            max = std::max(queue[i].maxCoeff(), max);
        }
    }

    _min = min;
    _max = max;
}

}
