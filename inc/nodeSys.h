#include "node.h"

#ifndef NODE_SYSTEM
#define NODE_SYSTEM

class NodeSystem{
private:
  float _rad;
  std::string _data;
  int _num;
  std::vector<Node*> _nodes;
  void _promise();
  int leader_index;
public:
  NodeSystem(int num, float rad, std::string data);
  ~NodeSystem();
  void update();
  void awake();
  int getSize();
};

#endif
