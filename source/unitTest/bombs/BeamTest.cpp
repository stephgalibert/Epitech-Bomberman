//
// Game.cpp for  in /home/avelin_j/bomberman/source/unitTest
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Thu Jun  2 14:26:33 2016 avelin_j
// Last update Sat Jun  4 12:20:40 2016 avelin_j
//

#include "Beam.hpp"
#include "gtest.h"

class CenterBeamTest : public::testing::Test
{
public:
  CenterBeamTest()
  {
  }

  virtual ~CenterBeamTest()
  {
  }
};

class NorthernBeamTest : public::testing::Test
{
public:
  NorthernBeamTest()
  {
  }

  virtual ~NorthernBeamTest()
  {
  }
};

class SouthernBeamTest : public::testing::Test
{
public:
  SouthernBeamTest()
  {
  }

  virtual ~SouthernBeamTest()
  {
  }
};

class EasternBeamTest : public::testing::Test
{
public:
  EasternBeamTest()
  {
  }

  virtual ~EasternBeamTest()
  {
  }
};

class WesternBeamTest : public::testing::Test
{
public:
  WesternBeamTest()
  {
  }

  virtual ~WesternBeamTest()
  {
  }
};

TEST_F(CenterBeamTest, rangeAssert) {
  bbman::Irrlicht Irr;
  bbman::CenterBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRange(), 5);
}

TEST_F(CenterBeamTest, repeatAssert) {
  bbman::Irrlicht Irr;
  bbman::CenterBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRepeat(), 0);
}

TEST_F(CenterBeamTest, runningAssert) {
  bbman::Irrlicht Irr;
  bbman::CenterBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRunning(), 0);
}

TEST_F(NorthernBeamTest, rangeAssert) {
  bbman::Irrlicht Irr;
  bbman::NorthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRange(), 5);
}

TEST_F(NorthernBeamTest, repeatAssert) {
  bbman::Irrlicht Irr;
  bbman::NorthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRepeat(), 0);
}

TEST_F(NorthernBeamTest, runningAssert) {
  bbman::Irrlicht Irr;
  bbman::NorthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRunning(), 0);
}

TEST_F(SouthernBeamTest, rangeAssert) {
  bbman::Irrlicht Irr;
  bbman::SouthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRange(), 5);
}

TEST_F(SouthernBeamTest, repeatAssert) {
  bbman::Irrlicht Irr;
  bbman::SouthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRepeat(), 0);
}

TEST_F(SouthernBeamTest, runningAssert) {
  bbman::Irrlicht Irr;
  bbman::SouthernBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRunning(), 0);
}

TEST_F(EasternBeamTest, rangeAssert) {
  bbman::Irrlicht Irr;
  bbman::EasternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRange(), 5);
}

TEST_F(EasternBeamTest, repeatAssert) {
  bbman::Irrlicht Irr;
  bbman::EasternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRepeat(), 0);
}

TEST_F(EasternBeamTest, runningAssert) {
  bbman::Irrlicht Irr;
  bbman::EasternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRunning(), 0);
}

TEST_F(WesternBeamTest, rangeAssert) {
  bbman::Irrlicht Irr;
  bbman::WesternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRange(), 5);
}

TEST_F(WesternBeamTest, repeatAssert) {
  bbman::Irrlicht Irr;
  bbman::WesternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRepeat(), 0);
}

TEST_F(WesternBeamTest, runningAssert) {
  bbman::Irrlicht Irr;
  bbman::WesternBeam t(Irr, 5);

  ASSERT_EQ(t.testGetRunning(), 0);
}
