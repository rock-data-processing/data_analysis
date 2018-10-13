#ifndef RMS_HPP
#define RMS_HPP

#include "queue.hpp"

namespace data_analysis {

class RMS{
 protected:
    double sum;
    Queue queue;
    int n_data;
    bool accumulate;

public:
    RMS(int window_size, bool accumulate = false);
    ~RMS(){}

    double update(const base::VectorXd& input_data);
    int nData(){return n_data;}
};

}

#endif
