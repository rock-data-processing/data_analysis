#include "rms.hpp"

using namespace std;

namespace data_analysis {

RMS::RMS(int window_size, bool acc) :
    sum(0),
    queue(Queue(window_size)),
    n_data(0),
    accumulate(acc){
}

double RMS::update(const base::VectorXd& input_data){

    if(queue.queueSize() == numeric_limits<int>::max()){
        sum += input_data.squaredNorm();
        n_data++;
    }
    else{
        queue.pushShift(input_data);
        n_data = queue.size();

        sum = 0;
        for(uint i = 0; i < queue.size(); i++)
            sum += queue[i].squaredNorm();

    }
    if(accumulate)
        return sqrt(sum);
    else
        return sqrt(sum / (double)n_data);
}

}


