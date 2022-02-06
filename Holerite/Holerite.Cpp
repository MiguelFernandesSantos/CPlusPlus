# include <stdio.h>
# include <locale.h>
# include <string.h>

float CalcularINSS (float BaseINSS);
float CalcularIRRF (float BaseIRRF);

// estrutura para funcionarios:
struct {

	// Informaçoes do funcionario:
	float salario;
	int horaExtra;
	int dependentes;
	int insalubridade;
	int periculosidade;
	int valeTransporte;
	
	// informaçoes do mes trabalhado:
	int qtsHrsEx;
	int qtsFaltas;
	int qtsAtrasos;
	
} Funcionario;

// estrutura do holerite:
struct {
	
	float salarioDia;
	float salarioHora;
	float hrExtra;
	float dsrHrExtra;
	float valorInsalubridade;
	float valorPericulosidade;
	float falta;
	float dsrFalta;
	float valorVt;
	float atraso;
	float valorDependente;
	float BaseINSS;
	float INSS;
	float FGTS;
	float BaseIRRF;
	float IRRF;
	float SalarioLiquido;
	
} Holerite;

int main(){
	
	setlocale(LC_ALL, "Portuguese");	
	
	// informaçoes do funcionario:
	Funcionario.salario = 800.00;
	Funcionario.horaExtra = 50;
	Funcionario.dependentes = 0;
	Funcionario.insalubridade = 0;
	Funcionario.periculosidade = 0;
	Funcionario.valeTransporte = 6;
	
	// informaçoes do mes trabalhado:
	Funcionario.qtsHrsEx = 5;
	Funcionario.qtsFaltas = 2;
	Funcionario.qtsAtrasos = 2;
	
	// Salario Dia:
	Holerite.salarioDia = Funcionario.salario / 30;
	
	// Salario Hora:
	Holerite.salarioHora = Funcionario.salario / 220;
	
	// Valor Hora Extra:
	Holerite.hrExtra = (((Holerite.salarioHora / 100) * Funcionario.horaExtra) + Holerite.salarioHora) * Funcionario.qtsHrsEx;
	
	// DSR hora Extra:
	Holerite.dsrHrExtra = (Holerite.hrExtra / 26) * 4;
	
	// Insalubridade:
	Holerite.valorInsalubridade = (1200 / 100) * Funcionario.insalubridade;
	
	// Periculosidade:
	Holerite.valorPericulosidade = (Funcionario.salario / 100) *  Funcionario.periculosidade;
	
	// Vale Transporte:
	Holerite.valorVt = (Funcionario.salario / 100) *  Funcionario.valeTransporte;
	
	// Falta:
	Holerite.falta = Holerite.salarioDia * Funcionario.qtsFaltas;
	
	// DSR Falta:
	Holerite.dsrFalta = Holerite.salarioDia * Funcionario.qtsFaltas;
	
	// Atraso:
	Holerite.atraso = Holerite.salarioHora * Funcionario.qtsAtrasos;
	
	// Dependentes:
	Holerite.valorDependente = Funcionario.dependentes * 189.59;
	
	//Base INSS:
	Holerite.BaseINSS = Funcionario.salario + Holerite.valorInsalubridade + Holerite.valorPericulosidade + Holerite.hrExtra + Holerite.dsrHrExtra - Holerite.falta - Holerite.atraso - Holerite.dsrFalta;

	// Valor INSS:
	Holerite.INSS = CalcularINSS(Holerite.BaseINSS);
	
	// Valor FGTS:
	Holerite.FGTS = (Holerite.BaseINSS / 100) * 8;
	
	// Base IRRF:
	Holerite.BaseIRRF = Holerite.BaseINSS - Holerite.INSS - Holerite.valorDependente;
	
	// Valor IRRF:
	Holerite.IRRF = CalcularIRRF(Holerite.BaseIRRF);

	// Salario Liquido:
	Holerite.SalarioLiquido = Funcionario.salario + Holerite.hrExtra + Holerite.dsrHrExtra + Holerite.valorInsalubridade + Holerite.valorPericulosidade - Holerite.valorVt - Holerite.falta - Holerite.dsrFalta - Holerite.atraso - Holerite.INSS - Holerite.IRRF;
	
	printf("Salario Base: %2.f", Funcionario.salario);
	printf("\nHora Extra: %2.f", Holerite.hrExtra);
	printf("\nDSR Hora Extra: %2.f", Holerite.dsrHrExtra);
	printf("\nInsalubridade: %2.f", Holerite.valorInsalubridade);
	printf("\nPericulosidade: %2.f", Holerite.valorPericulosidade);
	printf("\nFalta: %2.f", Holerite.falta);
	printf("\nDsR Falta: %2.f", Holerite.dsrFalta);
	printf("\nAtraso: %2.f", Holerite.atraso);
	printf("\nVale Transporte: %2.f", Holerite.valorVt);
	printf("\nINSS: %2.f", Holerite.INSS);
	printf("\nFGTS: %2.f", Holerite.FGTS);
	printf("\nIRRF: %2.f", Holerite.IRRF);
	printf("\n\nSalario Liquido: %2.f", Holerite.SalarioLiquido);
	
	
}

// Função para calcular o INSS:
float CalcularINSS (float BaseINSS){
	
	float INSS;
	
	if(BaseINSS <= 1100.00){
		
		INSS = (BaseINSS / 100) * 7.5;
		
	}else if(BaseINSS >= 1100.01 && BaseINSS <= 2203.48){
		
		INSS = (BaseINSS / 100) * 9;
		INSS = INSS - 16.50;
		
	}else if (BaseINSS >= 2203.49 && BaseINSS <= 3305.22){
		
		INSS = (BaseINSS / 100) * 12;
		INSS = INSS - 82.60;
		
	}else if(BaseINSS >= 3305.23 && BaseINSS <= 6433.57){
		
		INSS = (BaseINSS / 100) * 14;
		INSS = INSS - 148.70;
		
	}else{
		
		INSS = 751.97;
		
	}
	
	return INSS;
	
}

// Função para calcular o IRRF:
float CalcularIRRF (float BaseIRRF){
	
	float IRRF;
	
	if(BaseIRRF <= 1903.98){
		
		IRRF = 0;
		
	}else if(BaseIRRF >= 1903.99 && BaseIRRF <= 2826.65){
		
		IRRF = (BaseIRRF / 100) * 7.5;
		IRRF = IRRF - 142.80;
		
	}else if (BaseIRRF >= 2826.66 && BaseIRRF <= 3751.05){
		
		IRRF = (BaseIRRF / 100) * 15;
		IRRF = IRRF - 354.80;
		
	}else if(BaseIRRF >= 3751.06 && BaseIRRF <= 4664.68){
		
		IRRF = (BaseIRRF / 100) * 22.50;
		IRRF = IRRF - 636.13;
		
	}else{
		
		IRRF = (BaseIRRF / 100) * 27.50;
		IRRF = IRRF - 869.36;	
		
	}
	
	return IRRF;
	
}
