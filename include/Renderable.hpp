#pragma once
#include <SFML/Graphics.hpp>

/**
 * @file Renderable.hpp
 *
 * @brief Declaração da classe Renderable.
 *
 */

/**
 * @class Renderable
 *
 * @brief Define uma interface para objetos renderizáveis.
 *
 * A classe Renderable estabelece um contrato comum para todos os elementos gráficos da aplicação que podem ser desenhados em uma janela
 * da biblioteca SFML.
 *
 */
class Renderable{
        public:

            /**
             * @brief Destrói o objeto renderizável.
             *
             * Destrutor virtual responsável por garantir a destruição correta das classes derivadas quando manipuladas através de ponteiros
             * para a interface base.
             *
             */
            virtual ~Renderable() = default;

            /**
             * @brief Renderiza o objeto na janela.
             *
             * Método abstrato que deve ser implementado por todas as classes derivadas. Sua função é desenhar o objeto correspondente na janela
             * SFML fornecida.
             *
             * @param window Janela de renderização da SFML onde o objeto será desenhado.
             *
             */
            virtual void render(sf::RenderWindow& window) const = 0;
};
