#include <stdio.h>

typedef struct {
  int codigo;
  int nivel;
  int energia;
  float experiencia;
} Personagem;

void resolve_combate(Personagem* atacante, Personagem* defensor, int dano_base);
void exibe_personagem(Personagem* p);

void resolve_combate(Personagem* atacante, Personagem* defensor,
                     int dano_base) {
  defensor->energia -= dano_base;
  if (defensor->energia < 0) defensor->energia = 0;
  if (defensor->energia == 0) {
    printf("Defensor: energia zerada!\n");
    atacante->experiencia += defensor->nivel * 12.5;
    if (atacante->experiencia >= 100) {
      printf("Atacante: aumento de nível!\n");
      atacante->nivel++;
      atacante->experiencia -= 100;
    }
  }
}

void exibe_personagem(Personagem* p) {
  printf("Código: %d\n", p->codigo);
  printf("Nível: %d\n", p->nivel);
  printf("Energia: %d\n", p->energia);
  printf("Experiência: %.2f\n", p->experiencia);
}

int main() {
  Personagem p1 = {1, 1, 50, 0.0};
  Personagem p2 = {2, 10, 30, 0.0};

  printf("ANTES:\n\n");
  printf("Personagem p1:\n");
  exibe_personagem(&p1);
  printf("\nPersonagem p2:\n");
  exibe_personagem(&p2);

  resolve_combate(&p1, &p2, 30);

  printf("\nDEPOIS:\n");
  printf("\nPersonagem p1:\n");
  exibe_personagem(&p1);
  printf("\nPersonagem p2:\n");
  exibe_personagem(&p2);
}