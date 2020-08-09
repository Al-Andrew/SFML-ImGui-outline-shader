#pragma once
#include <random>
#include <ctime>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

float random(float min, float max);
float dist(float ax, float ay, float bx, float by);
float dist(sf::Vector2f a,sf::Vector2f b);
float length(sf::Vector2f a);
sf::Vector2f setLen(const sf::Vector2f& a,const float& len);
sf::Vector2f limit(const sf::Vector2f& a,const float& lim);
