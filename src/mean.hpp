#ifndef MEAN_HPP
#define MEAN_HPP

#include <base/Eigen.hpp>

namespace data_analysis {

class Mean{
protected:
    base::VectorXd sum, sqrt_sum;
    std::vector<base::VectorXd> queue;
    int window_size;
    int n_data;

public:
    Mean(int window_size);
    ~Mean(){}

    void update(const base::VectorXd& input_data, base::VectorXd& mean, base::VectorXd& std_dev);
};

}

#endif
