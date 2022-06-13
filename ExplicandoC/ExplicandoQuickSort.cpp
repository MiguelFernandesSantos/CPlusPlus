/*	

	Name: ExplicandoQuickSort.cpp
	Author: Miguel fernandes Santos 
	Date: 11/06/22 13:37
	Description: Explicando Quick Sort
	
*/

// Includes:
# include <stdio.h> // biblioteca basica do C
# include <string.h> // biblioteca para utilizar função para vetor de char
# include <stdlib.h>  // biblioteca de funções gesrais
# include <locale.h> //necessário para usar setlocale


// ------------------------------------------------------------------------//


// Prototipações:
void Limpar(); // função limpar
void QuickSort(int *, int, int); // função recursiva para ordenar
int Particionar(int *, int, int); // Função para particionar o vetor
void Exibir(int *, int); // Função para exibir o vetor

// ------------------------------------------------------------------------//


// inicio do main:
int main(){
	
	// declaração de um vetor de inteiros:
	int Numeros[20];
	
	for(int i = 0; i < (sizeof(Numeros) / sizeof(int)); i++){
		
		// adiciona 20 numeros aleatorios no vetor
		Numeros[i] = rand() % 100;
		
	} // fim do for:
	
	printf("\n\n");
	// exibe o vetor desordenado:
	printf("Numeros desordenados: \n");
	Exibir(Numeros, (sizeof(Numeros) / sizeof(int)));
	
	QuickSort(Numeros, 0, (sizeof(Numeros) / sizeof(int)) - 1);
	
	// exibe o vetor ordenado:
	printf("\n\nNumeros ordenados: \n");
	Exibir(Numeros, (sizeof(Numeros) / sizeof(int)));
	
	
} // fim do main


// ------------------------------------------------------------------------//


// função para limpar o console e o buffer do teclado:
void Limpar(){
	
	// limpar o console e o buffer:
	system("cls");
	fflush(stdin);
	
} // fim da função limpar


// ------------------------------------------------------------------------//


// a função para exibir o vetor:
void Exibir(int *MeuArray, int tam){
	
	// inicio do laço para exibir:
	for(int i = 0; i < tam; i++){
		
		// mostra o valor do vetor:
		printf("|%d|", MeuArray[i]);	
		
	}// fim do for:
	
}// fim da função


// ------------------------------------------------------------------------//

/*

	Quick sort é uma função que recebe 3 parametros sendo eles:
	1 - Um ponteiro de inteiros.
	2 - um inteiro que vai receber onde começa o vetor
	3 - um inteiro que vai receber onde termina o vetor

	   Essa função tem como objetivo chamar ela mesmo para fazer uma ordenação,
	para isso é declarado uma variavel do tipo inteiro denominada de PIVO
	onde essa variavel recebe o retorno da função particionar.
	   A função QuickSort chama ela mesmo para o lado esquerdo e
	para o lado direito do vetor, assim fazendo de forma recursiva
	a ordenação de ambos os lados.

*/

// função recursiva para ordenar o lado direito e esquerdo do vetor:
void QuickSort(int *Vetor, int inicio, int fim){
	
	//printf("QUICK: INICIO: %d || FIM: %d\n", inicio, fim);
	
	// declara uma variavel para?
	int Pivo;
	
	// verifica se o fim é maior que o inicio
	if(fim > inicio){
		
		// pivo recebe o retorno do particionar:
		Pivo = Particionar(Vetor, inicio, fim);
		
		// Chama o QuickSort para o lado esquerdo:
		QuickSort(Vetor, inicio, Pivo - 1);
		
		// Chama o QuickSort para o lado direito:
		QuickSort(Vetor, Pivo + 1, fim);
		
	}// fim do if:
	
} // fim do quick sort:


// ------------------------------------------------------------------------//

/*

	Particionar é uma função que recebe 3 parametros sendo eles:
	1 - Um ponteiro de inteiros.
	2 - um inteiro que vai receber onde começa o vetor
	3 - um inteiro que vai receber onde termina o vetor
	
	  A função particionar tem como objetivo organizar o vetor, para isso
	é realizo a declaração de variaveis chamadas de Esquerda, Direita, 
	e Pivo.
	  
	  A variavel Pivo tem como objetivo receber um valor do array,
	Esse valor vai ser tomado como o "menor" valor do array.
	  
	  ja variavel esquerda tem como objetivo receber o valor contido na 
	variavel inicio, apos fazer isso é realizado um laço que utiliza da
	variavel esquerda para encontrar um valor menor ou igual ao pivo.
	  Exemplo: Vetor[Esquerda] <- assim que a variavel esquerda é
	usada dentro do laço de repetição.
	  Toda essa interação é feita para encontrar um valor menor ou igual
	ao pivo.
	
	  ja variavel Direita tem como objetivo receber o valor contido na 
	variavel fim, apos fazer isso é realizado um laço que utiliza da
	variavel direita para encontrar um valor maior ou igual o pivo.
	  Exemplo: Vetor[Direita] <- assim que a variavel Direita é
	usada dentro do laço de repetição.
	  Toda essa interação é feita para encontar um valor maior que o pivo
	
	  Quando é encontrado um valor menor que o pivo e outro maior que o pivo
	é realizado a verificação se a variavel esquerda é maior que a variavel
	direita, caso seja ele troca os valores contidos nos indices esquerda e 
	direita.
	
	  Apos isso ele sai do laço principal e no indice inicio é adicionado
	o valor contido no indice direito do vetor, ja o indice direita recebe
	o valor do pivo e por fim é retornado o valor da direita.
	
	
*/

// Função para quebrar o vetor em 2:
int Particionar(int *Vetor, int inicio, int fim){
	
	// declara a variavel esquerda que recebe inicio:
	int Esquerda = inicio;
	
	// declara a variavel Direita que recebe Fim:
	int Direita = fim;
	
	// declara a variavel Pivo que recebe o valor do vetor do indice inicio:
	int Pivo = Vetor[inicio];
	
	// declara a variavel aux que recebe 0:
	int Aux = 0;
	
	// Execulta o laço ate a esquerda ser maior que a direita:
	while(Esquerda < Direita){
		
		// Continua o laço ate encontra um valor maior que o pivo:
		while(Vetor[Esquerda] <= Pivo && Esquerda <= fim){
			
			// Aumenta o valor de esquerda em 1:
			Esquerda++;
			
		} // fim do while
		
		// Continua o laço ate encontra um valor menor que o pivo:
		while(Vetor[Direita] > Pivo){
			
			// Diminui o valor da direita em 1:
			Direita--;
			
		} // fim do while
		
		// verifica se esquerda é menor que direita:
		if(Esquerda < Direita){
			
			// Faz a troca de valores:
			Aux = Vetor[Esquerda];
			Vetor[Esquerda] = Vetor[Direita];
			Vetor[Direita] = Aux;
			
		}// fim do if:
		
	} // fim do while principal:
	
	// o indice contido na variavel inicio recebe o valor contido no indice direita
	Vetor[inicio] = Vetor[Direita];
	
	// o valor contido no incide da direita recebe o pivo:
	Vetor[Direita] = Pivo;
	
	// return direita:
	return Direita;
	
}
