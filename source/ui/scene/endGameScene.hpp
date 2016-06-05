/*
** endGameScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun Jun 05 09:19:20 2016 Joffrey Escobar
*/

#ifndef  ENDGAMESCENE_HPP
#define  ENDGAMESCENE_HPP

#include "ASubLayout.hpp"

class endGameScene : public ASubLayout
{
public:

  endGameScene(ui &ui);
  ~endGameScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void setDraw();
  void setVictory();

  void loadRessources(void);
};

#endif
