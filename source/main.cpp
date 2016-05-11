//
// main.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Fri May  6 03:03:53 2016 stephane galibert
// Last update Fri May  6 03:03:54 2016 stephane galibert
//

#include <string>
#include <iostream>
#include <stdexcept>

#include "Application.hpp"

int	main(void)
{
  bbman::Application appli;

  try {
    appli.init();
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
    return (1);
  }
  return (appli.play());
}
