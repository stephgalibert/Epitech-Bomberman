//
// Generator.hpp for generator in /home/galibe_s/util/include
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun Apr 10 21:08:40 2016 stephane galibert
// Last update Sun May  8 17:40:10 2016 stephane galibert
//

#ifndef _GENERATOR_HPP_
# define _GENERATOR_HPP_

# include <random>

namespace tools
{
  class Generator
  {
  public:
    Generator(void);
    ~Generator(void);
    int operator()(unsigned int min, unsigned int max);
  private:
    std::default_random_engine *_generator;
    std::random_device _rd;
  };
}

#endif /* !_GENERATOR_HPP_ */
