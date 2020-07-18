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

void GameObject::setColor(sf::Color col){
  _color = col;
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


sf::Vector2f GameObject::unitVector(sf::Vector2f v){
  // get norm
  float v_norm = sqrt(pow(v.x, 2) + pow(v.y, 2));
  return v/v_norm;
}
