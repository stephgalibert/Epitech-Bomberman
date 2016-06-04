//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:53:23 2016 avelin_j
//

#include "TimeOut.hpp"
#include "gtest.h"

class TimeOutTest : public::testing::Test
{
public:
  TimeOutTest()
  {
  }

  virtual ~TimeOutTest()
  {
  }

  bbman::TimeOut t;
};

TEST_F(TimeOutTest, BoardAssert) {
  ASSERT_TRUE(t.testGetBoard() == NULL);
}

TEST_F(TimeOutTest, deltaAssert) {
  ASSERT_EQ(t.getDelta(), 0);
}

TEST_F(TimeOutTest, deltaAnimAssert) {
  ASSERT_EQ(t.getDeltaAnim(), 0);
}

TEST_F(TimeOutTest, stepAssert) {
  ASSERT_EQ(t.getStep(), 0);
}

TEST_F(TimeOutTest, directionAssert) {
  ASSERT_EQ(t.getDirection(), bbman::Direction::DIR_NONE);
}
