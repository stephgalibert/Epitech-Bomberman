//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 16:57:51 2016 avelin_j
//

#include "AddExplosingBombEffect.hpp"
#include "gtest.h"

class AddExplosingBombEffectTest : public::testing::Test
{
public:
  AddExplosingBombEffectTest()
  {
  }

  virtual ~AddExplosingBombEffectTest()
  {
  }
};

TEST_F(AddExplosingBombEffectTest, deltaAssert) {
  bbman::APlayer *player;
  bbman::AddExplosingBombEffect t(player);

  ASSERT_EQ(t.getDelta(), 0);
}

TEST_F(AddExplosingBombEffectTest, isFinishedAssert) {
  bbman::APlayer *player;
  bbman::AddExplosingBombEffect t(player);

  ASSERT_EQ(t.isFinished(), 0);
}

TEST_F(AddExplosingBombEffectTest, targetAssert) {
  bbman::APlayer *player;
  bbman::AddExplosingBombEffect t(player);

  ASSERT_TRUE(t.testGetTarget() == NULL);
}

TEST_F(AddExplosingBombEffectTest, enableAssert) {
  bbman::APlayer *player;
  bbman::AddExplosingBombEffect t(player);

  ASSERT_EQ(t.testGetEnable(), 0);
}
