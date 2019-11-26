// Bibliotecas importadas
	#include <stdlib.h>
	#include <stdio.h>
// Fim bibliotecas importadas

// Declaração de estruturas
	typedef struct
	{
		char nome[50];
		int notas[2];
		float media;
		int situacao;
	}aluno;
// Fim declaração de estruturas

// Função principal
	int main()
	{
		aluno info[50];
		//info = malloc(1000*char);
		int qtd_alunos, i;
		float media;
		printf("Quantos alunos você deseja cadastrar?\n");
		scanf("%d", &qtd_alunos);
		printf("Entendido, cadastraremos %d alunos!\n", qtd_alunos);
		// Inicio laço para cadastro dos x alunos inseridos pelo usuário.
			for(i = 0; i < qtd_alunos; i++)
			{
				printf("Vamos cadastrar o aluno %d.\nQual o nome dele? Lembre-se de substituir os espacos por _.\n", i+1);
				scanf("%s", info[i].nome);
				int i2;
				for(i2 = 0; i2 < 2; i2++)
				{
					printf("Qual a N%d deste usuario?\n", i2+1);
					scanf("%d", &info[i].notas[i2]);
				}
				// Nesta parte, definimos a média do aluno e a salvamos.
				info[i].media = (info[i].notas[0] + info[i].notas[1])/2;
				if(info[i].media < 6)
					info[i].situacao = 5;
				else if(info[i].media >= 6)
					info[i].situacao = 10;
				// Fim da definição de média do aluno.
			}
		// Fim do laço para cadastro dos x alunos inseridos pelo usuário.

		// Começo do uso do arquivo para inserção dos dados nos documentos.
			FILE *panorama, *aprovados, *reprovados;
			//Abrindo arquivos
				panorama = fopen("Alunos.txt", "a");
				aprovados = fopen("aprovados.txt", "a");
				reprovados = fopen("reprovados.txt", "a");
			//Fim de Abrindo arquivos
			for(i = 0; i < qtd_alunos; i++) // Primeiro insiro apenas os usuários aprovados
			{
				if(info[i].situacao == 10)
				{
					
					fprintf(panorama, "\n-----\nNome:%s;\nN1:%d;\nN2:%d;\nMEDIA:%.2f;\nSITUACAO:APROVADO.\n-----\n", info[i].nome, info[i].notas[0], info[i].notas[1], info[i].media);
					fprintf(aprovados, "\n-----\nNome:%s;\nN1:%d;\nN2:%d;\nMEDIA:%.2f;\nSITUACAO:APROVADO.\n-----\n", info[i].nome, info[i].notas[0], info[i].notas[1], info[i].media);
				}
			}
			for(i = 0; i < qtd_alunos; i++) // Depois insiro apenas os usuários reprovados
			{
				if (info[i].situacao == 5)
				{
					fprintf(panorama, "\n-----\nNome:%s;\nN1:%d;\nN2:%d;\nMEDIA:%.2f;\nSITUACAO:REPROVADO.\n-----\n", info[i].nome, info[i].notas[0], info[i].notas[1], info[i].media);
					fprintf(reprovados, "\n-----\nNome:%s;\nN1:%d;\nN2:%d;\nMEDIA:%.2f;\nSITUACAO:REPROVADO.\n-----\n", info[i].nome, info[i].notas[0], info[i].notas[1], info[i].media);
				}
			}
			// Fechando arquivos usados
				fclose(panorama);
				fclose(aprovados);
				fclose(reprovados);
			// Fim de Fechando arquivos usados
		// Fim do uso do arquivo para inserção dos dados nos documentos.

		// Uso dos arquivos para mostrar alunos
			FILE *mostrar, *ap, *rp;
			// Abrindo Arquivos
				mostrar = fopen("Alunos.txt", "r");
				ap = fopen("aprovados.txt", "r");
				rp = fopen("reprovados.txt", "r");
			// Fim de Abrindo Arquivos

			char tudo[10000];
			char tudo2[10000];
			char tudo3[10000];

			printf("A seguir, todos os usuarios cadastrados.\n");
			while(!feof(mostrar))
			{
				fscanf(mostrar, "%s", tudo);
				printf("%s\n", tudo);
			}

			printf("\n\nTodos os alunos aprovados:\n");
			while(!feof(ap))
			{
				fscanf(ap, "%s", tudo2);
				printf("%s\n", tudo2);
			}

			printf("\n\nTodos os alunos reprovados:\n");
			while(!feof(rp))
			{
				fscanf(rp, "%s", tudo3);
				printf("%s\n", tudo3);
			}
			// Fechando Arquivos Usados
				fclose(mostrar);
				fclose(ap);
				fclose(rp);
			// Fim de Fechando Arquivos Usados
		// Fim dos arquivos para mostrar alunos
		return 0;	
	}
// Fim Função principal