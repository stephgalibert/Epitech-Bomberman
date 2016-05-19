//
// CacheManager.hpp for indie in /home/galibe_s/rendu/bomberman/source/utils
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Thu May 19 14:32:43 2016 stephane galibert
// Last update Thu May 19 14:32:43 2016 stephane galibert
//

#ifndef _CACHEMANAGER_HPP_
# define _CACHEMANAGER_HPP_

# include <iostream>
# include <string>
# include <utility>
# include <map>
# include <stdexcept>

namespace bbman
{
  template<typename Key, typename Cache>
  class CacheManager
  {
  public:
    CacheManager(void) {}
    ~CacheManager(void) {}

    Cache &operator[](Key const& key)
    {
      if (this->_cache.find(key) != this->_cache.end())
	return (this->_cache[key]);
      throw (std::runtime_error("CacheManager: key not found"));
    }

    Cache const& operator[](Key const& key) const
    {
      if (this->_cache.find(key) != this->_cache.end())
	return (this->_cache.at(key));
      throw (std::runtime_error("CacheManager: key not found"));
    }

    void insert(Key const& key, Cache const& cache)
    {
      this->_cache.insert(std::make_pair(key, cache));
    }

    bool find(Key const& key)
    {
      return (this->_cache.find(key) != this->_cache.end());
    }
  private:
    std::map<Key, Cache> _cache;
  };
}

#endif /* !_CACHEMANAGER_HPP_ */
