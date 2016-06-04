//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:51:52 2016 avelin_j
//

#include "TimeOut.hpp"
#include "gtest.h"

class DestructibleBlockTest : public::testing::Test
{
public:
  DestructibleBlockTest()
  {
  }

  virtual ~DestructibleBlockTest()
  {
  }

  bbman::DestructibleBlock t;
};

TEST_F(DestructibleBlockTest, nodeAssert) {
  ASSERT_TRUE(t.testGetNode() == NULL);
}

TEST_F(DestructibleBlockTest, explosedAssert) {
  ASSERT_EQ(t.hasExplosed(), 1);
}

TEST_F(DestructibleBlockTest, explosionAssert) {
  ASSERT_TRUE(t.testGetExplosion() == NULL);
}
