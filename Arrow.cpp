#include "Arrow.hpp"
#include <cmath> 


Arrow::Arrow(double x_inicial, double y_inicial, double x_final, double y_final) {
    
    m_linha.setPrimitiveType(sf::PrimitiveType::Lines);

    m_linha.resize(2);

    m_linha[0].position = sf::Vector2f(x_inicial, y_inicial);
    m_linha[1].position = sf::Vector2f(x_final, y_final); 
    
    m_linha[0].color = sf::Color::Cyan;
    m_linha[1].color = sf::Color::Blue;

    


    float raioCabeca = 3.0;
    m_cabeca.setRadius(raioCabeca);
    m_cabeca.setPointCount(3); 
    m_cabeca.setFillColor(sf::Color::Red); 
    m_cabeca.setOutlineThickness(1.0);
    m_cabeca.setOutlineColor(sf::Color::Red);
    m_cabeca.setOrigin({raioCabeca, raioCabeca});

    
    double deltaX = x_final - x_inicial;
    double deltaY = y_final - y_inicial;

    double anguloRadianos = std::atan2(deltaY, deltaX);

    float anguloGraus = static_cast<float>(anguloRadianos * (180.0/M_PI));

    m_cabeca.setPosition({static_cast <float>(x_final), static_cast<float>(y_final)});
    m_cabeca.setRotation(sf::degrees(anguloGraus +90.0));
}


void Arrow::render(sf::RenderWindow& window) const {
    window.draw(m_linha); 
    window.draw(m_cabeca); 
}