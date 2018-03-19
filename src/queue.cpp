#include "queue.hpp"

namespace data_analysis {

Queue::Queue(const uint queue_size) :
    queue_size(queue_size){

}

Queue::~Queue(){
}

void Queue::pushShift(const base::VectorXd &data){
    if(size() < queue_size){ // Fill the queue, if it is not filled yet
        push_back(data);
    }
    else{ // Shift queue up
        for(size_t i = 1; i < size(); i++)
            at(i-1) = at(i);
        at(size()-1) = data;
    }
}

void Queue::pushShift(const double &data){
    base::VectorXd tmp;
    tmp << data;
    pushShift(tmp);
}

const std::vector<double> &Queue::rawData(){
    if(empty())
        return std::vector<double>();

    raw.resize(size()*at(0).size());
    uint idx = 0;
    for(size_t i = 0; i < size(); i++){
        for(int j = 0; j < at(i).size(); j++)
            raw[idx++] = at(i)(j);
    }
    return raw;
}

}
