#include "sigmoid.hpp"
#include <math.h>

namespace data_analysis {

double Sigmoid::compute(const double &input_data){
    return params.lower_asymptote + (params.upper_asymptote - params.lower_asymptote)/(1 + params.initial_value*exp(-params.growth_rate*(input_data - params.hor_shift)));
}

}


