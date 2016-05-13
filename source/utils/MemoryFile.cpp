//
// MemoryFile.cpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Fri May 13 11:40:16 2016 avelin_j
// Last update Fri May 13 11:45:28 2016 avelin_j
//

#include "MemoryFile.hpp"

MemoryFile::MemoryFile(void)
{
  this->_data = NULL;
  this->_size = 0;
  this->_filename = "";
}

MemoryFile::MemoryFile(std::string const& filename)
{
  this->_filename = filename;
  this->_data = NULL;
  this->_size = 0;
}

MemoryFile::~MemoryFile(void)
{
  if (this->_data != NULL)
    delete[] _data;
}

void MemoryFile::load(void)
{
  std::ifstream ifs(this->_filename, std::ios::binary);

  if (ifs)
    {
      ifs.seekg(0, ifs.end);
      _size = static_cast<int>(ifs.tellg());
      ifs.seekg(0, ifs.beg);
      _data = new char[_size];
      ifs.read(_data, _size);
      ifs.close();
    }
  else
    throw (std::runtime_error("Error: unable to open " + _filename));
}
