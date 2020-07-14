#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <time.h>
#include <SFML/Graphics.hpp>

#define SCREEN_W 1080
#define SCREEN_H 910
#define FPS 64
#define FONT_SIZE 15

#define KEY(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)

#define N_NODE(x) (3*x) + 1

#endif
