#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <map>
#include <cmath>
#include <set>
#include <stdio.h>
#include <string.h>


using std::string;
using std::cout;
using std::endl;

std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
std::vector<std::string> csv_read_row(std::string &in, char delimiter);

struct Datos{
    string Titulo;
    string Cuerpo;
    std::set<string> Categoria;
    string Clase;
    int Seguidores;
    int Respuestas;
    string Idioma;
};
struct Anclaje{
    int _perio;
    int _rafa;
    int _permanent;
    int _permanentR;
    int _mrafa;
    int _drift;
    int _others;
};
void Categorias_vs_Seguidores (std::map<string,std::set<string> > C,std::map <string,Datos> P){
    /*
    Arts &amp; Humanities
    Business &amp; Finance
    Consumer Electronics
    Education &amp; Reference
    Entertainment &amp; Music
    Health
    Games &amp; Recreation
    Science &amp; Mathematics
    Beauty &amp; Style
    Sports
    Social Science
    Cars &amp; Transportation
    Dining Out
    Food &amp; Drink
    Home &amp; Garden
    Local Businesses
    Family &amp; Relationships
    News &amp; Events
    Pets
    Politics &amp; Government
    Environment
    Society &amp; Culture
    Travel
    Computers &amp; Internet
    Pregnancy &amp; Parenting
    Yahoo Products
    */
    int m[1][27];
    for (int i=0; i<26;i++){
        m[0][i]=0;
    }
    for (auto i1=P.begin();i1!=P.end();i1++){
        for(auto i2=i1->second.Categoria.begin();i2!=i1->second.Categoria.end();i2++){
            cout << *i2 << endl;
            if(*i2=="Arts &amp; Humanities"){m[0][0]+=i1->second.Seguidores;continue;}
            if(*i2=="Business &amp; Finance"){m[0][1]+=i1->second.Seguidores;continue;}
            if(*i2=="Consumer Electronics"){m[0][2]+=i1->second.Seguidores;continue;}
            if(*i2=="Education &amp; Reference"){m[0][3]+=i1->second.Seguidores;continue;}
            if(*i2=="Entertainment &amp; Music"){m[0][4]+=i1->second.Seguidores;continue;}
            if(*i2=="Health"){m[0][5]+=i1->second.Seguidores;continue;}
            if(*i2=="Games &amp; Recreation"){m[0][6]+=i1->second.Seguidores;continue;}
            if(*i2=="Science &amp; Mathematics"){m[0][7]+=i1->second.Seguidores;continue;}
            if(*i2=="Beauty &amp; Style"){m[0][8]+=i1->second.Seguidores;continue;}
            if(*i2=="Sports"){m[0][9]+=i1->second.Seguidores;continue;}
            if(*i2=="Social Science"){m[0][10]+=i1->second.Seguidores;continue;}
            if(*i2=="Cars &amp; Transportation"){m[0][11]+=i1->second.Seguidores;continue;}
            if(*i2=="Dining Out"){m[0][12]+=i1->second.Seguidores;continue;}
            if(*i2=="Food &amp; Drink"){m[0][13]+=i1->second.Seguidores;continue;}
            if(*i2=="Home &amp; Garden"){m[0][14]+=i1->second.Seguidores;continue;}
            if(*i2=="Local Businesses"){m[0][15]+=i1->second.Seguidores;continue;}
            if(*i2=="Family &amp; Relationships"){m[0][16]+=i1->second.Seguidores;continue;}
            if(*i2=="News &amp; Events"){m[0][17]+=i1->second.Seguidores;continue;}
            if(*i2=="Pets"){m[0][18]+=i1->second.Seguidores;continue;}
            if(*i2=="Politics &amp; Government"){m[0][19]+=i1->second.Seguidores;continue;}
            if(*i2=="Environment"){m[0][20]++;continue;}
            if(*i2=="Society &amp; Culture"){m[0][21]+=i1->second.Seguidores;continue;}
            if(*i2=="Travel"){m[0][22]+=i1->second.Seguidores;continue;}
            if(*i2=="Computers &amp; Internet"){m[0][23]+=i1->second.Seguidores;continue;}
            if(*i2=="Pregnancy &amp; Parenting"){m[0][24]+=i1->second.Seguidores;continue;}
            if(*i2=="Yahoo Products"){m[0][25]+=i1->second.Seguidores;continue;}
        }
    }int sum=0;
    for (int i=0; i<26;i++){
        cout << m[0][i] << endl;
        sum+=m[0][i];
    }
    cout << sum << endl;
}
double Probabilidades (int v1){
    return (v1/double(650))*100;
}
void Read_Categories(std::map<string,std::set<string> > &C){
    std:: ifstream in("Categorias.txt");
    if (in.fail())  (cout << "File not found" << endl);
    string palabra;
    string _princi_word;
    while(in.good()){
        getline(in,palabra);
        if(palabra[0]!='	'){
            _princi_word=palabra;
        }
        if(palabra[0]=='	'){
            if(palabra[1]=='	'){
                continue;
            }
            C[_princi_word].insert(palabra);
        }
    }

}
std::vector<string> split(string str, char delimiter) {
  std::vector<string> internal;
  std::stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    if(tok[0]==' '){
        tok=tok.substr(1,tok.size()-1);
    }
    internal.push_back(tok);
    //cout << tok << endl;
  }

  return internal;
}
void _Entropia_Idioma(std::map <string,Datos> P){
    int _entr_idio [2][7];
    for (int i=0;i<7;i++){
        _entr_idio[0][i]=0;//español..
        _entr_idio[1][i]=0;//idioma...
    }

    for (auto i=P.begin();i!=P.end();i++){
        if(i->second.Idioma=="ESP"){
            if(i->second.Clase=="PERIODICA")_entr_idio[0][0]++;
            if(i->second.Clase=="RAFAGA")_entr_idio[0][1]++;
            if(i->second.Clase=="PERMANENTER")_entr_idio[0][2]++;
            if(i->second.Clase=="PERMANENTE-NR")_entr_idio[0][3]++;
            if(i->second.Clase=="M-RAFAGA")_entr_idio[0][4]++;
            if(i->second.Clase=="DRIFT")_entr_idio[0][5]++;
            if(i->second.Clase=="OTROS")_entr_idio[0][6]++;
        }else{
            if(i->second.Clase=="PERIODICA")_entr_idio[1][0]++;
            if(i->second.Clase=="RAFAGA")_entr_idio[1][1]++;
            if(i->second.Clase=="PERMANENTER")_entr_idio[1][2]++;
            if(i->second.Clase=="PERMANENTE-NR")_entr_idio[1][3]++;
            if(i->second.Clase=="M-RAFAGA")_entr_idio[1][4]++;
            if(i->second.Clase=="DRIFT")_entr_idio[1][5]++;
            if(i->second.Clase=="OTROS")_entr_idio[1][6]++;
        }
    }
    cout << "ENTROPIA PARA EL ESPN " << endl;
    cout << "clase PERIODICA     = " << -1*((double(_entr_idio[0][0]))/260)*log2((double(_entr_idio[0][0]))/260 ) << endl ;
    cout << "clase RAFAGA        = " << -1*((double(_entr_idio[0][1]))/260)*log2((double(_entr_idio[0][1]))/260 ) << endl ;
    cout << "clase PERMANENTER   = " << -1*((double(_entr_idio[0][2]))/260)*log2((double(_entr_idio[0][2]))/260 ) << endl ;
    cout << "clase PERMANENTE-NR = " << -1*((double(_entr_idio[0][3]))/260)*log2((double(_entr_idio[0][3]))/260 ) << endl ;
    cout << "clase M-RAFAGA      = " << -1*((double(_entr_idio[0][4]))/260)*log2((double(_entr_idio[0][4]))/260 ) << endl ;
    cout << "clase DRIFT         = " << -1*((double(_entr_idio[0][5]))/260)*log2((double(_entr_idio[0][5]))/260 ) << endl ;
    cout << "clase OTROS         = " << -1*((double(_entr_idio[0][6]))/260)*log2((double(_entr_idio[0][6]))/260 ) << endl ;
    cout << "-----------------------" << endl;
    cout << "ENTROPIA PARA EL ENG " << endl;
    cout << "clase PERIODICA     = " << -1*((double(_entr_idio[1][0]))/390)*log2((double(_entr_idio[1][0]))/390 ) << endl ;
    cout << "clase RAFAGA        = " << -1*((double(_entr_idio[1][1]))/390)*log2((double(_entr_idio[1][1]))/390 ) << endl ;
    cout << "clase PERMANENTER   = " << -1*((double(_entr_idio[1][2]))/390)*log2((double(_entr_idio[1][2]))/390 ) << endl ;
    cout << "clase PERMANENTE-NR = " << -1*((double(_entr_idio[1][3]))/390)*log2((double(_entr_idio[1][3]))/390 ) << endl ;
    cout << "clase M-RAFAGA      = " << -1*((double(_entr_idio[1][4]))/390)*log2((double(_entr_idio[1][4]))/390 ) << endl ;
    cout << "clase DRIFT         = " << -1*((double(_entr_idio[1][5]))/390)*log2((double(_entr_idio[1][5]))/390 ) << endl ;
    cout << "clase OTROS         = " << -1*((double(_entr_idio[1][6]))/390)*log2((double(_entr_idio[1][6]))/390 ) << endl ;
}


void _Entro_Categoria(std::map <string,Datos> P,int _cantidad_x_categoria[1][7]){
    int m[7][27];
    for (int i=0; i<26;i++){
        m[0][i]=0;m[1][i]=0;m[2][i]=0;m[3][i]=0;m[4][i]=0;m[5][i]=0;m[6][i]=0;
    }
    for (auto i1=P.begin();i1!=P.end();i1++){
        for(auto i2=i1->second.Categoria.begin();i2!=i1->second.Categoria.end();i2++){

            if(*i2=="Arts &amp; Humanities"){
                if(i1->second.Clase=="PERIODICA")m[0][0]++;
                if(i1->second.Clase=="RAFAGA")m[1][0]++;
                if(i1->second.Clase=="PERMANENTER")m[2][0]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][0]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][0]++;
                if(i1->second.Clase=="DRIFT")m[5][0]++;
                if(i1->second.Clase=="OTROS")m[6][0]++;
            }
            if(*i2=="Business &amp; Finance"){
                if(i1->second.Clase=="PERIODICA")m[0][1]++;
                if(i1->second.Clase=="RAFAGA")m[1][1]++;
                if(i1->second.Clase=="PERMANENTER")m[2][1]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][1]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][1]++;
                if(i1->second.Clase=="DRIFT")m[5][1]++;
                if(i1->second.Clase=="OTROS")m[6][1]++;
            }
            if(*i2=="Consumer Electronics"){
                if(i1->second.Clase=="PERIODICA")m[0][2]++;
                if(i1->second.Clase=="RAFAGA")m[1][2]++;
                if(i1->second.Clase=="PERMANENTER")m[2][2]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][2]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][2]++;
                if(i1->second.Clase=="DRIFT")m[5][2]++;
                if(i1->second.Clase=="OTROS")m[6][2]++;
            }
            if(*i2=="Education &amp; Reference"){
                if(i1->second.Clase=="PERIODICA")m[0][3]++;
                if(i1->second.Clase=="RAFAGA")m[1][3]++;
                if(i1->second.Clase=="PERMANENTER")m[2][3]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][3]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][3]++;
                if(i1->second.Clase=="DRIFT")m[5][3]++;
                if(i1->second.Clase=="OTROS")m[6][3]++;
            }
            if(*i2=="Entertainment &amp; Music"){
                if(i1->second.Clase=="PERIODICA")m[0][4]++;
                if(i1->second.Clase=="RAFAGA")m[1][4]++;
                if(i1->second.Clase=="PERMANENTER")m[2][4]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][4]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][4]++;
                if(i1->second.Clase=="DRIFT")m[5][4]++;
                if(i1->second.Clase=="OTROS")m[6][4]++;
            }
            if(*i2=="Health"){
                if(i1->second.Clase=="PERIODICA")m[0][5]++;
                if(i1->second.Clase=="RAFAGA")m[1][5]++;
                if(i1->second.Clase=="PERMANENTER")m[2][5]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][5]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][5]++;
                if(i1->second.Clase=="DRIFT")m[5][5]++;
                if(i1->second.Clase=="OTROS")m[6][5]++;
            }
            if(*i2=="Games &amp; Recreation"){
                if(i1->second.Clase=="PERIODICA")m[0][6]++;
                if(i1->second.Clase=="RAFAGA")m[1][6]++;
                if(i1->second.Clase=="PERMANENTER")m[2][6]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][6]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][6]++;
                if(i1->second.Clase=="DRIFT")m[5][6]++;
                if(i1->second.Clase=="OTROS")m[6][6]++;
            }
            if(*i2=="Science &amp; Mathematics"){
                if(i1->second.Clase=="PERIODICA")m[0][7]++;
                if(i1->second.Clase=="RAFAGA")m[1][7]++;
                if(i1->second.Clase=="PERMANENTER")m[2][7]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][7]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][7]++;
                if(i1->second.Clase=="DRIFT")m[5][7]++;
                if(i1->second.Clase=="OTROS")m[6][7]++;
            }
            if(*i2=="Beauty &amp; Style"){
                if(i1->second.Clase=="PERIODICA")m[0][8]++;
                if(i1->second.Clase=="RAFAGA")m[1][8]++;
                if(i1->second.Clase=="PERMANENTER")m[2][8]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][8]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][8]++;
                if(i1->second.Clase=="DRIFT")m[5][8]++;
                if(i1->second.Clase=="OTROS")m[6][8]++;
            }
            if(*i2=="Sports"){
                if(i1->second.Clase=="PERIODICA")m[0][9]++;
                if(i1->second.Clase=="RAFAGA")m[1][9]++;
                if(i1->second.Clase=="PERMANENTER")m[2][9]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][9]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][9]++;
                if(i1->second.Clase=="DRIFT")m[5][9]++;
                if(i1->second.Clase=="OTROS")m[6][9]++;
            }
            if(*i2=="Social Science"){
                if(i1->second.Clase=="PERIODICA")m[0][10]++;
                if(i1->second.Clase=="RAFAGA")m[1][10]++;
                if(i1->second.Clase=="PERMANENTER")m[2][10]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][10]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][10]++;
                if(i1->second.Clase=="DRIFT")m[5][10]++;
                if(i1->second.Clase=="OTROS")m[6][10]++;
            }
            if(*i2=="Cars &amp; Transportation"){
                if(i1->second.Clase=="PERIODICA")m[0][11]++;
                if(i1->second.Clase=="RAFAGA")m[1][11]++;
                if(i1->second.Clase=="PERMANENTER")m[2][11]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][11]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][11]++;
                if(i1->second.Clase=="DRIFT")m[5][11]++;
                if(i1->second.Clase=="OTROS")m[6][11]++;
            }
            if(*i2=="Dining Out"){
                if(i1->second.Clase=="PERIODICA")m[0][12]++;
                if(i1->second.Clase=="RAFAGA")m[1][12]++;
                if(i1->second.Clase=="PERMANENTER")m[2][12]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][12]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][12]++;
                if(i1->second.Clase=="DRIFT")m[5][12]++;
                if(i1->second.Clase=="OTROS")m[6][12]++;
            }
            if(*i2=="Food &amp; Drink"){
                if(i1->second.Clase=="PERIODICA")m[0][13]++;
                if(i1->second.Clase=="RAFAGA")m[1][13]++;
                if(i1->second.Clase=="PERMANENTER")m[2][13]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][13]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][13]++;
                if(i1->second.Clase=="DRIFT")m[5][13]++;
                if(i1->second.Clase=="OTROS")m[6][13]++;
            }
            if(*i2=="Home &amp; Garden"){
                if(i1->second.Clase=="PERIODICA")m[0][14]++;
                if(i1->second.Clase=="RAFAGA")m[1][14]++;
                if(i1->second.Clase=="PERMANENTER")m[2][14]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][14]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][14]++;
                if(i1->second.Clase=="DRIFT")m[5][14]++;
                if(i1->second.Clase=="OTROS")m[6][14]++;
            }
            if(*i2=="Local Businesses"){
                if(i1->second.Clase=="PERIODICA")m[0][15]++;
                if(i1->second.Clase=="RAFAGA")m[1][15]++;
                if(i1->second.Clase=="PERMANENTER")m[2][15]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][15]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][15]++;
                if(i1->second.Clase=="DRIFT")m[5][15]++;
                if(i1->second.Clase=="OTROS")m[6][15]++;
            }
            if(*i2=="Family &amp; Relationships"){
                if(i1->second.Clase=="PERIODICA")m[0][16]++;
                if(i1->second.Clase=="RAFAGA")m[1][16]++;
                if(i1->second.Clase=="PERMANENTER")m[2][16]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][16]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][16]++;
                if(i1->second.Clase=="DRIFT")m[5][16]++;
                if(i1->second.Clase=="OTROS")m[6][16]++;
            }
            if(*i2=="News &amp; Events"){
                if(i1->second.Clase=="PERIODICA")m[0][17]++;
                if(i1->second.Clase=="RAFAGA")m[1][17]++;
                if(i1->second.Clase=="PERMANENTER")m[2][17]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][17]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][17]++;
                if(i1->second.Clase=="DRIFT")m[5][17]++;
                if(i1->second.Clase=="OTROS")m[6][17]++;
            }
            if(*i2=="Pets"){
                if(i1->second.Clase=="PERIODICA")m[0][18]++;
                if(i1->second.Clase=="RAFAGA")m[1][18]++;
                if(i1->second.Clase=="PERMANENTER")m[2][18]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][18]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][18]++;
                if(i1->second.Clase=="DRIFT")m[5][18]++;
                if(i1->second.Clase=="OTROS")m[6][18]++;
            }
            if(*i2=="Politics &amp; Government"){
                if(i1->second.Clase=="PERIODICA")m[0][19]++;
                if(i1->second.Clase=="RAFAGA")m[1][19]++;
                if(i1->second.Clase=="PERMANENTER")m[2][19]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][19]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][19]++;
                if(i1->second.Clase=="DRIFT")m[5][19]++;
                if(i1->second.Clase=="OTROS")m[6][19]++;
            }
            if(*i2=="Environment"){
                if(i1->second.Clase=="PERIODICA")m[0][20]++;
                if(i1->second.Clase=="RAFAGA")m[1][20]++;
                if(i1->second.Clase=="PERMANENTER")m[2][20]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][20]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][20]++;
                if(i1->second.Clase=="DRIFT")m[5][20]++;
                if(i1->second.Clase=="OTROS")m[6][20]++;
            }
            if(*i2=="Society &amp; Culture"){
                if(i1->second.Clase=="PERIODICA")m[0][21]++;
                if(i1->second.Clase=="RAFAGA")m[1][21]++;
                if(i1->second.Clase=="PERMANENTER")m[2][21]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][21]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][21]++;
                if(i1->second.Clase=="DRIFT")m[5][21]++;
                if(i1->second.Clase=="OTROS")m[6][21]++;
            }
            if(*i2=="Travel"){
                if(i1->second.Clase=="PERIODICA")m[0][22]++;
                if(i1->second.Clase=="RAFAGA")m[1][22]++;
                if(i1->second.Clase=="PERMANENTER")m[2][22]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][22]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][22]++;
                if(i1->second.Clase=="DRIFT")m[5][22]++;
                if(i1->second.Clase=="OTROS")m[6][22]++;
            }
            if(*i2=="Computers &amp; Internet"){
                if(i1->second.Clase=="PERIODICA")m[0][23]++;
                if(i1->second.Clase=="RAFAGA")m[1][23]++;
                if(i1->second.Clase=="PERMANENTER")m[2][23]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][23]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][23]++;
                if(i1->second.Clase=="DRIFT")m[5][23]++;
                if(i1->second.Clase=="OTROS")m[6][23]++;
            }
            if(*i2=="Pregnancy &amp; Parenting"){
                if(i1->second.Clase=="PERIODICA")m[0][24]++;
                if(i1->second.Clase=="RAFAGA")m[1][24]++;
                if(i1->second.Clase=="PERMANENTER")m[2][24]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][24]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][24]++;
                if(i1->second.Clase=="DRIFT")m[5][24]++;
                if(i1->second.Clase=="OTROS")m[6][24]++;
            }
            if(*i2=="Yahoo Products"){
                if(i1->second.Clase=="PERIODICA")m[0][25]++;
                if(i1->second.Clase=="RAFAGA")m[1][25]++;
                if(i1->second.Clase=="PERMANENTER")m[2][25]++;
                if(i1->second.Clase=="PERMANENTE-NR")m[3][25]++;
                if(i1->second.Clase=="M-RAFAGA")m[4][25]++;
                if(i1->second.Clase=="DRIFT")m[5][25]++;
                if(i1->second.Clase=="OTROS")m[6][25]++;
            }
        }
    }

    double al=0.0;
    int i;
    for(i=0;i<7;i++){
        if(i==0){cout << "ENTROPIA DE LAS PERIODICA.." << endl;}
        if(i==1){cout << "ENTROPIA DE LAS RAFAGA.." << endl;}
        if(i==2){cout << "ENTROPIA DE LAS PERMANENTER.." << endl;}
        if(i==3){cout << "ENTROPIA DE LAS PERMANENTE-NR.." << endl;}
        if(i==4){cout << "ENTROPIA DE LAS M-RAFAGA.." << endl;}
        if(i==5){cout << "ENTROPIA DE LAS DRIFT.." << endl;}
        if(i==6){cout << "ENTROPIA DE LAS OTROS.." << endl;}
        for (int j=0;j<26;j++){
            if(j==0){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Arts &amp; Humanities :" <<  -1*(al)*log2(al) << endl ;
            }if(j==1){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Business &amp; Finance :" <<  -1*(al)*log2(al) << endl ;
            }if(j==2){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Consumer Electronics :" <<  -1*(al)*log2(al) << endl ;
            }if(j==3){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Education &amp; Reference :" <<  -1*(al)*log2(al) << endl ;
            }if(j==4){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Entertainment &amp; Music :" <<  -1*(al)*log2(al) << endl ;
            }if(j==5){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Health:" <<  -1*(al)*log2(al) << endl ;
            }if(j==6){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Games &amp; Recreation:" <<  -1*(al)*log2(al) << endl ;
            }if(j==7){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Science &amp; Mathematics :" <<  -1*(al)*log2(al) << endl ;
            }if(j==8){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Beauty &amp; Style :" <<  -1*(al)*log2(al) << endl ;
            }if(j==9){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Sports :" <<  -1*(al)*log2(al) << endl ;
            }if(j==10){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Social Science :" <<  -1*(al)*log2(al) << endl ;
            }if(j==11){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de  Cars &amp; Transportation:" <<  -1*(al)*log2(al) << endl ;
            }if(j==12){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Dining Out :" <<  -1*(al)*log2(al) << endl ;
            }if(j==13){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Food &amp; Drink:" <<  -1*(al)*log2(al) << endl ;
            }if(j==14){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Home &amp; Garden :" <<  -1*(al)*log2(al) << endl ;
            }if(j==15){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Local Businesses :" <<  -1*(al)*log2(al) << endl ;
            }if(j==16){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Family &amp; Relationships :" <<  -1*(al)*log2(al) << endl ;
            }if(j==17){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de News &amp; Events :" <<  -1*(al)*log2(al) << endl ;
            }if(j==18){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Pets :" <<  -1*(al)*log2(al) << endl ;
            }if(j==19){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Politics &amp; Government :" <<  -1*(al)*log2(al) << endl ;
            }if(j==20){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Environment :" <<  -1*(al)*log2(al) << endl ;
            }if(j==21){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Society &amp; Culture :" <<  -1*(al)*log2(al) << endl ;
            }if(j==22){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Travel :" <<  -1*(al)*log2(al) << endl ;
            }if(j==23){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Computers &amp; Internet :" <<  -1*(al)*log2(al) << endl ;
            }if(j==24){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Arts &amp; Humanities :" <<  -1*(al)*log2(al) << endl ;
            }if(j==25){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Pregnancy &amp; Parenting :" <<  -1*(al)*log2(al) << endl ;
            }if(j==26){
                al=((double(m[i][j]))/_cantidad_x_categoria[0][i]);
                cout << "Entropia de Yahoo Products :" <<  -1*(al)*log2(al) << endl ;
            }

        }
    }
}

int main(int argc, char *argv[]){
    Anclaje Anclaje_vs_Seguidores;
    std::map <string,Datos> Preguntas;
    int _entro_idio[1][2];//idioma
    int _entro_clase[1][7];//anclaje

    std::ifstream in("datos.csv");

    std::map<string,std::set<string> > Categorias;

    Read_Categories(Categorias);//obtengo las categorias del archivo.txt


    /*
     * Obtengo la informacion del .csv
     * */
    if (in.fail()) return (cout << "File not found" << endl) && 0;

    std::vector<std::string> row = csv_read_row(in, ',');

    while(in.good()){
        row = csv_read_row(in, ',');

        for(int i=0, leng=row.size(); i<leng; i++){

            Preguntas[row[0]].Titulo=row[1];
            Preguntas[row[0]].Cuerpo=row[2];

            std::vector<string>_Category=split(row[3], ',');
            for(int i=0;i<_Category.size();i++){
                Preguntas[row[0]].Categoria.insert(_Category[i]);
            }
            Preguntas[row[0]].Clase=row[4];
            Preguntas[row[0]].Seguidores=atoi(row[5].c_str());
            Preguntas[row[0]].Respuestas=atoi(row[6].c_str());
            Preguntas[row[0]].Idioma=row[7];

        }
    }
    in.close();

    for (int i=0;i<2;i++)
        _entro_idio[0][i]=0;
    for (int i=0;i<7;i++)
        _entro_clase[0][i]=0;

    for (auto i=Preguntas.begin();i!=Preguntas.end();i++){
        /*
        00 ESP
        01 ENG
        */
        if(i->second.Idioma=="ESP")_entro_idio[0][0]++;
        if(i->second.Idioma=="ENG")_entro_idio[0][1]++;
        /*
        00 Periodicas
        01 Rafagas
        02 Permanentes Reciclables
        03 Permanentes No-Reciclables
        04 Rafagas Multiples
        05 Modas
        06 Otras
        */
        if(i->second.Clase=="PERIODICA")_entro_clase[0][0]++;
        if(i->second.Clase=="RAFAGA")_entro_clase[0][1]++;
        if(i->second.Clase=="PERMANENTER")_entro_clase[0][2]++;
        if(i->second.Clase=="PERMANENTE-NR")_entro_clase[0][3]++;
        if(i->second.Clase=="M-RAFAGA")_entro_clase[0][4]++;
        if(i->second.Clase=="DRIFT")_entro_clase[0][5]++;
        if(i->second.Clase=="OTROS")_entro_clase[0][6]++;
    }
    cout << "PROBABILIDADES" << endl;
    cout << "PERIODICA      : " << Probabilidades(_entro_clase[0][0]) << "%" << endl;
    cout << "RAFAGA         : " << Probabilidades(_entro_clase[0][1]) << "%" << endl;
    cout << "PERMANENTER    : " << Probabilidades(_entro_clase[0][2]) << "%" << endl;
    cout << "PERMANENTE-NR  : " << Probabilidades(_entro_clase[0][3]) << "%" << endl;
    cout << "M-RAFAGA       : " << Probabilidades(_entro_clase[0][4]) <<  "%" << endl;
    cout << "DRIFT          : " << Probabilidades(_entro_clase[0][5]) << "%" << endl;
    cout << "OTROS          : " << Probabilidades(_entro_clase[0][6]) << "%" << endl;
    cout << "--------------" << endl;


    cout << "Entropia Para el IDIOMA ESP = " << -1*((double(_entro_idio[0][0]))/650)*log2((double(_entro_idio[0][0]))/650 ) << endl ;
    cout << "Entropia Para el IDIOMA ENG = " << -1*((double(_entro_idio[0][1]))/650)*log2((double(_entro_idio[0][1]))/650 ) << endl ;

    cout << "Entropia Para la clase PERIODICA     = " << -1*((double(_entro_clase[0][0]))/650)*log2((double(_entro_clase[0][0]))/650 ) << endl ;
    cout << "Entropia Para la clase RAFAGA        = " << -1*((double(_entro_clase[0][1]))/650)*log2((double(_entro_clase[0][1]))/650 ) << endl ;
    cout << "Entropia Para la clase PERMANENTER   = " << -1*((double(_entro_clase[0][2]))/650)*log2((double(_entro_clase[0][2]))/650 ) << endl ;
    cout << "Entropia Para la clase PERMANENTE-NR = " << -1*((double(_entro_clase[0][3]))/650)*log2((double(_entro_clase[0][3]))/650 ) << endl ;
    cout << "Entropia Para la clase M-RAFAGA      = " << -1*((double(_entro_clase[0][4]))/650)*log2((double(_entro_clase[0][4]))/650 ) << endl ;
    cout << "Entropia Para la clase DRIFT         = " << -1*((double(_entro_clase[0][5]))/650)*log2((double(_entro_clase[0][5]))/650 ) << endl ;
    cout << "Entropia Para la clase OTROS         = " << -1*((double(_entro_clase[0][6]))/650)*log2((double(_entro_clase[0][6]))/650 ) << endl ;
    /*

        Entropias

    */
    //por idioma...
    _Entropia_Idioma(Preguntas);
    //por categorias
    _Entro_Categoria(Preguntas,_entro_clase);


    /*
        RELACIONES....
    */
    Categorias_vs_Seguidores(Categorias,Preguntas);
    //Anclaje_vs_Seguidores(_entro_clase);

    return 0;
}

std::vector<std::string> csv_read_row(std::string &line, char delimiter)
{
    std::stringstream ss(line);
    return csv_read_row(ss, delimiter);
}

std::vector<std::string> csv_read_row(std::istream &in, char delimiter)
{
    std::stringstream ss;
    bool inquotes = false;
    std::vector<std::string> row;//relying on RVO
    while(in.good())
    {
        char c = in.get();

        if (!inquotes && c=='"') //beginquotechar
        {
            inquotes=true;
        }
        else if (inquotes && c=='"') //quotechar
        {
            if ( in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();

            }
            else //endquotechar
            {
                inquotes=false;
            }
        }
        else if (!inquotes && c==delimiter) //end of field
        {
            row.push_back( ss.str() );
            ss.str("");

        }
        else if (!inquotes && (c=='\r' || c=='\n') )
        {
            if(in.peek()=='\n') { in.get(); }
            row.push_back( ss.str() );

            return row;
        }
        else
        {
            ss << c;
        }
    }
}
