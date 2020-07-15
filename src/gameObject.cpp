#include "../inc/gameObject.h"

sf::RenderWindow* GameObject::window = NULL;

GameObject::GameObject(sf::Vector2<int> pos, sf::Color color){
  _pos = pos;
  _color = color;
}


GameObject::~GameObject(){

}

void GameObject::setPos(sf::Vector2<int> val){
  _pos = val;
}

void GameObject::update(){
  render();
  control();
}

// getters
sf::Vector2<int> GameObject::getPos(){
  return _pos;
}

sf::Color GameObject::getColor(){
  return _color;
}
