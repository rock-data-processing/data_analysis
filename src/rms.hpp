#ifndef RMS_HPP
#define RMS_HPP

#include <base/Eigen.hpp>

namespace data_analysis {

class RMS{
 protected:
    int window_size;
    double sum;
    int n_data;
    base::VectorXd queue;
    base::VectorXd input_data;

public:
    RMS(int window_size);
    ~RMS(){}

    double update(const base::VectorXd& input_data);
    int nData(){return n_data;}
};

}

#endif
