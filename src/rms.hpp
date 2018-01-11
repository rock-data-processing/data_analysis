#ifndef RMS_HPP
#define RMS_HPP

#include <base/Eigen.hpp>

namespace data_analysis {

class RMS{
    int window_size;
    double sum;
    int n_data;
    base::VectorXd queue;
    base::VectorXd input_data;

public:
    RMS();
    ~RMS(){}

    void setWindowSize(int w){window_size=w;}
    double update(const base::VectorXd& input_data);
};

}

#endif
