//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 22:19:15 2016 avelin_j
//

#include "PowerUPs.hpp"
#include "gtest.h"

class PowerUPsTest : public::testing::Test
{
public:
  PowerUPsTest()
  {
  }

  virtual ~PowerUPsTest()
  {
  }

  bbman::PowerUPs t;
};

TEST_F(PowerUPsTest, deltaAssert) {
  ASSERT_EQ(t.testGetDelta(), 0);
}
