#include "helpers.hpp"
#include <random>
#include <ctime>

float random(float min, float max)
{   
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

float dist(float ax, float ay, float bx, float by)
{   
    return sqrtf( (ax - bx)*(ax - bx) + (ay - by)*(ay - by) ) ;
}

float dist(sf::Vector2f a,sf::Vector2f b)
{
    return dist(a.x,a.y,b.x,b.y);
}

float length(sf::Vector2f a)
{
    return dist(0,0,a.x,a.y);
}

sf::Vector2f setLen(const sf::Vector2f& a,const float& len)
{
    float dif = len/length(a);
    return a*dif;
}

sf::Vector2f limit(const sf::Vector2f& a,const float& lim)
{
    return length(a) > lim?setLen(a,lim):a;
}