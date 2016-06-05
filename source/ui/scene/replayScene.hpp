/*
** replayScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 03:57:34 2016 Joffrey Escobar
*/

#ifndef REPLAYSCENE_HPP
#define REPLAYSCENE_HPP

#include "ASubLayout.hpp"
#include "SaveInfo.hpp"

class replayScene : public ASubLayout
{
public:

  replayScene(ui &ui);
  ~replayScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void loadRessources(void);
  std::string const& getSaveName(void) const;
  void resetSaveName(void);
private:
  std::string _name;
  bbman::SaveInfo _info;
  bool            _hasSave;
};

#endif
