cmake_minimum_required(VERSION 3.5.0)
project(Project4 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


set(SFML_DIR "C:/Libraries/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# add_library(GameState GameState.h)
# target_link_libraries(GameState sfml-graphics sfml-audio)

add_executable(Project4 main.cpp)
target_link_libraries(Project4 sfml-graphics sfml-audio)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
