//
// MusicBox.cpp for indie in /home/galibe_s/rendu/bomberman/source/music
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 18 22:55:42 2016 stephane galibert
// Last update Thu May 19 15:01:43 2016 stephane galibert
//

#include "MusicBox.hpp"

bbman::MusicBox::MusicBox(void)
{

}

bbman::MusicBox::~MusicBox(void)
{
  for (auto it : this->_sample) {
    if (it.second) {
      delete (it.second);
    }
  }
}

void bbman::MusicBox::play(std::string const& toplay)
{
  if (this->_sample.find(toplay) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not play " + toplay));
  this->_sample[toplay]->play();
}

void bbman::MusicBox::setLoop(std::string const& toloop, bool value)
{
  if (this->_sample.find(toloop) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not loop " + toloop));
  this->_sample[toloop]->setLoop(value);
}

void bbman::MusicBox::stop(std::string const& tostop)
{
  if (this->_sample.find(tostop) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not stop " + tostop));
  this->_sample[tostop]->stop();
}

void bbman::MusicBox::pause(std::string const& topause)
{
  if (this->_sample.find(topause) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not pause " + topause));
  this->_sample[topause]->pause();
}

void bbman::MusicBox::setVolumeBySample(std::string const& sample, float value)
{
  if (this->_sample.find(sample) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not set volume " + sample));
  this->_sample[sample]->setVolume(value);
}

float bbman::MusicBox::getVolumeBySample(std::string const& sample)
{
  if (this->_sample.find(sample) == this->_sample.cend())
    throw (std::runtime_error("MusicBox: can not set volume " + sample));
  return (this->_sample[sample]->getVolume());
}

void bbman::MusicBox::addSample(std::string const& name, MemoryFile const& file)
{
  sf::Music *sample = NULL;

  if (this->_sample.find(name) == this->_sample.cend()) {
    sample = new sf::Music;
    if (!sample->openFromMemory(file.data, file.size))
      {
	delete (sample);
	throw (std::runtime_error(name + " not found"));
      }
    this->_sample.insert(std::make_pair(name, sample));
  }
}

sf::SoundSource::Status bbman::MusicBox::getStatus(std::string const& name) const
{
  if (this->_sample.find(name) == this->_sample.cend())
    throw (std::runtime_error("Soundbox: can not get " + name + " status"));
  return (this->_sample.at(name)->getStatus());
}
