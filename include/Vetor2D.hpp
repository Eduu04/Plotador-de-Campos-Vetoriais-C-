#pragma once
#include "Ponto2D.hpp"

template <typename T>
class Vetor2D : public Ponto2D<T>{
    public:
        Vetor2D(T _x = 0, T _y = 0) : Ponto2D<T>(_x, _y) {};
        ~Vetor2D() = default;

        Vetor2D<T> operator+(const Vetor2D<T>& vec) const;
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

