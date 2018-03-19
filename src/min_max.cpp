#include "min_max.hpp"

using namespace std;

namespace data_analysis {

MinMax::MinMax(int window_size) :
     queue(Queue(window_size)){

    min =  std::numeric_limits<double>::infinity();
    max = -std::numeric_limits<double>::infinity();
}

void MinMax::update(const base::VectorXd &input_data, double& _min, double &_max){

    if(queue.queueSize() == numeric_limits<int>::max()){
        min = std::min(input_data.minCoeff(), min);
        max = std::max(input_data.maxCoeff(), max);
    }
    else{
        queue.pushShift(input_data);

        for(size_t i = 0; i < queue.size(); i++){
            min = std::min(queue[i].minCoeff(), min);
            max = std::max(queue[i].maxCoeff(), max);
        }
    }

    _min = min;
    _max = max;
}

}
