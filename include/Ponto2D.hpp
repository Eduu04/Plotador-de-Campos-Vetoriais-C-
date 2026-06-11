#pragma once

template <typename T>
class Ponto2D{
    protected:

    T x;
    T y;

    public:

    Ponto2D (T _x, T _y): x(_x), y(_y){}
    virtual ~Ponto2D() = default;
    T getX() const;
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