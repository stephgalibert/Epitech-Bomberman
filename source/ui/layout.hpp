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

#include <vector>
#include <utility>
#include "mainScene.hpp"
#include "settingsScene.hpp"
#include "gameScene.hpp"
#include "controlsScene.hpp"
#include "lobbyScene.hpp"
#include "creditScene.hpp"
#include "splashArtScene.hpp"
#include "endGameScene.hpp"
#include "rankingScene.hpp"
#include "replayScene.hpp"
#include "echapScene.hpp"
#include "tipsScene.hpp"
#include "ui.hpp"

class layout
{
public:

  layout(irr::IrrlichtDevice *device);
  ~layout();

  const std::string & display();
  void  input(bbman::InputListener &listener);
  void setGamepads(irr::core::array<irr::SJoystickInfo> const& jinfo);
  std::vector<int> const& getDevices(void) const;
  bool isGameStarted(void) const;
  void backToMenu(void);
  bool isClosed(void);
  std::vector<std::pair<std::string, int> > const getVolume(void) const;
  int getIADifficulty(void) const;

  void resetPauseMenu(void);
  void displayPauseMenu(void);
  bool isResuming(void) const;
  bool isSaving(void) const;
  bool isMenuing(void) const;

  void setScore(int id, int value);
  void setTimerGlobal(int value);
  void setTimerTimeout(int value);

  void loadHUD(void);
  std::string const& getSaveName(void) const;
  void resetSaveName(void);

  void setDraw(void);
  void setVictory(void);
  void loadEndScene(void);
  bool isInGame(void) const;
private:

  void loadScene();

  ui *_ui;
  std::map<std::string, ASubLayout *>_scene;
  gameScene *_game;
  echapScene *_echap;

  std::string _currentScene;
  irr::IrrlichtDevice *_device;
  replayScene *_replay;
  endGameScene *_endGame;
};

#endif // ifndef LAYOUT_HPP_
