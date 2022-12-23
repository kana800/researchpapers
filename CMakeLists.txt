cmake_minimum_required(VERSION 3.8)

project(ResearchPapers C)

# adding the code directory
add_subdirectory(code)
# adding the testing directory
add_subdirectory(external/check)
add_subdirectory(tests)
