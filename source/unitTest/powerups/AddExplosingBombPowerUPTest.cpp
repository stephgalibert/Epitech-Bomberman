//
// BoardTest.cpp for  in /home/avelin_j/bomberman/source/unitTest/environment
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 17:33:32 2016 avelin_j
// Last update Sat Jun  4 20:00:55 2016 avelin_j
//

#include "AddExplosingBombPowerUP.hpp"
#include "gtest.h"

class AddExplosingBombPowerUPTest : public::testing::Test
{
public:
  AddExplosingBombPowerUPTest()
  {
  }

  virtual ~AddExplosingBombPowerUPTest()
  {
  }

  bbman::AddExplosingBombPowerUP t;
};

TEST_F(AddExplosingBombPowerUPTest, deltaAssert) {
  ASSERT_EQ(t.testGetDelta(), 0);
}

TEST_F(AddExplosingBombPowerUPTest, meshAssert) {
  ASSERT_TRUE(t.testGetMesh() == NULL);
}
