#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <string.h>
using std::cout;
using std::string;
using std::endl;
int main (){
    std:: ifstream in("Categorias.txt");
    if (in.fail()) return (cout << "File not found" << endl) && 0;
    string palabra;
    while(in.good()){
        getline(in,palabra);
        if(palabra[0]=='	'){
            if(palabra[1]=='	')continue;
            cout << palabra << endl;
        }
        else cout << palabra << endl;

    }

    string linea="	Philosophy";
    string linea1 ="	";
    cout << linea.size() << endl;
    cout << linea[0] << endl;
    cout << linea << endl;
}
