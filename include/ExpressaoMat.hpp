#pragma once

/**
 * @file ExpressaoMat.hpp
 *
 * @brief Declaração da classe ExpressaoMat.
 *
 */

/**
 * @class ExpressaoMat
 *
 * @brief Define uma interface para avaliação de expressões matemáticas.
 *
 * A classe estabelece uma interface comum para objetos capazes de representar e avaliar expressões matemáticas
 * envolvendo duas variáveis. Ela fornece um método abstrato para cálculo do valor da expressão e permite que
 * diferentes implementações utilizem estratégias distintas de avaliação, mantendo uma forma padronizada de acesso
 * ao resultado.
 *
 */
class ExpressaoMat{
    public:

        /**
         * @brief Detrói a expressão matemática.
         *
         * Destrutor virtual reponsável por garantir a liberação os recursos utilizados pelas classes derivadas
         * quando manipuladas por meio de ponteiros.
         *
         */
        virtual ~ExpressaoMat() {}

        /**
         * @brief Avalia a expressão matemática.
         *
         * Método abstrato responsável por calcular o valor da expressão para os valores fornecidos das variáveis de entrada.
         * Cada classe derivada deve implementar sua própria lógica de avaliação.
         *
         * @param a Valor da primeira variável utilizada no cálculo.
         *
         * @param b Valor da segunda variável utilizada no cálculo.
         *
         * @return Resultado numérico da expressão avaliada.
         *
         */
        virtual double avalia(double a, double b) = 0;

};
