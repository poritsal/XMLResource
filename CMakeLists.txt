cmake_minimum_required (VERSION 3.8)

project ("XMLResource")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (XMLResource "main.cpp" "XMLElement.cpp" "XMLElement.h" "XMLResource.cpp" "XMLResource.h")