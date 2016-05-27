cmake_minimum_required(VERSION 3.5)
PROJECT(LuaSample)

# CXXFLAGS += -I ../../lib/lua/LuaInterpreter/include
# CXXFLAGS += -I ../../lib/lua/LuaBridge/
# CXXFLAGS += -I ../../lib/lua/LuaBridge/detail
INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaInterpreter/include
  ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaBridge/
  ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaBridge/detail
)

FILE(GLOB SRCS
    *.cpp
    *.hpp
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaInterpreter/include/*
    ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaBridge/*
    ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaBridge/detail/*
  )

ADD_EXECUTABLE(sampleLua ${SRCS})

TARGET_LINK_LIBRARIES(sampleLua
  -Wl,-rpath,${PROJECT_SOURCE_DIR}/../../lib/lua/LuaInterpreter/lib
  ${PROJECT_SOURCE_DIR}/../../lib/lua/LuaInterpreter/lib/liblua.so
  -ldl
  # ${PROJECT_SOURCE_DIR}/../lib/lua/LuaInterpreter/lib/lua5.3.2.lib
)
