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

add_executable(sort_the_people
  l2418_sort_the_people.cpp)

add_executable(search_in_rotated_sorted_array
  l31_search_in_rotated_sorted_array.cpp)

add_executable(valid_sudoku
  l36_valid_sudoku.cpp)

add_executable(count_and_say
  l38_count_and_say.cpp)

add_executable(add_two_numbers
  l2_add_two_numbers.cpp)

add_executable(longest_substring_without_repeating_characters
  l3_longest_substring_without_repeating_characters.cpp)

add_executable(first_occurrence_of_string_in_string
  l28_first_occurrence_of_string_in_string.cpp)

add_executable(combination_sum
  l39_combination_sum.cpp)

add_executable(length_of_last_word
  l58_length_of_last_word.cpp)

add_executable(kth_distinct_string_in_an_array
  l2053_kth_distinct_string_in_an_array.cpp)

add_executable(integer_to_roman
  l12_integer_to_roman.cpp)

add_executable(letter_combinations_of_a_phone_number
  l17_letter_combinations_of_a_phone_number.cpp)

add_executable(minimum_number_of_pushes_to_type_word_II
  l3016_minimum_number_of_pushes_to_type_word_II.cpp)

add_executable(roman_to_integer
  l13_roman_to_integer.cpp)

add_executable(permutations
  l46_permutations.cpp)

add_executable(valid_palindrome
  l125_valid_palindrome.cpp)

add_executable(rotate_list
  l61_rotate_list.cpp)

add_executable(sort_colors
  l75_sort_colors.cpp)

add_executable(remove_nth_node_from_end_of_list
  l19_remove_nth_node_from_end_of_list.cpp)

add_executable(sqrt
  l69_sqrt.cpp)

add_executable(search_in_rotated_array_II
  l81_search_in_rotated_array_II.cpp)

add_executable(group_anagrams
  l49_group_anagrams.cpp)

add_executable(lemonade_change
  l860_lemonade_change.cpp)