#include "node.h"

#ifndef NODE_SYSTEM
#define NODE_SYSTEM

class NodeSystem{
private:
  size_t _num;
  float _rad;
  std::string _data;
  std::vector<Node*> _nodes;
  sf::RenderWindow *_window;
public:
  NodeSystem(size_t num, float rad, std::string data);
  ~NodeSystem();
  void update();
  void awake();
  size_t getSize();
};

#endif
