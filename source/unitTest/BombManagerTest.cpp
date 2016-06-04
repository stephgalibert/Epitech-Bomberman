//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:52:14 2016 avelin_j
//

#include "BombManager.hpp"
#include "gtest.h"

class BombManagerTest : public::testing::Test
{
public:
  BombManagerTest()
  {
  }

  virtual ~BombManagerTest()
  {
  }

  bbman::BombManager t;
};

TEST_F(BombManagerTest, BombManagerAssert) {
  ASSERT_EQ(t.getCurrent(), t.getBombs().end());
}
