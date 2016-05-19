//
// SoundBox.cpp for indie in /home/galibe_s/rendu/bomberman/source/music
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 19 12:09:11 2016 stephane galibert
// Last update Thu May 19 15:00:52 2016 stephane galibert
//

#include "SoundBox.hpp"

bbman::SoundBox::SoundBox(void)
{

}

bbman::SoundBox::~SoundBox(void)
{
  for (auto it : this->_sample) {
    if (it.second) {
      delete (it.second->sound);
      delete (it.second->buffer);
      delete (it.second);
    }
  }
}

void bbman::SoundBox::play(std::string const& toplay)
{
  if (this->_sample.find(toplay) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not play " + toplay));
  this->_sample[toplay]->sound->play();
}

void bbman::SoundBox::setLoop(std::string const& toloop, bool value)
{
  if (this->_sample.find(toloop) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not loop " + toloop));
  this->_sample[toloop]->sound->setLoop(value);
}

void bbman::SoundBox::stop(std::string const& tostop)
{
  if (this->_sample.find(tostop) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not stop " + tostop));
  this->_sample[tostop]->sound->stop();
}

void bbman::SoundBox::pause(std::string const& topause)
{
  if (this->_sample.find(topause) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not pause " + topause));
  this->_sample[topause]->sound->pause();
}

void bbman::SoundBox::setVolumeBySample(std::string const& sample, float value)
{
  if (this->_sample.find(sample) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not set volume " + sample));
  this->_sample[sample]->sound->setVolume(value);
}

float bbman::SoundBox::getVolumeBySample(std::string const& sample)
{
  if (this->_sample.find(sample) == this->_sample.cend())
    throw (std::runtime_error("SoundBox: can not set volume " + sample));
  return (this->_sample[sample]->sound->getVolume());
}

void bbman::SoundBox::addSample(std::string const& name, MemoryFile const& file)
{
  SoundStruct *sound = NULL;

  if (this->_sample.find(name) == this->_sample.cend()) {
    sound = new SoundStruct;
    sound->buffer = new sf::SoundBuffer;
    if (!sound->buffer->loadFromMemory(file.data, file.size))
      {
	delete (sound->buffer);
	delete (sound);
	throw (std::runtime_error(name + " not found"));
      }
    sound->sound = new sf::Sound;
    sound->sound->setBuffer(*sound->buffer);
    this->_sample.insert(std::make_pair(name, sound));
  }
}

sf::SoundSource::Status bbman::SoundBox::getStatus(std::string const& name) const
{
  if (this->_sample.find(name) == this->_sample.cend())
    throw (std::runtime_error("Soundbox: can not get " + name + " status"));
  return (this->_sample.at(name)->sound->getStatus());
}
