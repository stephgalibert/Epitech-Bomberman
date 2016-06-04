//
// HighScore.cpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat Jun  4 21:07:49 2016 stephane galibert
// Last update Sat Jun  4 21:53:35 2016 stephane galibert
//

#include "HighScore.hpp"

bbman::HighScore::HighScore(std::string newNickName, int newScore)
{
  this->nickName = newNickName;
  this->score    = newScore;
}

bbman::HighScore::~HighScore(void)
{

}

bool bbman::HighScore::operator>(bbman::HighScore const& other) const
{
  return this->score > other.score;
}

void bbman::HighScore::loadScoreFromFile(std::string const& filename,
					 std::vector<HighScore>& ranking)
{
  std::ifstream rankingStream(filename.data());

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
        ranking.push_back(HighScore(tmp[0], std::stoi(tmp[1])));
      }
      tmp.clear();
    }
    rankingStream.close();
  }
  std::sort(std::begin(ranking), std::end(ranking), std::greater<HighScore>());
}

void bbman::HighScore::saveScoreInFile(std::string const& filename,
				       std::vector<HighScore>const& ranking)
{
  std::ofstream rankingStream(filename.data(),
			      std::fstream::out | std::fstream::trunc);

  for (auto const& it : ranking) {
    rankingStream << it.nickName << " " << std::to_string(it.score) << std::endl;
  }

  rankingStream.close();
}

void bbman::HighScore::saveNewHighScore(std::vector<HighScore>&ranking,
					std::string const& name, int score)
{
  ranking.push_back(HighScore(name, score));
  std::sort(std::begin(ranking), std::end(ranking), std::greater<HighScore>());
}
