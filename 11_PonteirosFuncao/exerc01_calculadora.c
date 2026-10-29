#include <math.h>
#include <stdio.h>

// Define a "assinatura" da função, isto é,
// tipo de retorno + parâmetros
typedef double (*Operacao)(double, double);

double soma(double a, double b);
double subtrai(double a, double b);
double multiplica(double a, double b);
double divide(double a, double b);
double potencia(double a, double b);

double soma(double a, double b) { return a + b; }

double subtrai(double a, double b) { return a - b; }

double multiplica(double a, double b) { return a * b; }

double divide(double a, double b) { return a / b; }

double potencia(double a, double b) { return pow(a, b); }

int main() {
  Operacao operacoes[] = {soma, subtrai, multiplica, divide, potencia};
  char nomes[] = {'+', '-', '*', '/', '^'};

  int op = 1;
  while (op != 0) {
    printf("\nDigite a op. desejada (1-5, 0 para sair): ");
    scanf("%d", &op);
    if (op > 0 && op <= 5) {
      double x, y;
      printf("Digite os operandos: ");
      scanf("%lf %lf", &x, &y);
      // Executa a função desejada diretamente através
      // do vetor
      double res = operacoes[op - 1](x, y);
      printf("%lf %c %lf = %lf\n", x, nomes[op - 1], y, res);
    }
  }
}