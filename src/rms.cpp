#include "rms.hpp"

using namespace std;

namespace data_analysis {

RMS::RMS(int window_size) :
    window_size(window_size),
    n_data(0){
}

double RMS::update(const base::VectorXd& input_data){

    if(window_size == numeric_limits<int>::max()){
        sum += input_data.squaredNorm();
        n_data++;
    }
    else{
        if(queue.size() < window_size) // Fill the queue, if it is not filled yet
            queue.conservativeResize(queue.rows()+1);
        else // Shift queue up
            queue.segment(0, queue.size() - 1) = queue.segment(1, queue.size() - 1);

        queue(queue.size()-1) = input_data.squaredNorm();
        sum = queue.sum();
        for(int i = 0; i < queue.size(); i++)
            sum += queue(i);
        n_data = queue.size();
    }
    return sqrt(sum / (double)n_data);
}

}


