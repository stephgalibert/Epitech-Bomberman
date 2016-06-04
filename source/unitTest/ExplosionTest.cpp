//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 15:52:48 2016 avelin_j
//

#include "Explosion.hpp"
#include "gtest.h"

class ExplosionTest : public::testing::Test
{
public:
  ExplosionTest()
  {
  }

  virtual ~ExplosionTest()
  {
  }

  bbman::Explosion t;
};

TEST_F(ExplosionTest, deltaAssert) {
  ASSERT_EQ(0, t.testGetDelta());
}

TEST_F(ExplosionTest, hasFinishedAssert) {
  ASSERT_EQ(0, t.hasFinished());
}

TEST_F(ExplosionTest, playedAssert) {
  ASSERT_EQ(0, t.testGetPlayed());
}

TEST_F(ExplosionTest, systemAssert) {
  ASSERT_TRUE(t.testGetSystem() == NULL);
}
