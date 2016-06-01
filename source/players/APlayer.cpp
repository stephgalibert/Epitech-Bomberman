//
// APlayer.cpp for indie in /home/galibe_s/rendu/bomberman/source/players
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May 24 22:09:16 2016 stephane galibert
// Last update Wed Jun  1 21:11:44 2016 stephane galibert
//

#include "APlayer.hpp"

size_t bbman::APlayer::NumberOfPlayer = 0;

bbman::APlayer::APlayer(void)
{
  this->_id = NumberOfPlayer;
  this->_score = 0;
  this->_mood = 0;
  this->_username = "Player" + std::to_string(NumberOfPlayer);
  this->_power = 0;
  ++NumberOfPlayer;
}

bbman::APlayer::~APlayer(void)
{

}

size_t bbman::APlayer::getID(void) const
{
  return (this->_id);
}

irr::s32 bbman::APlayer::getScore(void) const
{
  return (this->_score);
}

int bbman::APlayer::getMood(void) const
{
  return (this->_mood);
}

void bbman::APlayer::setMood(int mood)
{
  this->_mood = mood;
}

void bbman::APlayer::setScore(irr::s32 score)
{
  this->_score = score;
}

std::string const& bbman::APlayer::getUsername(void) const
{
  return (this->_username);
}

void bbman::APlayer::setUsername(std::string const& username)
{
  this->_username = username;
}

size_t bbman::APlayer::getPower(void) const
{
  return (this->_power);
}

void bbman::APlayer::setPower(size_t power)
{
  this->_power = power;
}
