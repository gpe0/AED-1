cmake_minimum_required(VERSION 3.20)
project(AED-1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
include_directories(Tests/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(AED-1 main.cpp Tests/Flight.cpp Tests/Flight.h Tests/Plane.cpp
        Tests/Plane.h Tests/Service.cpp Tests/Service.h Tests/Date.cpp Tests/Date.h
        Tests/Person.cpp Tests/Person.h Tests/Worker.cpp Tests/Worker.h Tests/Passenger.cpp
        Tests/Passenger.h Tests/ConstTimeGen.cpp Tests/ConstTimeGen.h Tests/Duration.cpp Tests/Duration.h
        Tests/Bst.h Tests/Location.cpp Tests/Location.h Tests/Carriage.cpp
        Tests/Carriage.h Tests/Luggage.h Tests/Luggage.cpp Tests/Car.h Tests/Car.cpp
        Tests/Schedule.cpp Tests/Schedule.h Tests/TransitStop.cpp Tests/TransitStop.h Tests/Interface.cpp
        Tests/Interface.h Tests/tests.cpp Tests/Airport.cpp Tests/Airport.h)

target_link_libraries(AED-1 gtest gtest_main)


# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

