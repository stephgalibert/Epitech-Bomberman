/*
** controlsScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Tue May 31 18:14:01 2016 Joffrey Escobar
*/

#ifndef CONTROLSSCENE_HPP
#define CONTROLSSCENE_HPP

#include "ASubLayout.hpp"

class controlsScene : public ASubLayout
{
public:

  controlsScene(ui& ui);
  ~controlsScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);
  void loadRessources(void);
};

#endif // ifndef CONTROLSSCENE_HPP
