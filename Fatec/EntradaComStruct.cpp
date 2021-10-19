# include <stdio.h>
# include <locale.h>
# include <string.h>

#define index 2

struct {
	
	char nome[51], sangue[4];
	float peso, altura;
	int idade;
	
}registros[index];

main(){
	
	float media = 0;
	int i = 0;
	int MaiorIdade = -1, MenorIdade = -1, MaiorPeso = -1, MenorPeso = -1, MaiorAltura = -1, MenorAltura = -1;
	
	setlocale(LC_ALL, "Portuguese");

	while( i < index){

		printf("\n\n---------- Pessoa %d ----------\n\n", (i + 1));
		
		// Entrada dos nomes:
		printf("Entre com seu nome: ");
		fgets(registros[i].nome, 51, stdin);
		registros[i].nome[strlen(registros[i].nome) - 1] = '\0';
		fflush(stdin);
		
		// Entrada das idades:
		printf("\nEntre com sua idade: ");
		scanf("%d", &registros[i].idade);
		fflush(stdin);
		
		// Entrada das alturas:
		printf("\nEntre com sua altura: ");
		scanf("%f", &registros[i].altura);
		fflush(stdin);
		
		// Entradas dos pesos:
		printf("\nEntre com seu peso: ");
		scanf("%f", &registros[i].peso);
		fflush(stdin);
		
		// Entradas dos tipos de sangue:
		printf("\nEntre com seu tipo de sangue:");
		fgets(registros[i].sangue, 4 ,stdin);
		registros[i].sangue[strlen(registros[i].sangue) - 1] = '\0';
		fflush(stdin);
		
		// Guarda a soma das idades:
		media = media + registros[i].idade;
		
		if (MenorIdade == -1 && MenorPeso == -1 && MenorAltura == -1 && MaiorIdade == -1 && MaiorPeso == -1 && MaiorAltura == -1){
			
			MenorIdade = i;
			MenorPeso = i;
			MenorAltura = i;
			MaiorIdade = i;
			MaiorPeso = i;
			MaiorAltura = i;
			
		}
		
		// Idade: Se for menor
		if (registros[MaiorIdade].idade < registros[i].idade){
			
			MaiorIdade = i;
			
		}
		
		// Idade: Se for maior
		if (registros[MenorIdade].idade > registros[i].idade){
			
			MenorIdade = i;
			
		}
		
		// Peso: Se for menor
		if (registros[MaiorPeso].peso < registros[i].peso){
			
			MaiorPeso = i;
			
		}
		
		// Peso: se for maior
		if (registros[MenorPeso].peso > registros[i].peso){
			
			MenorPeso = i;
			
		}
		
		// Altura: se for menor
		if (registros[MaiorAltura].altura < registros[i].altura){
			
			MaiorAltura = i;
			
		}
		
		// Altura: se for maior
		if (registros[MenorAltura].altura > registros[i].altura){
			
			MenorAltura = i;
			
		}
		
		i++;
		
	}
	
	printf("Mais velho: %s     |    Idade: %d \n\n", registros[MaiorIdade].nome, registros[MaiorIdade].idade);
	printf("Mais Novo: %s      |    Idade: %d \n\n", registros[MenorIdade].nome, registros[MenorIdade].idade);
	printf("Maior Peso: %s     |    Peso: %.2f \n\n", registros[MaiorPeso].nome, registros[MaiorPeso].peso);
	printf("Menor Peso: %s     |    Peso: %.2f \n\n", registros[MenorPeso].nome, registros[MenorPeso].peso);
	printf("Mais Alto: %s      |    Altura: %.2f \n\n", registros[MaiorAltura].nome, registros[MaiorAltura].altura);
	printf("Mais Baixo: %s     |    Altura: %.2f \n\n", registros[MenorAltura].nome, registros[MenorAltura].altura);
	
	// Calcula a media:
	media = (float) media / index;
	
	printf("Media de todas as idades: %.2f", media);
	
}
