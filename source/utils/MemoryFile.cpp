//
// MemoryFile.cpp for  in /home/avelin_j/Work/music
//
// Made by avelin_j
// Login   <avelin_j@epitech.net>
//
// Started on  Fri May 13 11:40:16 2016 avelin_j
// Last update Thu May 19 11:48:34 2016 stephane galibert
//

#include "MemoryFile.hpp"

bbman::MemoryFile::MemoryFile(void)
{
  this->data = NULL;
  this->size = 0;
  this->filename = "";
}

bbman::MemoryFile::MemoryFile(std::string const& filename)
{
  this->filename = filename;
  this->data = NULL;
  this->size = 0;
}

bbman::MemoryFile::~MemoryFile(void)
{
  if (this->data != NULL) {
    delete[] (this->data);
  }
}

void bbman::MemoryFile::load(void)
{
  std::ifstream ifs(this->filename, std::ios::binary);

  if (ifs) {
      ifs.seekg(0, ifs.end);
      this->size = static_cast<int>(ifs.tellg());
      ifs.seekg(0, ifs.beg);
      this->data = new char[this->size];
      ifs.read(this->data, this->size);
      ifs.close();
    }
  else {
    throw (std::runtime_error("Error: unable to open " + this->filename));
  }
}
