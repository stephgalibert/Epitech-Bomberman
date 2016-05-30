/*
** gameScene.hpp for ui in /home/escoba_j/Downloads/irrlicht-1.8.3/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Mon May 30 17:40:41 2016 Joffrey Escobar
*/

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "ASubLayout.hpp"

class gameScene : public ASubLayout
{
public:

  gameScene(ui& ui);
  ~gameScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);
  void loadRessources(void);
};

#endif // ifndef GAMESCENE_HPP
