#include "DatasetVetor.hpp"

DatasetVetor::DatasetVetor(unsigned long long _cap) : capacidade(_cap){
    vetores = new Vetor2D<double>[capacidade];
}

DatasetVetor::~DatasetVetor(){
    delete[] vetores;
}

DatasetVetor::DatasetVetor(const DatasetVetor& other) : capacidade(other.capacidade) {
    vetores = new Vetor2D<double>[capacidade];
    for (unsigned long long i = 0; i<capacidade; i++){
        vetores[i] = other.vetores[i];
    }
}

DatasetVetor& DatasetVetor::operator=(const DatasetVetor& other){
    if (this != &other){

        delete[] vetores;
        capacidade = other.capacidade;

        vetores = new Vetor2D<double>[capacidade];
        for (unsigned long long i = 0; i<capacidade; i++){
            vetores[i] = other.vetores[i];
        }
    }
    return *this;
}

void DatasetVetor::set(unsigned long long i, const Vetor2D<double>& vec){
    this->vetores[i] = vec;
}

Vetor2D<double> DatasetVetor::getVet(unsigned long long i) const{
    return vetores[i];
}

unsigned long long DatasetVetor::getCapacidade() const{
    return capacidade;
}
