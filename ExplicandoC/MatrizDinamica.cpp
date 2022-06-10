/*
	Name: MatrizDinamica.cpp
	Author: Miguel fernandes Santos 
	Date: 10/06/22 10:06
	Description: Explicando matriz dinamica
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gerais
# include <locale.h> //necessário para usar setlocale

// ponteiro de Matriz de char:
char **CharArray;

// Obs: Essa variavel é do tipo ponteiro e ela serve para criar
// Matrizes dinamicas, por possuir ** significa que ela é um
// ponteiro de ponteiros.
// Utilizando do malloc é possivel iniciar a qts de ponteiros
// de ponteiros dentro da variavel, veja a baixo:

int main(){
	
	// Inicialização das linha da matriz:
	CharArray = (char **) malloc(4 * sizeof(char *));
	
	// OBS: o codigo acima tem o cast para retornar um ponteiro
	// de ponteiro, mas o mais interessante é que ele libera
	// espaço na memoria para 4 ponteiros.
	
	// Abaixo segue o formato do nosso array no momento:
	
	// EXEMPLO:
	
	// | 0 |
	// | 1 |     <- Essas partes são basicamente as linhas da matriz
	// | 2 |
	// | 3 |
	
	// Fim Exemplo
	
	
	// -------------------------------------------------------------//
	
	
	// laço para criar as colunas da matriz:
	for(int i = 0; i < 4; i++){
		
		// inicialização da coluna do array:
		CharArray[i] = (char *) malloc(2 * sizeof(char));		
		
		// OBS: o codigo acima tem o cast para retornar um ponteiro
		// de char, mas o mais interessante é que ele libera
		// espaço na memoria para 2 char para cada linha.
		
	}
	
	// Abaixo segue o formato do nosso array no momento:
	
	// EXEMPLO:
	
	//       |  0  |  1  | <- Colunas do array: 
	// | 0 | | 0/0 | 0/1 |
	// | 1 | | 1/0 | 1/1 |    <- Valores com linha e coluna:
	// | 2 | | 2/0 | 2/1 |
	// | 3 | | 3/0 | 3/1 |
	
	// Fim Exemplo


	// -------------------------------------------------------------//
	
	
	// adiciona valores no array:
	for(int i = 0; i < 4; i++){
		
		// mostra mensagem, le um valor e limpa a tela:
		printf("\n\nDigite uma frase: ");
		gets(CharArray[i]);
		system("cls");
		
	}
	
	// laço para exibir o array:
	for(int i = 0; i < 4; i++){
		
		// exibe o array:
		printf("\nfrase: %s", CharArray[i]);
		
	}
	
}
