//
// CacheManager.hpp for cachemanager in /home/galibe_s/util/include
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sun Apr 10 20:55:25 2016 stephane galibert
// Last update Wed May  4 12:55:04 2016 stephane galibert
//

#ifndef _CACHEMANAGER_HPP_
# define _CACHEMANAGER_HPP_

# include <string>
# include <unordered_map>

namespace tools
{
  template<typename Key, typename Cache>
  class CacheManager
  {
  public:
    CacheManager(void) {}
    ~CacheManager(void) {}
    Cache &operator[](Key const& key)
    {
      if (_cache.find(key) != _cache.end())
	return (_cache[key]);
      throw (std::runtime_error("CacheManager: key not found"));
    }
    Cache const& operator[](Key const& key) const
    {
      if (_cache.find(key) != _cache.end())
	return (_cache.at(key));
      throw (std::runtime_error("CacheManager: key not found"));
    }
    void insert(Key const& key, Cache const& cache)
    {
      _cache.insert(std::make_pair(key, cache));
    }
    bool find(Key const& key)
    {
      return (_cache.find(key) != _cache.end());
    }
  private:
    std::unordered_map<Key, Cache> _cache;
  };
}

#endif /* !_CACHEMANAGER_HPP_ */
