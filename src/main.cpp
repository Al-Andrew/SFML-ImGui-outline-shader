#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <bits/stdc++.h>
#include "helpers.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Shaders");
    window.setVerticalSyncEnabled(true);
    window.requestFocus();
    ImGui::SFML::Init(window);
   
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    
    sf::Clock deltaClock;


    sf::Texture squareTexture;
    if(!squareTexture.loadFromFile("res/Square.png"))
    {
        printf("Texture failed to load: Square.png \n");
    }
    squareTexture.setSmooth(false);
    sf::Sprite square;
    square.setTexture(squareTexture,true);
    square.setScale(5.0f,5.0f);
    square.setPosition(100.f,300.f);
    sf::FloatRect squareBox = square.getGlobalBounds();



    sf::Texture circleTexture;
    if(!circleTexture.loadFromFile("res/Circle.png"))
    {
        printf("Texture failed to load: Circle.png \n");
    }
    circleTexture.setSmooth(false);
    sf::Sprite circle;
    circle.setTexture(circleTexture,true);
    circle.setScale(5.0f,5.0f);
    circle.setPosition(640.f,300.f);
    sf::FloatRect circleBox = circle.getGlobalBounds();

    sf::Shader shader;
    if(sf::Shader::isAvailable())
    {
        printf("Shaders available. Loading... \n");
        sf::FileInputStream fragmentStream;
        sf::FileInputStream vertexStream;
        fragmentStream.open("res/test_shader.fs");
        vertexStream.open("res/test_shader.vs");
        if(!shader.loadFromStream(vertexStream,fragmentStream))
        {
            printf("Shaders failed to load \n");
        }
    }
    shader.setUniform("texture",sf::Shader::CurrentTexture);
    float outlineThickness = 0.001f;
    float outlineColor[4] = { 1.0, 1.0, 1.0, 1.0};
    shader.setUniform("outLineSize",outlineThickness);
    while (window.isOpen()) {
       
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
            case sf::Event::MouseWheelScrolled:
                outlineThickness += 0.001f * event.mouseWheelScroll.delta;
               
            default:
                break;
            }

        }
        ImGui::SFML::Update(window, deltaClock.restart());
        bool debugOpen = true;
        ImGui::Begin("Debug",&debugOpen);
        ImGui::SliderFloat("Outline Thickness", &outlineThickness, 0.0f, 0.2f);
        ImGui::ColorPicker4("Outline Color",outlineColor);
        ImGui::End();
        shader.setUniform("outLineR",outlineColor[0]);
        shader.setUniform("outLineG",outlineColor[1]);
        shader.setUniform("outLineB",outlineColor[2]);
        shader.setUniform("outLineA",outlineColor[3]);
        shader.setUniform("outLineSize",outlineThickness);
        window.clear(sf::Color::Black); // fill background with color
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

         

        if( squareBox.contains((sf::Vector2f)mousePos)) window.draw(square, &shader);
        else window.draw(square);
        if( circleBox.contains((sf::Vector2f)mousePos)) window.draw(circle, &shader);
        else window.draw(circle);

        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();
}