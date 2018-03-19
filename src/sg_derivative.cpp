#include "sg_derivative.hpp"

namespace data_analysis {

SGDerivative::SGDerivative(int window_size, int poly_degree) :
    window_size(window_size),
    poly_degree(poly_degree){
    queue = Queue(2*window_size + 2);

    if(poly_degree >= window_size)
        throw std::runtime_error("SGFilter: Polynomial degree should be smaller than window size");
    if(window_size < 1)
        throw std::runtime_error("SGFilter: Window size must be >= 1");
    if(poly_degree < 0)
        throw std::runtime_error("SGFilter: Polynomial degree must be >= 0");
}

void SGDerivative::Process(const double& data, double& derivative){
    base::VectorXd tmp;
    tmp << data;
    queue.pushShift(tmp);

    // Compute derivative
    deriv_out = sg_derivative(queue.rawData(), window_size, poly_degree);
    derivative = deriv_out[floor(deriv_out.size()/2)];
}
}
