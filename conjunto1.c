#include <stdio.h>
#include <stdlib.h>
#include "conjunto1.h"

struct conjunto{
    int tam;
    int* valor;
};

Conjunto* cria(){
    int i;
    Conjunto* con;
    con = (Conjunto*)malloc(sizeof(Conjunto));
    con->valor = (int*)malloc(MAX*sizeof(int));
    con->tam = 0;
    for(i = 0; i < MAX; i++){
        con->valor[i] = NULL;
    }
    return con;
}

void preecher(Conjunto* con,int num){
    int i;
    if(con == NULL){
        printf("ERRO! \n");
        exit(1);
    }
    for(i = 0; i < con->tam; i++){
        if(num == con->valor[i]){
            return 0;
        }
    }
    con->valor[con->tam] = num;
    con->tam++;
    ordenar(con);
}

void preechercompleto(Conjunto* con){
    if(con == NULL){
        printf("ERRO! ");
        exit(1);
    }
    int i,j,num,verif;
    for(i = 0; i < MAX; i++){
        verif = 0;
        scanf("%d",&num);
        for(j = 0; j < con->tam; j++){
            if(num == con->valor[j]){
                verif++;
            }
        }
        if(verif == 0){
            con->valor[i] = num;
            con->tam++;
        }else{
            i--;
        }
    }
}

Conjunto* uniao(Conjunto* a, Conjunto* b){
    if(a == NULL || b == NULL){
        printf("ERRO! ");
        exit(1);
    }
    int i;
    int tamtotal = (a->tam + b->tam);
    if(tamtotal > MAX){
        printf("ERRO!!! conjunto uniao maior que maior que o limite \n");
        exit(1);
    }
    Conjunto* uni;
    uni = cria();
    if(uni == NULL){
        printf("ERRO! ");
        exit(1);
    }
    for(i = 0; i < a->tam; i++){
        preecher(uni,a->valor[i]);
    }
    for(i = 0; i < b->tam; i++){
        preecher(uni,b->valor[i]);
    }
    ordenar(uni);
    return uni;
}

Conjunto* intersecao(Conjunto* a,Conjunto* b){
    if(a == NULL || b == NULL){
        printf("ERRO! ");
        exit(1);
    }
    int i,j,k;
    k = 0;
    Conjunto* its;
    its = cria();
    if(its == NULL){
        printf("ERRO! ");
        exit(1);
    }
    for(i = 0; i < a->tam; i++){
        for(j = 0; j < b->tam; j++){

            if(a->valor[i] == b->valor[j]){
                its->valor[k] = a->valor[i];
                k++;
                its->tam++;
            }
        }
    }
    ordenar(its);
    return its;
}

Conjunto* diferenca(Conjunto* a, Conjunto* b){
    int i;
    Conjunto* dif;
    dif = cria();
    Conjunto* its;
    its = intersecao(a,b);
    if(its == NULL || dif == NULL){
        printf("ERRO! ");
        exit(1);
    }
    for(i = 0; i < a->tam; i++){
        if(a->valor[i] != its->valor[i]){
            preecher(dif,a->valor[i]);
        }
    }
    return dif;
}

int contido(Conjunto* a, Conjunto* b){
    int i,j,cont;
    cont = 0;
    if(a->tam == b->tam){
        return 0;
    }else if(a->tam > b->tam){
        for(i = 0; i < b->tam; i++){
            for(j = 0; j < a->tam; j++){
                if(b->valor[i] == a->valor[j]){
                    cont++;
                }
            }
        }
    }else{
        for(i = 0; i < a->tam; i++){
            for(j = 0; j < b->tam; j++){
                if(a->valor[i] == b->valor[j]){
                    cont++;
                }
            }
        }
    }
    if(cont == a->tam){
        printf("o primeiro esta contido no segundo \n");
        return 1;
    }
    if(cont == b->tam){
        printf("o segundo esta contido no primeiro \n");
        return 1;
    }
    return 0;
}

Conjunto* complementar(Conjunto* a, Conjunto* b){
    Conjunto* comp;
    comp = cria();
    if(comp == NULL){
        printf("ERRO! ");
        exit(1);
    }
    if(contido(a,b)){
        if(a->tam > b->tam){
            comp = diferenca(a,b);
        }else{
            comp = diferenca(b,a);
        }
    }else{
        printf("um nao e complemento do outro \n");
    }
    return comp;
}

void imprimir(Conjunto* con){
    if(con == NULL){
        printf("ERRO! ");
        exit(1);
    }
    int i;
    printf("{ %d ",con->valor[0]);
    for(i = 1; i < con->tam; i++){
        printf(", %d ",con->valor[i]);
    }
    printf("}\n");
}

void ordenar(Conjunto* con){
    int i,aux,troca;
    do{
        troca = 0;
        for(i = 0; i < con->tam-1; i++){
            if(con->valor[i] > con->valor[i+1]){
                aux = con->valor[i];
                con->valor[i] = con->valor[i+1];
                con->valor[i+1] = aux;
                troca = 1;
            }
        }
    }while(troca);
}

