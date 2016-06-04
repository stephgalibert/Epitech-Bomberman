//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 20:30:34 2016 avelin_j
//

#include "SpeedUPPowerUP.hpp"
#include "gtest.h"

class SpeedUPPowerUPTest : public::testing::Test
{
public:
  SpeedUPPowerUPTest()
  {
  }

  virtual ~SpeedUPPowerUPTest()
  {
  }

  bbman::SpeedUPPowerUP t;
};

TEST_F(SpeedUPPowerUPTest, deltaAssert) {
  ASSERT_EQ(t.testGetDelta(), 0);
}

TEST_F(SpeedUPPowerUPTest, meshAssert) {
  ASSERT_TRUE(t.testGetMesh() == NULL);
}
