//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Fri Jun  3 23:58:00 2016 stephane galibert
//

#include "Game.hpp"

bbman::Game::Game(void)
{
  this->_leaveGame = false;
  this->_board = new Board;
  this->_timeout = NULL;
  this->_layout = NULL;
  this->_delta = 0;
}

bbman::Game::~Game(void)
{
  if (this->_timeout) {
    delete (this->_timeout);
  }
  if (this->_board) {
    delete (this->_board);
  }
}

void bbman::Game::init(Irrlicht &irr, layout *layout, std::string const& saves)
{
  try {
    this->_layout = layout;
    if (!saves.empty()) {
      this->_loader.load(irr, saves);
      this->_board->init(irr, this->_loader);
      this->_timeout = this->_loader.getTimeOut();
      this->_timeout->init(irr, this->_board);
    }
    else {
      this->_board->init(irr);
      this->_timeout = new TimeOut;
      this->_timeout->init(irr, this->_board);
      createPlayers(irr);
    }
    initCamera(irr);
    initSound();
    boardBinding(this->_board);
  } catch (std::runtime_error const& e) {
    throw (e);
  }
}

bool bbman::Game::input(InputListener &inputListener)
{
  this->_layout->input(inputListener);
  if (inputListener.IsKeyDown(irr::KEY_ESCAPE)) {
    //this->_leaveGame = true;
    this->_layout->displayPauseMenu();
    // mettre le jeu en pause
    return (true);
  }
  else if (inputListener.IsKeyDown(irr::KEY_KEY_P)) {
    save("./save.txt");
    return (true);
  }
  else {
    this->_board->input(inputListener);
  }
  return (false);
}

void bbman::Game::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  /*if (this->_board->hasWinners()) {
    APlayer *winner = this->_board->getWinner();
    irr::core::vector3df const& cpos = this->_camera->getPosition();
    irr::core::vector3df const& npos = winner->getPosition();

    float x = 45 * std::cos(1 / delta * (2 * 3.1415));
    float y = 45 * std::sin(1 / delta * (2 * 3.1415));
    float z = std::atan2(y, x) + 3.1415f / 2;

    this->_camera->setTarget(winner->getPosition());
    this->_camera->setPosition(irr::core::vector3df(, y, z));
    } else {*/
    this->_board->update(irr, delta);
    this->_timeout->update(irr, delta);
    //}
}

bool bbman::Game::leaveGame(void) const
{
  return (this->_leaveGame);
}

void bbman::Game::initCamera(bbman::Irrlicht &irr)
{
  irr::core::vector3df pos;

  pos = this->_board->getPosition();
  this->_camera = irr.getSmgr()->addCameraSceneNode();
  this->_camera->setTarget(irr::core::vector3df(pos.X, pos.Y, pos.Z));
  this->_camera->setPosition(irr::core::vector3df(pos.X, pos.Y + 120, 10));
}

void bbman::Game::initSound(void)
{
  this->_musicBackground.filename = "./asset/sample/TronLegacy.wav";
  try {
    this->_musicBackground.load();
    this->_musics.addSample("mbackground", this->_musicBackground);
    this->_musics.setLoop("mbackground", true);
    this->_musics.setVolumeBySample("mbackground", tools::StaticTools::volume("music"));
    this->_musics.play("mbackground");
  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << std::endl;
  }
}

void bbman::Game::save(std::string const& fname)
{
  std::ofstream ofs(fname.c_str(), std::ifstream::out);
  if (ofs) {
    ofs << *this->_board;
    ofs << "TIMEOUT_BEGIN" << std::endl;
    ofs << *this->_timeout;
    ofs << "TIMEOUT_END" << std::endl;
  }
  else {
    throw (std::runtime_error("can not create ./save.txt"));
  }
}

void bbman::Game::createPlayers(Irrlicht &irr)
{
  std::vector<int> const& data = this->_layout->getDevices();
  std::string color;

  for (int i = 0 ; i < data.size() ; ++i) {
    if (i == 0)
      color = "Blue";
    else if (i == 1)
      color = "Orange";
    else if (i == 2)
      color = "Green";
    else
      color = "Purple";
    if (data[i] == -1) {
      AIPlayer *ai = new AIPlayer;
      ai->init(irr, color);
      ai->setPosition(this->_board->getSpawnPosition(i));
      this->_board->addPlayer(ai);
    } else {
      HumanPlayer *p1 = new HumanPlayer;
      p1->init(irr, data[i], color);
      p1->setPosition(this->_board->getSpawnPosition(i));
      this->_board->addPlayer(p1);
    }
  }
}
