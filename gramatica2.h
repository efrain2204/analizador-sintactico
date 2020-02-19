
vector<vector<string>> gramatica::Primero(no_termi *item){
        vector<vector<string>> temp;
        for(int j=0;j<item->siguiente.size();j++){
            vector<string>temp2;
            if(esTerminal(item->siguiente[j][0])){
                for(int i=0;i<item->siguiente[j].size();i++){
                    if(!esTerminal(item->siguiente[j][i]))
                        break;
                    temp2.push_back(item->siguiente[j][i]);
                }
                temp.push_back(temp2);
            }
            else{
                no_termi *nuevo;
                for(int i=0;i<NoTerminales.size();i++){
                    if(NoTerminales[i]->nombre==item->siguiente[j][0]){
                        nuevo=NoTerminales[i];
                        break;
                    }
                }
                for(int i=0;i<Primero(nuevo).size();i++){
                    temp.push_back(Primero(nuevo)[i]);
                }
            }
        }
        return temp;
}

void gramatica::Primeros(){
        for(int i=0;i<NoTerminales.size();i++){
            NoTerminales[i]->first=Primero(NoTerminales[i]);
        }
}
void gramatica::imprimirPrimeros(){
        for(int i=0;i<NoTerminales.size();i++){
            cout<<NoTerminales[i]->nombre<<"::";
            for(int j=0;j<NoTerminales[i]->first.size();j++){
                for(int k=0;k<NoTerminales[i]->first[j].size();k++){
                    cout<<NoTerminales[i]->first[j][k]<<" ";
                }
                cout<<'|';
            }
            cout<<endl;
        }
    }

/*void gramatica::Siguientes(){
    inicio->sig.push_back("$");
    for(int i=0;i<NoTerminales.size();i++){
        for(int j=0;j<NoTerminales[i]->siguientes.size();j++){
            for(int k=0;k<NoTerminales[i]->siguientes[j].size()-1;k++){
                if(!esTerminal(NoTerminales[i]->siguientes[j][k])){
                    if(esTerminal(NoTerminales[i]->siguientes[j][k+1])){
                        vector<string> temp;
                        for(int q=k;q<NoTerminales[i]->siguientes[j].size();q++){
                            if(esTerminal(NoTerminales[i]->siguientes[j][q])){
                                temp.push_back(NoTerminales[i]->siguientes[j][q]);
                                k++;
                            }
                        }
                        no_termi *current;
                        for(int q=k;q<NoTerminales.size();q++){
                            if(NoTerminales[q]->nombre==NoTerminales[i]->siguientes[j][k]){
                                current=NoTerminales[q];
                            }
                        }
                        current->sig.push_back(temp);
                    }
                    else{

                    }

                }
                else{

                }
            }
        }
    }

}*/
