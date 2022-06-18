/*

	Name:ExplicandoListaDuplamenteEncadeada.Cpp 
	Author: Miguel Fernandes Santos
	Date: 18/06/22 10:48
	Description:  Explica como fazer uma lsita duplamente encadeada

*/


// sessão de includes:
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>
# include <locale.h> 


// ----------------------------------/


// Structs node:
typedef struct Node{
	
	// atributos da struct
	char Nome[100];
	Node *Before = NULL;
	Node *Next = NULL;
	
}Node; // fim do laço


// ----------------------------------/


// Variaveis globais:
Node *List = NULL;
Node *Fim = NULL;
Node *N = NULL;
FILE *Arquivo = NULL;

// ----------------------------------/


// Prototipações:
void Limpar();
void Dados();
void NovoNo();
void Exibir();
void Procurar();
int Vazia();


// ----------------------------------/


// inicio do main:
int main(){
	
	// usada para adicionar acentuação portuguesa:
	setlocale(LC_ALL, "Portuguese");
	
	// variavel que vai ser usada para o Menu:
	int Menu = 0;
	
	// um laço que continua enquanto o usuario nao digitar 3:
	while(Menu != 4){
		
		// exibe uma mensagem e le uma variavel:
		printf("O que deseja fazer?\n1-Inserir\n2-Exibir\n3-Procurar\n4-Sair\n\nDigite aqui: ");
		scanf("%d", &Menu);
		
		// verifica se Menu é igual a 1
		if(Menu == 1){
		
			// chama a função novo No:
			NovoNo();
					
		}else if(Menu == 2){ // verifica se Menu é igual a 2
		
			// chama a função Exibir:
			Exibir();
			
		}else if(Menu == 3){ // verifica se Menu é igual a 3
			
			Procurar();
			
		}else if(Menu == 4){
			
			// chama a função limpar:
			Limpar();
			
			// Exibe uma mensagem e termina o programa:
			printf("Obrigado por me usar :)");
		
		}else{ // Se não:
		
			// chama a função limpar:
			Limpar();
			
			// exibe uma mensagem no console:
			printf("Erro!! Opção invalida.\n\n");
		
		}// fim do if
		
	} // fim do while
	
} // fim do main


// ----------------------------------/


// inicio da função limpar:
void Limpar(){
	
	// limpa o console e o buffer:
	system("cls");
	fflush(stdin);
	
} // fim da função


// ----------------------------------/


// função que verifica se existe Node na lista:
int Vazia(){
	
	// verifica se esta apontado para NULL:
	if(List == NULL){
		
		// se estiver retorna 1 ou verdadeiro:
		return 1;
		
	}else{ // se não:
		
		// Retorna 0 ou falso:
		return 0;
		
	} // fim do if:
	
} // fim da função


// ----------------------------------/


// inicio da função para ler informações:
void Dados(){
	
	// chama a função limpar:
	Limpar();
	
	// mostra uma mensagem e le uma variavel:
	printf("Digite seu nome: ");
	fgets(N->Nome, 100, stdin);
	
} // fim da função:


// ----------------------------------/


// Função que cria um novo Node:
void NovoNo(){
	
	// o ponteiro aponta para um espaço da memoria
	// com espaço para um node:
	N = (Node *) malloc(sizeof(Node));
	
	// Chama a função dados:
	Dados();
	
	// se nao tiver uma lista iniciada:
	if(List == NULL){
		
		// Lista agora aponta para o endereço de N:
		List = N;
		
		// Lista aponta para NULL como proximo e anterior:
		N->Next = NULL;
		List->Before = NULL;
		
		// Fim da lista:
		Fim = N;
		
	} else{ // Se não:
		
		// Fim aponta para N:
		Fim->Next = N;
		
		// N aponta para null:
		N->Next = NULL;
		
		// O anterior de N é o Fim:
		N->Before = Fim;
		
		// Fim se torna N:
		Fim = N;
		
	} // fim do if
	
	// chama a função limpar:
	Limpar();
			
} // termino da função:


// ----------------------------------/


// Função que exibe a lista:
void Exibir(){
	
	// chama a função Limpar:
	Limpar();
	
	// laço para exibir a lista:
	for(Node *P = List; P != NULL; P = P->Next){
		
		// Mostra as informações do No:
		printf("Nome: %s", P->Nome);
		printf("Endereço de memoria: %p\n", P);
		printf("Anterior: %p\n", P->Before);
		printf("Proximo: %p\n\n", P->Next);
		
	} // fim da lista:
	
} // fim da lista:


// ----------------------------------/


// função que procura por um nome:
void Procurar(){
	
	// declaração da variavel nome:
	char Nome[100];
			
	// variavel para saber a posição do No:
	int qts = 1;
	
	// chama a função limpar:
	Limpar();
	
	// verifica se a pilha esta vazia:
	if(Vazia() == 0){
	
		// Mostra uma mensagem e le uma variavel:
		printf("Digite o nome que deseja procurar: ");
		fgets(Nome, 100, stdin);
		
		// laço para exibir a lista:
		for(Node *P = List; P != NULL; P = P->Next, qts++){
			
			// verifica se é igual:
			if(strcmp(P->Nome, Nome) == 0){
				
				printf("Achou!!! é o Node numero: %d || Endereço: %p\n\n", qts, P);
				break;
				
			}else if(P->Next == NULL){ // se nao tiver proximo Node:
				
				printf("Nao existe na lista atual!!\n\n");
				
			}// fim do if:
			
		} // fim da lista:
	
	}else{ // se não:
		
		printf("Lista vazia!!\n\n");
		
	} // fim do if:
	
} // fim da função
