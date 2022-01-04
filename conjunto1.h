#define MAX 10

typedef struct conjunto Conjunto;

//i) criar conjunto vazio;
Conjunto* cria();
//ii) preencher um conjunto inicialmente vazio;
void preecher(Conjunto*, int);
void preechercompleto(Conjunto*);
//iii) uni�o de dois conjuntos (se a uni�o estourar o limite de 10 posi��es essa opera��o d� um erro e n�o acontece);
Conjunto* uniao(Conjunto*, Conjunto*);
//iv) interse��o de dois conjuntos;
Conjunto* intersecao(Conjunto*, Conjunto*);
//v) diferen�a entre dois conjuntos;
Conjunto* diferenca(Conjunto*, Conjunto*);
//vi) verificar se um conjunto est� contido no outro;
int contido(Conjunto*,Conjunto*);
//vii) conjunto complementar (use as fun��es vi e v para facilitar);
Conjunto* complementar(Conjunto*, Conjunto*);
//viii) imprimir os elementos de um conjunto.
void imprimir(Conjunto*);
// fun��o exce��o
void ordenar (Conjunto*);

