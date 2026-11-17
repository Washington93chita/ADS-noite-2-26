#include <iostream>
using namespace std;

int main() {

    int opcao, baseOrigem, baseDestino;
    int numero, resto, decimal = 0;
    int resultado[50];
    int i = 0;

    cout << "=== CONVERSOR DE BASES ===" << endl;
    cout << "1 - Decimal" << endl;
    cout << "2 - Binaria" << endl;
    cout << "3 - Hexadecimal" << endl;
    cout << "4 - Quinaria" << endl;
    cout << "5 - Ternaria" << endl;

    cout << "\nEscolha a base de origem: ";
    cin >> opcao;

    if (opcao == 1)
        baseOrigem = 10;
    else if (opcao == 2)
        baseOrigem = 2;
    else if (opcao == 3)
        baseOrigem = 16;
    else if (opcao == 4)
        baseOrigem = 5;
    else if (opcao == 5)
        baseOrigem = 3;
    else {
        cout << "Opcao invalida!";
        return 0;
    }

    cout << "\nEscolha a base de destino: ";
    cin >> opcao;

    if (opcao == 1)
        baseDestino = 10;
    else if (opcao == 2)
        baseDestino = 2;
    else if (opcao == 3)
        baseDestino = 16;
    else if (opcao == 4)
        baseDestino = 5;
    else if (opcao == 5)
        baseDestino = 3;
    else {
        cout << "Opcao invalida!";
        return 0;
    }

    cout << "\nDigite o numero: ";
    cin >> numero;

    // Converter para decimal

    int potencia = 1;

    while (numero > 0) {

        resto = numero % 10;

        if (resto >= baseOrigem) {
            cout << "Numero invalido para essa base!";
            return 0;
        }

        decimal = decimal + resto * potencia;

        potencia = potencia * baseOrigem;

        numero = numero / 10;
    }

    // Converter de decimal para a base escolhida

    if (decimal == 0) {
        cout << "\nResultado: 0";
        return 0;
    }

    while (decimal > 0) {

        resto = decimal % baseDestino;

        resultado[i] = resto;

        decimal = decimal / baseDestino;

        i++;
    }

    cout << "\nResultado: ";

    for (int j = i - 1; j >= 0; j--) {

        if (resultado[j] < 10)
            cout << resultado[j];
        else
            cout << char(resultado[j] + 55);
    }

    cout << endl;

    return 0;
}
