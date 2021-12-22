# include <stdio.h>
# include <string.h>
#include <time.h>


void escreveArquivo (FILE *file){
		
	system("cls");
	char nome [256];
	printf("Digite o Nome do paciente: ");
	scanf("%s", &nome);
	system("cls");
	int idade;
	printf("Digite a idade do paciente: ");
	scanf("%i", &idade); 
	system("cls");
	char cpf [12];
	printf("Digite o cpf do paciente: ");
	scanf("%s", &cpf);
	system("cls");
	char idadestr [3];
	itoa(idade, idadestr, 10);
	fputs(nome, file) ;
	fputs(";", file) ;
	fputs(idadestr, file) ;
	fputs(";", file) ;
	fputs(cpf, file) ;
	fputs("\n", file) ;
	printf("Dados cadastrados com sucesso.\nDeseja cadastrar Novo paciente?\n1 - Sim\n2 - Nao\nEscolha: ");
}

void menuFinal(FILE *file){
		int op;
		scanf("%d", &op);
		switch(op){
			case 1:
				system("cls");
				escreveArquivo(file);
				menuFinal(file);
				break;
			case 2:
				system("cls");
				printf("Programa Finalizado. Aperte Enter");
				break;
			default:
				system("cls");
				printf("Opcao invalida tente novamente.\n");
				printf("Deseja cadastrar Novo paciente?\n1 - Sim\n2 - Nao\nEscolha: ");
				menuFinal(file);
				break;
				
		}
}
		
int main( ){	
	// pega a data e cria o nome do arquivo
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char day [3]; 
	itoa(tm.tm_mday, day, 10);
	char month [3]; 
	itoa(tm.tm_mon + 1, month, 10);
	char year [5]; 
	itoa(tm.tm_year + 1900, year, 10);
	char fileName [15]  = {day[0],day[1],'_',month[0],month[1],'_',year[0],year[1],year[2],year[3],'.','t','x','t'};
	
	// Declara o ponteiro do arquivo
	FILE *filePointer ;
	// abre ou cria o arquivo com o nome criado
	filePointer = fopen(fileName, "r") ;
	
	// Verifica se o arquivo existe ou pode ser aberto
	if ( filePointer == NULL ) {
		fclose(filePointer);
		filePointer = fopen(fileName, "a") ;
		fputs("Nome;Idade;CPF\n", filePointer) ;
	}
	else {
		fclose(filePointer);
		filePointer = fopen(fileName, "a") ;
		escreveArquivo(filePointer);
		menuFinal(filePointer);
	}
	fclose(filePointer) ;
	return 0;       
}
