/*
** lobbyScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Thu Jun 02 14:53:19 2016 Joffrey Escobar
*/

#ifndef LOBBYSCENE_HPP
#define LOBBYSCENE_HPP

#include <algorithm>
#include "ASubLayout.hpp"

class lobbyScene : public ASubLayout
{
public:

  lobbyScene(ui& ui);
  ~lobbyScene(void);

  void createPlayerLabel(int x, int id);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);
  void loadRessources(void);
  void prevChoice(int id);
  void nextChoice(int id);
  std::vector<int> const& getUsed(void) const;
  void setGamepad(int pad);
  void init();

private:
  std::vector<std::string>  _selecter;
  std::vector<int>          _used;
  int                       _gamepad;
};

#endif // ifndef LOBBYSCENE_HPP
