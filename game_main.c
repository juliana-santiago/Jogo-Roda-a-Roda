//JO�O VICTOR TEIXEIRA DE OLIVEIRA && JULIANA MACEDO SANTIAGO
//BIBLIOTECAS: 
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
//ESTRUTURA DOS JOGADORES:
struct jogador{
	char nome[64];
	float valor;
};typedef struct jogador Jogador;
//ESTRUTURA DAS PALAVRAS E PISTAS:
struct palavras {
	char pista[17];
	char vetpalavras[3][17];
	int qtd;
};typedef struct palavras Palavra;
//PROCEDIMENTOS E GAME MAIN:
void gravar_premios();
void gravar_dicas();
void roda_game (Jogador[], int);
void jogador_screen (Jogador[]);
//FUN��ES:
char verifica_letradigitada(char, char*, int, int);
int verifica_resp(char[3][17], char, int, int);
int game_final(char[3][17], char[3][17], int);	
int verifica_word(char[3][17], char[3][17], int, int);
//VARI�VEIS GLOBAIS:
float premios[12];
Palavra dicas[3];
FILE *arq;
FILE *arq2;
char arquivo2[]="palavras.dat";
char arquivo[]="premios.dat";

main(){
	int i;
	Jogador jog[3];
	char op, op2;

	setlocale(LC_ALL, "Portuguese");

do{
	reset:
	//MENU:
	system("cls");
	//APENAS PARA DEIXAR O JOGO MAIS BONITINHO:
	printf("\n   <--------------------------------------------------------------------->         "
		   "\n   |  __    __    __       _          _       __    __    __       _     |         "   
		   "\n   |  | \\  /  \\  |   \\    / \\        / \\      | \\  /  \\  |   \\    / \\    |"
		   "\n   |  |_/ /    \\ |    \\  /___\\  __  /___\\  __ |_/ /    \\ |    \\  /___\\   |  " 
		   "\n   |  | \\ \\    / |    / /     \\    /     \\    | \\ \\    / |    / /     \\  |  "
		   "\n   |  |  \\ \\__/  |__ / /       \\  /       \\   |  \\ \\__/  |__ / /       \\ |  "
		   "\n   <--------------------------------------------------------------------->         "
		   "\n       By:Jo�o Victor Teixeira de Oliveira && Juliana Macedo Santiago\n");
	printf("\n       <---------------->"
		   "\n       | Menu Principal |"
		   "\n       <---------------->");
	printf("\n       1 - Jogar\n       2 - Instru��es\n       3 - Cr�ditos\n       4 - Sair");
	op = getch ();
	system("cls");

	switch(op){
		case '1':
			//PEDINDO OS NOMES E COLOCANDO NAS VAR�AVEIS JOG
			for(i=0; i<3; i++){
				sleep(.25);
				printf("\n\n\tDigite o nome do jogador %d: ", i+1);
				fflush(stdin);
				gets(jog[i].nome);
			}			
			gravar_dicas();
			gravar_premios();
			roda_game(jog , i);
		break;

		case '2':	
	//INFORMA��ES IMPORTANTES:
	printf("\n\n\t\t\t\t<------------>"
		   "\n\t\t\t\t| Instru��es |"
		   "\n\t\t\t\t<------------>"
		   "\n\n\tEste jogo � uma simula��o em linguagem de programa��o C do game-show\n\t'Roda-a-Roda Jequiti', apresentado por S�lvio Santos."
		   "\n\n\t� necess�rio tr�s jogadores para jogar este modelo de Roda-A-Roda. O\n\tobjetivo dos jogadores ser� acertar as palavras da pista que for sor-\n\tteada."
		   "\n\n\tAo iniciar o jogo, dever� ser informado o nome dos tr�s jogadores, a or-\n\tdem dos nomes inseridos ser� seguida para iniciar a jogada. Ap�s isso,\n\tvoc� dever� aguardar por a sua vez de jogar. E quando for sua vez, voc�\n\tdever� digitar uma letra que voc� acha que existe na palavra da pista\n\tsorteada."
		   "\n\n\tSe a letra que voc� informou fa�a parte das palavras sorteadas, voc� pon-\n\ttuar� a quantia sorteada pela roleta. Caso contr�rio, a vez ser� passada\n\tpara o pr�ximo jogador. Mas cuidado: a roleta n�o possui apenas pr�mios!\n\tAs op��es 'Passe a Vez' e 'Perde Tudo' tamb�m est�o presentes na 'roda'\n\tdeste jogo!"
		   "\n\n\tOs pr�mios dispon�veis neste jogo v�o de R$100,00 a R$1000,00. Onde s�o\n\tvariados de R$100,00 em R$100,00. "
		   "\n\n\tAo final do jogo, quando um dos jogadores acertar todas as palavras, ele\n\tser� declarado como vencedor! Entretanto, isto � apenas um jogo para a di-\n\tvers�o de todos, portanto n�o h� dinheiro real envolvido nesta simula��o."
		   "\n\n\tAgora que voc�s leram todas as instru��es presentes neste jogo, desejo-lhes\n\tque a sorte esteja sempre ao seu favor!"
		   "\n\n\tVolte ao menu principal e divirta-se com os seus amigos!"
		   "\n\n\n----------------------------------------------------------------------------------------\n"
		   "\t-> Pressione qualquer tecla para voltar...\n");
		   fflush(stdin);
		   scanf("%c", &op2);
		break;

		case '3':
	//CR�DITOS AOS DESENVOLVEDORES DESTE RODA-A-RODA:	   
	printf("\n\n\t\t\t\t<---------->"
		   "\n\t\t\t\t| Cr�ditos |"
		   "\n\t\t\t\t<---------->"
		   "\n\n\tIFSP - An�lise e Desenvolvimento de Sistemas - 1� Semestre."
		   "\n\n\tProjeto Did�tico - Linguagem de Programa��o - C"
		   "\n\n\tMat�ria: L�gica de Programa��o I.	 "
		   "\n\n\tProfessora: Josceli Maria Tenorio."
		   "\n\n\n\n\tPrograma desenvolvido por:"
		   "\n\n\tJo�o Victor Teixeira de Oliveira - SP3030644\n\n\tJuliana Macedo Santiago - SP3032337"
	   	   "\n\n\tObrigado por experimentar este modelo de 'RODA-A-RODA!'"
	   	   "\n\n\n----------------------------------------------------------------------------------------\n"
		   "\t-> Pressione qualquer tecla para voltar...\n");
		   	fflush(stdin);
			scanf("%c", &op2);
		break;

		case '4':
	printf("\n\n\t\t\t\t<-------------->"
	       "\n\t\t\t\t| Fim de jogo! |"
		   "\n\t\t\t\t<-------------->\n\n");
			exit(1);
		break;
}
}while(op != '1');
system ("pause");
}
//JOGO BASE:
void roda_game (Jogador jog[], int j)
{
	char palavra[3][17], *pista, resposta, linhas[3][17], respf[3][17], confrep[100];
	int i=0, cont=0, k=0, c=0, h, rprem, rpista, rpalavra;
//SEED:
	srand(time(NULL));
//SORTEANDO O N�MERO PARA A DICA E PALAVRA:
	rpista = rand() % 3;
//ARMAZENANDO A DICA E A PALAVRA:
	system("cls");
	arq2 = fopen(arquivo2, "r");
	fread(&dicas, sizeof(dicas), 1, arq);
	pista = dicas[rpista].pista;
	for(h=0; h<3; h++){
		strcpy(palavra[h], dicas[rpista].vetpalavras[h]);
	}
//FECHANDO ARQUIVO DAS PALAVRAS:
	fclose(arq2);
for(h=0; h<3; h++){
	for(j=0; j<strlen(palavra[h]); j++){
		linhas[h][j]='_';
		cont++;
		}
	}
//INSERINDO AS AS LINHAS:
//ZERANDO OS ACUMULADORES DE VALOR DOS JOGADORES:
	jog[0].valor=0; jog[1].valor=0; jog[2].valor=0;
//REPETI��O:
do{	
	//INICIANDO A RODADA:
		system("cls");
		//PRINTANDO A DICA:
		printf("\n\t\t\t\t\tA palavra est� associada com: %s\n\n\n", pista);
		printf("\t\t\t\t\t\t ");
		//PRINTANDO A PALAVRA:
		for(h=0; h<3; h++){	
			for(j=0;j<strlen(linhas[h]);j++){
		    printf("%c  ",linhas[h][j]);   
		}
		printf("\n");
		printf("\t\t\t\t\t\t ");  
	}
		printf("\n\n\n");
		//VEZ DOS JOGADORES:
		//PRINTANDO OS JOGADORES:
			jogador_screen (jog);
			//ABRINDO ARQUIVO PARA ARMAZENAR OS DADOS NO VETOR PREMIOS:
				arq = fopen(arquivo, "r");
				fread(&premios, sizeof(premios), 1, arq);
					//N�MERO SORTEADO:
						rprem = rand() % 12;
						if(rprem == 4){
								printf("\n\t\t\tPASSA A VEZ!\n");
								i++;
								if(verifica_word(palavra, linhas, j, h) != 0)
									k++;
								else if(k==3)
									goto pointk;
								goto fim;	
							}
						else if (rprem == 8){
								printf("\n\t\t\tPERDEU TUDO!\n");
								jog[i].valor = 0;
								i++;
								if(verifica_word(palavra, linhas, j, h) != 0)
									k++;
								else if(k==3)
									goto pointk;
								goto fim;
								}
						//VERIFICANDO SE FALTAM 3 LETRAS OU MENOS PARA SEREM CHUTADAS:
						else if	(verifica_word(palavra, linhas, j, h) != 0){
								 if(k==3)
									goto pointk;
								sleep(1);
								printf("\n\t\t\tRoda a Roda!\n");
								printf("\n\t\t\tJogador %s, faltam %d letras para completar as palavras!", jog[i].nome, verifica_word(palavra, linhas, j, cont));
								sleep(1);
								printf("\n\t\t\tVoc� tem 5 segundos para para pensar e depois digitar as palavras");
							
								for(j=0; j<=5; j++){
									printf("...%d", j);
									sleep(1);
								}
									printf("\n\t\t\tValendo R$ %0.2f, as palavras s�o: ", premios[rprem]+jog[i].valor);
								fflush(stdin);
								
							for(h=0; h<3; h++){
								gets(respf[h]);
								strupr(respf[h]); //COLOCA OS CARACTERES DA VARI�VEL "RESPF" EM MAI�SCULO (S� FUNCIONA COM STRING)
								printf("\t\t\t\t\t\t\t     ");
							}
								k++;
								//FIM DE JOGO ONDE � ANUNCIADO O VENCEDOR:
								 if (game_final(respf, palavra, h) == 0){
								 		jog[i].valor=(jog[i].valor*2)+premios[rprem];
										system("cls");
										sleep(1);
										printf("\n\t\t\t\t\tAS PALAVRAS S�O: %s, %s, %s\n\n\n", respf[0], respf[1], respf[2]);
										jogador_screen (jog);
										if(i==0){
											printf("\n\t\t\tVENCEDOR!\n\n");
											sleep(2);
											goto end;
										}
										else if(i==1){
											printf("\n\t\t\t\t\t\t       VENCEDOR!\n\n");
											sleep(2);
											goto end;
										}
										else{
											printf("\n\t\t\t\t\t\t\t\t\t\t  VENCEDOR!\n\n");
											sleep(2);
											goto end;
										}
								}
							//CASO NENHUM DOS 3 JOGADORES TENHA ACERTADO AS PALAVRAS:
							else if(k==3){
										pointk:
											for(h=0; h<3; h++){
												strcpy(respf[h], palavra[h]);
											}
										strcpy(respf[1], palavra[1]);
										strcpy(respf[2], palavra[2]);
										system("cls");
										sleep(1);
										printf("\n\t\t\t\t\tAS PALAVRAS S�O: %s, %s, %s\n\n\n", respf[0], respf[1], respf[2]);
										jogador_screen (jog);
										printf("\n\t\t\t\t\t\tN�O HOUVE VENCEDOR!\n\n");
										sleep(2);
										goto end;	
									}
							}
							else{
								printf("\n\t\t\tUma letra por R$ %0.2f: ", premios[rprem]);
								fflush(stdin);
								scanf("%c", &resposta);
								resposta = toupper(resposta); //COLOCA O CARACTER DA VARI�VEL RESPOSTA EM MA�SCULO (ESSE � S� PRA UM CARACTER)
							//VERIFICANDO SE A LETRA J� FOI DIGITADA
							if(verifica_letradigitada(resposta, confrep, j, c) == resposta){
								i++;
								sleep(1);
								printf("\n\t\t\tA letra %c j� foi digitada\n", resposta);
								sleep(1);
								goto fim;
							}	
							//VEIRIFICANDO SE ERROU A LETRA:
							else if(verifica_resp(palavra, resposta, j, h) == cont){
										i++;
										sleep(1);
										printf("\n\t\t\tN�o existe letra %c na palavra\n", resposta);
										sleep(1);
										goto fim;		
								}
							else{
									sleep(1);
									printf("\n\t\t\tVoc� acertou!\n");
									sleep(1);		
				//ANALISANDO A RESPOSTA, PREENCHENDO O VETOR AUX E DISTRIBUINDO O MONEY:
				for(h=0; h<3; h++){
					for(j=0; j<strlen(palavra[h]); j++){
						if (resposta==palavra[h][j]){
							jog[i].valor+= premios[rprem];
							linhas[h][j]=palavra[h][j];
						} 
					}
				}
				}
			}
i++;
fim:
confrep[c]=resposta; //ARMAZENANDO LETRAS J� DIGITADAS
c++;
if(i==3)
		i=0;
printf("\n\t\t\tA vez ser� passada para o jogador: %s", jog[i].nome);
sleep(1.5);
fclose(arq);
end:
sleep(1);
	}while(game_final(respf, palavra, h) != 0);
}
//GRAVA PR�MIOS NO ARQUIVO:
void gravar_premios(){
	
	arq = fopen(arquivo, "w");
	
	premios[0]=100;
	premios[1]=900;	
	premios[2]=600;
	premios[3]=1000;
	premios[4]=0.00;
	premios[5]=400;
	premios[6]=200;
	premios[7]=800;
	premios[8]=0.01;
	premios[9]=300;
	premios[10]=500;
	premios[11]=700;

	fwrite(&premios, sizeof(premios), 1, arq);

	fclose(arq);
	}
//GRAVA AS PALAVRAS E DICAS NO ARQUIVO:
void gravar_dicas(){
	
	arq2 = fopen(arquivo2, "w");

	strcpy(dicas[0].pista, "Vegetal");
	dicas[0].qtd= 2;
	strcpy(dicas[1].pista, "Autom�vel");
	dicas[1].qtd=3;
	strcpy(dicas[2].pista, "R�ptil");
	dicas[2].qtd=1;

 	strcpy(dicas[0].vetpalavras[0], "REPOLHO"); 
 	strcpy(dicas[0].vetpalavras[1], "ALFACE");
	strcpy(dicas[0].vetpalavras[2], "COUVE");
	strcpy(dicas[1].vetpalavras[0], "VOLANTE");	
	strcpy(dicas[1].vetpalavras[1], "MOTOR");
	strcpy(dicas[1].vetpalavras[2], "PNEU");
	strcpy(dicas[2].vetpalavras[0], "JACARE");
	strcpy(dicas[2].vetpalavras[1], "JABUTI");
	strcpy(dicas[2].vetpalavras[2], "COBRA");

	fwrite(&dicas, sizeof(dicas), 1, arq);

	fclose(arq2);
}
//IMPRIME OS DADOS DOS JOGADORES:
void jogador_screen (Jogador jog[]){
	printf("\n\t\t        Jogador: %s\t\t      Jogador: %s\t\t Jogador: %s\n\t\t\t==========\t\t      ==========\t\t ==========\n\t\t\tR$ %0.2f \t\t      R$ %0.2f   \t\t R$ %0.2f\n\n", jog[0].nome, jog[1].nome, jog[2].nome, jog[0].valor, jog[1].valor, jog[2].valor);
}
//VERIFICA SE A LETRA J� FOI DIGITADA
char verifica_letradigitada(char resposta, char *confrep, int j, int c){
	for(j=0; j<c; j++){
		if(resposta==confrep[j])
			return confrep[j];
	}
}
//VERIFICA SE A RESPOSTA FOI ERRADA:
int verifica_resp(char palavra[3][17], char resposta, int j, int h){
	int erro = 0;

	for(h=0; h<3; h++){
		for(j=0; j<strlen(palavra[h]); j++){
			if (resposta != palavra[h][j]){
				erro++;
			}
		}
	}
return erro;
}
//FUN��O QUE VERIFICA SE A PALAVRA EST� COM 3 LETRAS OU MENOS:
int verifica_word(char palavra[3][17], char linhas[3][17], int j, int h){
		int word = 0;
	
	for(h=0; h<3; h++){
		for(j=0; j<strlen(palavra[h]); j++){
			if (palavra[h][j] != linhas[h][j])
				word++;
		}
	}
	if(word <= 3)
		return word;
	else
		return 0;
}
//FUN��O QUE VERIFICA SE O GAME ACABOU:
int game_final(char respf[3][17], char palavra[3][17], int h){

	int contaux = 0;
//STRCMP PARA COMPARAR AS STRINGS:	
for(h=0; h<3; h++){
	if(strcmp(palavra[h], respf[h]) == 0)
		contaux++;
}
		if(contaux==3)
			return 0;
		else
			return 1;
}
