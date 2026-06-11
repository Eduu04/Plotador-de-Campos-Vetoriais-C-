#include "Parser.hpp"

Parser::Parser(const std::string& expressao) : m_expressaoTexto(expressao){

    m_symbol_table.add_variable("x", m_x);
    m_symbol_table.add_variable("y", m_y);
    m_symbol_table.add_constants();

    m_expression.register_symbol_table(m_symbol_table);

    m_parser.compile(m_expressaoTexto, m_expression);
}

double Parser::avalia(double x, double y) {

    this->m_x = x;
    this->m_y = y;

    return this->m_expression.value();
}