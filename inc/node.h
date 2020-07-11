#include "gameObject.h"


class Node: public GameObject{
private:
  std::string _data;
  sf::CircleShape circle;
public:
  Node(sf::Vector2<int> pos, sf::Color color, std::string data)
  : GameObject(pos, color){_data = data;}
  ~Node();
  void render(sf::RenderWindow *window) override;
  void control() override;
};
