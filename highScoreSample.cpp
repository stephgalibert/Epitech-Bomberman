/*
** main.cpp for  in cpp_arcade
**
** Made by sebperso
** Login   <salete_s@epitech.net>
**
** Started on  Thu Jun 02 23:44:03 2016 sebperso
** Last update Thu Jun 02 23:44:03 2016 sebperso
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

#define FILE_NAME "./rankingFile"

struct high_score
{
  std::string nickName;
  int         score;

  high_score(std::string newNickName, int newScore)
  {
    this->nickName = newNickName;
    this->score    = newScore;
  }

  bool operator>(const high_score& other) const
  {
    return this->score > other.score;
  }
};

void loadScoreFromFile(std::vector<high_score>& ranking)
{
  std::ifstream rankingStream(FILE_NAME);

  std::vector<std::string>tmp;
  std::string   score;
  std::string   scoreDetail;

  if (rankingStream.is_open()) {
    while (std::getline(rankingStream, score)) {
      std::stringstream ss(score);

      while (std::getline(ss, scoreDetail, ' ')) {
        tmp.push_back(scoreDetail);
      }

      if (tmp.size() == 2) {
        ranking.push_back(high_score(tmp[0], std::stoi(tmp[1])));
      }
      tmp.clear();
    }
    rankingStream.close();
  }
  std::sort(std::begin(ranking), std::end(ranking), std::greater<high_score>());
}

void saveScoreInFile(std::vector<high_score>const& ranking)
{
  std::ofstream rankingStream(FILE_NAME, std::fstream::out | std::fstream::trunc);

  for (auto const& it : ranking) {
    rankingStream << it.nickName << " " << std::to_string(it.score) << std::endl;
  }

  rankingStream.close();
}

void saveNewHighScore(std::vector<high_score>&ranking, std::string name, int score)
{
  ranking.push_back(high_score(name, score));
  std::sort(std::begin(ranking), std::end(ranking), std::greater<high_score>());
}

int main(int argc, char const *argv[])
{
  std::vector<high_score> ranking;

  if (argc > 1) {
    std::string name(argv[1]);
    loadScoreFromFile(ranking);
    saveNewHighScore(ranking, name, std::stoi(argv[2]));
    saveScoreInFile(ranking);
  } else {
    std::cerr << "Usage: ./a.out name new_score" << std::endl;
  }


  return 0;
}
