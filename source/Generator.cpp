//
// Generator.cpp for generator in /home/galibe_s/cpp_utils
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon Apr 11 02:56:43 2016 stephane galibert
// Last update Sun May  8 17:40:01 2016 stephane galibert
//

#include "Generator.hpp"

tools::Generator::Generator(void)
{
  this->_generator = new std::default_random_engine(this->_rd());
}

tools::Generator::~Generator(void)
{
  if (this->_generator)
    delete (this->_generator);
}

int tools::Generator::operator()(unsigned int min, unsigned int max)
{
  std::uniform_int_distribution<unsigned int> distrib(min, max);
  return (distrib(*this->_generator));
}
