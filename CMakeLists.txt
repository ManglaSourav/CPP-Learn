cmake_minimum_required(VERSION 3.21)
project(challenges)

set(CMAKE_CXX_STANDARD 14)

add_executable(challenges DS/Single_LL.cpp DS/Arrays.cpp STL/vector.cc)
add_executable(unodered_set STL/unodered_set.cc)
add_executable(map STL/map.cpp)
add_executable(string_tokenisation STL/string_tokenisation.cpp)
add_executable(mystrtok STL/mystrtok.cpp)

add_executable(Longest_mountain_845 Problems/Leetcode/Longest_mountain_845.cpp)
add_executable(Longest_consecative_sequence_128 Problems/Leetcode/Longest_consecative_sequence_128.cpp)

add_executable(Trapping_rain_water_42 Problems/Leetcode/Trapping_rain_water_42.cpp)
add_executable(min_swap_to_sort_array Problems/Others/min_swap_to_sort_array.cpp)
add_executable(space20 Problems/Others/space20.cpp)

add_executable(binary_search_tree DS/binary_search_tree.cpp)

add_executable(Subarray_Sum_Equals_K_560 Problems/Leetcode/Minimum_Size_Subarray_Sum_209.cpp)
add_executable(min_positive_sub_arr Problems/Others/min_positive_sum_sub_arr.cpp)
add_executable(DES_keys Algo/DES_keys.cpp)
add_executable(median_two_sorted_array_4 Problems/Leetcode/median_two_sorted_array_4.cpp)
add_executable(dijkstra Algo/dijkstra.cc)
add_executable(NK_ladder Problems/Others/NK_ladder.cpp)


add_executable(factorial Topics/DP/fibonacci.cpp)
add_executable(Ugly_Number_II_264 Problems/Leetcode/Ugly_Number_II_264.cpp)
