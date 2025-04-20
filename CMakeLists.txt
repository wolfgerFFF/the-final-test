cmake_minimum_required(VERSION 3.10.0)
project(projects_1 VERSION 0.1.0 LANGUAGES CXX)  # Убрали C, если не используете

# Установка стандарта C++ (важно для вашего кода)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Для MinGW (если используете)
if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif()

# Добавляем папку с заголовочными файлами
include_directories(
    ${CMAKE_SOURCE_DIR}/inc  # Если .h файлы в папке inc
    ${CMAKE_SOURCE_DIR}/src  # Если .h файлы в папке src
)

# Исходные файлы
file(GLOB SOURCES
    "src/*.cpp"
    "main.cpp"
)

# Создаем исполняемый файл
add_executable(projects_1 ${SOURCES})

# Для Windows (если нужно)
if(WIN32)
    target_link_libraries(projects_1)
endif()