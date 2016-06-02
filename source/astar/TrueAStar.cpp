//

// TrueAStar.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 21 16:44:05 2016 stephane galibert
// Last update Wed Jun  1 19:38:59 2016 jeremy Care
//

#include "TrueAStar.hpp"

bbman::TrueAStar::TrueAStar(void) {}


bbman::TrueAStar::~TrueAStar(void) {}


void bbman::TrueAStar::addBlockType(bbman::ItemID const& blocktype)
{
  _blockType.push_back(blocktype);
}

void bbman::TrueAStar::compute(const Map<bbman::Cell>& map, irr::core::vector3d<irr::s32>const& p1,
                        irr::core::vector3d<irr::s32>const& p2)
{
  Node begin(p1);
  bool found = false;
  
  this->_begin = p1;
  if (p1 == p2) {
    found = true;
    _path.push_back(p2);
  }
  addInList(begin, _listOpen);

  while (!_listOpen.empty() && !found) {
    Node u = getBestNode(_listOpen);

    if (u.pos == p2) {
      _end = u;
      addInCloseList(u);
      retrievePath(begin.pos);
      found = true;
    }

    if (!found) {
      addAdjCase(map, u, p2);
      addInCloseList(u);
    }
  }
}

irr::core::vector3d<irr::s32>bbman::TrueAStar::getNextResult(void)
{
  irr::core::vector3d<irr::s32> ret = this->_begin;

  if (_path.size() > 0) {
    ret = *_path.cbegin();
    _path.pop_front();
  } else {
    reset();
  }
  return ret;
}

size_t bbman::TrueAStar::getSize(void)
{
  return _path.size();
}

void bbman::TrueAStar::reset(void)
{
  _listOpen.erase(_listOpen.begin(), _listOpen.end());
  _listClose.erase(_listClose.begin(), _listClose.end());
  _path.erase(_path.begin(), _path.end());
}

bbman::TrueAStar::Node::Node(void)
{
  f = 0;
  h = 0;
  g = 0;
}

bbman::TrueAStar::Node::Node(irr::core::vector3d<irr::s32>const& pos)
{
  this->pos = pos;
  f         = 0;
  h         = 0;
  g         = 0;
}

bbman::TrueAStar::Node& bbman::TrueAStar::Node::operator=(bbman::TrueAStar::Node const& other)
{
  parent = other.parent;
  pos    = other.pos;
  g      = other.g;
  h      = other.h;
  f      = other.f;
  return *this;
}

void bbman::TrueAStar::addAdjCase(const Map<bbman::Cell>& map, Node const& u,
                           irr::core::vector3d<irr::s32>const& obj)
{
  irr::core::vector3d<irr::s32> current;

  for (int i = (int)u.pos.X - 1; i <= (int)u.pos.X + 1; ++i) {
    for (int j = (int)u.pos.Z - 1; j <= (int)u.pos.Z + 1; ++j)
    {
      Node v;
      v.pos = irr::core::vector3d<irr::s32>(i, 0, j);

      if (j > -1 && j < (int)map.h && i > -1 && i < (int)map.w
          && !isBlock(map.content[j][i].id)
          && u.pos != v.pos
          && (i == (int)u.pos.X || j == (int)u.pos.Z)) {
        if (!findInList(v, _listClose) && !findInList(v, _listOpen)) {
          v.parent = u.pos;
          v.g      = u.g + 10;
          v.h      = getDistance(v.pos, obj);
          v.f      = v.g + v.h;
          addInList(v, _listOpen);
        }
      }
    }
  }
}

float bbman::TrueAStar::getDistance(irr::core::vector3d<irr::s32>const& p1, irr::core::vector3d<irr::s32>const& p2) const
{
  return sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Z - p2.Z) * (p1.Z - p2.Z));
}

bool bbman::TrueAStar::findInList(Node const& p, std::vector<Node>& list) const
{
  for (auto& it : list) {
    if (it.pos == p.pos) {
      return true;
    }
  }
  return false;
}

void bbman::TrueAStar::addInList(Node node, std::vector<Node>& list)
{
  list.push_back(node);
}

void bbman::TrueAStar::addInCloseList(bbman::TrueAStar::Node const& p)
{
  addInList(p, _listClose);
  std::vector<Node>::iterator it = _listOpen.begin();

  while (it != _listOpen.end()) {
    if (it->pos == p.pos) {
      it = _listOpen.erase(it);
    } else {
      ++it;
    }
  }
}

bbman::TrueAStar::Node& bbman::TrueAStar::getNode(irr::core::vector3d<irr::s32>const& p, std::vector<bbman::TrueAStar::Node>& list) const
{
  for (auto& it : list) {
    if (it.pos == p) {
      return it;
    }
  }
  std::cerr << p.X << " " << p.Y << " " << p.Z << std::endl;
  throw std::runtime_error("Node not found");
}

bbman::TrueAStar::Node bbman::TrueAStar::getBestNode(std::vector<bbman::TrueAStar::Node>& list) const
{
  float min = list.cbegin()->f;
  Node  pos = *list.cbegin();

  for (auto& it : list) {
    if (it.f < min) {
      min = it.f;
      pos = it;
    }
  }
  return pos;
}

void bbman::TrueAStar::retrievePath(irr::core::vector3d<irr::s32>const& begin)
{
  Node& node = getNode(_end.pos, _listClose);

  irr::core::vector3d<irr::s32> prev = node.parent;
  irr::core::vector3d<irr::s32> pos  = node.pos;
  _path.push_front(pos);

  while (prev != begin) {
    pos = prev;
    _path.push_front(prev);
    node = getNode(node.parent, _listClose);
    prev = node.parent;
  }
}

bool bbman::TrueAStar::isBlock(bbman::ItemID const& id)
{
  return std::find_if(std::begin(this->_blockType), std::end(this->_blockType),
                      [&id](bbman::ItemID const & itId) {
                        return (itId == id);
                      }) != std::end(this->_blockType);
}
