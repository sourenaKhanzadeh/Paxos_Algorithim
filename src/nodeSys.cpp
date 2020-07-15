#include "../inc/nodeSys.h"

NodeSystem::NodeSystem(int num, float rad, std::string data){
  _num = N_NODE(num);
  _rad = rad;
  _data = data;

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

void NodeSystem::_promise(){
  /**
  * leader node makes promise
  * to none leader nodes
  */
  for(int i=0;i<_num;i++){
    if(i == leader_index)continue;
    if(leader_index>=0){

      sf::Vector2f dline = (sf::Vector2f)_nodes.at(i)->getPos() +
        sf::Vector2f(_rad, _rad);

      // take vector from leader to other nodes
      sf::Vertex line[]={

        sf::Vertex((sf::Vector2f)_nodes.at(leader_index)->getPos() +
         sf::Vector2f(_rad, _rad), sf::Color::Blue),

         sf::Vertex(dline, sf::Color::Blue)

        // sf::Vertex((sf::Vector2f)_nodes.at(i)->getPos() +
         // sf::Vector2f(_rad, _rad), sf::Color::Blue)
      };


      GameObject::window->draw(line, 2, sf::Lines);

    }
  }
}

void NodeSystem::update(){
  for(int i=0;i<_num;i++){
    _nodes.at(i)->update();
    if(_nodes.at(i)->isLeader())leader_index=i;
  }
  // std::thread promise(_promise);
  // promise.join();
  _promise();

}


int NodeSystem::getSize(){
  return _num;
}
