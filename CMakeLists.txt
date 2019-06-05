cmake_minimum_required (VERSION 3.0)
project(keybench CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(cotire)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (PRIMARY_SRC
	${PROJECT_SOURCE_DIR}/src/hlp.cpp
    )

set(CHAR_SRC
	#${PROJECT_SOURCE_DIR}/src/char/inventory.cpp
    )

set(ETC_SRC
	#${PROJECT_SOURCE_DIR}/src/etc/conf.cpp
    )

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${CHAR_SRC}
    ${PRIMARY_SRC}
    ${ETC_SRC}
)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#target_link_libraries(${PROJECT_NAME} lib)
target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG ${PLATFORM_DEFS})

#add_subdirectory(tests)
target_link_libraries(${PROJECT_NAME} PRIVATE
	stdc++fs
	)

cotire(keybench)

#add_custom_command(TARGET fallout_main PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory bin)
#add_custom_command(TARGET fallout_main PRE_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory lib)
