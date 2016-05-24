//
// Map.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:41:02 2016 stephane galibert
// Last update Tue May 24 19:34:45 2016 stephane galibert
//

#ifndef _MAP_HPP_
# define _MAP_HPP_

# include <iostream>
# include <string>

namespace bbman
{
  template<typename T>
  struct Map
  {
    Map(void);
    ~Map(void);
    void load(size_t w, size_t h, T const& vdef = T());
    T const& at(size_t x, size_t y) const;
    T &at(size_t x, size_t y);
    T **content;
    size_t w;
    size_t h;
  };

  template<typename T>
  std::ostream &operator<<(std::ostream &flux, Map<T> const& map)
  {
    flux << "MAP_BEGIN" << std::endl;
    for (size_t i = 0 ; i < map.h ; ++i) {
      for (size_t j = 0 ; j < map.w ; ++j) {
	flux << static_cast<int>(map.at(j, i).id) << " ";
      }
      flux << std::endl;
    }
    flux << "MAP_END" << std::endl;
    return (flux);
  }

  template<typename T>
  Map<T>::Map(void)
  {
    content = NULL;
    w = 0;
    h = 0;
  }

  template<typename T>
  Map<T>::~Map(void)
  {
    if (content) {
      for (size_t i = 0 ; i < h ; ++i) {
	delete[] (content[i]);
      }
      delete[] content;
    }
  }

  template<typename T>
  void Map<T>::load(size_t w, size_t h, T const& vdef)
  {
    this->w = w;
    this->h = h;
    content = new T*[h];
    for (size_t i = 0 ; i < h ; ++i) {
      content[i] = new T[w];
      for (size_t j = 0 ; j < w ; ++j) {
	content[i][j] = vdef;
      }
    }
  }

  template<typename T>
  T const& Map<T>::at(size_t x, size_t y) const
  {
    return (this->content[y][x]);
  }

  template<typename T>
  T &Map<T>::at(size_t x, size_t y)
  {
    return (this->content[y][x]);
  }
}

#endif /* !_MAP_HPP_ */
