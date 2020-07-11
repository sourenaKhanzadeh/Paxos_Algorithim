#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include "settings.h"

class GameObejct{
private:
  sf::Vector2<int> _pos;
  sf::Color _color;
protected:
  virtual void render() = 0;
  virtual void control() = 0;
public:
  GameObejct(sf::Vector2<int> pos, sf::Color color);
  ~GameObejct();
  sf::Vector2<int> getPos();
  sf::color getColor();
  void update();
};

#endif
