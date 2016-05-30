/*
** mainScene.hpp for UI in /home/escoba_j/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 28 23:40:07 2016 Joffrey Escobar
*/

#ifndef MAINSCENE_HPP_
#define MAINSCENE_HPP_

#include "ASubLayout.hpp"

class mainScene : public ASubLayout
{
public:

  mainScene(ui &ui);
  ~mainScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

private:
  void loadRessources(void);
  void displayIcon(void);
  void createLabel(void);
  void createAlveole(int x, int y, const std::string &name);
};

#endif
