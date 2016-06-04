//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 20:11:43 2016 avelin_j
//

#include "AddPowerPowerUP.hpp"
#include "gtest.h"

class AddPowerPowerUPTest : public::testing::Test
{
public:
  AddPowerPowerUPTest()
  {
  }

  virtual ~AddPowerPowerUPTest()
  {
  }

  bbman::AddPowerPowerUP t;
};

TEST_F(AddPowerPowerUPTest, deltaAssert) {
  ASSERT_EQ(t.testGetDelta(), 0);
}

TEST_F(AddPowerPowerUPTest, meshAssert) {
  ASSERT_TRUE(t.testGetMesh() == NULL);
}
