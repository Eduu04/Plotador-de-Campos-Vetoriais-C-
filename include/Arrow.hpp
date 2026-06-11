#pragma once
#include "Renderable.hpp"
#include <SFML/Graphics.hpp>

class Arrow : public Renderable{

    sf::VertexArray m_linha;
    sf::CircleShape m_cabeca;

    public:
        Arrow(double x_inicial, double y_inicial, double x_final, double y_final);
        void render(sf::RenderWindow& window) const override;
};