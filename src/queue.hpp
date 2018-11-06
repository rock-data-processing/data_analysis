#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <base/Eigen.hpp>
#include <vector>

namespace data_analysis{

class Queue : public std::vector<base::VectorXd>{
protected:
    uint queue_size;
    std::vector<double> raw;
public:
    Queue(){}
    Queue(const uint queue_size);
    ~Queue();

    void pushShift(const base::VectorXd &data);
    void pushShift(const double &data);
    uint queueSize(){return queue_size;}
    const std::vector<double> &rawData();
};

}

#endif
