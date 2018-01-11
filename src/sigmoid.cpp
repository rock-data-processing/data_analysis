#include "sigmoid.hpp"
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

namespace data_analysis {

double Sigmoid::compute(const double &input_data){
    return params.lower_asymptote + (params.upper_asymptote - params.lower_asymptote)/(1 + params.initial_value*exp(-params.growth_rate*(input_data - params.hor_shift)));
}

void Sigmoid::writeToFile(string const & filename, double range_min, double range_max, double step_size){
    ofstream file;
    file.open(filename.c_str());
    for(double x = range_min; x <= range_max; x += step_size)
        file << x << " " << compute(x) << std::setprecision(16) << std::endl;
    file.close();
}


}


