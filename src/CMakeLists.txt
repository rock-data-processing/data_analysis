rock_library(data_analysis
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(data_analysis_bin Main.cpp
    DEPS data_analysis)

