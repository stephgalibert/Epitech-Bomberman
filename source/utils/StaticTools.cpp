//
// StaticTools.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 23 17:54:23 2016 stephane galibert
// Last update Mon May 23 18:00:00 2016 stephane galibert
//

#include "StaticTools.hpp"

irr::s32 tools::StaticTools::getDistance2D(irr::core::vector3d<irr::s32> const& p1,
					   irr::core::vector3d<irr::s32> const& p2)
{
  return (sqrt(pow(p2.X - p1.X, 2) + pow(p2.Z - p1.Z, 2)));
}
