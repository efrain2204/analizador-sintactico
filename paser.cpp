#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector<string> encontrarPos(string item, vector<vector<vector<string>>> grama, string token)
{
    for(int i=0;i<grama.size();i++)
    {
        if(grama[i][0][0]==item){
            for(int j=0;j<grama[i].size();j++){
                if(grama[0][j][0]==token){
                    return grama[i][j];
                }
            }
        }
    }
}
void imprimir(vector<string> item){
    for(int i=0;i<item.size();i++)
        cout<<item[i]<<" ";
}

int main()
{

        vector<vector<vector<string>>> grama = {
        {{""}  , {"id"      }      , {":"    }     , {"int"  }     , {","    }     , {"pointer"}    , {"$"    }      },
        {{"S"} , {"L",":","T","S'"}, {"error","S"} , {"error","S"} , {"error","S"} , {"error","S"}  , {"error","S"}  },
        {{"S'"}, {"L",":","T","S'"}, {"error","S'"}, {"error","S'"}, {"error","S'"}, {"error","S'"} , {" "    }      },
        {{"L"} , {"id","L'"}       , {"error","L"} , {"error","L"} , {"error","L"} , {"error","L"}  , {"error","L"}  },
        {{"L'"}, {"error","L'"}    , {" "     }    , {"error","L'"}, {",", "L"  }  , {"error","L'"} , {"error","L'"} },
        {{"T"} , {"error","T"}     , {"error","T"} , {"int"  }     , {"error","T"} , {"pointer","T"}, {"error","T"}  }
        };
        vector<string> tokens={"id",":","int",",","pointer"};
        vector<string> NoTerminales={"S","S'","L","L'","T"};
        vector<string> prueba={"id", ",", ":", "id", ":", "pointer", "pointer", "int", "$"};
        vector<string> ini={"$","S"};
        bool a=true;
        while(prueba.size()>0)
        {
            imprimir(ini);
            cout<<"\t\t";
            imprimir(prueba);
            cout<<endl;
            vector<string> j;
            j=encontrarPos(ini[ini.size()-1],grama, prueba[0]);
            ini.pop_back();
            for(int i=j.size()-1;i>=0;i--){
                if(j[i]!=" ")
                    ini.push_back(j[i]);
            }
            if(ini[ini.size()-1]==prueba[0]){
                if(ini[ini.size()-1]=="$" && prueba[0]=="$" && a){
                    cout<<"__________"<<endl;
                    cout<<"|ACEPTADO|"<<endl;
                    cout<<"__________"<<endl;
                    break;
                }
                imprimir(ini);
                cout<<"\t\t";
                imprimir(prueba);
                cout<<endl;
                prueba.erase(prueba.begin());
                ini.pop_back();
            }
            else if(ini[ini.size()-1]=="error"){
                a=false;
                cout<<"error en: "<<prueba[0]<<endl;
                prueba.erase(prueba.begin());
                ini.pop_back();
            }
        }

        return 0;
}
