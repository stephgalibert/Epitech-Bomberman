cmake_minimum_required(VERSION 3.5)
PROJECT(LuaSample)

INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/../lib/lua/LuaInterpreter/include
  ${PROJECT_SOURCE_DIR}/../lib/lua/LuaBridge
)

FILE(GLOB SRCS
    *.cpp
    *.hpp
    ../lib/lua/LuaInterpreter/include/*.h*
  )

ADD_EXECUTABLE(sampleLua ${SRCS})

TARGET_LINK_LIBRARIES(sampleLua
  ${PROJECT_SOURCE_DIR}/../lib/lua/LuaInterpreter/lib/lua5.3.2.lib
)
