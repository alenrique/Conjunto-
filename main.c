#include <stdio.h>
#include <stdlib.h>
#include "conjunto1.h"

int main()
{
    // menu (caso nao goste, abaixo tem os testes comentados sem o menu)
    //Divirta-se :)
    int escolha,escolha2,escolha3,n,pp,modo,i,t;
    Conjunto* novo;
    Conjunto* v1;
    Conjunto* v2;
    Conjunto* u;
    Conjunto* it;
    Conjunto* d;
    Conjunto* c;
    printf("Escolha o modo: \nModo 1 (criar e preencher um unico conjunto) \nModo 2 (criar dois conjuntos e usar outras funcionalidades) \n\n");
    scanf("%d",&modo);
    switch(modo){
        case 1:
            while(1){
                printf("Menu: \n1-Criar Conjunto \n2-Fechar \n\n");
                scanf("%d",&escolha);
                printf("\n");
                switch(escolha){
                    case 1:
                        novo = cria();
                        pp = 1;
                        while(pp){
                            printf("1-Adicionar Elemento \n2-Parar o Preenchimento \n\n");
                            scanf("%d",&escolha2);
                            switch(escolha2){
                                case 1:
                                    printf("Digite um numero: ");
                                    scanf("%d",&n);
                                    printf("\n");
                                    preecher(novo,n);
                                    continue;
                                case 2:
                                    pp = 0;
                                    break;
                                }

                        }
                        printf("\nConjunto Criado: ");
                        imprimir(novo);
                        break;
                    case 2:
                        exit(1);
                        break;
                    default:
                        printf("opcao invalida! \n");
                        continue;

                }
            }
            break;
        case 2: //modo 2
            for(i = 0; i < 2; i++){
                printf("\nConjunto %d \n\n",i+1);
                t = 1;
                while(t){
                    printf("Menu: \n1-Criar Conjunto \n2-Fechar \n\n");
                    scanf("%d",&escolha);
                    printf("\n");
                    switch(escolha){
                        case 1:
                            novo = cria();
                            pp = 1;
                            while(pp){
                                printf("1-Adicionar Elemento \n2-Parar o Preenchimento \n\n");
                                scanf("%d",&escolha2);
                                switch(escolha2){
                                    case 1:
                                        printf("Digite um numero: ");
                                        scanf("%d",&n);
                                        printf("\n");
                                        preecher(novo,n);
                                        continue;
                                    case 2:
                                        pp = 0;
                                        break;
                                    }

                            }
                            if(i == 0){
                                v1 = novo;
                                printf("O primeiro conjunto: ");
                                imprimir(v1);
                            }else{
                                v2 = novo;
                                printf("O segundo conjunto: ");
                                imprimir(v2);
                            }
                            break;

                        case 2:
                            exit(1);
                            break;
                        default:
                            printf("opcao invalida! \n");
                            continue;

                    }
                    t = 0;
                }
            }
            while(1){
                printf("Menu: \n1-Uniao \n2-Intersecao \n3-Diferenca \n4-Contido \n5-Complementar \n6-Fechar \n");
                scanf("%d",&escolha3);
                switch(escolha3){
                    case 1:
                        u = uniao(v1,v2);
                        printf("uniao dos dois conjuntos: ");
                        imprimir(u);
                        break;
                    case 2:
                        it = intersecao(v1,v2);
                        printf("intersecao dos dois conjuntos: ");
                        imprimir(it);
                        break;
                    case 3:
                        d = diferenca(v1,v2);
                        printf("diferenca dos dois conjuntos: ");
                        imprimir(d);
                        break;
                    case 4:
                        printf("Esta contido um no outro? ");
                        if(contido(v1,v2) == 1){
                            printf("Sim! \n");
                        }else{
                            printf("Nao! \n");
                        }
                        break;
                    case 5:
                        c = complementar(v1,v2);
                        printf("complementar dos dois conjuntos: ");
                        imprimir(c);
                        break;
                    case 6:
                        exit(1);
                }
            }
            break;
    }

    /*Conjunto* novo;
    novo = cria();
    preecher(novo,6);
    preecher(novo,4);
    preecher(novo,2);
    preecher(novo,1);
    preecher(novo,10);
    imprimir(novo);
    Conjunto* novod;
    novod = cria();
    preecher(novod,4);
    preecher(novod,3);
    preecher(novod,2);
    preecher(novod,1);
    preecher(novod,6);
    preecher(novod,10);
    preecher(novod,30);
    imprimir(novod);
    Conjunto* u;
    u = uniao(novo,novod);
    imprimir(u);
    Conjunto* i;
    i = intersecao(novo,novod);
    imprimir(i);
    Conjunto* d;
    d = diferenca(novo,novod);
    imprimir(d);
    printf("%d \n",contido(novo,novod));
    Conjunto* c;
    c = complementar(novo,novod);
    imprimir(c);
    preechercompleto(novo);
    preecher(novo,21);
    preecher(novo, 3);
    imprimir(novo);*/
    return 0;
}
