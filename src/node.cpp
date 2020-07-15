#include "../inc/node.h"

int Node::num = 1;
bool leader_elected = false;

Node::~Node(){
  num--;
}

void Node::render(){
  /**
  * render the display
  * of the node
  */
  sf::CircleShape circle(_rad);
  sf::Vector2<int> pos = getPos();


  // set position,origin, color and rotate around pivot
  circle.setFillColor(getColor());
  circle.setPosition(pos.x, pos.y);

  // set leader display attributes
  if(_leader){
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Blue);
    circle.setOutlineThickness(LEADER_OUTLINE_THICKNESS);
  }
  // render Node in window
  GameObject::window->draw(circle);
}


void Node::_mouse_drag(sf::Vector2<int> pos, sf::Vector2i mouse_pos, bool mouse_col[2]){

  // on left mouse click if node is touched then move node
  if(!_drag && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouse_col[0] && mouse_col[1]){
    _drag = true;
  }

  // drag the node in the postion then release
  if(_drag){
    setPos(mouse_pos);
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      _drag = false;
    }
  }
}

void Node::_select_leader(sf::Vector2<int> pos, sf::Vector2i mouse_pos, bool mouse_col[2]){
  /**
  * select the leader by right clicking on the node
  */
  if(sf::Mouse::isButtonPressed(sf::Mouse::Right) && mouse_col[0] && mouse_col[1]){
    _leader = true;
  }
}

void Node::control(){

  // get node position
  sf::Vector2<int> pos = getPos();
  // get mouse position
  sf::Vector2i mouse_pos = sf::Mouse::getPosition(*GameObject::window);

  // check constraint's
  bool mouse_col[2] = {
    pos.x-_rad <= mouse_pos.x && mouse_pos.x <= pos.x + _rad,
    pos.y-_rad <= mouse_pos.y && mouse_pos.y <= pos.y+_rad
  };

  // Drag node
  _mouse_drag(pos, mouse_pos, mouse_col);
  // select leader
  _select_leader(pos, mouse_pos, mouse_col);
}


std::vector<Node*> awakeNode(){
  /*
  * awaken the gameObject
  * Node factory
  */
  size_t num = N_NODE(25);
  float rad = 10;
  std::string data = "";

  std::vector<Node*> scene;

  // seed srand to current time
  srand(time(0));

  // create random number of nodes
  for(int i=0;i<num;i++){
    scene.push_back(
      new Node(sf::Vector2<int>((rand()%(SCREEN_W-100))+50,
      (rand()%(SCREEN_H-100))+50),
    sf::Color::Black,rad, data));
  }

  return scene;
}
