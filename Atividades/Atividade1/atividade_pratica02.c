#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char cliente[100];
    int codigo;
    char produto[100];
    int qtd;
    float preco;
    char categoria;
    float total;

    printf("Digite o nome completo do cliente: ");
    fgets(cliente, sizeof(cliente), stdin);
    cliente[strcspn(cliente, "\n")] = '\0'; 

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    limpar_buffer(); 

    printf("Digite o nome do produto: ");
    fgets(produto, sizeof(produto), stdin);
    produto[strcspn(produto, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &qtd);

    printf("Digite o preco unitario: ");
    scanf("%f", &preco);
    limpar_buffer(); 

    printf("Digite a categoria (A, B ou C): ");
    scanf("%c", &categoria);

    total = qtd * preco;

    printf("\n========================================\n");
    printf("            RECIBO DE COMPRA\n");
    printf("========================================\n");
    printf("%-10s: %s\n", "Cliente", cliente);
    printf("%-10s: %s\n", "Produto", produto);
    printf("%-10s: %d\n", "Codigo", codigo);
    printf("%-10s: %c\n", "Categoria", categoria);
    printf("%-10s: %d\n", "Qtd", qtd);
    printf("%-10s: R$ %.2f\n", "Unitario", preco);
    printf("%-10s: R$ %.2f\n", "Total", total);
    printf("========================================\n");

    return 0;
}