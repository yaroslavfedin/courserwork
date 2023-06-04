cmake_minimum_required(VERSION 3.10)

# Установка имени проекта
project(ChessGame)

# Установка переменной пути к cmake файлам SFML
set(SFML_DIR "C:/Programs/vcpkg/installed/x64-windows/share/sfml")

# Добавление исполняемого файла
add_executable(ChessGame main.cpp)

# Добавление заголовочных файлов
target_include_directories(ChessGame PRIVATE headers)

# Добавление библиотеки SFML
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(ChessGame PRIVATE sfml-graphics)

# Установка файлов в систему
install(TARGETS ChessGame DESTINATION bin)
install(DIRECTORY images DESTINATION bin)
install(DIRECTORY datas DESTINATION bin)

# Копирование файло из корневой директории проекта в папку с Release версией сборки
set(IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)
file(COPY ${IMAGES_DIR} DESTINATION ${CMAKE_BINARY_DIR}/release)

set(DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/datas)
file(COPY ${DATA_DIR} DESTINATION ${CMAKE_BINARY_DIR}/release)

# Установка необходимых библиотек и заголовочных файлов
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/lib/libsfml-graphics.a" DESTINATION lib)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/headers" DESTINATION include)