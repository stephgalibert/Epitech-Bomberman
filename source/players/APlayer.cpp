//
// APlayer.cpp for indie in /home/galibe_s/rendu/bomberman/source/players
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Tue May 24 22:09:16 2016 stephane galibert
// Last update Sun May 29 08:40:47 2016 stephane galibert
//

#include "APlayer.hpp"

size_t bbman::APlayer::NumberOfPlayer = 0;

bbman::APlayer::APlayer(void)
{
  this->_id = NumberOfPlayer;
  this->_score = 0;
  this->_username = "Player" + std::to_string(NumberOfPlayer);
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

void bbman::APlayer::setScore(irr::s32 score)
{
  this->_score = score;
}

bool bbman::APlayer::hasExplosed(void) const
{
  return (!this->_alive);
}

void bbman::APlayer::setAlive(bool value)
{
  this->_alive = value;
}

std::string const& bbman::APlayer::getUsername(void) const
{
  return (this->_username);
}

void bbman::APlayer::setUsername(std::string const& username)
{
  this->_username = username;
}
