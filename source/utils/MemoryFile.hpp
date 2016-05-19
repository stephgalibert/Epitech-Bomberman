//
// MemoryFile.hpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Fri May 13 11:42:47 2016 avelin_j
// Last update Wed May 18 23:17:02 2016 stephane galibert
//

#ifndef _MEMORYFILE_HPP_
# define _MEMORYFILE_HPP_

# include <iostream>
# include <fstream>
# include <stdexcept>

namespace bbman
{
  struct MemoryFile
  {
    MemoryFile(void);
    MemoryFile(std::string const& filename);
    ~MemoryFile(void);
    void load(void);
    char *data;
    std::size_t size;
    std::string filename;
  };
}

#endif /* !_MEMORYFILE_HPP_ */
