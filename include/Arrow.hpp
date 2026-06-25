#pragma once
#include "Renderable.hpp"
#include <SFML/Graphics.hpp>

/**
 * @file Arrow.hpp
 *
 * @brief Declaração da classe Arrow.
 */

/**
 * @class Arrow
 *
 * @brief Implementa uma flecha utilizada na representação gráfica de vetores bidimensionais.
 *
 * A classe Arrow é responsável por criar e gerenciar os elementos gráficos utilizados para representar 
 * um vetor bidimensional na interface. Cada flecha é composta por uma linha e por uma ponta triangular.
 * A classe também implementa a interface Renderable, permitindo que o objeto seja desenhado na janela de
 * renderização SFML.
 *
 */
class Arrow : public Renderable{

    /**
     * @brief Corpo principal da flecha.
     *
     * Gerencia os vértices que definem a linha utilizada para representar graficamente a direção do vetor.
     *
     */
    sf::VertexArray m_linha;

    /**
     * @brief Ponta da flecha.
     *
     * Objeto gráfico configurado como um triângulo que indica o sentido do vetor.
     *
     */
    sf::CircleShape m_cabeca;

    public:

        /**
         * @brief Constrói a flecha.
         *
         * Inicializa os elementos gráficos que compõem a flecha, utiliza as coordenadas
         * iniciais e finais do vetor, calcula sua orientação e ajusta a ponta para representar
         * corretamente o sentido do vetor
         *
         * @param x_inicial Posição horizontal inicial;
         * @param y_inicial Posição vertical inicial;
         * @param x_final Posição horizontal final;
         * @param y_final Posição vertical final;
         *
         */
        Arrow(double x_inicial, double y_inicial, double x_final, double y_final);

        /**
         * @brief Renderiza a flecha.
         *
         * Renderiza tanto o corpo quanto a ponta da flecha na janela gráfica fornecida.
         *
         * @param window Janela de renderização da SFML.
         *
         */
        void render(sf::RenderWindow& window) const override;
};
