#ifndef SG_DERIVATIVE_HPP
#define SG_DERIVATIVE_HPP

#include "sg.hpp"
#include "queue.hpp"

namespace data_analysis {

class SGDerivative{
protected:
    int window_size;
    int poly_degree;
    Queue queue;
    std::vector<double> deriv_out;

    void queueColumn(uint idx, std::vector<double> &col);
public:
    /**
     * @brief Default constructor
     * @param window_size Size of the sliding window used internally by the filter. The higher this value, the bigger the sample delay, but the smoother the output
     * @param poly_degree Degree of the polynomial that is fitted into the data. The bigger this value, the more complex data can be fitted, but the slower the computation.
     */
    SGDerivative(int window_size, int poly_degree);
    ~SGDerivative(){}

    void Process(const double& data, double& derivative);

};

}

#endif
