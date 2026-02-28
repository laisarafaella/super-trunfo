//incluindo para usar printf
#include <stdio.h>

// incluindo para usar strcspn
#include <string.h>

int main() {

    // declarando as variaveis
    char estado, estado2;
    char codigo[5];
    char codigo2[5];
    char cidade[50];
    char cidade2[50];

    // alterar para unsigned long int - numeros positivos maiores
    unsigned long int populacao, populacao2;

    int pontos_turisticos, pontos_turisticos2;

    float area, pib;
    float area2, pib2;

    // adicionando: densidade e pib per capita
    float densidade, densidade2;
    float capita, capita2;

    float superPoderA, superPoderB;

    // exibir os resultados das comparacoes
    int resultadoPop;
    int resultadoArea;
    int resultadoPIB;
    int resultadoPontos;
    int resultadoDensidade;
    int resultadoCapita;
    int resultadoSuper;



    printf("CARTA 1:\n");

    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado);

    printf("Digite o Código da Carta (letra do estado + número de 01 a 04 - ex: A01: ");
    scanf("%s", &codigo);
    
    getchar(); // tirar o enter para não pular para o próximo, buffer

    printf("Digite o nome da Cidade: ");
    // scanf("%s", &cidade);
    // aceitar nome completo
    fgets(cidade, 50, stdin);
    //remover uma linha
    cidade[strcspn(cidade, "\n")] = 0;

    printf("Digite o número de Habitantes da cidade: ");
    scanf("%lu", &populacao);

    printf("Digite a Área da Cidade em km²: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib);

    printf("Digite a quantidade de Pontos Turisticos na cidade: ");
    scanf("%d", &pontos_turisticos);



    // CALCULAR DENSIDADE E PIB PER CAPITA, ARMAZENAR TAMBÉM
    // populacao está em long int e area em float
    densidade = (float) populacao / area;
    // pib está em bilhões
    capita = (pib * 1000000000) / populacao;



    // exibicao de informacoes
    printf("\nCARTA 1:\n");
    printf("ESTADO: %c\n", estado);
    printf("CÓDIGO: %s\n", codigo);
    printf("NOME DA CIDADE: %s\n", cidade);
    printf("POPULAÇÃO: %lu\n", populacao);
    printf("ÁREA: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("NÚMERO DE PONTOS TURÍSTICOS: %d\n", pontos_turisticos);
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidade);
    printf("PIB PER CAPITA: %.2f reais\n", capita);


    // CALCULANDO SUPER PODER, todos os atributos
    // densidade é inverso
    superPoderA = (float)populacao + area + pib + pontos_turisticos + capita + (1.0 / densidade);




    // CARTA 2

    printf("\nCARTA 2:\n");

    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: A01- letra do estado + número de 01 a 04): ");
    scanf("%s", &codigo2);
    
    getchar(); // tirar o enter para não pular para o próximo, buffer

    printf("Digite o nome da Cidade: ");
    // scanf("%s", &cidade);
    // aceitar nome completo e remover uma linha
    fgets(cidade2, 50, stdin);
    cidade2[strcspn(cidade2, "\n")] = 0;
    

    printf("Digite o número de Habitantes da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a Área da Cidade em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de Pontos Turisticos na cidade: ");
    scanf("%d", &pontos_turisticos2);


    // CALCULAR DENSIDADE E PIB PER CAPITA, ARMAZENAR
    densidade2 = (float) populacao2 / area2;
    capita2 = (pib2 * 1000000000) / populacao2;


    //exibicao de informacoes
    printf("\nCARTA 2:\n");
    printf("ESTADO: %c\n", estado2);
    printf("CÓDIGO: %s\n", codigo2);
    printf("NOME DA CIDADE: %s\n", cidade2);
    printf("POPULAÇÃO: %lu\n", populacao2);
    printf("ÁREA: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("NÚMERO DE PONTOS TURÍSTICOS: %d\n", pontos_turisticos2);
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidade2);
    printf("PIB PER CAPITA: %.2f reais\n", capita2);



    // CALCULANDO SUPER PODER
    // densidade é inverso
    superPoderB = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + capita2 + (1.0 / densidade2);


    // Comparacao de atributos

    resultadoPop = populacao > populacao2;
    resultadoArea = area > area2;
    resultadoPIB = pib > pib2;
    resultadoPontos = pontos_turisticos > pontos_turisticos2;

    // densidade é diferente: menor vence 
    resultadoDensidade = densidade < densidade2;

    resultadoCapita = capita > capita2;
    resultadoSuper = superPoderA > superPoderB;



    // EXIBICAO DOS RESULTADOS DA COMPARACAO
    // depois refatorar

    printf("\nCOMPARAÇÃO DE CARTAS:\n");
    printf("Se Carta 1 vencer, retona 1 e se a Carta 2 vencer, retorna 0\n");
    printf("População: Carta 1 venceu (%d)\n", resultadoPop);
    printf("Área: Carta 1 venceu (%d)\n", resultadoArea);
    printf("PIB: Carta 1 venceu (%d)\n", resultadoPIB);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", resultadoPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", resultadoDensidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", resultadoCapita);
    printf("Super Poder: Carta 1 venceu (%d)\n", resultadoSuper);

    return 0;
}