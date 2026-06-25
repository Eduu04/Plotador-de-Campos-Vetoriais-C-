#pragma once
#include "Ponto2D.hpp"

/**
 * @file Vetor2D.hpp
 *
 * @brief Declaração da classe Vetor2D.
 *
 */

/**
 * @class Vetor2D
 *
 * @brief Define uma estrutura genérica para representação de vetores bidimensionais.
 * 
 * A classe representa vetores no plano cartesiano por meio de duas componentes, uma horizontal e uma vertical.
 * Ela herda da classe Ponto2D para reutilizar o armazenamento das coordenadas e fornece operações matemáticas básicas entre vetores
 * como soma vetorial e multiplicação escalar.
 * 
 * @tparam T Tipo utilizado para armazenar as coordenadas do vetor.
 *
 */
template <typename T>
class Vetor2D : public Ponto2D<T>{
    public:
        
        /**
         * @brief Constrói um vetor bidimensional.
         *
         * Inicializa as componentes horizontal e vertical do vetor utilizando os valores fornecidos.
         * 
         * @param _x Valor da coordenada horizontal.
         * 
         * @param _y Valor da coordenada vertical.
         * 
         */
        Vetor2D(T _x = 0, T _y = 0) : Ponto2D<T>(_x, _y) {};
        
        /**
         * @brief Destrói o vetor bidimensional.
         *
         * Libera os recursos associados ao objeto.
         *
         */
        ~Vetor2D() = default;
        
        /** 
         * @brief Realiza a soma entre dois vetores bidimensionais. 
         *
         * Executa a soma de componente a componente entre vetor atual e vetor fornecido.
         *
         * @param vec Vetor a ser somado.
         * 
         * @return Novo vetor contendo o resultado da soma.
         * 
         */
        Vetor2D<T> operator+(const Vetor2D<T>& vec) const;
        
        /**
         * @brief Realiza a multiplicação de um vetor bidimensional.
         *
         * Multiplica cada componente do vetor pelo valor escalar fornecido.
         *
         * @param escalar Valor que multiplica o vetor.
         * 
         * @return Novo vetor contendo o resultado da soma.
         * 
         */
        Vetor2D<T> operator*(T escalar) const;
};

template <typename T>
Vetor2D<T> Vetor2D<T>::operator+(const Vetor2D& vec) const{
    return Vetor2D<T>(this->x + vec.x, this->y + vec.y);
}

template <typename T>
Vetor2D<T> Vetor2D<T>::operator*(T escalar) const{
    return Vetor2D<T>(this->x*escalar, this->y*escalar);
}
