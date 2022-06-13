/*	

	Name: ExplicandoSelectSort.cpp
	Author: Miguel fernandes Santos 
	Date: 13/06/22 10:43
	Description: Explicando select sort
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// Prototipações:
void Limpar(); // utilizada varias vezes
void Exibir(); // utilizada 2 vezes

// ------------------------------------------------------------------------//


// Variaveis globais:
int MeuArray[10]; // variavel que é a principal, afinal ela é o vetor


// ------------------------------------------------------------------------//


// inicio do main:
int main(){
	
	// declara variaveis que seram utilizadas:
	int Aux, Menor;
	
	// inicializa elas com 0:
	Menor = Aux = 0;
	
	// Inicia um laço para ler valores para a pilha:
	for(int i = 0; i < (sizeof(MeuArray) / sizeof(int)); i++){
		
		// mostra uma mensagem e le um valor:
		printf("Digite o %d numero a ser inserido: ", i + 1);
		scanf("%i", &MeuArray[i]);
		
		// Chama a função limpar:
		Limpar();
		
	} // fim do for
	
	// exibe uma mensagem e chama a função exibir:
	printf("Seu Array desordenado: \n");
	Exibir();
	
	/*
	
		O select sort é um algoritmo de ordenação que tem como objetivo
		selecionar um indice de um vetor como menor, e apos selecionar esse
		indice como menor ele percorre o resto do vetor verificando se existe
		um outro indice que possua dentro dele um valor menor que contido no 
		indice selecionado como menor.
	
	*/
	
	// Inicio do select Sort:
	for(int i = 0; i < (sizeof(MeuArray) / sizeof(int)); i++){
		
		// seleciona o indice i como menor:
		Menor = i;
		
		// inicia um segundo laço de repetição que percorre de i ate o final:
		for(int x = i; x < (sizeof(MeuArray) / sizeof(int)); x++){
			
			// verifica se o indice guardado na variavel menor
			// é maior que o indice da variavel X:
			if(MeuArray[Menor] > MeuArray[x]){
				
				// se for menor, menor recebe o valor de x:
				Menor = x;
				
			}// fim do if
			
		}// fim do segundo for:
		
		// verifica se i é diferente de menor:
		if(i != Menor){
			
			// se for menor faz a troca:
			Aux = MeuArray[i];
			MeuArray[i] = MeuArray[Menor];
			MeuArray[Menor] = Aux;
			
		}// fim do if:
		
	} // fim select sort
	
	// exibe uma mensagem e chama a função exibir:
	printf("\n\nSeu Array ordenado: \n");
	Exibir();
	
}// fim do main:


// ------------------------------------------------------------------------//


// Função para limpar buffer e a tela:
void Limpar(){
	
	// limpa o console:
	system("cls");
	
	// limpa o buffer:
	fflush(stdin);
	
} // fim da função


// ------------------------------------------------------------------------//


// a função para exibir o vetor:
void Exibir(){
	
	// inicio do laço para exibir:
	for(int i = 0; i < (sizeof(MeuArray) / sizeof(int)); i++){
		
		// mostra o valor do vetor:
		printf("|%d|", MeuArray[i]);	
		
	}// fim do for:
	
}// fim da função
