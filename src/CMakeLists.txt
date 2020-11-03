# Archivo CML simple
#
# Version minima requerida de cmake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SyncTimeServer)

# Estandar C++ requerido
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Librerias Boost requeridas
find_package(Boost 1.73 REQUIRED )

# Linkear con pthread
set(CMAKE_CXX_FLAGS "-lpthread")

# Nombre del ejecutable y el (los) fuentes a compilar
add_executable(syncts SyncTimeserver.cpp)

#
# Compilacion:
#
# $ cd <raiz del proyecto>
# $ mkdir bin
# $ cd bin
# $ cmake ../src
# $ cmake --build .
#
