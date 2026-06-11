#pragma once
#include "Vetor2D.hpp"

class DatasetVetor {
    Vetor2D<double> *vetores;
    unsigned long long capacidade;

    public:
        DatasetVetor(unsigned long long _cap);
        DatasetVetor(const DatasetVetor& other);
        ~DatasetVetor();

        DatasetVetor& operator=(const DatasetVetor& other);

        void set(unsigned long long i, const Vetor2D<double>& vet);
        Vetor2D<double> getVet(unsigned long long i) const;
        unsigned long long getCapacidade() const;
};

