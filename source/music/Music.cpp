//
// Music.cpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun May  8 14:31:09 2016 avelin_j
// Last update Tue May 10 12:34:14 2016 avelin_j
//

#include "Music.hpp"

MusicBox::MusicBox(void)
{
}

MusicBox::~MusicBox(void)
{
}

void	MusicBox::play(std::string toplay)
{
  this->_sample[toplay]->play();
}

void  MusicBox::loop(std::string toloop)
{
  this->_sample[toloop]->setLoop(true);
}

void	MusicBox::stop(std::string tostop)
{
  this->_sample[tostop]->stop();
}

void	MusicBox::pause(std::string topause)
{
  this->_sample[topause]->pause();
}

void MusicBox::setVolumeBySample(std::string sample, float value)
{
  this->_sample[sample]->setVolume(value);
}

float MusicBox::getVolumeBySample(std::string sample)
{
  return (this->_sample[sample]->getVolume());
}

void MusicBox::loadSampleFromMemory(std::string sample_name, MemoryFile *memory)
{
  sf::Music *sample = new sf::Music;

  sample->openFromMemory(memory->_data, memory->_size);
  this->_sample.insert({sample_name, sample});
}
