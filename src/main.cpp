#include <SFML/Graphics.hpp>
#include "Arrow.hpp"
#include "DatasetVetor.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <optional>

int main() {

    std::cout << std::setfill('-') << std::setw(15) << "" << " Plotador de Campos Vetoriais " << std::setw(15) << "" << std::endl;
    std::cout << std::setfill(' ') << std::setw(10) << "" << "* Clique 'esc' para fechar a interface *" << std::setw(10) << "" << std::endl;

    
    std::string fx, fy;
    std::cout << "\nDefina fx(x,y) = ";
    std::getline(std::cin, fx);
    std::cout << "\nDefina fy(x,y) = ";
    std::getline(std::cin, fy);

    Parser fx_exprtk(fx);
    Parser fy_exprtk(fy);

    int N = 30;

    int Total_Pontos = N*N;
    DatasetVetor dataset(Total_Pontos);

    unsigned int larguraJanela = 800;
    unsigned int alturaJanela = 650;
    sf::RenderWindow window(sf::VideoMode({larguraJanela, alturaJanela}), "Plot de Campo Vetorial");
    std::vector<std::unique_ptr<Renderable>> Rep_Grafica;

    double escala = 40.0;

    unsigned long long indice = 0;

    double fatorX = larguraJanela / 10.0;
    double fatorY = alturaJanela / 10.0;
    
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){

            double x = -5.0 + 10*j/(N-1);
            double y = 5.0 - 10*i/(N-1);

            double vx = fx_exprtk.avalia(x, y);
            double vy = fy_exprtk.avalia(x, y);

            dataset.set(indice, Vetor2D<double>(vx,vy));

            double modulo = std::sqrt(vx*vx + vy*vy);
            
            if (modulo > 1e-8){

                vx /= modulo;
                vy /= modulo;
            }

            double escalaDinamica = escala * std::tanh(modulo * 0.5);

            double xTela = (x + 5.0) * fatorX;
            double yTela = (5.0 - y) * fatorY;
            double xFinal = xTela + escalaDinamica * vx;
            double yFinal = yTela - escalaDinamica * vy;
            Rep_Grafica.push_back(std::make_unique<Arrow>(xTela, yTela, xFinal, yFinal));

            indice++;

        }
    }
    




    sf::Font fonte;
    if(!fonte.openFromFile("Nexa-Heavy.ttf")){
        std::cout << "fonte nao carregada" <<std:: endl;
    }
    std::string textoFuncao = "Campo vetorial: (" + fx + ")i + (" + fy + ")j";
    sf::Text texto(fonte, textoFuncao, 16);
    texto.setFillColor(sf::Color(243, 244, 246));
    sf::FloatRect caixaTexto = texto.getLocalBounds();
    texto.setPosition({(larguraJanela - caixaTexto.size.x) / 2.0f, 22.0f});




    sf::RectangleShape notch;
    float alturaNotch = 30.0;
    float larguraNotch = caixaTexto.size.x + 40.0;
    notch.setSize({larguraNotch, alturaNotch});
    notch.setPosition({(larguraJanela-larguraNotch) /2.0f, 20.0f});
    notch.setFillColor(sf::Color(51, 74, 92));
    

    sf::RectangleShape moldura;
    float espessuraMargem = 20.0;
    moldura.setSize({static_cast<float>(larguraJanela)-(espessuraMargem*2) , static_cast<float>(alturaJanela)-(espessuraMargem*2)});
    moldura.setPosition({espessuraMargem, espessuraMargem});
    moldura.setFillColor(sf::Color::Transparent);
    moldura.setOutlineThickness(espessuraMargem);
    moldura.setOutlineColor(sf::Color(51, 74, 92));


    sf::RectangleShape eixoX;
    eixoX.setSize({static_cast<float>(larguraJanela), 3.0f});
    eixoX.setPosition({0.0f, alturaJanela / 2.0f - 1.5f});
    eixoX.setFillColor(sf::Color(150, 150, 150, 20));

    sf::RectangleShape eixoY;
    eixoY.setSize({3.0f, static_cast<float>(alturaJanela)});
    eixoY.setPosition({larguraJanela / 2.0f - 1.5f, 0.0f});
    eixoY.setFillColor(sf::Color(150, 150, 150, 20));





    while (window.isOpen()) {      
        
        while (const std::optional evento = window.pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                window.close();
            }
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            }
        }
       
        window.clear(sf::Color(20,20,20));

        window.draw(eixoX);
        window.draw(eixoY);

        for (const auto& objeto : Rep_Grafica){
            objeto->render(window);
        }


        window.draw(moldura);
        window.draw(notch);
        window.draw(texto);
        window.display();
    }

    std::cout << "\n";
    std::cout << std::setfill('-') << std::setw(20) << "" << " Programa Encerrado " << std::setw(20) << "" << std::endl;
    std::cout << "\n";
    return 0;
}
