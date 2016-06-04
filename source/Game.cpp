//
// BoardGame.cpp for indie in /home/galibe_s/irrlicht/irrlicht-1.8.3/test
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Wed May  4 19:02:00 2016 stephane galibert
// Last update Sat Jun  4 12:29:25 2016 stephane galibert
//

#include "Game.hpp"

bbman::Game::Game(void)
{
  this->_leaveGame = false;
  this->_board = new Board;
  this->_timeout = NULL;
  this->_layout = NULL;
  this->_delta = 0;
  this->_pause = false;
  this->_delta_pause = 0;
}

bbman::Game::~Game(void)
{
  if (this->_timeout) {
    delete (this->_timeout);
  }
  if (this->_board) {
    delete (this->_board);
  }
  AIPlayer::NumberOfPlayer = 0;
  HumanPlayer::NumberOfPlayer = 0;
  APlayer::NumberOfPlayer = 0;
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

    std::vector<std::pair<std::string, int> > const vol = _layout->getVolume();
    for (auto &it : vol) {
      tools::StaticTools::volume(it.first, it.second);
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

    if (this->_delta_pause > 0.5) {
      this->_pause = !this->_pause;
      this->_layout->pauseMenu(this->_pause);
      this->_delta_pause = 0;
    }
    return (true);
  }
  else {
    this->_board->input(inputListener);
  }
  return (false);
}

void bbman::Game::update(bbman::Irrlicht &irr, irr::f32 delta)
{
  if (this->_pause) {
    if (this->_layout->isResuming()) {
      this->_pause = false;
    }
    if (this->_layout->isMenuing()) {
      this->_leaveGame = true;
    }
    if (this->_layout->isSaving()) {
      save("./save.txt");
      this->_pause = false;
    }
    this->_layout->resetPauseMenu();
  } else if (this->_board->hasWinners()) {
    APlayer *winner = this->_board->getWinner();
    irr::core::vector3df const& cpos = this->_camera->getPosition();
    irr::core::vector3df const& npos = winner->getPosition();
    cameraTargetSmoothAnimation(delta, this->_camera->getTarget(), npos);
    if (this->_camera->getTarget() == winner->getPosition()) {
      irr::core::vector3df fpos(npos.X, npos.Y + 50, npos.Z - 60);
      cameraPositionSmoothAnimation(delta, this->_camera->getPosition(), fpos);
    }
  } else {
    this->_board->update(irr, delta);
    this->_timeout->update(irr, delta);
    this->_delta += delta;
  }
  this->_delta_pause += delta;
}

bool bbman::Game::leaveGame(void) const
{
  return (this->_leaveGame);
}

void bbman::Game::cameraPositionSmoothAnimation(irr::f32 delta,
						irr::core::vector3df const& cpos,
						irr::core::vector3df const& npos)
{
  irr::core::vector3df res = cpos;

  if (res.X > npos.X + 1.5f)
    res.X -= (fabs(npos.X) * delta);
  else if (res.X < npos.X - 1.5f)
    res.X += (fabs(npos.X) * delta);
  else
    res.X = npos.X;

  if (res.Y > npos.Y + 1.5f)
    res.Y -= (fabs(npos.Y) * delta);
  else if (res.Y < npos.Y - 1.5f)
    res.Y += (fabs(npos.Y) * delta);
  else
    res.Y = npos.Y;

  if (res.Z > npos.Z + 2.f)
    res.Z -= (fabs(npos.Z) * delta);
  else if (res.Z < npos.Z - 2.f)
    res.Z += (fabs(npos.Z) * delta);
  else
    res.Z = npos.Z;
  this->_camera->setPosition(res);
}

void bbman::Game::cameraTargetSmoothAnimation(irr::f32 delta,
					      irr::core::vector3df const& cpos,
					      irr::core::vector3df const& npos)
{
  irr::core::vector3df res = cpos;

  if (res.X > npos.X + 1.5f)
    res.X -= (fabs(npos.X) * delta);
  else if (res.X < npos.X - 1.5f)
    res.X += (fabs(npos.X) * (delta));
  else
    res.X = npos.X;

  if (res.Y > npos.Y + 1.5f)
    res.Y -= (fabs(npos.Y) * delta);
  else if (res.Y < npos.Y - 1.5f)
    res.Y += (fabs(npos.Y) * (delta));
  else
    res.Y = npos.Y;

  if (res.Z > npos.Z + 1.5f)
    res.Z -= (fabs(npos.Z) * delta);
  else if (res.Z < npos.Z - 1.5f)
    res.Z += (fabs(npos.Z) * (delta));
  else
    res.Z = npos.Z;
  this->_camera->setTarget(res);
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
