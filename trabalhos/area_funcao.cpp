#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

//Fun��o para limpar a tela
void LimpaTela(){
    system("CLS");
}

//Fun��o linear para calcular f(x), que � a altura do ret�ngulo aproximante
double FuncLinear(double x, vector<double>parametros){
    return (parametros[0]*x) + parametros[1];
}

//Fun��o polinomial do 2� grau para calcular f(x), que � a altura do ret�ngulo aproximante
double FuncPolinomial(double x, vector<double>parametros){
    return (parametros[0]*x*x) + (parametros[1]*x) + parametros[2];
}

//Fun��o exponencial para calcular f(x), que � a altura do ret�ngulo aproximante
double FuncExponencial(double x, vector<double>parametros){
    return parametros[0]*pow(parametros[1],parametros[2]*x);
}

//Fun��o para calcular a �rea de uma fun��o escolhida pelo usu�rio pelo m�todo de Riemman pela esquerda
double CalculaAreaRiemman(double (*func)(double, vector<double>), double xi, double xf, int quantretang, vector<double>param){

    int i;
    double deltax, soma=0.0;
    deltax = (xf-xi)/quantretang;
    for(i=0;i<quantretang;i++){
        soma = soma + (deltax*(func(xi, param)));
        xi = xi + deltax;
    }
    return soma;
}

//Fun��o para par�metros e calcula a �rea
double Parametros(int escolha){

    double area, valor, xinicial, xfinal, aux;
    int retangulos = -1;
    vector <double> param;
    //Resolve o problema se o usu�rio digitar um n�mero negativo para a quantidade ret�ngulos
    while(retangulos < 0){
        cout << "Digite a quantidade de retangulos aproximantes: ";
        cin >> retangulos;
        if(retangulos < 0){
            cout << "O numero de retangulos nao pode ser negativo! Digite novamente:";
            cout << endl;
        }
    }

    cout << "Digite o intervalo: " << endl;
    cout << "x inicial: ";
    cin >> xinicial;
    cout << "x final: ";
    cin >> xfinal;
    //Resolve o problema se o usu�rio digitar o intervalo errado
    if(xfinal < xinicial){
        cout << endl;
        cout << "Intervalo invalido, x final menor que o inicial." << endl;
        aux = xinicial;
        xinicial = xfinal;
        xfinal = aux;
        cout << "O intervalo foi invertido para o calculo ser realizado." << endl;
        cout << endl;
        cout << "x inicial: " << xinicial << endl;
        cout << "x final: " << xfinal << endl;
        cout << endl;
    }

    cout << "Digite o parametro a: ";
    cin >> valor;
    param.push_back(valor);
    cout << "Digite o parametro b: ";
    cin >> valor;
    param.push_back(valor);

    switch(escolha){
        case 1:
            area = CalculaAreaRiemman(FuncLinear, xinicial, xfinal, retangulos, param);
            break;
        case 2:
            cout << "Digite o parametro c: ";
            cin >> valor;
            param.push_back(valor);
            area = CalculaAreaRiemman(FuncPolinomial, xinicial, xfinal, retangulos, param);
            break;
        case 3:
            cout << "Digite o parametro c: ";
            cin >> valor;
            param.push_back(valor);
            area = CalculaAreaRiemman(FuncExponencial, xinicial, xfinal, retangulos, param);
            break;
    }
    return area;
}

//Fun��o para retornar a escolha do usu�rio
int EscolhaDoUsuario(){

    int escolha;
    cout << "Digite a opcao de funcao para calcular a area: " << endl;
    cout << "1 - Linear - f(x) = ax + b" << endl;
    cout << "2 - Polinomial 2 grau - f(x) = ax2 + bx + c" << endl;
    cout << "3 - Exponencial - f(x) = a*b(onde b elevado a cx)" << endl;
    cin >> escolha;
    return escolha;
}

int main()
{
    int escolha;
    double area;
    cout << "Programa para calcular a area de uma funcao pelo metodo de Riemman!" << endl;
    cout << endl;
    escolha = EscolhaDoUsuario();
    LimpaTela();
    area = Parametros(escolha);
    LimpaTela();
    cout << "A area eh aproximadamente: " << area << endl;
    return 0;
}
