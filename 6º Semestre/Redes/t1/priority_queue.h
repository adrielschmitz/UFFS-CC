#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#define dad(myIndex) ((myIndex) - 1) / 2
#define left(myIndex) (myIndex)*2 + 1
#define right(myIndex) (myIndex)*2 + 2
#define MAX 11234

// Estrutura da fila, key é obrigatoria, podendo tem mais elementos na estrutura!
typedef struct {
  int key, value;
} type;

void swap(int index1, int index2);

// Sobe a heap checando se o nó pai é menor que o filho (utilizado no PUSH)
void check_priority_top(int tempIndex);

// Desce a heap da raiz checando se o nó é menor que seus dois filhos (utilizado no POP)
void check_priority_bottom(int tempIndex);

// Remove o primeiro elemento
void pop();

// Testa se a fila está vazia, 0 == vazia 
int empty();

// Inseri um elemento na fila
void push(type element);

// Retorna o primeiro elemento da Fila, se existir.
type top();

#endif