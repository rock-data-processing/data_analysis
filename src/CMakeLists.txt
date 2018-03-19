rock_library(data_analysis
    SOURCES mean.cpp rms.cpp sigmoid.cpp min_max.cpp sg.cpp sg_derivative.cpp queue.cpp
    HEADERS mean.hpp rms.hpp sigmoid.hpp min_max.hpp sg.hpp sg_derivative.hpp queue.hpp
    DEPS_PKGCONFIG base-types)
