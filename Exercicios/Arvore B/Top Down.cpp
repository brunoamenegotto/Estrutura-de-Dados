#include<cstdlib>
#include<iostream>
#include<stdio.h>

using namespace std;

int repetidos = 0;
const int ORDEM = 200;
#define MIN_OCUP (ORDEM-1)/2
#define MAX_CHAVES ORDEM-1
struct no
{
    int dado[ORDEM - 1];
    struct no *filhos[ORDEM];
    int n_chaves;
};
struct no *raiz = NULL;
struct no *raizB = NULL;

struct no *cria_no(int chave){
    int i;

    struct no *novo;
    novo = new (struct no);
    novo -> dado[0] = chave;
    for(i = 0; i < ORDEM; i++)
        novo -> filhos[i] = NULL;
        novo -> n_chaves = 1;
        return novo;
}

// Encontra um valor dentro de um n� de uma ABM
int encontra_chave(struct no *atual, int chave) {

    int i=0;

    while (i<atual->n_chaves && chave>atual->dado[i])
        i++;
    return i;
}

// Insere uma chave em uma folha de uma ABM TopDown
void insere_folha(struct no *atual, int chave) {

    int i;

    for (i=atual->n_chaves ; i>0 && chave<atual->dado[i-1] ; i--)
        atual->dado[i]=atual->dado[i-1];
    atual->dado[i] = chave;
    atual->n_chaves++;
}

// Encontra o n� no qual uma determinada chave est�
struct no *encontra_no(int chave, int &posicao) {

    struct no *atual, *anterior;

    anterior=NULL;
    atual=raiz;
    while (atual!=NULL) {
        posicao=encontra_chave(atual,chave);
        anterior = atual;
        if (posicao<atual->n_chaves && chave==atual->dado[posicao]) {
            return atual;
        }
        atual = atual->filhos[posicao];
    }
    return anterior;
}

// Imprime todos os n�s de uma ABM
void percurso(struct no *atual) {
    int i;

    if (atual!=NULL) {

        for (i=0; i<atual->n_chaves; i++) {
            percurso(atual->filhos[i]);
            cout << atual->dado[i] << " ";
        }
        percurso(atual->filhos[atual->n_chaves]);
    }
}

// Conta o n�mero de n�s de uma ABM
int conta(struct no *atual) {

    int i, total;

    if (atual!=NULL) {
        total=1;
        for (i=0; i<atual->n_chaves+1; i++) {
            total = total + conta(atual->filhos[i]);
        };
        return total;
    };
    return 0;
}

void insere(int chave)
{
    struct no *novo, *atual;
    int posicao;
    if(raiz == NULL)
    {
        raiz = cria_no(chave);
        repetidos++;
        return;
    }
    atual = encontra_no(chave, posicao);

    if(atual -> dado[posicao] == chave)
        return; // chave repetida
    if(atual -> n_chaves != ORDEM - 1)
    {
        insere_folha(atual, chave);
        return;
    }
    novo = cria_no(chave);
    atual -> filhos[posicao] = novo;
}

int encontra_chave_B(struct no *atual, int chave) {

    int i=0;

    while (i<atual->n_chaves && chave>atual->dado[i])
        i++;
    return i;
}

// Insere uma chave em um nó de uma árvore B
void insere_chave_B(struct no *atual, int chave, struct no *filhodir) {
    int i;

    for (i=atual->n_chaves ; i>0 && chave<atual->dado[i-1] ; i--) {
        atual->dado[i] = atual->dado[i-1];
        atual->filhos[i+1] = atual->filhos[i];
    }

    atual->dado[i] = chave;
    atual->filhos[i+1] = filhodir;
    atual->n_chaves++;

}

// Função auxiliar para inserir um valor em uma árvore B  - Números repetidos não são inseridos
struct no *insere(struct no *atual, int info, bool &h, int &info_retorno) {
    int i, pos,
        info_mediano, //auxiliar para armazenar a chave que ira subir para o pai
        pos_mediano;    //posicao do mediano;
    struct no *temp, *filho_dir; //ponteiro para o filho a direita da chave

    if (atual == NULL) {
        //O no anterior e o ideal para inserir a nova chave (chegou em um no folha)
        h = true;
        info_retorno = info;
        return NULL;
    } else {
        pos = encontra_chave_B(atual,info);
        if (atual->n_chaves > pos && atual->dado[pos] == info) { //Números repetidos não são inseridos
         // printf("Chave ja contida na arvore -> %d \n",info);
            h = false;
        } else {
            //desce na arvore ate encontrar o no folha para inserir a chave.
            filho_dir = insere(atual->filhos[pos],info,h,info_retorno);
            if (h) { //Se true deve inserir a info_retorno no no.
                if (atual->n_chaves < MAX_CHAVES) { //Tem espaco na pagina
                    insere_chave_B(atual, info_retorno, filho_dir);
                    h = false;
                } else { //Overflow. Precisa subdividir
                    temp = new (struct no);
                    temp->n_chaves = 0;

                    //inicializa filhos com NULL
                    for (i = 0; i < ORDEM; i++)
                        temp->filhos[i] = NULL;

                    if (pos<MIN_OCUP)
                        pos_mediano=MIN_OCUP-1;
                    if (pos>=MIN_OCUP)
                        pos_mediano=MIN_OCUP;
                    //elemento mediano que vai subir para o pai
                    if (pos==MIN_OCUP) {
                        info_mediano = info_retorno;
                        temp->filhos[0] = filho_dir;
                        insere_chave_B(temp, atual->dado[pos_mediano], atual->filhos[pos_mediano+1]);
                     }
                     else {
                            info_mediano = atual->dado[pos_mediano];
                            temp->filhos[0] = atual->filhos[pos_mediano+1];
                     }
                    //insere metade do no atual no temp (efetua subdivisao)
                    for (i = pos_mediano + 1; i < MAX_CHAVES; i++)
                        insere_chave_B(temp, atual->dado[i], atual->filhos[i+1]);

                    //atualiza na atual.
                    for (i = pos_mediano; i<MAX_CHAVES; i++) {
                        atual->dado[i] = 0;
                        atual->filhos[i+1] = NULL;
                    }
                    atual->n_chaves = pos_mediano;

                    //Verifica em qual no sera inserida a nova chave
                    if (pos < MIN_OCUP)
                        insere_chave_B(atual, info_retorno, filho_dir);
                    if (pos > MIN_OCUP)
                        insere_chave_B(temp, info_retorno, filho_dir);

                    //retorna o mediano para inseri-lo no no pai e o temp como filho direito do mediano.
                    info_retorno = info_mediano;
                    return temp;
                }
            }
        }
    }
}

// Insere uma chave em uma árvore B
struct no *insere_arvoreB(struct no *atual, int chave) {
    bool h;
    int info_retorno, i;
    struct no *filho_dir, *nova_raiz;

    filho_dir = insere(atual,chave,h,info_retorno);
    if (h) {
        //Aumetara a altura da arvore
        nova_raiz = new (struct no);
        nova_raiz->n_chaves = 1;
        nova_raiz->dado[0] = info_retorno;
        nova_raiz->filhos[0] = atual;
        nova_raiz->filhos[1] = filho_dir;
        for (i = 2; i <= MAX_CHAVES; i++)
            nova_raiz->filhos[i] = NULL;
        return nova_raiz;
    } else return atual;
}
int main()
{
    int i, valor;
    for(i = 0; i < 30000; i++)
    {
        valor = rand();
        insere(valor);
        raizB = insere_arvoreB(raizB, valor);
    }
    cout << "\n TOP DOWN: ";
    cout << 100 * ((float)(30000-repetidos)/(conta(raiz) * ORDEM)) << "%";
    cout << "\n ArvoreB: ";
    cout << 100 * ((float)(30000-repetidos)/(conta(raizB) * ORDEM)) << "%";
}
