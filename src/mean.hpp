#ifndef MEAN_HPP
#define MEAN_HPP

#include "queue.hpp"

namespace data_analysis {

class Mean{
protected:
    Queue queue;

    base::VectorXd sum, sqrt_sum;
    int n_data;

public:
    Mean(int window_size);
    ~Mean(){}

    void update(const base::VectorXd& input_data, base::VectorXd& mean, base::VectorXd& std_dev);
    int nData(){return n_data;}
};

}

#endif
