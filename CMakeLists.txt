cmake_minimum_required(VERSION 3.15)

project(FixPOC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QUICKFIX_ROOT "C:/quickfix-poc/quickfix")
set(QUICKFIX_INCLUDE "${QUICKFIX_ROOT}/src/C++")
set(QUICKFIX_LIBRARY "${QUICKFIX_ROOT}/lib/quickfix.lib")

include_directories(
    "${QUICKFIX_INCLUDE}"
)

add_executable(fix_acceptor
    src/acceptor.cpp
    src/Application.cpp
)

add_executable(fix_initiator
    src/initiator.cpp
    src/Application.cpp
)

target_link_libraries(
    fix_acceptor
    "${QUICKFIX_LIBRARY}"
    ws2_32
)

target_link_libraries(
    fix_initiator
    "${QUICKFIX_LIBRARY}"
    ws2_32
)