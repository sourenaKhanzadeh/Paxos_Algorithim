#include "../inc/nodeSys.h"

NodeSystem::NodeSystem(size_t num, float rad, std::string data){
  _num = N_NODE(num);
  _rad = rad;
  _data = data;
  _window = GameObject::window;
}

NodeSystem::~NodeSystem(){

}

void NodeSystem::awake(){
  // seed srand to current time
  srand(time(0));

  // create random number of nodes
  for(int i=0;i<_num;i++){
    _nodes.push_back(
      new Node(sf::Vector2<int>((rand()%(SCREEN_W-100))+50,
      (rand()%(SCREEN_H-100))+50),
    sf::Color::Black,_rad, _data));
  }
}

void NodeSystem::update(){
  for(int i=0;i<_num;i++){
    _nodes.at(i)->update();
  }
}


size_t NodeSystem::getSize(){
  return _num;
}
