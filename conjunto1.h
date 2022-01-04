#define MAX 10

typedef struct conjunto Conjunto;

//i) criar conjunto vazio;
Conjunto* cria();
//ii) preencher um conjunto inicialmente vazio;
void preecher(Conjunto*, int);
void preechercompleto(Conjunto*);
//iii) união de dois conjuntos (se a união estourar o limite de 10 posições essa operação dá um erro e não acontece);
Conjunto* uniao(Conjunto*, Conjunto*);
//iv) interseção de dois conjuntos;
Conjunto* intersecao(Conjunto*, Conjunto*);
//v) diferença entre dois conjuntos;
Conjunto* diferenca(Conjunto*, Conjunto*);
//vi) verificar se um conjunto está contido no outro;
int contido(Conjunto*,Conjunto*);
//vii) conjunto complementar (use as funções vi e v para facilitar);
Conjunto* complementar(Conjunto*, Conjunto*);
//viii) imprimir os elementos de um conjunto.
void imprimir(Conjunto*);
// função exceção
void ordenar (Conjunto*);

