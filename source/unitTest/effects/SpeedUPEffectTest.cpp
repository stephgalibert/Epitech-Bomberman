//
// AddPowerEffectTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/effects
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 16:51:30 2016 avelin_j
// Last update Sun Jun  5 13:47:38 2016 stephane galibert
//

#include "SpeedUPEffect.hpp"
#include "gtest.h"

class SpeedUPEffectTest : public::testing::Test
{
public:
  SpeedUPEffectTest()
  {
  }

  virtual ~SpeedUPEffectTest()
  {
  }
};

TEST_F(SpeedUPEffectTest, deltaAssert) {
  bbman::APlayer *player;
  player = NULL;
  bbman::SpeedUPEffect t(player);

  ASSERT_EQ(t.getDelta(), 0);
}

TEST_F(SpeedUPEffectTest, isFinishedAssert) {
  bbman::APlayer *player;
  player = NULL;
  bbman::SpeedUPEffect t(player);

  ASSERT_EQ(t.isFinished(), 0);
}

TEST_F(SpeedUPEffectTest, targetAssert) {
  bbman::APlayer *player;
  player = NULL;
  bbman::SpeedUPEffect t(player);

  ASSERT_TRUE(t.testGetTarget() == NULL);
}

TEST_F(SpeedUPEffectTest, enableAssert) {
  bbman::APlayer *player;
  player = NULL;
  bbman::SpeedUPEffect t(player);

  ASSERT_EQ(t.testGetEnable(), 0);
}
