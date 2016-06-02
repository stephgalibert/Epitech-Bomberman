/*
** layout.hpp for UI in /home/escoba_j/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sun May 29 02:13:41 2016 Joffrey Escobar
*/

#ifndef LAYOUT_HPP_
#define LAYOUT_HPP_

#include "mainScene.hpp"
#include "settingsScene.hpp"
#include "gameScene.hpp"
#include "controlsScene.hpp"
#include "lobbyScene.hpp"
#include "ui.hpp"

class layout
{
public:

  layout(irr::IrrlichtDevice *device);
  ~layout();

  const std::string & display();
  void  input(bbman::InputListener &listener);
  bool isGameStarted(void) const;
  void backToMenu(void);
  bool isClosed(void);
private:

  void loadScene();

  ui *_ui;
  std::map<std::string, ASubLayout *>_scene;
  std::string _currentScene;
  irr::IrrlichtDevice *_device;
};

#endif // ifndef LAYOUT_HPP_
