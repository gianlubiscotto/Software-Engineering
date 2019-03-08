cmake_minimum_required (VERSION 2.8.11)

project (myhypro_template)

#set(${PROJECT_NAME}_MAJORVERSION 17)

#set(${PROJECT_NAME}_MINORVERSION 09)

#set(${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_MAJORVERSION}.${${PROJECT_NAME}_MINORVERSION}")



# sets the directories (in your projects build folder) where the output is put in.

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# creates the executable, which will be build out of the source files

#Must have installed hypro
add_executable(myhypro_template main-hypro.cpp basic.tpp IR.tpp UIR.tpp BR.tpp DAG.tpp DAG-cmp.tpp DAG-cover.tpp DAG-sum.tpp DAG-make.tpp DAG-cover-hypro.tpp DAG-make-hypro.tpp)


# compiler flags

add_definitions(-std=c++14 -Wall -Wextra -Wpedantic)



# for apple systems

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

endif()



# header files - put your folders with header files here (list, separated by blanks)

include_directories(include src/templates) 



# find hypro and include it (it's already registered with cmake, so no find script required)

find_package(hypro REQUIRED)



include_directories(${hypro_INCLUDE_DIR})

include_directories(${hypro_INCLUDE_DIRS})

message(STATUS "Hypro include dir: " ${hypro_INCLUDE_DIR})

message(STATUS "Hypro include dirs: " ${hypro_INCLUDE_DIRS})

message(STATUS "Hypro library: " ${hypro_LIBRARIES})



set(LIBRARIES ${LIBRARIES} ${Boost_LIBRARIES} ${GMP_LIBRARY} ${GMPXX_LIBRARY})



MESSAGE(STATUS "Linking to libs:" ${LIBRARIES})



# linking against libraries

target_link_libraries(myhypro_template PUBLIC hypro ${LIBRARIES})
