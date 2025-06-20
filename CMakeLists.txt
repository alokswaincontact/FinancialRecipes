cmake_minimum_required(VERSION 3.0)

project(FinancialRecipes CXX)

# Set C++ standard (optional but recommended)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Use -std=c++11 instead of -std=gnu++11 for stricter compliance
set(CMAKE_CXX_EXTENSIONS OFF)

#Add CMakeLists.txt in these directories
add_subdirectory(all_cc_progs)
add_subdirectory(date)
add_subdirectory(security)

# Executable to test financial recipes examples
add_executable(main_examples examples_cc/run_all_examples.cc)
target_link_libraries(main_examples PRIVATE financial_recipes)
target_include_directories(main_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Another Executable to test date and security examples
add_executable(date_examples examples_cc/run_examples.cc)
target_link_libraries(date_examples PRIVATE date_library security_library)
target_include_directories(date_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
