#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "settings.h"

class GameObject{
private:
  sf::Vector2<int> _pos;
  sf::Color _color;
protected:
  virtual void render() = 0;
  virtual void control() = 0;
public:
  static sf::Vector2f unitVector(sf::Vector2f v);
  static sf::RenderWindow *window;
  GameObject(sf::Vector2<int> pos, sf::Color color);
  ~GameObject();
  void setPos(sf::Vector2<int> val);
  sf::Vector2<int> getPos();
  sf::Color getColor();
  void update();
};

#endif
