/*	

	Name: ExplicandoFor.cpp
	Author: Miguel fernandes Santos 
	Date: 10/06/22 10:45
	Description: Explicando laço For
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gerais
# include <locale.h> //necessário para usar setlocale

// inicio do main:
int main(){
	
	
	// O for é um laço de repetição que precisa de 3 parametros, sendo eles:
	// 1 -> declaração da variavel usada no laço
	// 2 -> condição pro fim do laço
	// 3 -> Alteração de variaveis
	
	 
	// -----------------------------------------------------------------------//
	
	
	// Inicio de um laço for:
	for( int i = 0 ; i < 5; i++){
		
		// explicando o laço:
		
		// int i = 0 ||| Explicação: declarando uma variavel inteira com o nome I
		// Essa variavel se inicia com o valor 0
		
		// i < 5 ||| Explicação: Condição para o fim do laço, a leitura ficaria
		// Enquanto a variavel i ser menor que o numero 5.
		
		// i++ ||| Explicação: Incremento na variavel i, toda vez que o laço
		// se repete é adicionado mais 1 na variavel i
		
		// exibe a quantidade de vezes que o laço foi execultado:
		printf("Qts de vezes que rodou: %d\n", i + 1);
		
	} // fim do laço for
	
	
	// -----------------------------------------------------------------------//
	
	// OBS1: É possivel ter um laço dentro de outro laço
	
	// OBS2: caso a condição nao tenha uma logica para saida se tornara
	// um laço inifito
	
	// OBS3: A variavel declarada pode ser inicializada com qualquer valor.
	
	// OBS4: Não necessariamente precisa ocorrer incremento, as vezes pode
	// ocorrer um decremento.
	
	
} // fim do main
