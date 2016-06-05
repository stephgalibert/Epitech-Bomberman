/*
** splashArtScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun Jun 05 06:27:43 2016 Joffrey Escobar
*/

#ifndef SPLASHARTSCENE_HPP
#define SPLASHARTSCENE_HPP

#include "ASubLayout.hpp"

class splashArtScene : public ASubLayout
{
public:

  splashArtScene(ui &ui);
  ~splashArtScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void loadRessources(void);
private:
  int _time;
};

#endif
