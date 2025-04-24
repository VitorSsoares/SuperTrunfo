#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[30];
    int codigo;

    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;

    float densidade;
    double pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade(unsigned long int pop, float area) {
    return pop / area;
}

// Função para calcular o PIB per capita
double calcular_pib_per_capita(double pib, unsigned long int pop) {
    return pib / pop;
}

// Função para calcular o Super Poder
float calcular_super_poder(Carta c) {
    return (float)(c.populacao + c.area + c.pib + c.pontos_turisticos + c.pib_per_capita + (1.0f / c.densidade));
}

// Função para comparar atributos
void comparar_atributo(const char* nome, float valor1, float valor2, int menor_vence) {
    int resultado = 0;

    if (menor_vence) {
        resultado = valor1 < valor2 ? 1 : 0;
    } else {
        resultado = valor1 > valor2 ? 1 : 0;
    }

    printf("%s: Carta 1 venceu (%d)\n", nome, resultado);
}

int main() {
    Carta c1, c2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Nome: "); scanf(" %[^\n]", c1.nome);
    printf("Estado: "); scanf(" %[^\n]", c1.estado);
    printf("Código: "); scanf("%d", &c1.codigo);
    printf("População: "); scanf("%lu", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%lf", &c1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c1.pontos_turisticos);

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Nome: "); scanf(" %[^\n]", c2.nome);
    printf("Estado: "); scanf(" %[^\n]", c2.estado);
    printf("Código: "); scanf("%d", &c2.codigo);
    printf("População: "); scanf("%lu", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%lf", &c2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c2.pontos_turisticos);

    // Cálculo dos atributos derivados
    c1.densidade = calcular_densidade(c1.populacao, c1.area);
    c2.densidade = calcular_densidade(c2.populacao, c2.area);

    c1.pib_per_capita = calcular_pib_per_capita(c1.pib, c1.populacao);
    c2.pib_per_capita = calcular_pib_per_capita(c2.pib, c2.populacao);

    c1.super_poder = calcular_super_poder(c1);
    c2.super_poder = calcular_super_poder(c2);

    // Comparações
    printf("\nComparação de Cartas:\n");
    comparar_atributo("População", c1.populacao, c2.populacao, 0);
    comparar_atributo("Área", c1.area, c2.area, 0);
    comparar_atributo("PIB", c1.pib, c2.pib, 0);
    comparar_atributo("Pontos Turísticos", c1.pontos_turisticos, c2.pontos_turisticos, 0);
    comparar_atributo("Densidade Populacional", c1.densidade, c2.densidade, 1); // menor vence
    comparar_atributo("PIB per Capita", c1.pib_per_capita, c2.pib_per_capita, 0);
    comparar_atributo("Super Poder", c1.super_poder, c2.super_poder, 0);

    return 0;
}
