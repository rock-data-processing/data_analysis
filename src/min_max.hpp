#ifndef MIN_MAX_HPP
#define MIN_MAX_HPP

#include "queue.hpp"

namespace data_analysis {

class MinMax{
protected:
    double min, max;
    Queue queue;
public:
    MinMax(int window_size);
    ~MinMax(){}

    void update(const base::VectorXd &input_data, double& min, double &max);
};

}

#endif // MIN_MAX_HPP
