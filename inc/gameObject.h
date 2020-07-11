#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "settings.h"

class GameObject{
private:
  sf::Vector2<int> _pos;
  sf::Color _color;
protected:
  virtual void render(sf::RenderWindow *window) = 0;
  virtual void control() = 0;
public:
  GameObject(sf::Vector2<int> pos, sf::Color color);
  ~GameObject();
  sf::Vector2<int> getPos();
  sf::Color getColor();
  void update(sf::RenderWindow *window);
};

#endif
