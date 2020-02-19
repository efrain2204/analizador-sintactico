struct no_termi
{
    string nombre;
    vector<vector<string>> siguiente;
    vector<vector<string>> first;
    vector<vector<string>> sig;
    vector<vector<vector<string>>> TerminalDic;
};

class gramatica
{
    vector<no_termi*> NoTerminales;
    vector<string> terminales;
    vector<vector<string>> todo;
    vector<vector<string>> sig;
    vector<vector<string>> tokens;
    no_termi *inicio;

public:
    gramatica(){
        inicio=nullptr;
    }
    void insertar(string linea){
        bool a=false;
        string temp, temp2;
        vector<string> temp3;
        for(int i=0;i<linea.size();i++){
            if(i+1==linea.size()){
                temp+=linea[i];
                temp3.push_back(temp);
            }
            else if(linea[i]==' '){
                temp3.push_back(temp);
                temp=temp2;
            }
            else
                temp+=linea[i];
        }
        todo.push_back(temp3);
    }
    void actualizar()
    {
        for(int i=0;i<todo.size();i++){
            int a=0;
            vector<string> pri,pri2;
            for(int j=0;j<todo[i].size();j++){
                string temp;
                if(todo[i][j]=="%token:"){
                    a=1;
                    j++;
                }
                else if(todo[i][j]=="-->")
                {
                    a=2;
                    j++;
                }
                if(a==0){
                    no_termi *nuevo=new no_termi();
                    nuevo->nombre=todo[i][j];
                    NoTerminales.push_back(nuevo);
                }
                else if(a==1){
                    terminales.push_back(todo[i][j]);
                }
                else if(a==2){
                    if(j+1==todo[i].size()){
                        pri.push_back(todo[i][j]);
                        NoTerminales[i-1]->siguiente.push_back(pri);
                    }
                    else if(todo[i][j]=="|"){
                        NoTerminales[i-1]->siguiente.push_back(pri);
                        pri=pri2;
                    }
                    else{
                        pri.push_back(todo[i][j]);

                    }
                }
            }
        }
    }
    bool esTerminal(string item){
        for(int i=0;i<terminales.size();i++){
            if(item==terminales[i])
                return true;
        }
        return false;
    }
    void Primeros();
    vector<vector<string>> Primero(no_termi *item);
    void tabular1()
    {
        for(int i=0;i<terminales.size();i++){
            for(int j=0;i<NoTerminales.size();j++){

            }
        }
    }
    void imprimir(){
        for(int i=0;i<NoTerminales.size();i++){
            cout<<NoTerminales[i]->nombre<<"--> ";
            for(int j=0;j<NoTerminales[i]->siguiente.size();j++){
                for(int k=0;k<NoTerminales[i]->siguiente[j].size();k++){
                    cout<<NoTerminales[i]->siguiente[j][k]<<" ";
                }
                cout<<"| ";
            }
            cout<<endl;
        }
    }
    void imprimirPrimeros();
    //*void Siguientes();
};
