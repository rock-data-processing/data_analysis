#ifndef __SGSMOOTH_HPP__
#define __SGSMOOTH_HPP__

#include <vector>

class SGDerivative{
protected:
    int window_size;
    int queue_size;
    int poly_degree;
    std::vector<double> queue;
    std::vector<double> deriv_out;
public:
    /**
     * @brief Default constructor
     * @param window_size Size of the sliding window used internally by the filter. The higher this value, the bigger the sample delay, but the smoother the output
     * @param poly_degree Degree of the polynomial that is fitted into the data. The bigger this value, the more complex data can be fitted, but the slower the computation.
     */
    SGDerivative(int window_size, int poly_degree);
    ~SGDerivative(){}

    void Process(const double &data_in, double& derivative);

};

// savitzky golay smoothing.
std::vector<double> sg_smooth(const std::vector<double> &v, const int w, const int deg);
//! numerical derivative based on savitzky golay smoothing.
std::vector<double> sg_derivative(const std::vector<double> &v, const int w,
                                const int deg, const double h=1.0);

#endif // __SGSMOOTH_HPP__
