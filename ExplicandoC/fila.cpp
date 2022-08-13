# include <stdio.h>
# include <conio.h>

// Prototipação:
int isEmpty();
int isFull();
void inserir(int);
int retirar();

// variaveis:
int fila[3]; // a fila
int total = 0; // qts de elementos dentro da pilha
int inicio = 0; // indice inicial da fila
int fim = 0; // indice do final da fila


// inicio do main:
int main(){
	
	inserir(10);
	inserir(24);
	inserir(56);
	
	while(isEmpty() != 1){
		
		printf("\n%d", retirar());
		
	}
	
	
} // fim do main


// função utilizada para verificar se a fila esta vazia:
int isEmpty(){
	
	// verifica se não existe um elemento na lista:
	if(total == 0){
		
		return 1;
		
	}else{ // se tiver um elemento:
		
		return 0;
		
	}
	
} // fim da função


// função para verificar se a fila esta cheia:
int isFull(){

	// verifica se a variavel total esta com o tamanho da pilha	
	if(total == sizeof(fila) / sizeof(int)){
	
		return 1;	
		
	}else{ // se ainda não estiver:
		
		return 0;
		
	}
	
} // fim da função


// função para inserir um elemento na lista:
void inserir(int numero){
	
	// verifica se a fila esta cheia:
	if(isFull() == 1){
		
		printf("\n\nFila cheia!!");
		
	}else{ // se não
		
		// adiciona o elemento no fim da pilha:
		fila[fim] = numero;
		
		// adiciona mais 1 no fim:
		fim++;
		
		// adiciona mais 1 no total:
		total++;

		// verifica se o fim da fila superou o tamanho total:
		if(fim == sizeof(fila) / sizeof(int)){
			
			// fim retorna a 0:
			inicio = 0;
			
		}
		
	}
	
} // fim da função


// retira um elemento da fila:
int retirar(){
	
	// verifica se a fila esta vazia:
	if(isEmpty() == 1){
		
		printf("\n\nFila vazia!!");
		
	}else{ // se não estiver
		
		// pega o elemento do inicio da lista:
		int elemento = fila[inicio];

		// inicio adiciona mais 1:
		inicio++;
		
		// diminui 1 no total:
		total--;
		
		// verifica se o inicio da fila superou o tamanho total:
		if(inicio == sizeof(fila) / sizeof(int)){

			// inicio retorna para 0
			inicio = 0;			
			
		}
		
		// retorna o elemento:
		return elemento;
		
	}
	
} // fim da função:
