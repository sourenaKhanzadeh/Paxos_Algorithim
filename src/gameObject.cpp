#include "../inc/gameObject.h"


GameObejct::GameObejct(sf::Vector2<int> pos, sf::Color color){
  _pos = pos;
  _color = color;
}


GameObejct::~GameObejct(){

}

void GameObejct::update(){

}

// getters
sf::Vector2<int> GameObejct::getPos(){
  return _pos;
}

sf::Color GameObejct::getColor(){
  return _color;
}
