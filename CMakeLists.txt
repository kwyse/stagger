cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project(fyp_implementation)
set(EXECUTABLE fyp_implementation)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(WARNINGS "-Wall -Wextra -Wshadow -Weffc++ -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS} -std=c++11")
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()
set(SOURCE_FILES src/main.cpp
                 src/Application.cpp
                 src/fyp/World.cpp
                 src/fyp/BodySprite.cpp)

# Change to reflect location of SFML libaries and header files
set(SFML_DIR /usr/local/Cellar/sfml/2.1)

# Change to reflect desired SFML version and file extension native to platform
set(SFML_EXT .2.1.dylib)

# Change to reflect location of Box2D libraries and header files
set(BOX2D_DIR /usr/local/Cellar/box2d/2.3.0)

# Change to reflect desired Box2D version and file extension native to platform
set(BOX2D_EXT .dylib)

set(SFML_SYSTEM   ${SFML_DIR}/lib/libsfml-system${SFML_EXT})
set(SFML_WINDOW   ${SFML_DIR}/lib/libsfml-window${SFML_EXT})
set(SFML_GRAPHICS ${SFML_DIR}/lib/libsfml-graphics${SFML_EXT})
set(SFML_AUDIO    ${SFML_DIR}/lib/libsfml-audio${SFML_EXT})
set(SFML_NETWORK  ${SFML_DIR}/lib/libsfml-network${SFML_EXT})
set(BOX2D         ${BOX2D_DIR}/lib/libBox2D${BOX2D_EXT})

include_directories(SYSTEM ${SFML_DIR}/include ${BOX2D_DIR}/include)
add_executable(${EXECUTABLE} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE} ${SFML_GRAPHICS} ${SFML_WINDOW} ${SFML_SYSTEM} ${BOX2D})