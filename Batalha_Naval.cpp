#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Escopo das funções
void menuInicial();
void jogo(string nome);

void limpaTela(){
    system("cls");
}

void exibeMapa(){
    for(int j = 0;j < 10;j++){
        if(j == 0){
            cout << "    ";
        }
        cout << j << " ";
    }
    cout << endl;
    for(int j = 0;j < 10;j++){
        if(j == 0){
            cout << "    ";
        }
        cout << "| ";
    }
    cout << endl;
}

void exibeTabuleiro(char tabuleiro[10][10],char mascara[10][10],bool mostraGabarito){

    char blue[] = {0x1b,'[','1',';','3','4','m',0};
    char red[] = {0x1b,'[','1',';','3','1','m',0};
    char normal[] = {0x1b,'[','1',';','3','9','m',0};

    for(int i = 0;i < 10;i++){
        cout << i << " - ";
        for(int j = 0;j < 10;j++){
            switch(mascara[i][j]){
                case 'A':
                    cout << blue << mascara[i][j] << " " << normal;
                    break;

                case 'L':
                    cout << red << mascara[i][j] << " " << normal;
                    break;

                case 'F':
                    cout << red << mascara[i][j] << " " << normal;
                    break;

                case 'S':
                    cout << red << mascara[i][j] << " " << normal;
                    break;

                case 'E':
                    cout << red << mascara[i][j] << " " << normal;
                    break;

                case 'P':
                    cout << red << mascara[i][j] << " " << normal;
                    break;

                default:
                    cout << mascara[i][j] << " ";
                    break;
            }
        }
        cout << endl;
    }
    cout << endl;

    if(mostraGabarito == true){
        exibeMapa();
        for(int i = 0;i < 10;i++){
            cout << i << " - ";
            for(int j = 0;j < 10;j++){
                cout << tabuleiro[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void iniciaTabuleiro(char tabuleiro[10][10],char mascara[10][10]){
     for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            tabuleiro[i][j] = 'A';
            mascara[i][j] = '*';
        }
    }
}

void posicionaBarcos(char tabuleiro[10][10]){
    int linha,coluna,quantidade = 2;
    int quantidadePosicionada = 0;              // Quantidade de barcos a ser posicionada

    while(quantidadePosicionada < quantidade){
        linha = rand() % 10;                    // Gera um numero aleatorio entre 0 e 9
        coluna = rand() % 10;                   // Gera um numero aleatorio entre 0 e 9
        if(tabuleiro[linha][coluna] == 'A'){
            // Posiciona os 10 barcos aleatoriamente
            tabuleiro[linha][coluna] = 'L';     // L = lancha torpedeira (4 pts)
            quantidadePosicionada++;
        }
    }
    quantidadePosicionada = 0;
    while(quantidadePosicionada < quantidade){
        linha = rand() % 10;                    // Gera um numero aleatorio entre 0 e 9
        coluna = rand() % 10;                   // Gera um numero aleatorio entre 0 e 9
        if(tabuleiro[linha][coluna] == 'A'){
            // Posiciona os 10 barcos aleatoriamente
            tabuleiro[linha][coluna] = 'F';     // F = fragata (6 pts)
            quantidadePosicionada++;
        }
    }
    quantidadePosicionada = 0;
    while(quantidadePosicionada < quantidade){
        linha = rand() % 10;                    // Gera um numero aleatorio entre 0 e 9
        coluna = rand() % 10;                   // Gera um numero aleatorio entre 0 e 9
        if(tabuleiro[linha][coluna] == 'A'){
            // Posiciona os 10 barcos aleatoriamente
            tabuleiro[linha][coluna] = 'S';     // S = submarino (6 pts)
            quantidadePosicionada++;
        }
    }
    quantidadePosicionada = 0;
    while(quantidadePosicionada < quantidade){
        linha = rand() % 10;                    // Gera um numero aleatorio entre 0 e 9
        coluna = rand() % 10;                   // Gera um numero aleatorio entre 0 e 9
        if(tabuleiro[linha][coluna] == 'A'){
            // Posiciona os 10 barcos aleatoriamente
            tabuleiro[linha][coluna] = 'E';     // E = encouraçado (8 pts)
            quantidadePosicionada++;
        }
    }
    quantidadePosicionada = 0;
    while(quantidadePosicionada < quantidade){
        linha = rand() % 10;                    // Gera um numero aleatorio entre 0 e 9
        coluna = rand() % 10;                   // Gera um numero aleatorio entre 0 e 9
        if(tabuleiro[linha][coluna] == 'A'){
            // Posiciona os 10 barcos aleatoriamente
            tabuleiro[linha][coluna] = 'P';     // P = porta aviões (10 pts)
            quantidadePosicionada++;
        }
    }
}

void verificaTiro(char tabuleiro[10][10],int linha,int coluna,int *pontos,string *mensagem){
    // Verifica quantos pontos adicionar
    switch(tabuleiro[linha][coluna]){
        case 'P':
            *pontos = *pontos + 10;
            *mensagem = "Parabens! Voce acertou um Porta Avioes. (10 pts).";
            break;

        case 'E':
            *pontos = *pontos + 8;
            *mensagem = "Parabens! Voce acertou um Encouracado. (8 pts).";
            break;

        case 'S':
            *pontos = *pontos + 6;
            *mensagem = "Parabens! Voce acertou um Submarino. (6 pts).";
            break;

        case 'F':
            *pontos = *pontos + 6;
            *mensagem = "Parabens! Voce acertou uma Fragata. (6 pts).";
            break;

        case 'L':
            *pontos = *pontos + 4;
            *mensagem = "Parabens! Voce acertou uma Lancha Torpedeira. (10 pts).";
            break;

        case 'A':
            *mensagem = "Essa nao! Voce acertou apenas a agua.";
            break;
    }
}

void jogarNovamente(string nome){

    int opcao;

    cout << "O que deseja fazer" << endl;
    cout << "1 - Jogar novamente" << endl;
    cout << "2 - Voltar ao Menu Inicial" << endl;
    cin >> opcao;

    switch(opcao){
        case 1:
            jogo(nome);
            break;

        case 2:
            menuInicial();
            break;

        default:
            cout << "Opcao invalida ! Tente novamente." << endl;
            break;
    }
}

void jogo(string nome){

    /// Variaveis Gerais
    char tabuleiro[10][10],mascara[10][10];
    int linha,coluna;                               // Variaveis para a leitura das jogadas
    int estadoDeJogo = 1;                          // 1 = jogo acontecendo 0 = jogo finalizado
    int pontos = 0;                               // Variavel responsavel pela pontuacao do jogador
    int tentativas = 0,maximoDeTentativas = 10;  // Gurada a quantidade de tentivas que o jogador tem
    int opcao;                                  // Opcoes de fim de jogo
    string mensagem = "Bem vindo!";            // Mensagem de informação para o jogador
    FILE *arq;

    iniciaTabuleiro(tabuleiro,mascara);
    posicionaBarcos(tabuleiro);

    while(tentativas < maximoDeTentativas){
        exibeMapa();           // Exibe mapa das posições para os tiros
        exibeTabuleiro(tabuleiro,mascara,false);

        cout << "Pontos : " << pontos << endl;
        cout << "Tentativas restantes : " << maximoDeTentativas - tentativas << endl;
        cout << mensagem << endl;

        // Verificação de dados
        linha = -1;
        coluna = -1;
        while((linha < 0 || coluna < 0) || (linha > 9 || coluna > 9)){
            cout << nome <<", digite uma linha : ";
            cin >> linha;
            cout << nome << ", digite uma coluna : ";
            cin >> coluna;
            limpaTela();
            if((linha < 0 || coluna < 0) || (linha > 9 || coluna > 9)){
                cout << "Pontos : " << pontos << endl;
                cout << "Tentativas restantes : " << maximoDeTentativas - tentativas << endl;
                cout << "Valores digitados invalidos. Tente novamente." << endl;
                exibeMapa();           // Exibe o mapa das posições para os tiros
                exibeTabuleiro(tabuleiro,mascara,false);
            }
        }

        verificaTiro(tabuleiro,linha,coluna,&pontos,&mensagem);

        // Revela o que esta no tabueiro
        mascara[linha][coluna] = tabuleiro[linha][coluna];

        tentativas++;
    }
    exibeMapa();           // Exibe mapa das posições para os tiros
    exibeTabuleiro(tabuleiro,mascara,true);
    cout << "Fim de jogo!" << endl;
    cout << "Sua pontucao final foi : " << pontos << " pts." << endl;
    jogarNovamente(nome);
}

void menuInicial(){
    int opcao;
    string nome;          // Gurada o nome do jogador

    do{
        cout << "Bem vindo ao jogo" << endl;
        cout << "1 - Jogar" << endl;
        cout << "2 - Sobre" << endl;
        cout << "3 - Sair" << endl;
        cin >> opcao;
        limpaTela();

        switch(opcao){
            case 1:
                cout << "Jogo iniciado!" << endl << endl;
                cout << "Digite seu nome : ";
                cin >> nome;
                limpaTela();
                jogo(nome);
                break;

            case 2:
                cout << "Jogo criado unico e exclusivamente com o intuito de aprendizado" << endl;
                cout << "07/04/2021 : inicio do projeto." << endl;
                cout << "08/04/2021 : continuacao do projeto." << endl;
                system("pause");
                limpaTela();
                break;

            case 3:
                cout << "Obrigado por jogar, ate a proxima!" << endl;
                return;
                break;

            default:
                cout << "Opcao invalida, tente novamente" << endl;
                break;
        }
    }while(opcao != 3);
}

void gravaNoArquivo(FILE **arq,string nome,int pontos){
    *arq = fopen("Tabela de Pontuacao (Batalha Naval).txt","a");
    if(*arq != NULL){
        cout << "Arquivo de saida gravado com sucesso!" << endl;
        fprintf(*arq,"Nome : %s",nome);
        fprintf(*arq," , Pontos : %d.",pontos);
    }
    fprintf(*arq,"\n");
}

int main(){

    srand((unsigned)time(NULL));

    menuInicial();

    return 0;
}
