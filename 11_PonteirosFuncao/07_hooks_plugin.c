#include <stdio.h>

// Definição do ponteiro de função para o Hook
typedef void (*HookPreEnvio)(char* mensagem);

// Ponteiro global que agirá como o plugin registrado
HookPreEnvio pluginPreEnvio = NULL;

// Função para o usuário registrar o plugin customizado
void registrarPlugin(HookPreEnvio novoHook) { pluginPreEnvio = novoHook; }

// Extensão externa (Plugin) desenvolvida pelo usuário
void pluginCriptografia(char* msg) {
  printf("[PLUGIN] Criptografando logs antes de transmitir...\n");
  while (*msg != NULL) {
    // printf("Trocando %c para %c\n", *msg, (*msg) + 1);
    (*msg)++;  // próxima letra no alfabeto
    msg++;     // próximo caractere na string
  }
}

// Núcleo do sistema (Core)
void processarEnvio(char* dados) {
  // Executa o hook se algum plugin estiver acoplado
  if (pluginPreEnvio != NULL) {
    pluginPreEnvio(dados);
  }
  printf("[CORE] Transmitindo payload: %s\n", dados);
}

int main() {
  printf("--- Execução sem Plugin ---\n");
  char msg[] = "Texto puro";
  processarEnvio(msg);

  printf("\n--- Execução com Plugin Acoplado ---\n");
  registrarPlugin(pluginCriptografia);
  processarEnvio(msg);

  return 0;
}
