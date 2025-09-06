cmake_minimum_required(VERSION 3.16)
project(NetworkStudy
    VERSION 1.0.0
    LANGUAGES CXX
)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 全局选项
option(ENABLE_WARNINGS "Enable compiler warnings" ON)
option(ENABLE_TESTING "Enable testing" ON)

# 全局警告设置
if(ENABLE_WARNINGS)
    if(MSVC)
        add_compile_options(/W4 /permissive-)
    else()
        add_compile_options(-Wall -Wextra -Wpedantic)
    endif()
endif()

# 子目录
add_subdirectory(01-sample)

# 测试
# if(ENABLE_TESTING)
#     enable_testing()
#     add_subdirectory(tests)
# endif()
