#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <map>
#include <cmath>
#include <set>

using std::string;
using std::cout;
using std::endl;

std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
std::vector<std::string> csv_read_row(std::string &in, char delimiter);

struct Datos{
    string Titulo;
    string Cuerpo;
    string Categoria;
    string Clase;
    int Seguidores;
    int Respuestas;
    string Idioma;
};

/*Class Probabilidades{
    Private:
        int _perio;
        int _rafa;
        int _permanent;
        int _permanentR;
        int _m-rafa;
        int _drift;
        int _others;
    Public
        Probabilidades (int perio, int rafa, int permanent, int permanentR, int m-rafa, int drift, int others){
            _perio=perio;
            _rafa=rafa;
            _permanent=permanent;
            _permanentR=permanentR;
            _m-rafa=m-rafa;
            _drift=drift;
            _others=others;
        }
}*/
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
            //cout << _princi_word << endl;
            //cout << palabra << endl;
            C[_princi_word].insert(palabra);
        }
    }
    for (auto i1=C.begin();i1!=C.end();i1++){
            cout << i1->first << endl;
            for(auto i2=i1->second.begin(); i2!=i1->second.end();i2++){
                cout << *i2 << endl;
            }
     }
}
int main(int argc, char *argv[]){
    std::map <string,Datos> Preguntas;
    int _entro_idio[1][2];//idioma
    int _entro_clase[1][7];//anclaje
    std::ifstream in("datos.csv");

    std::map<string,std::set<string> > Categorias;

    Read_Categories(Categorias);//obtengo las categorias del archivo.txt
    /*for (auto i1=Categorias.begin();i1!=Categorias.end();i1++){
        cout << i1->first << endl;
        for(auto i2=i1->second.begin(); i2!=i1->second.end();i2++){
            cout << *i2 << endl;
        }

    }*/

    /*
     * Obtengo la informacion del .csv
     * */
    if (in.fail()) return (cout << "File not found" << endl) && 0;
        //std::vector<std::string> row1 = csv_read_row(in, ',');
        //cout << row1[3] << endl;
        std::vector<std::string> row = csv_read_row(in, ',');
    while(in.good()){
        std::vector<std::string> row = csv_read_row(in, ',');
	      //cout << "- " << row[4] << endl;
        for(int i=0, leng=row.size(); i<leng; i++){
            Preguntas[row[0]].Titulo=row[1];
            Preguntas[row[0]].Cuerpo=row[2];
            Preguntas[row[0]].Categoria=row[3];
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
