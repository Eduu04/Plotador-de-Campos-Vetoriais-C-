# Plotador de Campos Vetoriais

## Descrição

Projeto desenvolvido em C++ para visualização de campos vetoriais bidimensionais. O programa recebe duas expressões matemáticas fornecidas pelo usuário, correspondentes às componentes horizontal e vertical de um campo vetorial, plotando esse mesmo campo

## Estrutura do Projeto

- Ponto2D
- Vetor2D
- DatasetVetor
- ExpressaoMat
- Parser
- Renderable
- Arrow

## Pré-Requisitos

Para compilar e executar o projeto é necessário ter:

- Compilador compatível com C++ 17 ou superior;
- CMake 3.20 ou superior;
- SFML 3 instalada no sistema;
- Arquivo de fonte 'Nexa-Heavy.ttf' presente no diretório de execução;
- Git (opcional, para clonar o repositório);

  ### Verificando o CMake

  ```bash
  cmake --version
  ```

  ### Verificando a instalação da SFML

  A versão da SFML deve ser compatível com a utilizada pelo projeto (SFML 3).

  ## Instalação

  Clone o repositório:
  
  ```bash
  git clone <url-do-repositorio>
  ```

  Entre na pasta do projeto:

  ```bash
  cd plotador_vetorial
  ```

  Crie a pasta de compilação:

  ```bash
  mkdir build
  cd build
  ```
  ```bash
  cmake ..
  ```

  Compile:

  ```bash
  cmake --build .
  ```

  Após a compilação, o executável 'plotador_vetorial' será gerado na pasta de build

  ## Utilização

  Após executar o programa, será exibida uma mensagem solicitando os componentes horizontal e vertical do campo vetorial.

  ```text
  Defina fx(x,y) =
  Defina fy(x,y) =
  ```

  As expressões devem ser escritas utilizando as variáveis 'x' e 'y'.

  ### Operadores Suportados

  As expressões podem utilizar os seguintes operadores matemáticos:

  - '+' → Soma
  - '-' → Subtração
  - '*' → Multiplicação
  - '/' → Divisão
  - '^' → Potenciação

  ### Funções Matemáticas

  - 'sin(x)' → Seno
  - 'cos(x)' → Cosseno
  - 'tan(x)' → Tangente
  - 'cot(x)' → Cotangente
  - 'sec(x)' → Secante
  - 'csc(x)' → Cossecante
  - 'sinc(x)' → função sinc
  - 'asin(x)' → Arco seno
  - 'acos(x)' → Arco cosseno
  - 'atan(x)' → Arco tangente
  - 'sinh(x)' → Seno hiperbólico
  - 'cosh(x)' → Cosseno hiperbólico
  - 'tanh(x)' → Tangente hiprebólica
  - 'asinh(x)' → Arco seno hiperbólico
  - 'acosh(x)' → Arco cosseno hiperbólico
  - 'atanh(x)' → Arco tangente hiperbólica
  - 'sqrt(x)' → Raiz quadrada
  - 'exp(x)' → Exponencial
  - 'log(x)' → Logaritmo natural
  - 'abs(x)' → Valor absoluto
 
  ### Constantes

  Também podem ser utilizadas constantes matemáticas como:

  - 'pi' → Número π
  - 'e' → Número de Euler

  ### Controles

  - 'ESC' → Fecha a aplicação

  ### Exemplos de Entrada

  #### Campo Rotacional

  ```text
  Defina fx(x,y) = -y
  Defina fy(x,y) = x
  ```
  
  #### Campo Radial

  ```text
  Defina fx(x,y) = x
  Defina fy(x,y) = y
  ```

  #### Campo Convergente

  ```text
  Defina fx(x,y) = -x
  Defina fy(x,y) = -y
  ```

  #### Campo Trigonométrico

  ```text
  Defina fx(x,y) = sin(y)
  Defina fy(x,y) = cos(x)
  ```
  ## Construído com

  - C++17
  - SFML 3
  - ExprTk
  - Doxygen
  - CMake
  
  ## Autores

  - Arthur Argenton Cecchin
  - Eduardo Floriani de Souza
  - Lucas Fogaça Romão

  ## Licença

  Este projeto está licenciado sob a MIT License.

  ``` MIT License

  Copyright (c) 2026

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE. ```
