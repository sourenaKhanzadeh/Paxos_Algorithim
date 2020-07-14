#include "../inc/node.h"

int Node::num = 1;

Node::~Node(){
  num--;
}

void Node::render(sf::RenderWindow *window){
  sf::CircleShape circle(_rad);
  sf::Vector2<int> pos = getPos();

  // set position,origin, color and rotate around pivot
  circle.setFillColor(getColor());
  circle.rotate(_drot);
  circle.setPosition(pos.x, pos.y);


  // render Node in window
  window->draw(circle);
}

void Node::control(){

}


std::vector<Node*> awakeNode(){
  /*
  * awaken the gameObject
  * Node factory
  */
  size_t num = N_NODE(15);
  float rad = 10;
  std::string data = "1";

  std::vector<Node*> scene;

  // seed srand to current time
  srand(time(0));


  for(int i=0;i<num;i++){
    scene.push_back(
      new Node(sf::Vector2<int>((rand()%(SCREEN_W-100))+50,
      (rand()%(SCREEN_H-100))+50),
    sf::Color::Black,rad, data));
  }

  return scene;
}
