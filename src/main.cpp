#include "../inc/node.h"

int main(){
  // create a window
  sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Paxos Algorithim");

  std::vector<Node*> nodes = awakeNode();

  // change frameRate
  window.setFramerateLimit(FPS);

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
    window.clear(sf::Color::White);

    // update Nodes
    for(int i=0;i<nodes.size();i++)
      nodes.at(i)->update(&window);

    // display the window
    window.display();
  }
  return EXIT_SUCCESS;
}
