#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <random>
#include <thread>

#define SCREEN_W 1080
#define SCREEN_H 910
#define FPS 8
#define FONT_SIZE 15
#define TIME_DELAY 0.5
#define LEADER_OUTLINE_THICKNESS 5

#define KEY(x) sf::Keyboard::isKeyPressed(sf::Keyboard::x)

#define N_NODE(x) (3*x) + 1

#endif
