//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:51:42 2016 avelin_j
//

#include "TimeOut.hpp"
#include "gtest.h"

class IndestructibleBlockTest : public::testing::Test
{
public:
  IndestructibleBlockTest()
  {
  }

  virtual ~IndestructibleBlockTest()
  {
  }

  bbman::IndestructibleBlock t;
};

TEST_F(IndestructibleBlockTest, nodeAssert) {
  ASSERT_TRUE(t.testGetNode() == NULL);
}
