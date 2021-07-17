// @autor: Felipe Ucelli
// @github: github.com/felipeucelli

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


#ifdef __unix__
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
    #define OS_Windows

#endif

void screen_wipe(){
    #ifdef OS_Windows
        system("cls");
    #else
        system("clear");
    #endif
}

int check_answer(char resposta[]){
    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S' || resposta[0] == 'N'){
        return 1;
    }else{
        screen_wipe();
        printf("\nOPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE!\n");
        return 0;
    }
}

int number_checker(char resposta[50], char msg_error[10]){
    int flag = 0;
    char alpha[26];
    alpha[0] = 'a';
    alpha[1] = 'b';
    alpha[2] = 'c';
    alpha[3] = 'd';
    alpha[4] = 'e';
    alpha[5] = 'f';
    alpha[6] = 'g';
    alpha[7] = 'h';
    alpha[8] = 'i';
    alpha[9] = 'j';
    alpha[10] = 'k';
    alpha[11] = 'l';
    alpha[12] = 'm';
    alpha[13] = 'n';
    alpha[14] = 'o';
    alpha[15] = 'p';
    alpha[16] = 'q';
    alpha[17] = 'r';
    alpha[18] = 's';
    alpha[19] = 't';
    alpha[20] = 'u';
    alpha[21] = 'v';
    alpha[22] = 'w';
    alpha[23] = 'x';
    alpha[24] = 'y';
    alpha[25] = 'z';

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 26; j++){
            if(resposta[i] == alpha[j]){
                flag = 1;
            }
        }
    }

    if(msg_error == 'cpf' && flag == 1){
        screen_wipe();
        printf("CPF INVALIDO, TENTE NOVAMENTE!\n");
    }else if(msg_error == 'idade' && flag == 1){
        screen_wipe();
        printf("IDADE INVALIDA, TENTE NOVAMENTE!\n");
    }
    return flag;
}

int main(){
    int flag_sexo = 1;
    int contador = 0;
    char resposta[10];
    char risco[1];

    struct ficha_pessoa{
        char nome[20];
        char cpf[20];
        char sexo[20];
        char idade[20];
    };

    struct ficha_pessoa pessoa;

    screen_wipe();

    printf("-----------------------------------");
    printf("\nBEM VINDO AO SISTEMA DE TRIAGEM!");
    printf("\n-----------------------------------");

    fflush(stdin);
    printf("\nDigite seu nome: ");
    fgets(pessoa.nome, 100, stdin);

    screen_wipe();
    do{
        printf("\nDigite seu CPF (APENAS NUMEROS): ");
        fgets(pessoa.cpf, 20, stdin);
        fflush(stdin);
    }while(number_checker(pessoa.cpf, 'cpf') == 1);

    screen_wipe();
    do{
        printf("\nDigite sua idade: ");
        fgets(pessoa.idade, 20, stdin);
        fflush(stdin);
    }while(number_checker(pessoa.idade, 'idade') == 1);

    screen_wipe();
    while (flag_sexo == 1){
        printf("\nDigite seu Sexo [M/F]: ");
        fgets(pessoa.sexo, 10, stdin);
        fflush(stdin);

        pessoa.sexo[0] = toupper(pessoa.sexo[0]);

        if(pessoa.sexo[0] == 'M' || pessoa.sexo[0] == 'F'){
            flag_sexo = 0;
        }else{
            screen_wipe();
            printf("OPCAO INVALIDA, POR FAVOR TENTE NOVAMENTE!\n");
        }
    }

    screen_wipe();
    for(int i = 5; i >= 0; i--){
        printf("\nCADASTRO REALIZADO COM SUCESSO!\n\n");
        printf("Continuando em %d", i);
        sleep(1);
        screen_wipe();
    }

    fflush(stdout);

    screen_wipe();
    do{
        printf("\nTem febre? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 5;
    }

    screen_wipe();
    do{
        printf("\nTem dor de cabeca? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 1;
    }

    screen_wipe();
    do{
        printf("\nTem secrecao nasal ou espirros? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 1;
    }

    screen_wipe();
    do{
        printf("\nTem dor/irritacao na garganta? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 1;
    }

    screen_wipe();
    do{
        printf("\nTem tosse seca? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 3;
    }

    screen_wipe();
    do{
        printf("\nTem dificuldade respiratoria? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 10;
    }

    screen_wipe();
    do{
        printf("\nTem dores no corpo? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 1;
    }

    screen_wipe();
    do{
        printf("\nTem diarreia? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 1;
    }

    screen_wipe();
    do{
        printf("\nEsteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 10;
    }

    screen_wipe();
    do{
        printf("\nEsteve em locais com grandes aglomeracao? [S/N]: ");
        fgets(resposta, 10, stdin);
        fflush(stdin);
    }while(check_answer(resposta) == 0);

    resposta[0] = toupper(resposta[0]);
    if(resposta[0] == 'S'){
        contador += 3;
    }


    printf("\n\n%d pontos", contador);
    if(contador <= 9){
        risco[0] = 'B';
        printf("\nPor favor, se encaminhe para a ala de BAIXO risco\n");
    }else if(contador <= 19){
        risco[0] = 'M';
        printf("\nPor favor, se encaminhe para a ala de MEDIO risco\n");
    }else{
        risco[0] = 'A';
        printf("\nPor favor, se encaminhe para a ala de ALTO risco\n");
    }

    FILE *registro;
	registro = fopen("dados.txt", "a");
	fprintf(registro, "\n\nPaciente: %s", pessoa.nome);
	fprintf(registro, "\nCPF: %s", pessoa.cpf);
	fprintf(registro, "\nIdade: %s", pessoa.idade);
	fprintf(registro, "\nSexo: %s", pessoa.sexo);

    if(contador <= 9){
        risco[0] = 'B';
        fprintf(registro, "\nRisco: BAIXO, ");
    }else if(contador <= 19){
        risco[0] = 'M';
        fprintf(registro, "\nRisco: MEDIO, ");
    }else{
        risco[0] = 'A';
        fprintf(registro, "\nRisco: ALTO, ");
    }
    fprintf(registro, "Pontos: %d", contador);

	fprintf(registro, "\n-----------------------------------");
    fprintf(registro, "\n-----------------------------------");

    fclose(registro);


    return 0;
}
