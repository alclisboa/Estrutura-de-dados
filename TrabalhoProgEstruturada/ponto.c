#include "ponto.h"
#include <math.h>

// Inclui a biblioteca math.h para usar a função fabs() que calcula o valor absoluto
// Essa função é usada no cálculo da área do triângulo
float calcularAreaTriangulo(Ponto A, Ponto B, Ponto C) {
    // Fórmula do determinante para calcular a área do triângulo calculo feito com base no documento apresentado TP03
    return 0.5 * fabs(A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y));
}
