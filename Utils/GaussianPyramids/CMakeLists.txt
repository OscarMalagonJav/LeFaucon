cmake_minimum_required(VERSION 2.8)
project(ImageConvolution)
if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
add_executable(GaussianPyramids MACOSX_BUNDLE main.cxx GaussianPyramids.cxx GaussianPyramids.h)
target_link_libraries(GaussianPyramids ${ITK_LIBRARIES})
