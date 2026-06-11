#pragma once
#include "ExpressaoMat.hpp"
#include "../libs/exprtk.hpp" 
#include <string>

class Parser : public ExpressaoMat {
private:
    std::string m_expressaoTexto;

    double m_x;
    double m_y;

    exprtk::symbol_table<double> m_symbol_table;
    exprtk::expression<double>   m_expression;
    exprtk::parser<double>       m_parser;

public:

    Parser(const std::string& expressao);
    virtual ~Parser() = default;
    
    double avalia(double x, double y) override;
};
