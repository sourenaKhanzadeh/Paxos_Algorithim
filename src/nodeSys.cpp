#include "../inc/nodeSys.h"

std::string random_string()
{
     std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

     std::random_device rd;
     std::mt19937 generator(rd());

     std::shuffle(str.begin(), str.end(), generator);

     return str.substr(0, str.size());    // assumes 32 < number of characters in str
}


inline sf::Vector2f norm(sf::Vector2f v){
  float g = sqrt(pow(v.x,2)+pow(v.y, 2));
  return v/g;
}


inline sf::Vector2f norm(sf::Vector2f v, sf::Vector2f b){
  float g = sqrt(pow(b.x - v.x,2)+pow(b.y - v.y, 2));
  return v/g;
}



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

void NodeSystem::_clear(){
  for(int i=0;i<_num;i++){
    delete _nodes.at(i);
    _nodes.at(i) = NULL;
  }
  _nodes.clear();
  _scaler = 1;
  _is_promise = false;
}

void NodeSystem::_promise(){
  /**
  * leader node makes promise
  * to none leader nodes
  */
  // generate a random value
  std::string value = random_string().substr(0,2);

  for(int i=0;i<_nodes.size();i++){
    if(_nodes.at(i) != NULL && i != leader_index && leader_index < _nodes.size())
      if(leader_index>=0){

        // add promise to the data
        // _nodes.at(i)->appendData(value);

        sf::Vector2f dline = (sf::Vector2f)_nodes.at(i)->getPos() +
          sf::Vector2f(_rad, _rad);

        sf::Vector2f leader = (sf::Vector2f)_nodes.at(leader_index)->getPos() +
           sf::Vector2f(_rad, _rad);

        sf::Vector2f dline_n = norm(leader - dline);

        dline_n = sf::Vector2f(dline_n.x*-_scaler, dline_n.y*-_scaler);

        // dline.x - _rad >= (leader + dline_n).x  && (leader + dline).x >= dline.x + _rad &&
          // dline.y - _rad >= (leader + dline_n).y && (leader + dline_n).y >= dline.y + _rad

        sf::Vertex line[2];
        int range = _nodes.size()/7;
        if(_nodes.at(i)->recieved ||
        (inRange(dline.x - _rad*range, dline.x + _rad*range, (leader + dline_n).x )
          && inRange(dline.y - _rad*range, dline.y + _rad*range, (leader + dline_n).y))){
          _nodes.at(i)->setColor(sf::Color::Magenta);

          // take vector from leader to other nodes

          line[0] = sf::Vertex(leader, sf::Color::Blue);
          line[1] = sf::Vertex(leader, sf::Color::Blue);

          _nodes.at(i)->recieved = true;

        }else{

          // take vector from leader to other nodes

          line[0] = sf::Vertex(leader, sf::Color::Blue);
          line[1] = sf::Vertex(leader + dline_n, sf::Color::Blue);

        }

        // if(leader.x > dline.x)dline_n.x *= -_scaler;
        // else dline_n.x *= _scaler;
        // if(leader.y > dline.y)dline_n.y *= _scaler;
        // else dline_n.y *= -_scaler;




      GameObject::window->draw(line, 2, sf::Lines);
      _scaler++;

    }
  }
}

void NodeSystem::update(){
  for(int i=0;i<_num;i++){
    if(_nodes.at(i) != NULL){
      _nodes.at(i)->update();
      if(_nodes.at(i)->isLeader())leader_index=i;
    }
  }
  // send promise if spacebar is pressed
  if(!_is_promise && KEY(Space)){
    _is_promise = true;
  }

  // if up key pressed then increase the size of the nodes
  if(KEY(Up)){
    _clear();
    _num = N_NODE(R_NODE(_num)+2);
    awake();
  }else if(KEY(Down)){
    _clear();
    _num = N_NODE(R_NODE(_num)-2);
    awake();
  }

  if(_is_promise){
    std::thread promise(&NodeSystem::_promise, this);
    promise.join();
  }

}


int NodeSystem::getSize(){
  return _num;
}
