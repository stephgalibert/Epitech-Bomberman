/*
** settingsScene.hpp for UI in /home/escoba_j/Downloads/irrlicht-1.8.3/ui/scene
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 03:00:07 2016 Joffrey Escobar
*/

#ifndef SETTINGSSCENE_HPP
#define SETTINGSSCENE_HPP

#include <vector>
#include <string>
#include <utility>
#include "ASubLayout.hpp"

class settingsScene : public ASubLayout
{
public:

  settingsScene(ui &ui);
  ~settingsScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);

  void loadRessources(void);
  void loadIA(void);
  void loadSound(void);

std::vector<std::pair<std::string, int> > const getVolume(void) const;
int getIADifficulty(void) const;

private:
  int   _music;
  int   _effect;
  int   _iaLevel;
};

#endif
