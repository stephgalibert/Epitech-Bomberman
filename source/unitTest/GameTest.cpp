//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:53:04 2016 avelin_j
//

#include "Game.hpp"
#include "gtest.h"

class GameTest : public::testing::Test
{
public:
  GameTest()
  {
  }

  virtual ~GameTest()
  {
  }

  bbman::Game t;
};

TEST_F(GameTest, leaveGameAssert) {
  ASSERT_EQ(0, t.leaveGame());
}

TEST_F(GameTest, BoardAssert) {
  ASSERT_FALSE(t.testGetBoard() == NULL);
}

TEST_F(GameTest, TimeOutAssert) {
  ASSERT_TRUE(t.testGetTimeOut() == NULL);
}
