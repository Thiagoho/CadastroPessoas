#include <stdio.h>
//#include <string.h>

#define BUFFER 200
//promeira passo
char nome[BUFFER] [50];
char email[BUFFER] [50];
int cpf[BUFFER];
int op;

void cadastro();

void pesquisa();
void lista(); //Essa função vai registra todos os nossos cadastros.


int main(void){
//Parte Fianl
    do{
        printf("\t MENU \n1 - Cadasdtrar\n2 - Lista tdodos\n3 - Pesquisar\n4 - Sair");
        scanf("%d", &op);
        switch (op) {
        case 1:
            cadastro();
            break;
        case 2: 
            lista();
            break;
        case 3: 
            pesquisa();
            break;
        case 4:
            system("exit");
            break;
        
        default:
            printf("Opcao Invalida!");
            getchar();
            getchar();
            break;
        }
        
    } while (op != 4);
        return 0;
    }
//terceiro passo.
void lista() {
    int i;
    for(i = 0; i <BUFFER && cpf[i] > 0; i++){
            printf("\nNOME: %s \nEmail: %s \nCPF: %d", nome[i], email[i], cpf[i]);
       
    }
}

//primeiro passo.
void cadastro() {
    static int linha;

    do {
        printf("\nInsire o nome: ");
        scanf("%s", &nome[linha]);

        printf("\nInsire o e-mail: ");
        scanf("%s", &email[linha]);

        printf("\nInsire o cpf: ");
        scanf("%d", &cpf[linha]);

        
    printf("\nInsire 1 para continuar ou 0 para sair: ");
    scanf("%d", &op);
    linha++; 

    }while(op == 1);
}
//Função de cadastro.

//segundo passo.
void pesquisa() {//Essa função vai pesquisa 2 função CPF E E-MAIL.
    int cpfPesquisa;
    char emailPesquisa[50];
    int i;
    int cpfErrado = 0;
    char emailErrado = 0;
    do {
        printf("\nDigte 1 para pesquisar por CPF ou 2 para pesquisar por E-mail: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("\nDigite o CPF: ");
                scanf("%d", &cpfPesquisa);

                for(i = 0; i < BUFFER; i++){
                    if(cpf[i] == cpfPesquisa) {
                        printf("\nNOME: %s \nE-MAIL: %s \nCPF: %d", nome[i], email[i], cpf[i]);
                        cpfErrado = 1;
                        break;
                    }if (!cpfErrado) {
                        printf("\nCPF INValido!");
                    }
                    
                }

            break;

            case 2:
                printf("\nDigite o Email: ");
                scanf("%s", emailPesquisa);

                for(i = 0; i< BUFFER; i++) {
                    if(strcmp(email[i], emailPesquisa)== 0) { //Adicionei ==0 será o return da função strcmp.
                        printf("\nNOME: %s \nE-MAIL: %s \nCPF: %d", nome[i], email[i], cpf[i]);
                        emailErrado = 1;
                    }if (!emailErrado) {
                        printf("\nEMAIL Invalido!");
                        break;
                    }
                    
                }
                break;
            default: 
                printf("\nOpcao Inválida!");
                break;
        }
        printf("\nInsire 1 para continuar pesquisar: ");
        scanf("%d", &op);
    }while(op == 1);

}


