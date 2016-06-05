//
// HighScore.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat Jun  4 21:07:56 2016 stephane galibert
// Last update Sun Jun  5 16:52:56 2016 stephane galibert
//

#ifndef _HIGHT_SCORE_HPP_
# define _HIGHT_SCORE_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>

namespace bbman
{
  class HighScore
  {
  public:
    HighScore(std::string newNickName, int newScore);
    ~HighScore(void);
    bool operator>(const HighScore& other) const;
    static void loadScoreFromFile(std::string const& filename,
				  std::vector<HighScore>& ranking);
    static void saveScoreInFile(std::string const& filename,
				std::vector<HighScore>const& ranking);
    static void saveNewHighScore(std::vector<HighScore>&ranking,
				 std::string const& name, int score);
    std::string nickName;
    int         score;
  };
}

#endif /* !_HIGHT_SCORE_HPP_ */
