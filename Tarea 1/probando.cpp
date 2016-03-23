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
    Royalty
    Travel
    Computers &amp; Internet
    Pregnancy &amp; Parenting
    Yahoo Products
    */
    int m[1][27];
    for (int i=0; i<27;i++){
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
            if(*i2=="Royalty"){m[0][22]+=i1->second.Seguidores;continue;}//no hay
            if(*i2=="Travel"){m[0][23]+=i1->second.Seguidores;continue;}
            if(*i2=="Computers &amp; Internet"){m[0][24]+=i1->second.Seguidores;continue;}
            if(*i2=="Pregnancy &amp; Parenting"){m[0][25]+=i1->second.Seguidores;continue;}
            if(*i2=="Yahoo Products"){m[0][26]+=i1->second.Seguidores;continue;}
        }
    }int sum=0;
    for (int i=0; i<27;i++){
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

            /*
            OBTENER RELACION ENTRE ANCLAJE Y SEGUIDORES......
            */
            if(row[4]=="PERIODICA")Anclaje_vs_Seguidores._perio++;
            if(row[4]=="RAFAGA")Anclaje_vs_Seguidores._rafa++;
            if(row[4]=="PERMANENTER")Anclaje_vs_Seguidores._permanent++;
            if(row[4]=="PERMANENTE-NR")Anclaje_vs_Seguidores._permanentR++;
            if(row[4]=="M-RAFAGA")Anclaje_vs_Seguidores._mrafa++;
            if(row[4]=="DRIFT")Anclaje_vs_Seguidores._drift++;
            if(row[4]=="OTROS")Anclaje_vs_Seguidores._others++;

            /*
            OBTENER CATEGORIAS VS SEGUIDORES
            */
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

    Categorias_vs_Seguidores(Categorias,Preguntas);

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
