cmake_minimum_required(VERSION 2.8)
project(GBVS)
if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
add_executable(GBVS MACOSX_BUNDLE GBVSImpl.cxx )
target_link_libraries(GBVS ${ITK_LIBRARIES})