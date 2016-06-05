//
// PlayerAttr.cpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May 25 20:06:55 2016 stephane galibert
// Last update Sun Jun  5 13:40:28 2016 stephane galibert
//

#include "TimeOutAttr.hpp"
#include "TimeOut.hpp"

bbman::TimeOutAttr::TimeOutAttr(void)
{
  this->_attrs["delta"] = std::bind(&bbman::TimeOutAttr::setDelta, this,
				    std::placeholders::_1, std::placeholders::_2,
				    std::placeholders::_3);
  this->_attrs["deltaanim"] = std::bind(&bbman::TimeOutAttr::setDeltaAnim, this,
					std::placeholders::_1, std::placeholders::_2,
					std::placeholders::_3);
  this->_attrs["step"] = std::bind(&bbman::TimeOutAttr::setStep, this,
				   std::placeholders::_1, std::placeholders::_2,
				   std::placeholders::_3);
  this->_attrs["dir"] = std::bind(&bbman::TimeOutAttr::setDir, this,
				  std::placeholders::_1, std::placeholders::_2,
				  std::placeholders::_3);
  this->_attrs["begin"] = std::bind(&bbman::TimeOutAttr::setBegin, this,
				    std::placeholders::_1, std::placeholders::_2,
				    std::placeholders::_3);
  this->_attrs["current"] = std::bind(&bbman::TimeOutAttr::setCurrent, this,
				      std::placeholders::_1, std::placeholders::_2,
				      std::placeholders::_3);
}

bbman::TimeOutAttr::~TimeOutAttr(void)
{

}

void bbman::TimeOutAttr::set(TimeOut *out, Irrlicht &irr, std::string const& name,
			     std::string const& value)
{
  if (this->_attrs.find(name) != this->_attrs.cend()) {
    this->_attrs[name](out, irr, value);
  }
}

void bbman::TimeOutAttr::setDelta(TimeOut *out, Irrlicht &irr,
				  std::string const& value)
{
  (void)irr;
  if (out) {
    out->setDelta(std::atof(value.data()));
  }
}

void bbman::TimeOutAttr::setDeltaAnim(TimeOut *out, Irrlicht &irr,
				      std::string const& value)
{
  (void)irr;
  if (out) {
    out->setDeltaAnim(std::atof(value.data()));
  }
}

void bbman::TimeOutAttr::setStep(TimeOut *out, Irrlicht &irr,
				 std::string const& value)
{
  (void)irr;
  if (out) {
    out->setStep(std::atof(value.data()));
  }
}

void bbman::TimeOutAttr::setDir(TimeOut *out, Irrlicht &irr,
				std::string const& value)
{
  (void)irr;
  if (out) {
    out->setDirection(static_cast<Direction>(std::atoi(value.data())));
  }
}

void bbman::TimeOutAttr::setBegin(TimeOut *out, Irrlicht &irr,
				  std::string const& value)
{
  (void)irr;
  if (out) {
    irr::core::vector3d<irr::u32> pos;
    std::vector<std::string> tokens;
    std::istringstream iss(value);
    std::copy(std::istream_iterator<std::string>(iss),
	      std::istream_iterator<std::string>(),
	      std::back_inserter(tokens));
    if (tokens.size() == 2) {
      pos.X = std::atoi(tokens[0].data());
      pos.Z = std::atoi(tokens[1].data());
      out->setBegin(pos);
    }
  }
}

void bbman::TimeOutAttr::setCurrent(TimeOut *out, Irrlicht &irr,
				    std::string const& value)
{
  (void)irr;
  if (out) {
    irr::core::vector3d<irr::u32> pos;
    std::vector<std::string> tokens;
    std::istringstream iss(value);
    std::copy(std::istream_iterator<std::string>(iss),
	      std::istream_iterator<std::string>(),
	      std::back_inserter(tokens));
    if (tokens.size() == 2) {
      pos.X = std::atoi(tokens[0].data());
      pos.Z = std::atoi(tokens[1].data());
      out->setCurrent(pos);
    }
  }
}
