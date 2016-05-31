/*
** ASubLayout.hpp for UI in /home/escoba_j/ui
**
** Made by Joffrey Escobar
** Login   <escoba_j@epitech.net>
**
** Started on  Sat May 28 22:52:38 2016 Joffrey Escobar
*/


#ifndef ASUBLAYOUT_HPP_
#define ASUBLAYOUT_HPP_

#include "ui.hpp"
#include "InputListener.hpp"

//#define GETSTATE listener.getState()
//#define GETPOSITION listener.getPosition()
#define MEDIAPATH "../source/ui/scene/media/"

class ASubLayout
{
public:

  ASubLayout(ui& ui, std::string name);
  ~ASubLayout(void);

  void               setReturnMsg(const std::string& msg);
  const std::string& getName();

  void               initScene();

  virtual void       loadRessources()    = 0;
  virtual void       loadScene(void)     = 0;
  virtual void       updateRuntime(void) = 0;
  virtual void       manageEvent(bbman::InputListener &listener)   = 0;
  const std::string& display(void);
  bool isGameStarted(void) const;
  bool isClosed(void) const;
  void setStartGame(bool value);
protected:

  ui& _ui;
  std::string _name;
  std::string _nextScene;
  std::string _returnMsg;
  irr::core::position2d<irr::s32> _mousePosition;
  bool _startGame;
  bool _closed;
};

#endif // ifndef ASUBLAYOUT_HPP_
