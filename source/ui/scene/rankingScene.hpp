/*
** rankingScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 03:42:51 2016 Joffrey Escobar
*/

#ifndef RANKINGSCENE_HPP
#define RANKINGSCENE_HPP

#include <fstream>
#include "ASubLayout.hpp"

#define FILE_NAME "./score.txt"

class rankingScene : public ASubLayout
{
public:

  rankingScene(ui& ui);
  ~rankingScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener& listener);

  void loadRessources(void);
  void createLabel(int id, const std::string &score);
  void loadScoreFromFile(void);
};

#endif // ifndef RANKINGSCENE_HPP
