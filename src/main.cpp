#include "../inc/node.h"

std::vector<Node> awakeNode();

int main(){
  // create a window
  sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Paxos Algorithim");

  std::vector<Node> nodes = awakeNode();

  while(window.isOpen()){
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            window.close();
    }
    // Clear screen
    window.clear();

    // update Nodes
    for(int i=0;i<nodes.size();i++)
      nodes.at(i).update(&window);

    // display the window
    window.display();
  }
  return EXIT_SUCCESS;
}

std::vector<Node> awakeNode(){
  /*
  * awaken the gameObject
  */
  std::vector<Node> scene;

  Node node(sf::Vector2<int>(10, 20), sf::Color(0xff,0,0), "Hello");

  scene.push_back(node);

  return scene;
}
