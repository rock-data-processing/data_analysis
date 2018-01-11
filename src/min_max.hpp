#ifndef MIN_MAX_HPP
#define MIN_MAX_HPP

#include <base/Eigen.hpp>

namespace data_analysis {

class MinMax{
protected:
    double min, max;
    int window_size;
    base::MatrixXd queue;
public:
    MinMax(int window_size);
    ~MinMax(){}

    void update(base::VectorXd &input_data, double& min, double &max);
};

}

#endif // MIN_MAX_HPP
