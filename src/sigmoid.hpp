#ifndef SIGMOID_HPP
#define SIGMOID_HPP

namespace data_analysis {

class Sigmoid{
public:
    Sigmoid();
    ~Sigmoid(){}

    double compute(const double& data_in);
};

}

#endif
