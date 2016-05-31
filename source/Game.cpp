//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Mon May 30 15:59:12 2016 stephane galibert
//

#include "Game.hpp"

bbman::Game::Game(void)
{
  this->_leaveGame = false;
  this->_board = new Board;
  //this->_timeout = new TimeOut;
  this->_timeout = NULL;
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

void bbman::Game::init(Irrlicht &irr, std::string const& saves)
{
  try {
    if (!saves.empty()) {
      this->_loader.load(irr, saves);
      this->_board->init(irr, this->_loader);
      this->_timeout = this->_loader.getTimeOut();
      this->_timeout->init(irr, this->_board);
    }
    else {
      this->_timeout = new TimeOut;
      this->_board->init(irr);
      this->_timeout->init(irr, this->_board);
      // BEGIN todel
      AIPlayer *ai1 = new AIPlayer;
      ai1->init(irr);
      ai1->setPosition(this->_board->getSpawnPosition(2));
      irr::core::vector3df const& pos = ai1->getPosition();
      this->_board->addPlayer(ai1);
      HumanPlayer *p1 = bbman::HumanPlayer::create();
      p1->init(irr);
      p1->setPosition(this->_board->getSpawnPosition(0));
      this->_board->addPlayer(p1);
      HumanPlayer *p2 = bbman::HumanPlayer::create();
      p2->init(irr);
      p2->setPosition(this->_board->getSpawnPosition(1));
      this->_board->addPlayer(p2);
      // END todel
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
  if (inputListener.IsKeyDown(irr::KEY_ESCAPE)) {
    this->_leaveGame = true;
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
  this->_board->update(irr, delta);
  this->_timeout->update(irr, delta);
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
  this->_camera->setPosition(irr::core::vector3df(pos.X, pos.Y + 120, 0));
}

void bbman::Game::initSound(void)
{
  this->_musicBackground.filename = "./asset/sample/TronLegacy.wav";
  try {
    this->_musicBackground.load();
    this->_musics.addSample("mbackground", this->_musicBackground);
    this->_musics.setLoop("mbackground", true);
    this->_musics.setVolumeBySample("mbackground", 50.f);
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
