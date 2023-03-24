#include <iostream>

class senha
{
    public:
        char Cores[4] {'v', 'a', 'p', 'b'};
        char SenhaGerada[4], Palpite[4];
        void GerarSenha();
        int VerificarAcertos();
};
