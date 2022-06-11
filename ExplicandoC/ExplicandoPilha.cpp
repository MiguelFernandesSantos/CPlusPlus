/*	

	Name: ExplicandoPilha.cpp
	Author: Miguel fernandes Santos 
	Date: 11/06/22 12:37
	Description: Explicando buble
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// Prototipações:
int IsEmpty(); // função que verifica se a pilha esta vazia:
int IsFull(); // função que verifica se a pilha esta cheia:
void Push(char); // função que coloca algo no topo da pilha:
char Pop(); // função que remove algo da pilha:
void Exibir(); // função que exibe a pilha:
void Ler(); // função que le um valor:
void Limpar(); // limpar buffer e o console

// ------------------------------------------------------------------------//

// Variaveis globais:
char MinhaPilha[6]; // variavel que é a principal, afinal ela é a pilha
int Topo = -1; // variavel que vai ser utilizada para saber a posição atual
char Retirado; // Variavel para receber o valor retirado pelo pop

// ------------------------------------------------------------------------//

/*

	  O conceito de pilha é basicamente criar algo que permita ser empilhado
	seu conceito principal é de que o ultimo que entrou na pilha vai ser
	o primeiro a ser retirado. 
	  Um bom exemplo disso seria pratos empilhados, quando retiramos os
	pratos pegamos o que esta no topo da pilha de pratos ate chegar 
	ao ultimo.
	  A pilha dentro da programação segue esse conceito, porem tendo um 
	limite, como a pilha é um vetor e um vetor precisa ser inicializado
	com o total de indices que ele tera, o limite da pilha acaba sendo 
	N - 1 (sendo N = Total de indices).

*/

// Inicio do main:
int main(){
	
	// Variavel para ser usada como menu:
	int Menu = 0;
	
	// Enquanto Menu for diferente de 4:
	while(Menu != 4){	
		
		// exibe um menu com 4 opções:
		printf("O que deseja fazer?\n1-Inserir\n2-Remover\n3-Exibir\n4-Sair\n\nDigite Aqui: ");
		
		// Le a variavel Menu:
		scanf("%d", &Menu);
		
		// Verifica se o usuario digitou 1:
		if(Menu == 1){
			
			// chama a função ler:
			Ler();
			
		}else if(Menu == 2){ // verifica se o usuario digitou 2:
			
			// chama a função limpar:
			Limpar();
			
			// chama a função pop:
			Retirado = Pop();
			
		}else if(Menu == 3){
			
			// chama a função limpar:
			Limpar();
			
			// chama a função exibir:
			Exibir();

		}else if(Menu == 4){ // Verifica se o usuario digitou 4:
			
			// chama a função limpar:
			Limpar();

			// Exibe uma mensagem:
			printf("Obrigado por me usar :)");
	
			// sai do laço:
			break;
			
		}else{ // Se não:
			
			// chama a função limpar:
			Limpar();			
		
			// Exibe uma mensagem no console dizendo que não existe a opção:
			printf("Erro!!! Opção invalida\nTente novamente.\n\n");
			
		} // fim do if
		
	}// fim do while

}// fim do main:


// ------------------------------------------------------------------------//

/*

	A função limpar é basicamente desenvolvida para limpar tanto o console
	Como o buffer do teclado, retirando assim os possiveis erros de entrada
	de dados tanto no menu quanto na parte de inserir algo na pilha.
	ja a parte de limpar o console é literalmente so para deixar visivelmente
	mais agradavel.

*/

// função limpar:
void Limpar(){
	
	// limpa o console e o buffer:
	system("cls");
	fflush(stdin);
	
} // fim limpar:


// ------------------------------------------------------------------------//

/*
	
	Essa função serve basicamente para verificase se a pilha se encontra 
	vazia.
	Para fazer isso a função verifica se a variavel global TOPO se encontra
	com o valor de -1 (que seria seu valor inicial).

*/

// função para saber se a pilha esta vazia:
int IsEmpty(){
	
	// Ele verifica se a variavel Topo esta com seu valor inicial:
	if(Topo == -1){
		
		// Se tiver ele retorna 1 ou lendo de forma indireta verdadeiro:
		return 1;
		
	}else{ // Se não
		
		// Ele retorna 0 ou lendo de forma indireta falso:
		return 0;
		
	}// fim do if
	
} // fim da função is empty


// ------------------------------------------------------------------------//

/*

	Essa função é oposto da função isEmpty, porque ela verifica se a pilha
	se encontra cheia, para deixar algo mais dinamico ela esta utilizando
	do sizeof para pegar a quantidade de valores da pilha e subtraindo 1.
	Fazendo isso ele encontra o ultimo indice da pilha, e quando a variavel
	Topo se encontra com o ultimo indice da pilha ele nao permite inserir.

*/

// função usada para saber se a pilha esta cheia ou não:
int IsFull(){
	
	// Ele verifica se a variavel topo esta com o tamanho total do vetor:
	if(Topo == (sizeof(MinhaPilha) - 1)){
		
		// Se tiver ele retorna 1 ou lendo de forma indireta verdadeiro:
		return 1;
		
	}else{ // Se não
		
		// Ele retorna 0 ou lendo de forma indireta falso:
		return 0;
		
	} // fim do if
	
} // Fim da função Is full


// ------------------------------------------------------------------------//

/*

	A função push é basicamente para inserir valores na pilha, ela é uma
	função sem retorno que tem como parametro o que vc deseja inserir
	ela verifica se a função isFULL retornou 1 (verdadeiro) se estiver
	1 ele nao permite inserir pois significa que o topo ja foi ocupado
	por algum valor.
	caso não ele insere um item na pilha e adiciona +1 no topo

*/

// Função que vai ser utilizada para inserir elementos na pilha:
void Push(char elemento){
	
	// ele verifica se existe ainda valores livres chamando a função Is full:
	if(IsFull() == 0){ // Se tiver espaço:
		
		// Ele adiciona mais um na variavel para poder ir para o proximo indice:
		Topo++;
		
		// E adiciona o elemento nesse novo indice:
		MinhaPilha[Topo] = elemento;
		
		// chama a função limpar:
		Limpar();
		
	}else{ // Se não
		
		// chama a função limpar:
		Limpar();
		
		// Exibe que a pilha esta cheia:
		printf("\nA pilha ja esta cheia!!");
		
	} // fim do if
	
} // fim da função push


// ------------------------------------------------------------------------//

/*
	
	
	A função pop é o oposto da push, ela tem como objetivo remover um valor
	da pilha, para isso ela verifica primeiro se a função is empty retornou
	1 (verdadeiro), caso tenha retornado ele nao permite retirar algo.
	caso ela tenha retornado falso a função guarda em uma variavel o elemento
	retirado e subtrai 1 da variavel TOPO.

*/

// Função que vai ser utilizada para remover elementos da pilha:
char Pop(){
	
	// verifica se a pilha esta vazia com a função is empty:
	if(IsEmpty() == 0){ // se nao estiver:
		
		// declara uma variavel elemento para receber o elemento atual da pilha:
		char elemento = MinhaPilha[Topo];
		
		// Decrementa a variavel Topo: 
		Topo--;
		
		// Exibe o que foi removido:
		printf("Foi removido '%c' da pilha\n\n", elemento);
		
		// Retorna o elemento retirado:
		return elemento;
		
	}else{ // Se estiver vazia:
		
		// chama a função limpar:
		Limpar();;
		
		// Exibe que a pilha esta vazia:
		printf("Nao existe nada para retirar!!\n\n");
		
	}// fim do if:
	
} // Fim da função Pop


// ------------------------------------------------------------------------//

/*

	é uma função que permite fazer a leitura de um valor para ser inserido
	na pilha, passando o valor lido para a função push

*/

// função para ler valores:
void Ler(){
	
	// verifica se a pilha nao esta cheia;
	if(IsFull() == 0){
	
		// variavel para o push/Inserir:
		char Elemento[1];
					
		// laço que obriga o usuario a digitar algo:
		while(strlen(Elemento) == 0){
					
			// chama a função limpar:
			Limpar();
					
			// mostra uma mensagem e le um elemento:
			printf("Digite o valor que deseja inserir: ");
			gets(Elemento);
				
		} // fim do while:
				
		// Envia o que foi lido para a função push:
		Push(Elemento[0]);
				
		// chama a função limpar:
		Limpar();
		
	}else{ // se nao:
	
		// chama a função limpar:
		Limpar();
	
		// Exibe que a pilha esta cheia:
		printf("A pilha ja esta cheia!!\n\n");
		
	} // fim do if
	
} // fim  da função:


// ------------------------------------------------------------------------//

/*

	Essa função tem como objetivo fazer com que a pilha seja exibida do 
	primeiro indice ate o valor da variavel Topo

*/

// função para exibir o array:
void Exibir(){
	
	// Verifica se a pilha esta vazia:
	if(IsEmpty() == 1){ // se estiver:
				
		// Exibe que a pilha esta vazia:
		printf("Pilha vazia!! nada para exibir\n\n");
				
	}else{ // Se não
			

		// Exibe uma mensagem:
		printf("Pilha Atualmente:\n");
				
		// Exibe a pilha ate o seu topo:
		for(int i = 0; i <= Topo; i++){
					
			// Mostra o valor de 0 ao topo no console:
			printf("Valor: %c\n", MinhaPilha[i]);
					
		} // fim do for:
				
		// pula duas linhas:
		printf("\n\n");
				
	} // fim do if:
	
} // fim da função exibir:
