#include "../inc/nodeSys.h"


int main(){
  // create a window
  sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Paxos Algorithim");

  // Create a Node system
  NodeSystem nodes(2, 5, "");

  // awaken node system
  nodes.awake();

  sf::Font font;
  // Load it from a file
  if (!font.loadFromFile("font/arial.ttf"))
  {
      // error...
      return EXIT_FAILURE;
  }

  // Number of nodes
  sf::Text nodes_num_text(std::string("Number of Nodes: ") + std::to_string(nodes.getSize()),
  font, FONT_SIZE);
  nodes_num_text.setPosition(10, 10);
  nodes_num_text.setFillColor(sf::Color::Black);

  // change frameRate
  window.setFramerateLimit(FPS);

  // change static GameObject window
  GameObject::window = &window;

  // run the program
  while(window.isOpen()){
    // delay system
    sleep(TIME_DELAY);

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
    nodes.update();

    //display text
    window.draw(nodes_num_text);

    // display the window
    window.display();
  }
  return EXIT_SUCCESS;
}
