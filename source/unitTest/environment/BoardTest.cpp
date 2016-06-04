//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 18:22:57 2016 avelin_j
//

#include "Board.hpp"
#include "gtest.h"

class BoardTest : public::testing::Test
{
public:
  BoardTest()
  {
  }

  virtual ~BoardTest()
  {
  }

  bbman::Board t;
};

TEST_F(BoardTest, scaleXAssert) {
  ASSERT_TRUE(t.testGetScale().X != 0);
}

TEST_F(BoardTest, scaleYAssert) {
  ASSERT_TRUE(t.testGetScale().Y != 0);
}

TEST_F(BoardTest, scaleZAssert) {
  ASSERT_TRUE(t.testGetScale().Z != 0);
}

TEST_F(BoardTest, sizeXAssert) {
  ASSERT_TRUE(t.testGetSize().X != 0);
}

TEST_F(BoardTest, sizeZAssert) {
  ASSERT_TRUE(t.testGetSize().Z != 0);
}

TEST_F(BoardTest, oddSizeX) {
  int odd = t.testGetSize().X;
  ASSERT_TRUE(odd % 2 == 1);
}

TEST_F(BoardTest, oddSizeZ) {
  int odd = t.testGetSize().X;
  ASSERT_TRUE(odd % 2 == 1);
}
