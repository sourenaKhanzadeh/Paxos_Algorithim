#include "gameObject.h"


class Node: public GameObject{
private:
  std::string _data;
  float _rad;
  float _drot=10.f;
  sf::CircleShape circle;
public:
  static int num;
  Node(sf::Vector2<int> pos, sf::Color color, float radius, std::string data)
  : GameObject(pos, color){
    _data = data;
    _rad = radius;
    num++;
    _drot*=_rad*num;
  }
  ~Node();
  void render(sf::RenderWindow *window) override;
  void control() override;
};

std::vector<Node*> awakeNode();
