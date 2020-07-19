#include "../inc/node.h"

int Node::num = 1;
bool leader_elected = false;
int Node::confirms = 0;

// Returns true if x is in range [low..high], else false
bool inRange(unsigned low, unsigned high, unsigned x)
{
    return  ((x-low) <= (high-low));
}


Node::~Node(){
  num--;
}

void Node::reset(){
  recieved = false;
  sent = false;
  data_confirmed = false;
  scaler = 1;
  Node::confirms = 0;
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

  // represent data of the node

  sf::Font font;
  // Load it from a file
  if (!font.loadFromFile("font/arial.ttf"))
  {
      // error...
      exit(EXIT_FAILURE);
  }

  // Number of nodes
  sf::Text data_text(_data,
  font, FONT_SIZE);
  data_text.setPosition(getPos().x - _data.size(), getPos().y-(_rad*4));
  data_text.setFillColor(sf::Color::Magenta);

  GameObject::window->draw(data_text);
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
    inRange(pos.x-_rad*3, pos.x+_rad*3, mouse_pos.x),
    inRange(pos.y-_rad*3, pos.y+_rad*3, mouse_pos.y)
  };

  // Drag node
  _mouse_drag(pos, mouse_pos, mouse_col);
  // select leader
  _select_leader(pos, mouse_pos, mouse_col);
}

bool Node::isLeader(){
  return _leader;
}

void Node::appendData(std::string val){
  _data+= std::string(", ") + val;
}
