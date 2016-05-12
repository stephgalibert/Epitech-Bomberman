//
// Map.hpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May  5 11:41:02 2016 stephane galibert
// Last update Thu May 12 15:59:12 2016 stephane galibert
//


#ifndef _MAP_HPP_
# define _MAP_HPP_

namespace bbman
{
  template<typename T>
  struct Map
  {
    Map(void);
    ~Map(void);
    void load(size_t w, size_t h, T const& vdef);
    T const& at(size_t x, size_t y) const;
    T &at(size_t x, size_t y);
    T **content;
    int w;
    int h;
  };

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
