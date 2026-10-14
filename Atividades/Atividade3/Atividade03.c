/*
O fall-through consciente e vantajoso quando varios valores precisam
executar exatamente a mesma acao, pois evita a repeticao de codigo.
Nesta atividade, ele e especialmente util para agrupar as prioridades
em maiusculas e minusculas e os dias que possuem o mesmo expediente.
O switch trabalha comparando valores exatos e constantes.
Por isso, ele nao substitui o if-else-if usado para faixas de renda,
pois intervalos exigem comparacoes relacionais, como maior e menor.
*/

#include <stdio.h>

int main(void)
{
    int codigo_servico;
    int dia;
    int guiche;

    char prioridade;

    const char *servico;
    const char *categoria;
    const char *prazo;
    const char *nome_prioridade;
    const char *nome_dia;
    const char *expediente;
    const char *status;

    float taxa_base;
    float acrescimo;
    float taxa_final;


    /* ========================================
       ENTRADA DE DADOS
       ======================================== */

    printf("Digite o codigo do servico: ");
    scanf("%d", &codigo_servico);

    printf("Digite a prioridade (U/u, N/n ou B/b): ");
    scanf(" %c", &prioridade);

    printf("Digite o dia da semana (1 a 7): ");
    scanf("%d", &dia);


    /* ========================================
       1. SERVICO
       ======================================== */

    switch (codigo_servico)
    {
        case 1:
            servico = "Historico escolar";
            categoria = "Documento simples";
            prazo = "2 dias uteis";
            taxa_base = 15.00f;
            status = "ACEITO";
            break;

        case 2:
            servico = "Declaracao de matricula";
            categoria = "Documento simples";
            prazo = "2 dias uteis";
            taxa_base = 15.00f;
            status = "ACEITO";
            break;

        case 3:
            servico = "Declaracao de vinculo";
            categoria = "Documento simples";
            prazo = "2 dias uteis";
            taxa_base = 15.00f;
            status = "ACEITO";
            break;

        case 4:
            servico = "Trancamento";
            categoria = "Interrupcao de vinculo";
            prazo = "10 dias uteis";
            taxa_base = 0.00f;
            status = "ACEITO";
            break;

        case 5:
            servico = "Cancelamento";
            categoria = "Interrupcao de vinculo";
            prazo = "10 dias uteis";
            taxa_base = 0.00f;
            status = "ACEITO";
            break;

        case 6:
            servico = "Colacao de grau";
            categoria = "Ato solene";
            prazo = "15 dias uteis";
            taxa_base = 80.00f;
            status = "ACEITO";
            break;

        default:
            servico = "Codigo invalido";
            categoria = "-";
            prazo = "0";
            taxa_base = 0.00f;
            status = "RECUSADO";
            break;
    }


    /* ========================================
       2. PRIORIDADE
       ======================================== */

    switch (prioridade)
    {
        case 'U':
            /* fall-through */
        case 'u':
            nome_prioridade = "Urgente";
            guiche = 1;
            acrescimo = 10.00f;
            break;

        case 'N':
            /* fall-through */
        case 'n':
            nome_prioridade = "Normal";
            guiche = 2;
            acrescimo = 0.00f;
            break;

        case 'B':
            /* fall-through */
        case 'b':
            nome_prioridade = "Balcao";
            guiche = 3;
            acrescimo = 0.00f;
            break;

        default:
            nome_prioridade = "Invalida";
            guiche = 0;
            acrescimo = 0.00f;
            break;
    }


    /* ========================================
       3. NOME DO DIA
       Todo case possui break.
       ======================================== */

    switch (dia)
    {
        case 1:
            nome_dia = "Domingo";
            break;

        case 2:
            nome_dia = "Segunda-feira";
            break;

        case 3:
            nome_dia = "Terca-feira";
            break;

        case 4:
            nome_dia = "Quarta-feira";
            break;

        case 5:
            nome_dia = "Quinta-feira";
            break;

        case 6:
            nome_dia = "Sexta-feira";
            break;

        case 7:
            nome_dia = "Sabado";
            break;

        default:
            nome_dia = "Dia invalido";
            break;
    }


    /* ========================================
       4. EXPEDIENTE
       ======================================== */

    switch (dia)
    {
        case 2:
            /* fall-through */
        case 3:
            /* fall-through */
        case 4:
            /* fall-through */
        case 5:
            expediente = "Pleno";
            break;

        case 6:
            expediente = "Reduzido";
            break;

        case 1:
            /* fall-through */
        case 7:
            expediente = "Fechado";
            break;

        default:
            expediente = "Dia invalido";
            break;
    }


    /* ========================================
       CALCULO FINAL
       ======================================== */

    taxa_final = taxa_base + acrescimo;


    /* ========================================
       SAIDA
       ======================================== */

    printf("\n");
    printf("========================================\n");
    printf("    TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");

    printf("Servico            : %s\n", servico);
    printf("Categoria          : %s\n", categoria);
    printf("Prazo              : %s\n", prazo);
    printf("Taxa base          : R$ %.2f\n", taxa_base);
    printf("Prioridade         : %s\n", nome_prioridade);
    printf("Guiche             : %d\n", guiche);
    printf("Acrescimo          : R$ %.2f\n", acrescimo);
    printf("Dia                : %s\n", nome_dia);
    printf("Expediente         : %s\n", expediente);

    printf("----------------------------------------\n");

    printf("Taxa final         : R$ %.2f\n", taxa_final);
    printf("Status do servico  : %s\n", status);

    printf("========================================\n");

    return 0;
}
