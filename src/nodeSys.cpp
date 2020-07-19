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
  /**
  * clear the nodes from
  * the screen
  */
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
  if(_data_mutex){
    _data = random_string().substr(0,2);
    _data_mutex = false;
  }

  for(int i=0;i<_nodes.size();i++){
    if(_nodes.at(i) != NULL && i != leader_index && leader_index < _nodes.size())
      if(leader_index>=0){

        // add promise to the data
        sf::Vector2f dline = (sf::Vector2f)_nodes.at(i)->getPos() +
          sf::Vector2f(_rad, _rad);

        sf::Vector2f leader = (sf::Vector2f)_nodes.at(leader_index)->getPos() +
           sf::Vector2f(_rad, _rad);

        sf::Vector2f dline_n = norm(leader - dline);

        dline_n = sf::Vector2f(dline_n.x*-_scaler, dline_n.y*-_scaler);


        sf::Vertex line[2];
        int range = _nodes.size()/7;

        // check if request reached node
        if(_nodes.at(i)->recieved ||
        (inRange(dline.x - _rad*range, dline.x + _rad*range, (leader + dline_n).x )
          && inRange(dline.y - _rad*range, dline.y + _rad*range, (leader + dline_n).y))){

          Node *n = _nodes.at(i);
          Node *lead = _nodes.at(leader_index);


          dline_n = norm(dline - leader);
          dline_n = sf::Vector2f(dline_n.x * n->scaler, dline_n.y * n->scaler);


          // check majority votes
          if(n->sent && !n->data_confirmed && Node::confirms >= (_nodes.size()/2)+1){
            n->appendData(_data);
            n->data_confirmed = true;
          }

          if(!n->sent && inRange(leader.x-_rad * range, leader.x + _rad * range, (dline - dline_n).x) &&
            inRange(leader.y - _rad * range, leader.y + _rad * range, (dline - dline_n).y)){

              // take vector from leader to other nodes
              line[0] = sf::Vertex(leader, sf::Color::Blue);
              line[1] = sf::Vertex(leader, sf::Color::Blue);

              n->sent = true;

              Node::confirms++;

              n->setColor(sf::Color::Black);


          }
          else if(!n->sent){
            // take vector from leader to other nodes
            line[0] = sf::Vertex(dline, sf::Color::Magenta);
            line[1] = sf::Vertex(dline - dline_n, sf::Color::Magenta);

            n->setColor(sf::Color::Magenta);
          }


          n->recieved = true;
          n->scaler += 3;

        }else{

          // take vector from leader to other nodes
          line[0] = sf::Vertex(leader, sf::Color::Blue);
          line[1] = sf::Vertex(leader + dline_n, sf::Color::Blue);

        }

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
