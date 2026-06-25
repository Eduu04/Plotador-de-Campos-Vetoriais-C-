#pragma once
#include "Vetor2D.hpp"

/**
 * @file Vetor2D.hpp
 *
 * @brief Declaração da classe DatasetVetor.
 */

/**
 * @class DatasetVetor
 *
 * @brief Define uma estrutura para armazenamento de vetores bidimensionais.
 *
 * A classe gerencia um conjunto de objetos Vetor2D<double>. Ela permite criar coleções de tamanho definido,
 * acessar e modificar elemento individuais, além de realizar cópias dos dados armazenados através de um segundo
 * construtor
 *
 */
class DatasetVetor {

    /**
     * @brief Vetores armazenados pelo dataset.
     *
     * Ponteiro para um bloco de memória contendo vetores bidimensionais pertencentes ao conjunto de dados.
     *
     */
    Vetor2D<double> *vetores;

    /**
     * @brief Valor do tamanho do array.
     *
     * Armazena a quantidade máxima de vetores que cabem no conjunto de dados.
     *
     */
    unsigned long long capacidade;

    public:

        /**
         * @brief Constroi um dataset com tamanho definido.
         *
         * Aloca dinamicamente memória suficiente para armazenar uma quantidade definida de vetores bidimensionais.
         *
         * @param _cap Tamanho do dataset.
         *
         */
        DatasetVetor(unsigned long long _cap);

        /**
         * @brief Cria uma cópia independente de outro dataset.
         *
         * Realiza uma cópia dos dados armazenados, criando um novo dataset independente e copiando todos os vetores do objeto de origem.
         *
         * @param other Dataset a ser copiado.
         *
         */
        DatasetVetor(const DatasetVetor& other);

        /**
         * @brief Libera os recursos utilizados pelo dataset.
         *
         * Libera a memória alocada para o armazenamento dos vetores bidimensionais
         */
        ~DatasetVetor();

        /**
         * @brief Copia o conteúdo de outro dataset.
         *
         * Libera os dados armazenados no dataset criando um novo dataset com mesma capacidade e vetores.
         *
         * @param other Dataset de origem.
         *
         * @return Referência para objeto atualizado.
         *
         */
        DatasetVetor& operator=(const DatasetVetor& other);

        /**
         * @brief Armazena um vetor em uma posição específica.
         *
         * Substitui o vetor armazenado no dataset por um vetor especifico na posição indicada.
         *
         * @param i Posição desejada.
         *
         * @param vet Vetor a ser inserido.
         *
         */
        void set(unsigned long long i, const Vetor2D<double>& vet);

        /**
         * @brief Obtém um vetor armazenado no dataset.
         *
         * Retorna uma cópia do vetor localizado na posição indicada.
         *
         * @param i Posição desejada.
         *
         * @return Vetor na posição desejada.
         *
         */
        Vetor2D<double> getVet(unsigned long long i) const;

        /**
         * @brief Obtém a capacidade do dataset.
         *
         * Retorna a quantidade de vetores que o dataset é capaz de armazenar.
         *
         * @return Capacidade do dataset.
         *
         */
        unsigned long long getCapacidade() const;
};
