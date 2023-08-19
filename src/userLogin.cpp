#include <iostream>
#include <string>
#include <windows.h>

//É bom ter uma pasta src para seus arquivos .cpp fica mais organizado, e sempre quando der commit no github coloque a extensão do arquivo.

//Como é um programa pequeno pode usar, mas evite usar o namespace std dessa forma, preferia sempre colocar o que vai usar.
using namespace std;


string username, password, un, pw;
bool registrado = false;

void registrar()
{
    cout << "insira seu user para registrar: "; 
    cin >> username;
    //Remove espaços em branco do username.
    username.erase(std::remove_if(username.begin(), username.end(), ::isspace), username.end());
    '\n';
    cout << "insira sua senha: "; 
    //Espaço é considerado um caracter especial, na senha não deveria ser bloqueado.
    cin >> password;
    '\n';
    //A lógica antiga ficava quebrada já que você comparava username com un, mas o correto é passar os valores de username pra un.
    un = username;
    pw = password;
    cout << "conta criada!" << '\n';
    '\n';
    registrado = true;
}

void logar()
{
    cout << "insira seu username: "; 
    cin >> un;
    un.erase(std::remove_if(un.begin(), un.end(), ::isspace), un.end());
    '\n';
    cout << "insira sua senha: ";
    cin >> pw;
    '\n';
}

int main()
{
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    while (true)
    {

        int choices;
        cout << "Escolha as opções\n";
        cout << "1. para registrar\n";
        cout << "2. para logar\n";
        //\n tem que ser um caracter, então passe em aspas simples para não ser contado como strings e ele não precisa ser impresso na tela.
        '\n';
        cin >> choices;
        switch (choices)
        {
        case 1:
            registrar();
            continue;
        case 2:
            //Pra evitar redundância você pode só usar negação ao em vez de comparar, o mesmo vale pra true, pode só deixar if(registrado).
            if (!registrado)
            {
                cout << "você não está registrado!\n";
                registrar();
            }
            else
            {
                cin.ignore();
                logar();
                if (un == username && pw == password)
                {
                    cout << "logado com suceso";
                    '\n';
                    return false;
                }
                while (un != username && pw != password)
                {
                    cout << "usuario e senha incorretos\n";
                    cout << '\n';
                    logar();
                }

                while (un != username || pw != password)
                {
                    cout << "usuario incorreto ou senha incorreta\n";
                    cout << '\n';
                    logar();
                }
            }

        }
    }
}
