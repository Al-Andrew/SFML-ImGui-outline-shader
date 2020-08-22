#pragma once
#include <random>
#include <ctime>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const sf::Vector2f VECTOR_ZERO(0.f, 0.f);
const sf::Vector2f VECTOR_UNIT(1.f, 1.f);
const sf::Vector2f VECTOR_UP(0.f ,-1.f);
const sf::Vector2f VECTOR_DOWN(0.f, 1.f);
const sf::Vector2f VECTOR_LEFT(-1.f, 0.f);
const sf::Vector2f VECTOR_RIGHT(1.f, 0.f);




float random(float min, float max);
float dist(float ax, float ay, float bx, float by);
float dist(sf::Vector2f a,sf::Vector2f b);
float length(sf::Vector2f a);
sf::Vector2f setLen(const sf::Vector2f& a,const float& len);
sf::Vector2f limit(const sf::Vector2f& a,const float& lim);
