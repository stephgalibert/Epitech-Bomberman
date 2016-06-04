//
// AddPowerEffectTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/effects
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 16:51:30 2016 avelin_j
// Last update Sat Jun  4 16:57:21 2016 avelin_j
//

#include "AddPowerEffect.hpp"
#include "gtest.h"

class AddPowerEffectTest : public::testing::Test
{
public:
  AddPowerEffectTest()
  {
  }

  virtual ~AddPowerEffectTest()
  {
  }
};

TEST_F(AddPowerEffectTest, deltaAssert) {
  bbman::APlayer *player;
  bbman::AddPowerEffect t(player);

  ASSERT_EQ(t.getDelta(), 0);
}

TEST_F(AddPowerEffectTest, isFinishedAssert) {
  bbman::APlayer *player;
  bbman::AddPowerEffect t(player);

  ASSERT_EQ(t.isFinished(), 0);
}

TEST_F(AddPowerEffectTest, targetAssert) {
  bbman::APlayer *player;
  bbman::AddPowerEffect t(player);

  ASSERT_TRUE(t.testGetTarget() == NULL);
}

TEST_F(AddPowerEffectTest, enableAssert) {
  bbman::APlayer *player;
  bbman::AddPowerEffect t(player);

  ASSERT_EQ(t.testGetEnable(), 0);
}
