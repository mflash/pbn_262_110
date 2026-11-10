#include <stdio.h>

// Cores ANSI para o terminal
#define ANSI_CYAN "\033[36m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_RED "\033[31m"
#define ANSI_RESET "\033[0m"

#ifndef LOG_LEVEL
#define LOG_LEVEL 0  // 0 = DEBUG, 1 = WARN, 2 = ERROR
#endif

#if LOG_LEVEL <= 0
#define LOG_DEBUG(fmt, ...)                                                    \
  fprintf(stderr, ANSI_CYAN "[DEBUG] " ANSI_RESET "[%s:%d in %s()] " fmt "\n", \
          __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)  // removido em tempo de compilacao!
#endif

#if LOG_LEVEL <= 1
#define LOG_WARN(fmt, ...)                                               \
  fprintf(stderr,                                                        \
          ANSI_YELLOW "[WARN]  " ANSI_RESET "[%s:%d in %s()] " fmt "\n", \
          __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
#define LOG_WARN(fmt, ...)
#endif

#define LOG_ERROR(fmt, ...)                                                   \
  fprintf(stderr, ANSI_RED "[ERROR] " ANSI_RESET "[%s:%d in %s()] " fmt "\n", \
          __FILE__, __LINE__, __func__, ##__VA_ARGS__)

int dividir(int a, int b) {
  LOG_DEBUG("Iniciando divisao de %d por %d", a, b);
  if (b == 0) {
    LOG_ERROR("Tentativa de divisao por zero!");
    return -1;
  }
  return a / b;
}

int main(void) {
  LOG_DEBUG("Iniciando aplicacao");
  int r1 = dividir(10, 2);
  printf("Resultado: %d\n", r1);
  int r2 = dividir(10, 0);
  printf("Resultado: %d\n", r2);
  return 0;
}
