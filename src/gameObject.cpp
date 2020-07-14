#include "../inc/gameObject.h"


GameObject::GameObject(sf::Vector2<int> pos, sf::Color color){
  _pos = pos;
  _color = color;
}


GameObject::~GameObject(){

}


void GameObject::update(sf::RenderWindow *window){
  render(window);
  control();
}

// getters
sf::Vector2<int> GameObject::getPos(){
  return _pos;
}

sf::Color GameObject::getColor(){
  return _color;
}
