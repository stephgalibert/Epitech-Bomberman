//
// ISound.hpp for indie in /home/galibe_s/rendu/bomberman/source/music
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 19 12:21:57 2016 stephane galibert
// Last update Thu May 19 15:00:07 2016 stephane galibert
//

#ifndef _ISOUND_HPP_
# define _ISOUND_HPP_

# include <string>

# include "MemoryFile.hpp"

namespace bbman
{
  class ISound
  {
  public:
    virtual ~ISound(void) {}
    virtual void stop(std::string const& tostop) = 0;
    virtual void play(std::string const& play) = 0;
    virtual void setLoop(std::string const& toloop, bool value) = 0;
    virtual void pause(std::string const& topause) = 0;
    virtual void setVolumeBySample(std::string const& sample, float value) = 0;
    virtual float getVolumeBySample(std::string const& sample) = 0;
    virtual void addSample(std::string const& name, MemoryFile const& file) = 0;
    virtual sf::SoundSource::Status getStatus(std::string const& name) const = 0;
  };
}

#endif /* !_ISOUND_HPP_ */
