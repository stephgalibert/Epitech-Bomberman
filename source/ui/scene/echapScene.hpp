/*
** echapScene.hpp for bomberman in /home/escoba_j/rendu/bomberman/source/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Fri Jun 03 22:23:38 2016 Joffrey Escobar
*/

#ifndef ECHAPSCENE_HPP
#define ECHAPSCENE_HPP

#include "ASubLayout.hpp"

class echapScene : public ASubLayout
{
public:

  echapScene(ui& ui);
  ~echapScene(void);

  void loadScene(void);
  void updateRuntime(void);
  void manageEvent(bbman::InputListener &listener);
  void loadRessources(void);

  void reset(void);
  bool isResuming(void) const;
  bool isSaving(void) const;
  bool isMenuing(void) const;
private:
  bool _resume;
  bool _save;
  bool _menu;
};

#endif // ifndef ECHAPSCENE_HPP
