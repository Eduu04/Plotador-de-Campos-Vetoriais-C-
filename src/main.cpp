#include <SFML/Graphics.hpp>
#include "Arrow.hpp"
#include "DatasetVetor.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

int main() {

    std::cout << std::setfill('-') << std::setw(15) << "" << " Plotador de Campos Vetoriais " << std::setw(15) << "" << std::endl;
    
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

    sf::RenderWindow window(sf::VideoMode({800, 800}), "Plot de Campo Vetorial");
    std::vector<std::unique_ptr<Renderable>> Rep_Grafica;

    double escala = 15.0;

    unsigned long long indice = 0;

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

            double xTela = (x + 5.0) * (80.0);
            double yTela = (5.0 - y) * (80.0);
            double xFinal = xTela + escala*vx;
            double yFinal = yTela - escala*vy;

            Rep_Grafica.push_back(std::make_unique<Arrow>(xTela, yTela, xFinal, yFinal));

            indice++;

        }
    }
    
    while (window.isOpen()) {      
        
        while (const std::optional evento = window.pollEvent()) {
            if (evento->is<sf::Event::Closed>()) {
                window.close();
            }
        }
       
        window.clear(sf::Color(20,20,20));

        for (const auto& objeto : Rep_Grafica){
            objeto->render(window);
        }
        window.display();
    }

    std::cout << "\n";
    std::cout << std::setfill('-') << std::setw(20) << "" << " Programa Encerrado " << std::setw(20) << "" << std::endl;
    std::cout << "\n";
    return 0;
}