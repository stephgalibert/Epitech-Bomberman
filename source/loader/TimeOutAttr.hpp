//
// TimeOutAttr.hpp for indie in /home/galibe_s/rendu/bomberman/source/loader
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Mon May 30 06:13:16 2016 stephane galibert
// Last update Mon May 30 09:36:42 2016 stephane galibert
//

#ifndef _TIMEOUTATTR_HPP_
# define _TIMEOUTATTR_HPP_

# include <string>
# include <map>
# include <functional>
# include <cstdlib>
# include <algorithm>
# include <iterator>
# include <sstream>

# include "Direction.hpp"
# include "Irrlicht.hpp"

namespace bbman
{
  class TimeOut;

  class TimeOutAttr
  {
  public:
    TimeOutAttr(void);
    ~TimeOutAttr(void);
    void set(TimeOut *out, Irrlicht &irr, std::string const& name,
	     std::string const& value);
  private:
    void setDelta(TimeOut *out, Irrlicht &irr, std::string const& value);
    void setDeltaAnim(TimeOut *out, Irrlicht &irr, std::string const& value);
    void setStep(TimeOut *out, Irrlicht &irr, std::string const& value);
    void setDir(TimeOut *out, Irrlicht &irr, std::string const& value);
    void setBegin(TimeOut *out, Irrlicht &irr, std::string const& value);
    void setCurrent(TimeOut *out, Irrlicht &irr, std::string const& value);
    std::map<std::string, std::function<void(TimeOut *, Irrlicht &, std::string const&)> > _attrs;
  };
}

# endif /* !_TIMEOUTATTR_HPP_ */
