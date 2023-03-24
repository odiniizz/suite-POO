# include "forca.h"
# include "velha.h"
#include "senha.h"
using namespace std;
int main (){
Forca F;
velha W;
senha S;
int op , jogadas, i, j, acertos;
string p1 , p2 , letras;
char L;
bool achei , acertou;
srand (time(NULL));
    do{
        system (" clear ") ;
        cout << "1 - Jogo da Forca" << endl;
        cout << "2 - Jogo da Velha" << endl;
        cout << "3 - Jogo da Senha" << endl;
        cout << "4 - Sair " << endl ;
        cin >> op;
        switch (op){

        case 1:
            p1 = F. Sortear();
            letras = "";
            jogadas = 0;
            p2 = F. montarP2( p1 );
            acertou = false;
            do{
                system ("clear") ;
                cout << "Palavra:" << p2 << endl ;
                cout << "Letras :" << letras << endl ;
                cout << "Jogadas:" << jogadas << endl ;
                cout << "Informe uma letra:" ;
                cin >> L;
                p2 = F. verificarLetra (p1, p2, L, & achei);
                if (! achei){
                    jogadas ++;
                }
                acertou = F. verificaFimJogo (p2) ;
            } while (jogadas < 6 && ! acertou) ;
            if( acertou){
                cout << "Parabéns !!! acertou a palavra:" << p2 << endl ;
            }else{
            cout << "Que pena !! a palavra era: " << p1 << endl ;
            }
        break;

        case 2:
            char V [3][3];
            int i, j, jogadas, cont, k;
            bool J1, J2, linha, coluna, diagP, diagS;
            char continua;
            do{
                jogadas = 0;
                J1 = false;
                J2 = false;
                W.inicializar(V);
                do{
                    W. desenhaMatriz(V);
                    do{
                        cout << " Jogador 1 , faça sua jogada informando linha e coluna : ";
                        cin >> i >> j;
                    } while (V [i][j] != NULL );
                    V [i][j] = 'X';
                    J1 = W. verificaVencedor(V, 'X', i, j) ;
                    if( J1 )
                        break ;
                        jogadas ++;
                        if( jogadas < 9) {
                            W. desenhaMatriz( V);
                            do{
                                cout << " Jogador 2 , faça sua jogada informando linha e coluna : ";
                                cin >> i >> j;
                            } while ( V[i][j] != NULL );
                            V [i][j] = 'O';
                            J2 = W. verificaVencedor(V, 'O', i, j) ;
                            if(J2)
                                break;
                            jogadas ++;
                        }
            } while ((jogadas < 9) && (! J1) && (! J2 )) ;
                if( J1 ){
                    cout << " Jogador 1 venceu !!!!! ";
                } else if(J2) {
                    cout << " Jogador 2 venceu !!!! ";
                } else{
                    cout << " Empatou !!!! ";
                }
        }while (op != 3);
        break;

        case 3:
            system("clear");
            S.GerarSenha();
            jogadas = 1;
            acertou = false;
            do{
                cout << "Informe seu palpite: v - vermelho";
                cout << "A - Azul, P - preto e B - branco" << endl;
                cout << "jogada" << jogadas << ": ";
                for (i = 0; i < 4; i++){
                    cin >> S.Palpite[i];
                }
                acertos = S.VerificarAcertos();
                if (acertos == 4){
                    acertou = true;
                }else{
                    jogadas++;
                    cout << acertos << "acertos" << endl;
                }
            }while (jogadas <= 10 && !acertou);
            if (acertou){
                cout << "Parabéns!! Você acertou!";
            } else {
                cout << "Que pena! Você perdeu! :(" << endl;
                cout << "A senha era:";
                for (i = 0; i < 4; i++){
                    cout << S.SenhaGerada[i] << " ";
                }
            }

        case 4:
            cout << " TCHAU !! " << endl;
        break;

        default:
            cout << " Opção inválida!! " << endl;
    }
    cin.ignore().get();
    }while( op != 4);
return 0;
}






