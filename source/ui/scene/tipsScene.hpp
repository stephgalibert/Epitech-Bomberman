/*
** tips.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 04:08:25 2016 Joffrey Escobar
*/

#ifndef  TIPSSCENE_HPP
#define  TIPSSCENE_HPP

#include "ASubLayout.hpp"

class tipsScene : public ASubLayout
{
public:

  tipsScene(ui &ui);
  ~tipsScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void loadRessources(void);
};

#endif
