#include <iostream>
#include <vector>

using namespace std;

class Data {
    private:
    int dia;
    int mes;
    int ano;

    public:
    
     Data(int _dia, int _mes, int _ano) {
        this-> dia = _dia;
        this -> mes = _mes; 
        this-> ano = _ano; 
    }

    
   
    int getDia(){
        return this->dia;
    }
    void setDia(int _dia){
        this->dia = _dia;
    }

    
     int getMes(){
        return this->mes;
    }
    void setMes(int _mes){
        this->mes = _mes;
    }

    
     int getAno(){
        return this->ano;
    }

    void setAno(int _ano){
        this->ano = _ano;
    }

};

class Paciente {
    string cpf;
    Data dtNascimento;
    
    public:
    
    string nome;

    Paciente(string _nomePaciente, string _cpf,  Data _dtNascimento)
        : cpf(_cpf), nome(_nomePaciente), dtNascimento(_dtNascimento) {}

    string getCpf() {
        return this-> cpf;
    }

    void setCpf(string _cpf) {
       
       this-> cpf = _cpf;

    }

    Data getDtNascimento() {
        return this -> dtNascimento;
    }

    void setDtNascimento( Data _dtNascimento) {
        this->dtNascimento = _dtNascimento;
    }
    
};

class Medico{
        string crm;

    public:

    string NomeMedico, Especialidade;
    

    string getCrm()
    {
        return this ->crm;
    }
    void setCrm(string _crm)
    {
        this ->crm = _crm;
    }

    Medico(string _NomeMedico, string _Especialidade, string _crm) {
        this-> NomeMedico = _NomeMedico;
        this-> Especialidade = _Especialidade;
        this-> crm = _crm;
    }
};

   
int localizaCpf(vector <Paciente*> pacientes, string cpf) {
    int i=0;
    for(auto el : pacientes) {
        if(el-> getCpf() == cpf) {
            return i;

    }
        i++;
    }

    return -1;

}

int localizaCrm(vector <Medico*> medicos, string crm) {
    int i = 0;
    for(auto el : medicos) {
        if(el->getCrm() == crm) {

            return i;
        }
        i++;
    }
    return -1;
}




int main(){

    int opcao1;
    int opcao;
    vector <Paciente*> listaPaciente;
    vector <Medico*> listaMedico;

    do{
        cout <<"ESCOLHA UMA OPCAO: " << endl;
        cout <<"1- PACIENTE: " << endl;
        cout <<"2- MEDICO: " << endl;
        cin >> opcao1;

        if(opcao1 == 1){
            do {
        cout << "----- OPCOES PACIENTE ------: " << endl;
        cout << " 1-ADICIONAR PACIENTE: " << endl;
        cout << " 2-EXCLUIR PACIENTE: (por CPF) " << endl;
        cout << " 3-ALTERAR PACIENTE: (por CPF) " << endl;
        cout << " 4-LISTAR PACIENTES: " << endl;
        cout << " 5-LOCALIZAR PACIENTE: (por CPF) " << endl;
        cout << " 0- SAIR " << endl;
        cin >> opcao;


        string auxNome, auxCpf, auxDtNasc;
        int dia; 
        int mes; 
        int ano;
        
        if(opcao == 1){
       
        cout << "Informe o nome: " ;
        getline(cin >> ws,auxNome);
        
        cout << "Informe o CPF: " ;
        getline(cin >> ws,auxCpf);
       
        cout << "Informe o dia de nascimento: " << endl;
        cin >> dia;
        cout << "Informe o mes de nascimento: " << endl;
        cin >> mes;
        cout << "Informe o ano de nascimento: " << endl;
        cin >> ano;

        if(auxCpf.length() != 11){
            cout << "CPF invalido!" << endl;
            break;
        }

        int posicao = localizaCpf(listaPaciente,auxCpf);
        if(posicao < 0)
         {
            Data data (dia, mes, ano);
            Paciente *paciente =  new Paciente(auxNome, auxCpf, data);
            listaPaciente.push_back(paciente);
         } else
         {
            cout << "Paciente ja inserido" << endl;
         }
          
        }
        
        else if(opcao == 2){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA EXCLUIR: ";
            getline (cin >> ws, auxCpf); 

            int posicao = localizaCpf(listaPaciente, auxCpf);
            
            listaPaciente.erase(listaPaciente.begin() + posicao);

            }
        else if(opcao == 3){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA ALTERAR: ";
            getline (cin >> ws, auxCpf); 

            int posicao = localizaCpf(listaPaciente, auxCpf);

            if(posicao < 0)
            cout <<"PACIENTE NAO ENCONTRADO" << endl;
            else{
                int escolha;
                cout <<"Nome: " << listaPaciente[posicao]->nome << endl;
                cout <<"Cpf: " << listaPaciente[posicao]->getCpf() << endl;
                cout <<"Data de nascimento: " << listaPaciente[posicao]->getDtNascimento().getDia() << endl;
                cout <<" / " << listaPaciente[posicao]->getDtNascimento().getMes() << endl;
                cout <<" / " << listaPaciente[posicao]->getDtNascimento().getAno() << endl;
                string NomeNovo; 
                string DataNova;

                cout <<"DESEJA ALTERAR O NOME? 1-SIM ou 2- NAO " << endl;
                cin >> escolha;

                if(escolha == 1){
                    cout << "INFORME O NOVO NOME: " << endl; 
                    getline(cin >> ws , NomeNovo);
                    listaPaciente[posicao]-> nome = NomeNovo;

                }else{}

                cout <<"DESEJA ALTERAR A DATA? 1- SIM OU 2- NAO " << endl;
                cin >> escolha;
                if(escolha == 1){
                    cout<<"Informe o dia de nascimento: " << endl;
                    cin >> dia;
                    cout<<"Informe o mes de nascimento: " << endl;
                    cin >> mes;
                    cout<<"Informe o ano de nascimento: " << endl;
                    cin >> ano;
                    Data data (dia, mes, ano);
                    listaPaciente[posicao]->setDtNascimento(data);

                }else{}
            }


            }
        else if(opcao == 4){
            for(auto el : listaPaciente) {
                cout << el->nome << endl;
                cout << el->getCpf() << endl;
                cout << el->getDtNascimento().getDia()<< endl;
                cout << el->getDtNascimento().getMes()<< endl;
                cout << el->getDtNascimento().getAno()<< endl;
                cout << endl;
    }
            }
        else if(opcao == 5){
            cout << "INFORME O CPF DO PACIENTE QUE DESEJA LOCALIZAR: ";
            getline(cin >> ws, auxCpf);

            int posicao = localizaCpf(listaPaciente, auxCpf);

            if (posicao < 0)
            cout << "PACIENTE NAO ENCONTRADO" << endl;

            else {
               
            cout << listaPaciente.at(posicao)->nome << endl;
    }
        }
        else if(opcao == 0){
        

        }
        else {
            cout << "OPÇAO INVALIDA" << endl;
        }
        
        }while (opcao !=0);

    }else if(opcao1 == 2){
     do {
        cout << "----- OPCOES MEDICO ------: " << endl;
        cout << " 1-ADICIONAR MEDICO: " << endl;
        cout << " 2-EXCLUIR MEDICO: (por CRM) " << endl;
        cout << " 3-ALTERAR MEDICO: (por CRM) " << endl;
        cout << " 4-LISTAR MEDICOS: " << endl;
        cout << " 5-LOCALIZAR MEDICO: (por CRM) " << endl;
        cout << " 0- SAIR " << endl;
        cin >> opcao;

        string auxNomeMedico, auxCrm, auxEspecialidade; 
        if(opcao==1){
                cout << "Informe o nome: ";
                getline(cin >> ws, auxNomeMedico);

                cout << "Informe o CRM: ";
                getline(cin >> ws, auxCrm);

                cout << "Informe a Especialidade: ";
                getline(cin >> ws, auxEspecialidade);

                int posicao1 = localizaCrm(listaMedico,auxCrm);

                if(posicao1  < 0){
                    Medico *medico = new Medico(auxNomeMedico, auxEspecialidade, auxCrm);
                    listaMedico.push_back(medico);
                }
                else{
                    cout << "Medico ja inserido" << endl;
                } 
        }        
        else if(opcao == 2){
            cout << "Informe o CRM do medico que deseja excluir: ";
                getline(cin >> ws, auxCrm);

                int posicao1 = localizaCrm(listaMedico,auxCrm);

                
                listaMedico.erase(listaMedico.begin() + posicao1);
                
            }
        else if(opcao == 3){
            cout << "Informe o CRM do Medico que deseja alterar: ";
                getline(cin >> ws, auxCrm);

                int posicao1 = localizaCrm(listaMedico,auxCrm);

                if(posicao1  < 0)
                    cout << "Medico não encontrado" << endl;
                else{
                    int escolha1;
                    string novoNomeMedico;
                    string novaEspecialidade;
                    cout << "Nome: " << listaMedico[posicao1]->NomeMedico << endl;
                    cout << "Especialidade: " << listaMedico[posicao1]->Especialidade << endl;
                    cout << "CRM: " << listaMedico[posicao1]->getCrm() << endl;

                    cout << "Deseja alterar o nome? 1-Sim / 2 - Nao" << endl;
                    cin>> escolha1;

                    if(escolha1 == 1){
                        cout << "Informe o nome do medico: " << endl;
                        getline(cin >> ws, novoNomeMedico);
                        listaMedico[posicao1]->NomeMedico = novoNomeMedico;
                    }else{  }

                    cout << "Deseja alterar a especialidade? 1-Sim / 2 - Nao" << endl;
                    cin>> escolha1;

                    if(escolha1 == 1){
                        cout << "Informe a especialidade: " << endl;
                        getline(cin >> ws, novaEspecialidade);
                        listaMedico[posicao1]->Especialidade = novaEspecialidade;
                    }else{  }

                }   
        }
        else if(opcao == 4){
            for(auto el : listaMedico){
                    cout << el->NomeMedico << endl;
                    cout << el->getCrm() << endl;
                    cout << el->Especialidade << endl;
                    cout << endl;
                }
        }    
        else if(opcao ==5){
             cout << "Informe o Crm do medico que deseja localizar: ";
                getline(cin >> ws, auxCrm); 

                int posicao1 = localizaCrm(listaMedico,auxCrm);

                if(posicao1 < 0)
                    cout << "Medico nao encontrado" << endl;
                else{
                    cout << listaMedico.at(posicao1)->NomeMedico << endl;
                    cout << listaMedico.at(posicao1)->getCrm()<< endl;
                    cout << listaMedico.at(posicao1)-> Especialidade << endl;
                }
        } 
        else if(opcao==0){
                
            } else{
                cout << "Opção inválida" << endl;
            }
     }while(opcao != 0);
   
    }
    
    }while(opcao1 != 0);

        return 0;

    }