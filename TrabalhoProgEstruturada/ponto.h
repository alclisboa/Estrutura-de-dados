#ifndef PONTO_H
#define PONTO_H

// Inclui a biblioteca que define a estrutura Ponto para representar coordenadas (X, Y) no programa
typedef struct {
    float X;
    float Y;
} Ponto;

// Protótipo da função para calcular a área de um triângulo com base em seus vértices que serão passados no arquivo txt
float calcularAreaTriangulo(Ponto A, Ponto B, Ponto C);

#endif
