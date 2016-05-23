//
// AStar.hpp for indie in /home/galibe_s/rendu/bomberman/source
//
// Made by stephane galibert
// Login   <galibe_s@epitech.net>
//
// Started on  Sat May 21 16:44:05 2016 stephane galibert
// Last update Sat May 21 16:49:53 2016 stephane galibert
//

#ifndef _ASTAR_HPP_
# define _ASTAR_HPP_

# include <irrlicht.h>
# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <list>
# include <stdexcept>
# include <algorithm>

# include "Map.hpp"

namespace bbman
{
  template<typename T>
  class AStar
  {
  public:
    AStar(void);
    ~AStar(void);
    void addBlockType(T const& blocktype);
    void compute(Map<T> &map, irr::core::vector3df const& p1,
		 irr::core::vector3df const& p2);
    irr::core::vector3df getNextResult(void);
    void reset(void);
  private:
    struct Node
    {
      Node(void);
      Node(irr::core::vector3df const& pos);
      Node &operator=(Node const& other);
      irr::core::vector3df parent;
      irr::core::vector3df pos;
      float g;
      float h;
      float f;
    };
    void addAdjCase(bbman::Map<T> &map, Node const& p,
		    irr::core::vector3df const& obj);
    float getDistance(irr::core::vector3df const& p1,
		      irr::core::vector3df const& p2) const;
    bool findInList(Node const& p, std::vector<Node> &list) const;
    void addInList(Node node, std::vector<Node> &list);
    void addInCloseList(Node const& p);
    Node &getNode(irr::core::vector3df const& p, std::vector<Node> &list) const;
    Node getBestNode(std::vector<Node> &list) const;
    void retrievePath(irr::core::vector3df const& begin);
    bool isBlock(T const& id);
    std::vector<Node> _listClose;
    std::vector<Node> _listOpen;
    std::vector<T> _blockType;
    Node _end;
    std::list<irr::core::vector3df> _path;
  };

  template<typename T>
  AStar<T>::AStar(void) {}

  template<typename T>
  AStar<T>::~AStar(void) {}

  template<typename T>
  void AStar<T>::addBlockType(T const& blocktype)
  {
    _blockType.push_back(blocktype);
  }

  template<typename T>
  void AStar<T>::compute(Map<T> &map, irr::core::vector3df const& p1,
			 irr::core::vector3df const& p2)
  {
    Node begin(p1);
    bool found = false;

    if (p1 == p2)
      {
	found = true;
	_path.push_back(p2);
      }
    addInList(begin, _listOpen);
    while (!_listOpen.empty() && !found)
      {
	Node u = getBestNode(_listOpen);
	if (u.pos == p2)
	  {
	    _end = u;
	    addInCloseList(u);
	    retrievePath(begin.pos);
	    found = true;
	  }
	if (!found)
	  {
	    addAdjCase(map, u, p2);
	    addInCloseList(u);
	  }
      }
  }

  template<typename T>
  typename irr::core::vector3df AStar<T>::getNextResult(void)
  {
    irr::core::vector3df ret;

    if (_path.size() > 0)
      {
	ret = *_path.cbegin();
	_path.pop_front();
      }
    else
      reset();
    return (ret);
  }

  template<typename T>
  void AStar<T>::reset(void)
  {
    _listOpen.erase(_listOpen.begin(), _listOpen.end());
    _listClose.erase(_listClose.begin(), _listClose.end());
    _path.erase(_path.begin(), _path.end());
  }

  template<typename T>
  bbman::AStar<T>::Node::Node(void)
  {
    f = 0;
    h = 0;
    g = 0;
  }

  template<typename T>
  bbman::AStar<T>::Node::Node(irr::core::vector3df const& pos)
  {
    this->pos = pos;
    f = 0;
    h = 0;
    g = 0;
  }

  template<typename T>
  typename AStar<T>::Node &AStar<T>::Node::operator=(AStar<T>::Node const& other)
  {
    parent = other.parent;
    pos = other.pos;
    g = other.g;
    h = other.h;
    f = other.f;
    return *this;
  }

  template<typename T>
  void AStar<T>::addAdjCase(Map<T> &map, Node const& u,
			    irr::core::vector3df const& obj)
  {
    irr::core::vector3df current;
    for (int i = (int)u.pos.x - 1 ; i <= (int)u.pos.x + 1 ; ++i)
      for (int j = (int)u.pos.y - 1 ; j <= (int)u.pos.y + 1 ; ++j)
	{
	  Node v;
	  v.pos = irr::core::vector3df(i, j);
	  if (j > -1 && j < (int)map.h && i > -1 && i < (int)map.w
	      && !isBlock(map.content[j][i])
	      && u.pos != v.pos
	      && (i == (int)u.pos.x || j == (int)u.pos.y))
	    {
	      if (!findInList(v, _listClose) && !findInList(v, _listOpen))
		{
		  v.parent = u.pos;
		  v.g = u.g + 10;
		  v.h = getDistance(v.pos, obj);
		  v.f = v.g + v.h;
		  addInList(v, _listOpen);
		}
	    }
	}
  }

  template<typename T>
  float AStar<T>::getDistance(irr::core::vector3df const& p1, irr::core::vector3df const& p2) const
  {
    return (sqrt((p1.X - p2.X) * (p1.X - p2.X) + (p1.Z - p2.Z) * (p1.Z - p2.Z)));
  }

  template<typename T>
  bool AStar<T>::findInList(Node const& p, std::vector<Node> &list) const
  {
    for (auto &it : list)
      if (it.pos == p.pos)
	return (true);
    return (false);
  }

  template<typename T>
  void AStar<T>::addInList(Node node, std::vector<Node> &list)
  {
    list.push_back(node);
  }

  template<typename T>
  void AStar<T>::addInCloseList(AStar<T>::Node const& p)
  {
    addInList(p, _listClose);
    typename std::vector<Node>::iterator it = _listOpen.begin();
    while (it != _listOpen.end())
      {
	if (it->pos == p.pos)
	  it = _listOpen.erase(it);
	else
	  ++it;
      }
  }

  template<typename T>
  typename AStar<T>::Node &AStar<T>::getNode(irr::core::vector3df const& p, std::vector<AStar<T>::Node> &list) const
  {
    for (auto &it : list)
      if (it.pos == p)
	return it;
    throw std::runtime_error("Node not found");
  }

  template<typename T>
  typename AStar<T>::Node AStar<T>::getBestNode(std::vector<AStar<T>::Node> &list) const
  {
    float min = list.cbegin()->f;
    Node pos = *list.cbegin();
    for (auto &it : list)
      if (it.f < min)
	{
	  min = it.f;
	  pos = it;
	}
    return (pos);
  }

  template<typename T>
  void AStar<T>::retrievePath(irr::core::vector3df const& begin)
  {
    Node &node = getNode(_end.pos, _listClose);
    irr::core::vector3df prev = node.parent;
    irr::core::vector3df pos = node.pos;
    _path.push_front(pos);
    while (prev != begin)
      {
	pos = prev;
	_path.push_front(prev);
	node = getNode(node.parent, _listClose);
	prev = node.parent;
      }
  }

  template<typename T>
  bool AStar<T>::isBlock(T const& id)
  {
    return (std::find_if(std::begin(this->_blockType), std::end(this->_blockType),
			 [&id](T const& itId) {
			   return (itId == id);
			 }) != std::end(this->_blockType));
  }
}

#endif /* !_ASTAR_HPP_ */
