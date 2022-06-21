    #include <iostream>
    #include <string>

    /*
    - Guilherme Fabricio Brito da Rosa
    - Matricula: 202120497
    - Turma: 10A

    -- Enunciado 05 - Olimpiadas
    -- Feito: 15/06/2022

    */
   
    using namespace std;

    struct atleta{

        string nacionalidade;
        float altura;
        float peso;
        string nome;
        int idade;

        string atl_esporte;

    };

    struct patrocinador{
        string nome;
        string setor;
        string pais_sede;
        float valor_invest;
        int inicio_contrato;
        int fim_contrato;

        string pat_esporte;
    };

    struct esporte{
        string nome;
        string atividade;
        int dias;
        string atletas_inscritos;
        string patrocinadores_inscritos;
    };

// ------------------------------ Classe ------------------------------------------------------

    class organizacao{

        private:
            atleta *lista_atletas;
            patrocinador *lista_patrocinadores;
            esporte *lista_esporte;
            int total_atleta;
            int total_patron;
            int total_esporte;

        public:
            organizacao(int quanti_atleta, int quanti_patron, int quanti_esporte);
            ~organizacao();

            void registrar_atleta();
            void registrar_patrocio();
            void registrar_esporte();
            void rastreioEsporte(string rastreio);
    };

// ----------------------------- Metodos --------------------------------------------------------

/* -- Valores quanti_atleta, quanti_patron, quanti_esporte serão definidos pelo usuario para
ser alocado com tamanho correto */

    organizacao::organizacao(int quanti_atleta, int quanti_patron, int quanti_esporte){

        total_atleta = quanti_atleta;
        lista_atletas = new atleta[total_atleta];

        total_patron = quanti_patron;
        lista_patrocinadores = new patrocinador[total_patron];

        total_esporte = quanti_esporte;
        lista_esporte = new esporte[total_esporte];

    };

    organizacao::~organizacao(){
        delete[] lista_atletas;
        total_atleta = 0;

        delete[] lista_patrocinadores;
        total_patron = 0;

    };

// "getline(cin >> ws, .... );" - Extração de todos caracteres de espaço em branco após o cin.

    void organizacao::registrar_patrocio(){

        for(int i = 0; i < total_patron; i++){

            cout << "Registro de Patrocinadores !!!" << endl;

           cout << "Nome: ";
            getline(cin >> ws, lista_patrocinadores[i].nome); 
            
            cout << "Setor: ";
            getline(cin >> ws, lista_patrocinadores[i].setor);

            cout << "Pais Sede: ";
            getline(cin >> ws, lista_patrocinadores[i].pais_sede);

            cout << "Valor Investido: ";
            cin >> lista_patrocinadores[i].valor_invest;

            cout << "Inicio do Contrato (tudo junto): ";
            cin >> lista_patrocinadores[i].inicio_contrato;

            cout << "Fim do Contrato: ";
            cin >> lista_patrocinadores[i].fim_contrato;

            cout << "Qual Esporte referente? ";
            getline(cin >> ws, lista_patrocinadores[i].pat_esporte);

            cout << endl << "Registro Sucedido !" << endl << endl;
        }
    }

    void organizacao::registrar_atleta(){

        for(int j = 0; j < total_atleta; j++){

            cout << "Registro de Atletas !!!" << endl;

            cout << "Nome: ";
            getline(cin >> ws, lista_atletas[j].nome);

            cout << "Nacionalidade: ";
            getline(cin >> ws, lista_atletas[j].nacionalidade);

            cout << "Altura: ";
            cin >> lista_atletas[j].altura;

            cout << "Peso: ";
            cin >> lista_atletas[j].peso;

            cout << "Idade: ";
            cin >> lista_atletas[j].idade;

            cout << "Qual Esporte referente? ";
            getline(cin >> ws, lista_atletas[j].atl_esporte);

            cout << endl <<"Registro Sucedido !" << endl << endl;
        }
    }

    void organizacao::registrar_esporte(){
        for(int k = 0; k < total_esporte; k++){
            cout << "Registro de Esportes !!!!" << endl;

            cout << "Nome: ";
            cin >> lista_esporte[k].nome;

            cout << "Atividade: ";
            cin >> lista_esporte[k].atividade;

            cout << "Dias: ";
            cin >> lista_esporte[k].dias;

            cout << "Atleta Inscrito: ";
            cin >> lista_esporte[k].atletas_inscritos;

            cout << endl <<"Registro Sucedido !" << endl << endl;
        }
    }

    /* -- Metodo de verificação de busca - comparando as duas strings, e recorrendo o que o usuário
    cadastrou durante o registro do programa. Caso não tenha comparacao, um auxiliar será utilizado.
    Se houver cadastro, será aux = 1, caso contrario, ele irá dar a mensagem : "X - Nao cadastrado"
    "enviará a mensagem "X Não cadastrado"*/

    void organizacao::rastreioEsporte(string rastreio){

        cout << endl << "-------- Atletas Buscados pelo Esporte --------" << endl;
        int aux = 0;

        for (int i = 0; i < total_atleta; i++){

            if (rastreio == lista_atletas[i].atl_esporte){

                cout << "Nome: " << lista_atletas[i].nome << endl;
                cout << "Nacionalidade: " << lista_atletas[i].nacionalidade << endl;
                cout << "Idade: " << lista_atletas[i].idade << endl << endl;
                aux = 1;
            }
            
        }

        if(aux == 0)
            cout << "Atleta Nao Cadastrado :(" << endl;

        cout << endl << "-------- Patrocinios Buscados pelo Esporte --------" << endl;

        aux = 0;

        for (int k = 0; k < total_esporte; k++){
            if (rastreio == lista_patrocinadores[k].pat_esporte){

                cout << "Nome: " << lista_patrocinadores[k].nome << endl;
                cout << "Setor: " << lista_patrocinadores[k].setor << endl;
                cout << "Pais Sede: " << lista_patrocinadores[k].pais_sede << endl; 
                aux = 1;
            }
            if(aux == 0)
                cout << "Patrocinio Nao Cadastrado :(" << endl;
        }
    }

//----------------------------------------- Funcao Main ----------------------------------------------------------

    int main (){

        int quanti_atleta, quanti_patron, quanti_esporte;
        string rastreio;

        cout <<"------------ Seja Bem vindo ao Registro das Olimpiadas 20XX !!!! ------------" << endl << endl;

        cout << "Quantidade de atletas: " << endl;
        cin >> quanti_atleta;
        cout << "Quantidade de Patrocinador: " << endl;
        cin >> quanti_patron;
        cout << "Quantidade de esporte: " << endl;
        cin >> quanti_esporte;

        organizacao *org = new organizacao(quanti_atleta, quanti_patron, quanti_esporte);

        org -> registrar_atleta();

        org -> registrar_patrocio();

        org -> registrar_esporte();

        cout << "Qual Esporte que queira consultar ? ";
        getline(cin >> ws, rastreio);

        org -> rastreioEsporte(rastreio);

        cout << endl << "Obrigado por usar Busque Olimpiadas 20XX - Feito por: Guilherme Fabricio B. da Rosa" << endl;

        delete org;

        return 0;
    }