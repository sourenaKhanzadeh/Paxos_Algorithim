#include "../inc/node.h"

int main(){
  // create a window
  sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Paxos Algorithim");

  // get Nodes
  std::vector<Node*> nodes = awakeNode();

  sf::Font font;
  // Load it from a file
  if (!font.loadFromFile("font/arial.ttf"))
  {
      // error...
      return EXIT_FAILURE;
  }

  // Number of nodes
  sf::Text nodes_num(std::string("Number of Nodes: ") + std::to_string(nodes.size()),
  font, FONT_SIZE);
  nodes_num.setPosition(10, 10);
  nodes_num.setFillColor(sf::Color::Black);

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

    window.draw(nodes_num);

    // display the window
    window.display();
  }
  return EXIT_SUCCESS;
}
