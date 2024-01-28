cmake_minimum_required(VERSION 3.5)

project(Thv_1_Olio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Thv_1_Olio main.cpp)

include(GNUInstallDirs)
install(TARGETS Thv_1_Olio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
