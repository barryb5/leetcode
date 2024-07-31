cmake_minimum_required (VERSION 3.1.0)
project (leetcode)

# Set Configuration specific DEFINES
IF ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
  add_definitions ( "-DUSE_PERFORMANCE_DATA")
  add_definitions ( "-DDEBUG " )
  add_definitions ( "-D_DEBUG " )
  add_definitions ( "-std=c++20")
  add_definitions ( "-rdynamic ")
  add_definitions ( "-g ")

  add_definitions ( "-Wno-deprecated ")
  add_definitions ( "-Wno-unknown-pragmas ")

ELSE()
  add_definitions ( "-Wall ")
  add_definitions ( "-DNDEBUG " )
  add_definitions ( "-DUSE_PERFORMANCE_DATA")
  add_definitions ( "-O3 ")
  add_definitions ( "-std=c++20")
  add_definitions ( "-march=native ")
  add_definitions ( "-mtune=native ")
  add_definitions ( "-Wno-deprecated ")
  add_definitions ( "-Wno-unknown-pragmas ")
  add_definitions ( "-rdynamic ")
  add_definitions ( "-g ")
ENDIF()

add_executable(two_sum
    l01_two_sum.cpp)

add_executable(remove_duplicates_from_sorted
  l26_remove_duplicates_from_sorted.cpp)

add_executable(remove_element
  l27_remove_element.cpp)

add_executable(search_insert_position
  l35_search_insert_position.cpp)

add_executable(plus_one
  l66_plus_one.cpp)

add_executable(merge_sorted_array
  l88_merge_sorted_array.cpp)

add_executable(convert_array_to_binary_search_tree
  l108_convert_sorted_array_to_binary_search_tree.cpp)

add_executable(pascals_triangle
  l118_pascals_triangle.cpp)

add_executable(container_with_most_water
  l11_container_with_most_water.cpp)

add_executable(next_permutation
  l31_next_permutation.cpp)