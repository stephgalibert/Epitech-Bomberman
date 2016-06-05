//
// ExplodingBomb.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sat Jun  4 11:29:51 2016 avelin_j
// Last update Sun Jun  5 13:48:44 2016 stephane galibert
//

#include "ExplodingBomb.hpp"
#include "Board.hpp"
#include "gtest.h"



class ExplodingBombTest : public::testing::Test
{
public:
  ExplodingBombTest()
  {
  }

  virtual ~ExplodingBombTest()
  {
  }
};

TEST_F(ExplodingBombTest, isExplosingAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_EQ(t.isExplosing(), 0);
}

TEST_F(ExplodingBombTest, RangeAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_EQ(t.getRange(), 3);
}

TEST_F(ExplodingBombTest, addRange) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  EXPECT_EQ(t.getRange(), 3);
  t.addRange(7);
  EXPECT_EQ(t.getRange(), 10);
}

TEST_F(ExplodingBombTest, isExplodingAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_EQ(t.isExploding(), 0);
}

TEST_F(ExplodingBombTest, meshAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetMesh() == NULL);
}

TEST_F(ExplodingBombTest, northernBeamAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetNorthernBeam() == NULL);
}

TEST_F(ExplodingBombTest, southernBeamAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetSouthernBeam() == NULL);
}

TEST_F(ExplodingBombTest, easternBeamAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetEasternBeam() == NULL);
}

TEST_F(ExplodingBombTest, westernBeamAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetWesternBeam() == NULL);
}

TEST_F(ExplodingBombTest, centerBeamAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_TRUE(t.testGetCenterBeam() == NULL);
}

TEST_F(ExplodingBombTest, deltaAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_EQ(t.getDelta(), 0);
}

TEST_F(ExplodingBombTest, cptAssert) {
  bbman::APlayer *owner;
  owner = NULL;
  bbman::ExplodingBomb t(owner);

  ASSERT_EQ(t.getDelta(), 0);
}
