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

    // unsigned long int - numeros positivos maiores
    unsigned long int populacao, populacao2;

    int pontos_turisticos, pontos_turisticos2;

    // float / double
    float area, pib;
    float area2, pib2;

    // adicionando: densidade e pib per capita
    float densidade, densidade2;
    float capita, capita2;

    float superPoderA, superPoderB;


    // usar no switch
    int primeiroAtributo, segundoAtributo;
    float soma1, soma2;
    float atributo1Carta1, atributo1Carta2;
    float atributo2Carta1, atributo2Carta2;


    // CARTA 1

    printf("CARTA 1:\n");

    printf("Digite o Estado (letra de A a H): ");
    scanf(" %c", &estado);

    printf("Digite o Código da Carta (letra do estado + número de 01 a 04 - ex: A01): ");
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
    //pode acontecer de a densidade retornar 0.00 por conta das casas decimais, verificar
    printf("DENSIDADE POPULACIONAL: %.2f hab/km²\n", densidade2);
    printf("PIB PER CAPITA: %.2f reais\n", capita2);



    // CALCULANDO SUPER PODER
    // densidade é inverso
    superPoderB = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + capita2 + (1.0 / densidade2);



    // MENU INTERATIVO
    printf("\nEscolha o primeiro Atributo que deseja comparar:\n");
    printf("1 - Exibição dos Nomes\n");
    printf("2 - População\n");
    printf("3 - Área\n");
    printf("4 - PIB\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade\n");
    printf("7 - PIB per Capita\n");
    printf("8 - Super Poder\n");
    scanf("%d", &primeiroAtributo);

    switch (primeiroAtributo) {
        case 1:
        printf("Atributo - NOME\n");
        printf("Carta 1 - %s\n", cidade);
        printf("Carta 2 - %s\n", cidade2);
        break;

        case 2:
        printf("Atributo - POPULAÇÃO\n");
        printf("Carta 1 - %s: %lu\n", cidade, populacao);
        printf("Carta 2 - %s: %lu\n", cidade2, populacao2);

        if (populacao > populacao2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (populacao < populacao2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = populacao;
        atributo1Carta2 = populacao2;
        break;

        case 3:
        printf("Atributo - ÁREA\n");
        printf("Carta 1 - %s: %.2f\n", cidade, area);
        printf("Carta 2 - %s: %.2f\n", cidade2, area2);

        if (area > area2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (area < area2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = area;
        atributo1Carta2 = area2;
        break;

        case 4:
        printf("Atributo - PIB\n");
        printf("Carta 1 - %s: %.2f\n", cidade, pib);
        printf("Carta 2 - %s: %.2f\n", cidade2, pib2);

        if (pib > pib2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (pib < pib2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = pib;
        atributo1Carta2 = pib2;
        break;

        case 5:
        printf("Atributo - PONTOS TURÍSTICOS\n");
        printf("Carta 1 - %s: %d\n", cidade, pontos_turisticos);
        printf("Carta 2 - %s: %d\n", cidade2, pontos_turisticos2);

        if (pontos_turisticos > pontos_turisticos2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (pontos_turisticos < pontos_turisticos2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = pontos_turisticos;
        atributo1Carta2 = pontos_turisticos2;
        break;

        case 6:
        printf("Atributo - DENSIDADE\n");
        printf("Carta 1 - %s: %.2f\n", cidade, densidade);
        printf("Carta 2 - %s: %.2f\n", cidade2, densidade2);

        if (densidade < densidade2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (densidade > densidade2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = densidade;
        atributo1Carta2 = densidade2;
        break;

        case 7:
        printf("Atributo - PIB per Capita\n");
        printf("Carta 1 - %s: %.2f\n", cidade, capita);
        printf("Carta 2 - %s: %.2f\n", cidade2, capita2);

        if (capita > capita2) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (capita < capita2) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = capita;
        atributo1Carta2 = capita2;
        break;

        case 8:
        printf("Atributo - Super Poder\n");
        printf("Carta 1 - %s: %.2f\n", cidade, superPoderA);
        printf("Carta 2 - %s: %.2f\n", cidade2, superPoderB);

        if (superPoderA > superPoderB) {
            printf("Carta 1 - %s venceu!\n", cidade);
        } else if (superPoderA < superPoderB) {
            printf("Carta 2 - %s venceu!\n", cidade2);
        } else {
            printf("Empate!\n");
        }

        atributo1Carta1 = superPoderA;
        atributo1Carta2 = superPoderB;
        break;

        default:
        printf("Atributo inválido!\n");
        break;
    }


    printf("\nEscolha o segundo Atributo que deseja comparar:\n");
    printf("1 - Exibição dos Nomes\n");
    printf("2 - População\n");
    printf("3 - Área\n");
    printf("4 - PIB\n");
    printf("5 - Pontos Turísticos\n");
    printf("6 - Densidade\n");
    printf("7 - PIB per Capita\n");
    printf("8 - Super Poder\n");
    scanf("%d", &segundoAtributo);

    if (primeiroAtributo == segundoAtributo) {
        printf("Você escolheu o mesmo atributo!\n");
        printf("Reinicie o programa e escolha outro atributo!\n");
        return 0;
    } else {
        switch (segundoAtributo) {
            case 1:
            printf("Atributo - NOME\n");
            printf("Carta 1 - %s\n", cidade);
            printf("Carta 2 - %s\n", cidade2);
            break;

            case 2:
            printf("Atributo - POPULAÇÃO\n");
            printf("Carta 1 - %s: %lu\n", cidade, populacao);
            printf("Carta 2 - %s: %lu\n", cidade2, populacao2);

            if (populacao > populacao2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (populacao < populacao2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = populacao;
            atributo2Carta2 = populacao2;
            break;

            case 3:
            printf("Atributo - ÁREA\n");
            printf("Carta 1 - %s: %.2f\n", cidade, area);
            printf("Carta 2 - %s: %.2f\n", cidade2, area2);

            if (area > area2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (area < area2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = area;
            atributo2Carta2 = area2;
            break;

            case 4:
            printf("Atributo - PIB\n");
            printf("Carta 1 - %s: %.2f\n", cidade, pib);
            printf("Carta 2 - %s: %.2f\n", cidade2, pib2);

            if (pib > pib2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (pib < pib2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = pib;
            atributo2Carta2 = pib2;
            break;

            case 5:
            printf("Atributo - PONTOS TURÍSTICOS\n");
            printf("Carta 1 - %s: %d\n", cidade, pontos_turisticos);
            printf("Carta 2 - %s: %d\n", cidade2, pontos_turisticos2);

            if (pontos_turisticos > pontos_turisticos2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (pontos_turisticos < pontos_turisticos2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = pontos_turisticos;
            atributo2Carta2 = pontos_turisticos2;
            break;

            case 6:
            printf("Atributo - DENSIDADE\n");
            printf("Carta 1 - %s: %.2f\n", cidade, densidade);
            printf("Carta 2 - %s: %.2f\n", cidade2, densidade2);

            if (densidade < densidade2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (densidade > densidade2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = densidade;
            atributo2Carta2 = densidade2;
            break;

            case 7:
            printf("Atributo - PIB per Capita\n");
            printf("Carta 1 - %s: %.2f\n", cidade, capita);
            printf("Carta 2 - %s: %.2f\n", cidade2, capita2);

            if (capita > capita2) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (capita < capita2) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = capita;
            atributo2Carta2 = capita2;
            break;

            case 8:
            printf("Atributo - Super Poder\n");
            printf("Carta 1 - %s: %.2f\n", cidade, superPoderA);
            printf("Carta 2 - %s: %.2f\n", cidade2, superPoderB);

            if (superPoderA > superPoderB) {
                printf("Carta 1 - %s venceu!\n", cidade);
            } else if (superPoderA < superPoderB) {
                printf("Carta 2 - %s venceu!\n", cidade2);
            } else {
                printf("Empate!\n");
            }

            atributo2Carta1 = superPoderA;
            atributo2Carta2 = superPoderB;
            break;

            default:
            printf("Atributo inválido!\n");
            break;
        }
    }

    // Soma dos Atributos
    soma1 = atributo1Carta1 + atributo2Carta1;
    soma2 = atributo1Carta2 + atributo2Carta2;

    printf("\nSoma dos atributos:\n");
    printf("Carta 1 - (%s): %.2f\n", cidade, soma1);
    printf("Carta 2 - (%s): %.2f\n", cidade2, soma2);

    // se as somas forem iguais, ocorre empate
    // se não, vence a carta com a maior soma de atributos
    if (soma1 == soma2) {
        printf("Empate!\n");
    } else {
        printf("%s venceu a rodada!\n", (soma1 > soma2) ? cidade : cidade2);
    }

    return 0;
}