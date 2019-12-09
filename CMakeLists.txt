cmake_minimum_required(VERSION 3.15)

project( NameAnalyzer
         VERSION 0.0.1
         DESCRIPTION "An experiment!"
         LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a" )

# Release MinSizeRel
set(CMAKE_BUILD_TYPE Release)

# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set(EXE_NAME
${PROJECT_NAME}
) 

set(LIB_NAME
${PROJECT_NAME}_lib
)

set(TEST_EXE_NAME
${PROJECT_NAME}_test
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(include_directories)
include(local)
# include(test)