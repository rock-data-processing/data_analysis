rock_library(data_analysis
    SOURCES mean.cpp rms.cpp sigmoid.cpp min_max.cpp sg_smooth.cpp
    HEADERS mean.hpp rms.hpp sigmoid.hpp min_max.hpp sg_smooth.hpp
    DEPS_PKGCONFIG base-types)
