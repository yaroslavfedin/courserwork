cmake_minimum_required(VERSION 3.10)

# Установка имени проекта
project(ChessGame)

# Установка переменной пути инсталяции файлов
set(CHESS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Chess")

# Добавление исполняемого файла
add_executable(ChessGame main.cpp)

# Добавление заголовочных файлов
target_include_directories(ChessGame PRIVATE headers)

# Добавление библиотеки SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Настройки Doxygen
find_package(Doxygen)

set(DOXYGEN_INPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Chess)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxy/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(
    doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)

# Установка пути к бинарным файлам SFML
if(WIN32)
    set(SFML_RUNTIME_PATH "${SFML_DIR}/../../bin")
elseif(APPLE)
    set(SFML_RUNTIME_PATH "${SFML_DIR}/../../Frameworks") 
else() 
    set(SFML_RUNTIME_PATH "${SFML_DIR}/../../lib")
endif()

target_link_libraries(ChessGame PRIVATE sfml-graphics)

# Установка файлов приложения в директорию инсталяции
install(TARGETS ChessGame DESTINATION ${CHESS_DIR})
install(DIRECTORY images DESTINATION ${CHESS_DIR})
install(DIRECTORY datas DESTINATION ${CHESS_DIR})

# Копирование файло из корневой директории проекта в папку с Release версией сборки
set(IMAGES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)
file(COPY ${IMAGES_DIR} DESTINATION ${CMAKE_BINARY_DIR}/release)

set(DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/datas)
file(COPY ${DATA_DIR} DESTINATION ${CMAKE_BINARY_DIR}/release)

# Установка необходимых библиотек и заголовочных файлов
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/headers" DESTINATION ${CHESS_DIR})

install(DIRECTORY "${SFML_RUNTIME_PATH}/"
  DESTINATION ${CHESS_DIR}
  FILES_MATCHING PATTERN "*sfml*"
)
