#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_file(vector<string> &v, ifstream &fin){

    string line; // <= recomended to use string
    while(getline(fin, line)){ // <= operator bool() is overloaded
        v.push_back(line);
    }

}

void search(vector<string> &v, string &word){

    for(int i=0; i< v.size(); i++){
        int idx = v[i].find(word);
        if (idx != -1){
            cout << v[i] << endl;
        }
    }
    
}

int main(){
 
    vector<string> word_vector;
    ifstream fin("./data/words.txt");
    
    if(!fin){
        cout << "cannot open words.txt file" << endl;
        return 0;
    }

    read_file(word_vector, fin);
    fin.close();

    cout << "read words.txt file successfully" << endl;

    while(true){
        cout << "input your search word: ";
        string word;
        getline(cin, word); //<= method from std::string 

        if(word == "exit")
            break;

        search(word_vector, word);
    }

    cout << "program ends" << endl;

    return 0;

}