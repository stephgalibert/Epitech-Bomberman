/*
** creditScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat Jun 04 03:26:24 2016 Joffrey Escobar
*/
#ifndef CREDITSCENE_HPP
#define CREDITSCENE_HPP

#include "ASubLayout.hpp"

class creditScene : public ASubLayout
{
public:

  creditScene(ui &ui);
  ~creditScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void loadRessources(void);
};

#endif
