#include "gameObject.h"

#ifndef NODE
#define NODE

bool inRange(unsigned low, unsigned high, unsigned x);

class Node: public GameObject{
private:
  std::string _data;
  float _rad;
  bool _leader = false;
  bool _drag = false;
  sf::CircleShape circle;
  void _mouse_drag(sf::Vector2<int> pos, sf::Vector2i mouse_pos, bool mouse_col[2]);
  void _select_leader(sf::Vector2<int> pos, sf::Vector2i mouse_pos, bool mouse_col[2]);
public:
  bool recieved = false;
  bool sent = false;
  bool data_confirmed = false;
  float scaler = 1;

  static int num;
  static bool leader_elected;
  static int confirms;

  Node(sf::Vector2<int> pos, sf::Color color, float radius, std::string data)
  : GameObject(pos, color){
    _data = data;
    _rad = radius;
    num++;
  }
  ~Node();
  void render() override;
  void control() override;
  bool isLeader();
  void appendData(std::string val);
  std::string getData(){return _data;}
  void reset();
};


#endif
