#include "node.h"

#ifndef NODE_SYSTEM
#define NODE_SYSTEM

std::string random_string();
inline sf::Vector2f norm(sf::Vector2f v);
inline sf::Vector2f norm(sf::Vector2f v, sf::Vector2f b);


class NodeSystem{
private:
  float _rad;
  int _scaler = 1;
  std::string _data;
  int _num;
  std::vector<Node*> _nodes;
  void _promise();
  bool _is_promise = false;
  int leader_index;
public:
  NodeSystem(int num, float rad, std::string data);
  ~NodeSystem();
  void update();
  void awake();
  int getSize();
};

#endif
