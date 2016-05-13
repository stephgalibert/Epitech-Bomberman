//
// Music.hpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Sun May  8 14:31:07 2016 avelin_j
// Last update Tue May 10 12:32:49 2016 avelin_j
//

#ifndef MUSIC_HPP
# define MUSIC_HPP


#include <SFML/Audio.hpp>
#include <unordered_map>
#include <iostream>
#include "MemoryFile.hpp"

class MusicBox
{
public:
  MusicBox(void);
  ~MusicBox(void);
  void stop(std::string tostop);
  void play(std::string toplay);
  void loop(std::string toloop);
  void pause(std::string topause);
  void setVolumeBySample(std::string sample, float value);
  float getVolumeBySample(std::string sample);
  void loadSampleFromMemory(std::string, MemoryFile*);

private:
  std::unordered_map<std::string, sf::Music*> _sample;
};

#endif /* MUSIC_HPP */
