/*
** AIPlayer.cpp for bomberman in /home/care_j/work/bomberman/source/players
**
** Made by care_j
** Login   <care_j@epitech.net>
**
*/

#include "AIPlayer.hpp"
#include "Board.hpp"

bbman::AIPlayer::AIPlayer(void)
{
  this->_move[Direction::DIR_EAST] =
    std::bind(&bbman::AIPlayer::moveEast, this, std::placeholders::_1);
  this->_move[Direction::DIR_WEST] =
    std::bind(&bbman::AIPlayer::moveWest, this, std::placeholders::_1);
  this->_move[Direction::DIR_NORTH] =
    std::bind(&bbman::AIPlayer::moveNorth, this, std::placeholders::_1);
  this->_move[Direction::DIR_SOUTH] =
    std::bind(&bbman::AIPlayer::moveSouth, this, std::placeholders::_1);
  this->_mesh      = NULL;
  this->_isRunning = false;
  this->_mood = 0;
  this->_speed     = INITIAL_SPEED;
  this->_direction = Direction::DIR_NONE;
  this->_action = Action::ACT_NONE;
  this->_deviceID = 0;
}

size_t bbman::AIPlayer::getAPlayerID(void) const
{
  return 0;
}

bbman::AIPlayer::~AIPlayer(void)
{
  if (this->_mesh) {
    this->_mesh->remove();
  }

  for (auto& it : this->_effects) {
    delete (it);
  }
}

void bbman::AIPlayer::init(bbman::Irrlicht& irr, std::string const& color)
{
  IBomb *bomb = NULL;

  try {
    std::string txt = "./asset/media/ninja.b3d";
    this->_color = color;
    this->_mesh = irr.getSmgr()->addAnimatedMeshSceneNode(irr.getMesh(txt.data()));
    this->_binding.init("../source/binding/script.lua");
    if (this->_mesh) {
      this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->_mesh->setAnimationSpeed(0);
      this->_mesh->setScale(irr::core::vector3df(1.5f, 2.f, 1.5f));
      this->_mesh->setRotation(irr::core::vector3df(0, 180, 0));
    } else {
      throw(std::runtime_error("can not create ai " + std::to_string(this->_playerNum)));
    }
    bomb = new ExplodingBomb(this);
    bomb->setColor(color);
    addBomb(bomb);
    this->_alive = true;
  } catch (std::runtime_error const& e) {
    throw(e);
  }
}

void bbman::AIPlayer::init(bbman::Irrlicht& irr, int deviceID,
			   std::string const& color)
{
  try {
    std::string txt = "./asset/media/ninja.b3d";
    this->_color = color;
    this->_deviceID = deviceID;
    this->_mesh = irr.getSmgr()->addAnimatedMeshSceneNode(irr.getMesh(txt.data()));
    this->_binding.init("../source/binding/script.lua");
    if (this->_mesh) {
      this->_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->_mesh->setAnimationSpeed(0);
      this->_mesh->setScale(irr::core::vector3df(1.5f, 2.f, 1.5f));
      this->_mesh->setRotation(irr::core::vector3df(0, 180, 0));
    } else {
      throw(std::runtime_error("can not create ai " + std::to_string(this->_playerNum)));
    }
    addBomb(new ExplodingBomb(this));
    this->_alive = true;
  } catch (std::runtime_error const& e) {
    throw(e);
  }
}

void bbman::AIPlayer::update(bbman::Irrlicht& irr, irr::f32 delta)
{
  int retAI;
  (void)irr;

  if (this->_alive) {
    retAI = this->_binding.runAI(this->getID());
    if (retAI >= 10) {
      this->_action = bbman::ACT_BOMB;
      retAI -= 10;
    }
    else {
      this->_action = bbman::ACT_NONE;
    }
    if (retAI == 1) {
      this->_direction = Direction::DIR_EAST;
    }
    else if (retAI == 2) {
      this->_direction = Direction::DIR_WEST;
    }
    else if (retAI == 4) {
      this->_direction = Direction::DIR_NORTH;
    }
    else if (retAI == 8) {
      this->_direction = Direction::DIR_SOUTH;
    }
    else {
      this->_direction = Direction::DIR_NONE;
    }
    this->_delta = delta;
    updateEffets(delta);
  }
}

void bbman::AIPlayer::play(bbman::Irrlicht& irr, bbman::Board *board)
{
  if (this->_alive) {
    //checkDirection(board);
    if (this->_action == bbman::ACT_BOMB) {
      dropBomb(irr, board);
    }
    if (!board->isInNode(this->getPosition())) {
      this->_direction = this->_prevDirection;
    }
    move(this->_delta);
  }
}

void bbman::AIPlayer::dropBomb(bbman::Irrlicht& irr, bbman::Board *board)
{
  IBomb *newBomb = createBomb(irr);
  if (newBomb) {
    irr::core::vector3df pos = getPosition();

    pos.X = board->getScale().X / 2 + std::floor(pos.X)
      - (int)(std::floor(pos.X)) % (int)board->getScale().X;
    pos.Z = board->getScale().Z / 2 + std::floor(pos.Z)
      - (int)(std::floor(pos.Z)) % (int)board->getScale().Z;
    newBomb->setPosition(pos);
    if (!board->addBomb(newBomb)) {
      addBomb(newBomb);
    }
  }
}

void bbman::AIPlayer::addBomb(bbman::IBomb *bomb)
{
  this->_bombManager.addBomb(bomb);
}

void bbman::AIPlayer::setPosition(irr::core::vector3df const& pos)
{
  irr::f32 x = (int)(pos.X / 10.f) * 10.f;
  irr::f32 y = (int)(pos.Z / 10.f) * 10.f;

  x += (10.f / 2.f);
  y += (10.f / 2.f);
  this->_mesh->setPosition(irr::core::vector3df(x, 0.f, y));
  this->_mesh->updateAbsolutePosition();
}

irr::core::vector3df const& bbman::AIPlayer::getPosition(void) const
{
  return this->_mesh->getPosition();
}

irr::core::aabbox3df const bbman::AIPlayer::getBoundingBox(void) const
{
  if (this->_alive) {
    return this->_mesh->getTransformedBoundingBox();
  }
  return irr::core::aabbox3df();
}

bool bbman::AIPlayer::isColliding(irr::core::aabbox3df const& box) const
{
  if (this->_alive) {
    return box.intersectsWithBox(this->getBoundingBox());
  }
  return false;
}

void bbman::AIPlayer::explode(Board *board)
{
  if (this->_alive) {
    this->_alive = false;
    //this->_mesh->remove();
    //this->_mesh = NULL;
    this->_mesh->setVisible(false);
    std::cerr << "ia" << getID() << "died" << std::endl;
  }
}

void bbman::AIPlayer::playExplosion(void)
{

}

bool bbman::AIPlayer::isRunning(void) const
{
  return this->_isRunning;
}

irr::core::vector3d<irr::s32>const& bbman::AIPlayer::getPosInMap(irr::core::vector3df const& scale)
{
  this->_posInMap.X = getPosition().X / scale.X;
  this->_posInMap.Z = getPosition().Z / scale.Z;
  return this->_posInMap;
}

bbman::BombManager const& bbman::AIPlayer::getBombManager(void) const
{
  return this->_bombManager;
}

std::list<bbman::IEffect *>const& bbman::AIPlayer::getEffects(void) const
{
  return this->_effects;
}

void bbman::AIPlayer::setRotation(irr::s32 rotation)
{
  if (this->_mesh) {
    this->_mesh->setRotation(irr::core::vector3df(0, rotation, 0));
  }
}

irr::s32 bbman::AIPlayer::getRotation(void) const
{
  return (irr::s32)this->_mesh->getRotation().Y;
}

void bbman::AIPlayer::setAlive(bool v)
{
  this->_alive = v;
  if (!this->_alive && this->_mesh) {
    this->_mesh->setVisible(false);
  }
}

std::string const& bbman::AIPlayer::getColor(void) const
{
  return (this->_color);
}

void bbman::AIPlayer::setColor(std::string const& color)
{
  this->_color = color;
}

bool bbman::AIPlayer::isAlive(void) const
{
  return (this->_alive);
}

bool bbman::AIPlayer::hasExplosed(void) const
{
  return (!this->_alive);
}

bool bbman::AIPlayer::input(bbman::InputListener& inputListener)
{
  (void)inputListener;
  return false;
}

size_t bbman::AIPlayer::getSpeed(void) const
{
  return this->_speed;
}

void bbman::AIPlayer::setSpeed(size_t speed)
{
  this->_speed = speed;
}

void bbman::AIPlayer::addEffect(IEffect *effect)
{
  if (this->_alive) {
    if (std::find_if(std::begin(this->_effects), std::end(this->_effects),
                     [&effect](IEffect * buff) {
                       if (effect->getEffectID() == buff->getEffectID()) {
                         buff->restart();
                       }
                       return true;

                       return false;
                     }) == std::end(this->_effects)) {
      effect->enable();
      this->_effects.push_back(effect);
    } else {
      delete (effect);
    }
  }
}

void bbman::AIPlayer::updateEffets(irr::f32 delta)
{
  for (std::list<IEffect *>::iterator it = std::begin(this->_effects);
       it != std::end(this->_effects);) {
    if ((*it)->isFinished()) {
      delete (*it);
      it = this->_effects.erase(it);
    } else {
      (*it)->update(delta);
      ++it;
    }
  }
}

/*void bbman::AIPlayer::checkDirection(bbman::Board *board)
{
  if (this->_alive) {
    if (!board->isInNode(getPosition())) {
      if ((this->_prevDirection == Direction::DIR_EAST
	   || this->_prevDirection == Direction::DIR_WEST)
	  &&
	  (this->_direction == Direction::DIR_NORTH
	 || this->_direction == Direction::DIR_SOUTH)) {
	this->_direction = Direction::DIR_NONE;
      }
      else if ((this->_prevDirection == Direction::DIR_NORTH
		|| this->_prevDirection == Direction::DIR_SOUTH)
	       &&
	       (this->_direction == Direction::DIR_EAST
		|| this->_direction == Direction::DIR_WEST)) {
	this->_direction = Direction::DIR_NONE;
      }
    }
    else if (!board->isValidMove(getPosition(), this->_direction)) {
      this->_direction = Direction::DIR_NONE;
    }
  }
  }*/

void bbman::AIPlayer::move(irr::f32 delta)
{
  if (this->_direction == Direction::DIR_NONE) {
    this->_mesh->setCurrentFrame(5);
    this->_mesh->setAnimationSpeed(0);
    this->_isRunning = false;
  } else {
    if (!this->_isRunning) {
      this->_mesh->setAnimationSpeed(15);
      this->_mesh->setFrameLoop(0, 13);
      this->_isRunning = true;
    }
    this->_move.at(this->_direction) (delta);
  }
}

void bbman::AIPlayer::moveEast(irr::f32 delta)
{
  this->_prevDirection = Direction::DIR_EAST;
  irr::core::vector3df playerPos = this->_mesh->getPosition();
  playerPos.X += this->_speed * delta;
  this->_mesh->setPosition(playerPos);
  this->_mesh->setRotation(irr::core::vector3df(0, -90, 0));
}

void bbman::AIPlayer::moveWest(irr::f32 delta)
{
  this->_prevDirection = Direction::DIR_WEST;
  irr::core::vector3df playerPos = this->_mesh->getPosition();
  playerPos.X -= this->_speed * delta;
  this->_mesh->setPosition(playerPos);
  this->_mesh->setRotation(irr::core::vector3df(0, 90, 0));
}

void bbman::AIPlayer::moveNorth(irr::f32 delta)
{
  this->_prevDirection = Direction::DIR_NORTH;
  irr::core::vector3df playerPos = this->_mesh->getPosition();
  playerPos.Z += this->_speed * delta;
  this->_mesh->setPosition(playerPos);
  this->_mesh->setRotation(irr::core::vector3df(0, 180, 0));
}

void bbman::AIPlayer::moveSouth(irr::f32 delta)
{
  this->_prevDirection = Direction::DIR_SOUTH;
  irr::core::vector3df playerPos = this->_mesh->getPosition();
  playerPos.Z -= this->_speed * delta;
  this->_mesh->setPosition(playerPos);
  this->_mesh->setRotation(irr::core::vector3df(0, 0, 0));
}

bbman::IBomb * bbman::AIPlayer::createBomb(bbman::Irrlicht& irr)
{
  IBomb *bomb = this->_bombManager.getSelectedBomb();
  if (bomb) {
  bomb->addRange(this->_power);
  bomb->init(irr, _color);
  }
  return bomb;
}

size_t bbman::AIPlayer::getPlayerNumber(void) const
{
  return (this->_playerNum);
}

void bbman::AIPlayer::setDeviceID(int id)
{
  this->_deviceID = 0;
}

int bbman::AIPlayer::getDeviceID(void) const
{
  return (this->_deviceID);
}
