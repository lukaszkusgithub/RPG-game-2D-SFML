cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME RPG)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

file(GLOB source_files
        RPG
        *.cpp
        *.h
        headers/*.h
        src/*.cpp
        Characters/*.cpp
        Characters/*.h
        States/*.cpp
        States/*.h
        Enemies/*.cpp
        Enemies/*.h
        NPC/*.cpp
        NPC/*.h
        GUI/*.cpp
        GUI/*.h)

set(SOURCES ${source_files})

add_executable(${PROJECT_NAME} ${SOURCES})

# LOCAL
if (UNIX)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_INCLUDE_DIR "/SFML/include")
    set(SFML_DIR "/SFML/build")
    set(SFML_LIBRARY_DIR "/SFML/build/lib")
    set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

    link_directories(SFML_DIR)
    link_directories(SFML_LIBRARY_DIR)
    include_directories(SFML_INCLUDE_DIR)

    find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
    target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)
    target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
endif()



if (WIN32)
    set(SFML_DIR C:/SFML/lib/cmake/SFML)
    find_package(SFML COMPONENTS system window graphics audio REQUIRED)
    if (SFML_FOUND)
        include_directories(C:/SFML/include)
        target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
    endif()

    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})

endif()

file(COPY config DESTINATION ${CMAKE_BINARY_DIR})
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

