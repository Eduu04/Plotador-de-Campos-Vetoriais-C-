#pragma once

/**
 * @file Ponto2D.hpp
 *
 * @brief Declaração da classe Ponto2D.
 */

/**
 * @class Ponto2D
 *
 * @brief Define uma estrutura genérica para representação de pontos bidimensionais.
 *
 * A classe representa um ponto no plano através de duas coordenadas, uma horizontal e uma vertical. Por ser implementada como uma
 * classe template permite utilizar diferentes tipos numéricos para armazenar as coordenadas.
 *
 * @tparam T Tipo utilizado para armazenar as coordenadas.
 *
 */
template <typename T>
class Ponto2D{
    protected:

    /**
     * @brief Coordenada horizontal.
     *
     * Armazena a posição do ponto ao longo do eixo x do sistema cartesiano.
     *
     */
    T x;
    
    /**
     * @brief Coordenada vertical.
     *
     * Armazena a posição do ponto ao longo do eixo y do sistema cartesiano.
     *
     */
    T y;

    public:
    
    /**
     * @brief Constrói um ponto bidimensional.
     *
     * Inicializa as coordenadas horizontal e vertical do ponto utilizando os valores fornecidos.
     * 
     * @param _x Valor da coordenada horizontal.
     *
     * @param _y Valor da coordenada vertical.
     *
     */
    Ponto2D (T _x, T _y): x(_x), y(_y){}
    
    /**
     * @brief Destrói o ponto bidimensional.
     *
     * Destrutor virtual que garante a destruição correta de objetos derivados quando manipulados através de ponteiros para a classe base.
     *
     */
    virtual ~Ponto2D() = default;
    
    /**
    * @brief Obtém a coordenada horizontal.
    *
    * Retorna o valor atualmente armazenado na coordenada x do ponto.
    *
    * @return Valor armazenado em x.
    *
    */
    T getX() const;
    
    /**
    * @brief Obtém a coordenada vertical.
    *
    * Retorna o valor atualmente armazenado na coordenada y do ponto.
    *
    * @return Valor armazenado em y.
    *
    */
    T getY() const;

};

template <typename T>
T Ponto2D<T>::getX() const{
    return x;
}

template <typename T>
T Ponto2D<T>::getY() const{
    return y;
}
