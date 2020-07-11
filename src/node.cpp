#include "../inc/node.h"


Node::~Node(){

}


void Node::render(sf::RenderWindow *window){
  sf::CircleShape circle(60);
  window->draw(circle);
}

void Node::control(){

}
