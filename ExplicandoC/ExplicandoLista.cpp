/*	
	Name: ExplicandoList.cpp
	Author: Miguel fernandes Santos 
	Date: 11/06/22 22:35
	Description: Explicando List
	
*/

// ------------------------------------------------------------------------//


// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// Prototipações:
void Limpar(); // limpa o console e o buffer
void Dados(); // Faz a leitura da variavel nome e idade
void inserir(); // cria um novo node
void Exibir(); // exibe a lista do inicio ao fim:

// ------------------------------------------------------------------------//


// Struct node:
typedef struct node{
	
	char Nome[51]; // Guarda o nome da pessoa
	int idade; // Guarda a idade da pessoa
	node *next = NULL; // Aponta para o proximo Node
	
} node; // fim da struct


// ------------------------------------------------------------------------//


// Variaveis globais:
node *list = NULL; // Inicio da lista
node *n = NULL; // cria um ponteiro de node para criar novos node

// ------------------------------------------------------------------------//


// inicio do main:
int main(){
	
	// variavel para ser usada como menu:
	int menu = 0;
	
	// enquanto menu for diferente de 3:
	while(menu != 3){
		
		// pergunta para o usuario o que ele deseja fazer e depois le a variavel
		printf("o que deseja fazer?\n1-Inserir\n2-Exibir\n3-Sair\n\ndigite aqui: ");
		scanf("%d", &menu);
		
		// Se menu for igual a 1:
		if(menu == 1){
			
			// chama a função limpar()
			Limpar();
			
			// chama a função inserir:
			inserir();
			
		}else if(menu == 2){ // se menu for igual a 2:
			
			// chama a função limpar()
			Limpar();
			
			// chama a função para exibir a lista:
			Exibir();
			
		}else if(menu == 3){ // se menu for igual a 3
			
			// chama a função limpar()
			Limpar();
			
			// Exibe uma mensagem:
			printf("Obrigado por me usar :)");
		
		}else{ // se não:
			
			// chama a função limpar()
			Limpar();
			
			// exibe uma mensagem de erro:
			printf("Erro!! opção invalida\nTente novamente\n\n");
			
		} // fim do if
		
	} // fim do while

} // fim do main caraio


// ------------------------------------------------------------------------//


// função para limpar console e buffer:
void Limpar(){
	
	// limpa o console:
	system("cls");
	
	// limpa o buffer do teclado:
	fflush(stdin);
	
} // fim da função


// ------------------------------------------------------------------------//


// função para pegar os dados necessarios:
void Dados(){
	
	// declara um ponteiro de no, que aponta para um espaço de
	// memoria capaz de guardar um node:
	n = (node *) malloc(sizeof(node));	
	
	// Verifica se teve algum tipo de dificuldade ao pedir uma
	// memoria livre:
	if(n == NULL){
		
		// Exibe uma mensagem e sai do programa:
		printf("Sem espaço na memoria!!!");
		exit(1);
		
	} // fim do if:
	
	// Mostra uma mensagem no console e le a variavel nome:
	printf("Digite seu nome: ");
	fgets(n->Nome, 51, stdin);
	
	// Mostra uma mensagem no console e le a variavel idade:
	printf("\n\nDigite sua idade: ");
	scanf("%d", &n->idade);
	
} // fim da função:


// ------------------------------------------------------------------------//


// função para criar um Node:
void inserir(){
	
	// chama a função dados:
	Dados();
	
	fflush(stdin);
	printf("Endereço de n: %p\n\n", n);
	
	// verifica se a lista aponta para null:
	if(list == NULL){
		
		// lista aponta para o endereço de N:
		list = n;
		
		// no atual aponta para NULL:
		n->next = NULL;
		
	}else{ // se nao:
		
		// O node n agora aponta para o que a lsita aponta:
		n->next = list;
		
		// lista aponta para n:
		list = n;
		
	} // fim do if
	
} // fim da função


// ------------------------------------------------------------------------//


// exibe a lista:
void Exibir(){
	
	// um laço para percorrer a lista:
	for(node *no = list; no != NULL; no = no->next){
		
		printf("Nome: %s",no->Nome);
		printf("Idade: %d\n\n", no->idade);
		
	} // fim do for
	
	printf("\n");
	
} // fim da função
