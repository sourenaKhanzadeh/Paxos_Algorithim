#include "../inc/gameObject.h"

int main(){
  // create a window
  sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Paxos Algorithim");

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

    // display the window
    window.display();
  }
  return EXIT_SUCCESS;
}
