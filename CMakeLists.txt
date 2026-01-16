cmake_minimum_required(VERSION 3.12)

# 1. Nazwa projektu i język
project(ToDoList)

# 2. Ustawienie standardu C++ (np. C++17 lub C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opcjonalnie: Włącz ostrzeżenia kompilatora (dobre praktyki)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 3. Automatyczne znalezienie wszystkich plików .cpp w folderze src/
# Używamy GLOB_RECURSE, aby przeszukać też podkatalogi wewnątrz src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 4. Utworzenie pliku wykonywalnego
# Zmienna ${PROJECT_NAME} podstawi nazwę zdefiniowaną w punkcie 1 (MojProjekt)
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. Wskazanie folderu z plikami nagłówkowymi (.hpp)
# Dzięki temu w kodzie możesz pisać #include "plik.hpp" zamiast #include "../include/plik.hpp"
target_include_directories(${PROJECT_NAME} PUBLIC include)