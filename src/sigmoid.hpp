#ifndef SIGMOID_HPP
#define SIGMOID_HPP

#include <string>

namespace data_analysis {

/** Parameters defining a 1-dim. Sigmoid function*/
struct SigmoidParams{
    SigmoidParams() :
        lower_asymptote(0.0),
        upper_asymptote(1.0),
        growth_rate(1.0),
        hor_shift(0.0),
        initial_value(1.0){}

    /** The lower Asymptote of the Sigmoid function*/
    double lower_asymptote;
    /** The upper Asymptote of the Sigmoid function*/
    double upper_asymptote;
    /** The growth rate of the Sigmoid function*/
    double growth_rate;
    /** The Horizontal shift of the Sigmoid function*/
    double hor_shift;
    /** The initial value  of the Sigmoid function*/
    double initial_value;
};

class Sigmoid{
protected:
    SigmoidParams params;
public:
    Sigmoid(){}
    ~Sigmoid(){}

    void setParams(const SigmoidParams& p){params = p;}
    double compute(const double& input_data);
    void writeToFile(std::string const &filename, double range_min, double range_max, double step_size);
};

}

#endif
