#include "rms.hpp"

using namespace std;

namespace data_analysis {

RMS::RMS() :
    window_size(numeric_limits<int>::max()){

}

double RMS::update(const base::VectorXd& input_data){

    if(window_size == std::numeric_limits<int>::max()){
        sum += input_data.squaredNorm();
        n_data++;
    }
    else{
        if(queue.size() < window_size) // Fill the queue, if it is not filled yet
            queue.conservativeResize(queue.rows()+1);
        else // Shift queue up
            queue.block(0, 0, queue.rows() - 1, 1) = queue.block(1, 0, queue.rows(), 1);

        queue(queue.rows()-1) = input_data.squaredNorm();
        sum = 0;
        for(int i = 0; i < queue.size(); i++)
            sum += queue(i)*queue(i);
        n_data = queue.size();
    }
    return sqrt(sum / (double)n_data);
}

}


