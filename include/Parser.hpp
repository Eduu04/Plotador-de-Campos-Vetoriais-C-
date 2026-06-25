#pragma once
#include "ExpressaoMat.hpp"
#include "../libs/exprtk.hpp" 
#include <string>

/**
 * @file Parser.hpp
 *
 * @brief Declaração da classe Parser.
 *
 */

/**
 * @class Parser
 *
 * @brief Implementa um avaliador de expressões matemáticas
 *
 * A classe Parser implementa a interface ExpressaoMat utilizando a biblioteca ExprTk para interpretar, compilar e avaliar
 * expressões matemáticas definidas pelo usuário. Durante a construção do objeto, a expressão textual é compilada e associada
 * a uma tabela de símbolos contendo as variáveis x e y. Após a compilação, a expressão pode ser avaliada repetidamente para
 * diferentes valores dessas variáveis sem a necessidade de recompilar o texto, tornando o processo mais eficiente para cálculos
 * realizados em grande quantidade.
 *
 */
class Parser : public ExpressaoMat {
private:

    /**
     * @brief  Expressão matemática fornecida pelo usuário.
     *
     * Armazena o texto original da expressão utilizado durante o processo de compilação realizado pela biblioteca ExprTk.
     *
     */
    std::string m_expressaoTexto;

    /**
     * @brief  Valor da variável x.
     *
     * Variável registrada na tabela de símbolos da ExprTk e utilizada durante a avaliação da expressão matemática.
     *
     */
    double m_x;

    /**
     * @brief  Valor da variável y.
     *
     * Variável registrada na tabela de símbolos da ExprTk e utilizada durante a avaliação da expressão matemática.
     *
     */
    double m_y;

    /**
     * @brief  Tabela de símbolos utilizada pelo ExprTk.
     *
     * Responsável por associar nomes de variáveis, constantes e funções aos respectivos valores utilizados durante a
     * avaliação da expressão.
     *
     */
    exprtk::symbol_table<double> m_symbol_table;

    /**
     * @brief  Expressão matemática compilada.
     *
     * Armazena a estrutura interna gerada pela ExprTk após a compilação da expressão textual, permitindo
     * avaliações eficientes sem a necessidade de reinterpretar o texto a cada cálculo.
     *
     */
    exprtk::expression<double>   m_expression;

    /**
     * @brief  Compilador de expressões da biblioteca ExprTk.
     *
     * Responsável por interpretar a expressão textual fornecida pelo usuário e convertê-la para a representação
     * interna utilizada durante os cálculos.
     *
     */
    exprtk::parser<double>       m_parser;

public:

    /**
     * @brief Constrói um avaliador de expressões matemáticas.
     *
     * Inicializa a tabela de símbolos, registra as variáveis x e y, adiciona constantes matemáticas fornecidas pela biblioteca
     * ExprTk e compila a expressão textual recebida. Após a construção do objeto, a expressão fica pronta para ser avaliada multiplas
     * vezes com diferentes valores das variáveis.
     *
     * @param expressao Expressão matemática em formato textual.
     *
     */
    Parser(const std::string& expressao);

    /**
     * @brief  Destrói o avaliador de expressões.
     *
     * Como a classe utiliza objetos que gerenciam seus próprios recursos, não é necessária nenhuma rotina explícita de liberação de memória.
     *
     */
    virtual ~Parser() = default;

     /**
     * @brief Avalia a expressão matemática.
     *
     * Atualiza os valores das variáveis x e y registradas na tabela de símbolos e executa o cálculo da expressão previamente compilada.
     *
     * @param x Valor atribuído à variável x.
     *
     * @param y Valor atribuído à variável y.
     *
     * @return Resultado numérico da expressão.
     *
     */    
    double avalia(double x, double y) override;
};
