//
// MemoryFile.hpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Fri May 13 11:42:47 2016 avelin_j
// Last update Fri May 13 11:42:49 2016 avelin_j
//

#ifndef _MEMORYFILE_HPP_
# define _MEMORYFILE_HPP_

# include <iostream>
# include <fstream>
# include <stdexcept>

struct MemoryFile
{
  MemoryFile(void);
  MemoryFile(std::string const& filename);
  ~MemoryFile(void);
  void load(void);
  char *_data;
  std::size_t _size;
  std::string _filename;
};

#endif /* !_MEMORYFILE_HPP_ */
