//
// MemoryFileTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/utils
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 23:00:23 2016 avelin_j
// Last update Sat Jun  4 23:13:33 2016 avelin_j
//

#include "MemoryFile.hpp"
#include "gtest.h"

class MemoryFileTest : public::testing::Test
{
public:
  MemoryFileTest()
  {
  }

  virtual ~MemoryFileTest()
  {
  }

  bbman::MemoryFile t;
};

TEST_F(MemoryFileTest, sizeAssert) {
  ASSERT_EQ(t.size, 0);
}

TEST_F(MemoryFileTest, runningAssert) {
  ASSERT_TRUE(t.data == NULL);
}

TEST_F(MemoryFileTest, filenameAssert) {
  ASSERT_TRUE(t.filename == "");
}
