cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(fyp_implementation)
set(EXECUTABLE fyp_implementation)
set(WARNINGS "-Wall -Wextra -Werror -Wshadow -Weffc++ -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS} -std=c++11 -stdlib=libc++")
set(SOURCE_FILES src/main.cpp
                 src/Application.cpp)

# Change to reflect location of SFML libaries and header files
set(SFML_DIR /usr/local/Cellar/sfml/2.1)

# Change to reflect desired SFML version and file extension native to platform
set(SFML_EXT .2.1.dylib)

set(SFML_SYSTEM   ${SFML_DIR}/lib/libsfml-system${SFML_EXT})
set(SFML_WINDOW   ${SFML_DIR}/lib/libsfml-window${SFML_EXT})
set(SFML_GRAPHICS ${SFML_DIR}/lib/libsfml-graphics${SFML_EXT})
set(SFML_AUDIO    ${SFML_DIR}/lib/libsfml-audio${SFML_EXT})
set(SFML_NETWORK  ${SFML_DIR}/lib/libsfml-network${SFML_EXT})

include_directories(SYSTEM ${SFML_DIR}/include)
add_executable(${EXECUTABLE} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE} ${SFML_GRAPHICS} ${SFML_WINDOW} ${SFML_SYSTEM})