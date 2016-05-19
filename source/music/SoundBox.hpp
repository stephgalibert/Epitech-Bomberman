//
// SoundBox.hpp for indie in /home/galibe_s/rendu/bomberman/source/music
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 19 11:51:42 2016 stephane galibert
// Last update Thu May 19 15:00:20 2016 stephane galibert
//

#ifndef _SOUNDBOX_HPP_
# define _SOUNDBOX_HPP_

# include <SFML/Audio.hpp>
# include <unordered_map>
# include <iostream>

# include "ISound.hpp"

namespace bbman
{
  class SoundBox : public ISound
  {
  public:
    SoundBox(void);
    virtual ~SoundBox(void);
    virtual void stop(std::string const& tostop);
    virtual void play(std::string const& toplay);
    virtual void setLoop(std::string const& toloop, bool value);
    virtual void pause(std::string const& topause);
    virtual void setVolumeBySample(std::string const& sample, float value);
    virtual float getVolumeBySample(std::string const& sample);
    virtual void addSample(std::string const& name, MemoryFile const& file);
    virtual sf::SoundSource::Status getStatus(std::string const& name) const;
  private:
    struct SoundStruct
    {
      sf::Sound *sound;
      sf::SoundBuffer *buffer;
    };
    std::unordered_map<std::string, SoundStruct *> _sample;
  };
}

#endif /* !_SOUNDBOX_HPP_ */
