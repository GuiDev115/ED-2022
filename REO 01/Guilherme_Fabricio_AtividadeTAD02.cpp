/* 
    berlinde.cpp - aplicação para desenvolvimento de atividade
    de Tipo Abstrado de Dados

    Atividade de  GCC216 - Estruturas de Dados, 2020

    Solução de: Guilherme Fabrício Brito da Rosa

    Enunciado: 07 - berlinde.cpp

    Redimensionar o vetor adicionando três novas posições a cada redimensionamento
*/

#include <iostream>

using namespace std;

struct competidor {
    string nomeDoCompetidor;
    string categoriaDoCompetidor;  //iniciante, intermediário ou avançado
    int diaDasPartidas;
    competidor();       
};

competidor::competidor() {
    nomeDoCompetidor.clear();
    categoriaDoCompetidor.clear();
    diaDasPartidas = 0;
}


class campeonato {
    private:
        // *** AVISO: Não altere os atributos privados da classe *** 
        competidor* listaDeCompetidores;
        int quantidadeDeCompetidores;
        int capacidadeMaxima;
    public:
        campeonato(int capacidade);
        campeonato(const campeonato &other);
        ~campeonato();
        void inserirNovoCompetidor(const competidor& umCompetidor);
        bool buscarCompetidor(const string& umNome, competidor& umCompetidor);
        void redimensionarCapacidade();
        friend void simularMudancaDeDia(campeonato umaEquipe, int novoDia);
};

campeonato::campeonato(int capacidade) {
    quantidadeDeCompetidores = 0;
    capacidadeMaxima = capacidade;
    listaDeCompetidores = new competidor[capacidadeMaxima];
}

//----Construtor de Cópia------------------------------------------

campeonato::campeonato (const campeonato &aux){ 
    quantidadeDeCompetidores = aux.quantidadeDeCompetidores;
    capacidadeMaxima = aux.capacidadeMaxima;
    listaDeCompetidores = new competidor[capacidadeMaxima];
    copy(aux.listaDeCompetidores, aux.listaDeCompetidores + aux.capacidadeMaxima, listaDeCompetidores);
}

campeonato::~campeonato() {
    delete [] listaDeCompetidores;
}

void campeonato::inserirNovoCompetidor(const competidor& umCompetidor) {
    if (quantidadeDeCompetidores == capacidadeMaxima) { // vetor cheio, precisa redimensionar
        redimensionarCapacidade();
    }
    listaDeCompetidores[quantidadeDeCompetidores] = umCompetidor;
    quantidadeDeCompetidores++;
}

bool campeonato::buscarCompetidor(const string& nome, competidor& umCompetidor) {
    int posicaoAtual = 0;

    while (posicaoAtual < quantidadeDeCompetidores and
           listaDeCompetidores[posicaoAtual].nomeDoCompetidor != nome) 
        posicaoAtual++;

    // se posicaoAtual não for menor que quantidade de competidores, é porque não encontrou
    if (posicaoAtual < quantidadeDeCompetidores) {
        umCompetidor = listaDeCompetidores[posicaoAtual];
        return true;
    }

    return false;
}

//-----Metodo de Redimensionamento----------------------------------------

void campeonato::redimensionarCapacidade() {
    competidor *listaAux = new competidor[capacidadeMaxima];
    copy(listaDeCompetidores, listaDeCompetidores + quantidadeDeCompetidores, listaAux);//copia tudo do listacompetidores para uma lista nova usando do proprio iostream
    delete[] listaDeCompetidores; 
    
    cout << "Capacidade máxima inicial da equipe: " << capacidadeMaxima << endl; //Verificacao antes de redimensionar
    int new_capacity = capacidadeMaxima + 3;
    
    listaDeCompetidores = new competidor[new_capacity]; //aloca com a new_capacity. Será desalocada quando o destrutor o chamar
    copy(listaAux, listaAux + quantidadeDeCompetidores, listaDeCompetidores);// copia dados da lista para a listaDeCompetidores, utilizando proprio Iostream
    delete[] listaAux;
    
    capacidadeMaxima = new_capacity;
    cout << "Vetor com tamanho: " << capacidadeMaxima << endl; 
}

void simularMudancaDeDia(campeonato umCampeonato, int novoDia) {
    // *** AVISO: Não altere esta função *** 
    for (int i = 0; i < umCampeonato.quantidadeDeCompetidores; i++) {
        if (umCampeonato.listaDeCompetidores[i].diaDasPartidas % 2 == 0)
        cout << umCampeonato.listaDeCompetidores[i].nomeDoCompetidor << " " 
             << umCampeonato.listaDeCompetidores[i].categoriaDoCompetidor << " " 
             << novoDia << endl;
    }
    cout << endl;
}


int main() {
    // *** AVISO: Não altere a função principal, o main() *** 
    int capacidadeInicial;

    cout << "Competição de Bolinha de Gude\nAplicativo para simular alteração na data das partidas\n" 
         << "\nEntre com capacidade máxima inicial do campeonato: ";
    cin >> capacidadeInicial;

    campeonato meuCampeonato(capacidadeInicial);

    cout << "Competidores - Escolha a Opção:\n"
         << "i - inserir novo competidor\n"
         << "b - buscar por dados de um competidor a partir do nome\n"
         << "r - simular alteração de data das partidas\n"
         << "s - para sair do programa" << endl;

    char opcaoDoMenu;
    competidor umCompetidor;
    string nome;
    int novoDia;

    cin >> opcaoDoMenu;

    while (opcaoDoMenu != 's') {
        switch(opcaoDoMenu) {
            case 'i' : 
                cout << "Entre com dados do competidor (nome, categoria e dia das partidas):" << endl;
                cin >> umCompetidor.nomeDoCompetidor
                    >> umCompetidor.categoriaDoCompetidor >> umCompetidor.diaDasPartidas;
                meuCampeonato.inserirNovoCompetidor(umCompetidor);
                break;

            case 'b' :
                cout << "Entre com nome do Competidor para busca: ";
                cin >> nome;
                
                if (meuCampeonato.buscarCompetidor(nome, umCompetidor)) 
                    cout << umCompetidor.nomeDoCompetidor<< " "
                         << umCompetidor.categoriaDoCompetidor << " " <<  umCompetidor.diaDasPartidas << endl << endl;
                else 
                    cout << "Competidor não encontrado!" << endl << endl;
                break;

            case 'r' : 
                cout << "Entre com o novo dia das partidas: ";
                cin >> novoDia;
                simularMudancaDeDia (meuCampeonato,novoDia);
                break;

            case 's' : // não faz nada, espera retorno ao while para sair 
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;

        }
        cout << "Competidores - Escolha a Opção:\n"
         << "i - inserir novo competidor\n"
         << "b - buscar por dados de um competidor a partir do nome\n"
         << "r - simular alteração de data das partidas\n"
         << "s - para sair do programa" << endl;
        cin >> opcaoDoMenu;
    }

    return 0;
}

