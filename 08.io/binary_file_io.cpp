#include <iostream>
#include <fstream>
using namespace std;

int main(){
    const char *src_file = "./data/joro.png";
    const char *dst_file = "./data/joro.copy.png";

    ifstream fsrc(src_file, ios::in | ios::binary);
    if(!fsrc){
        cout << src_file << "open error" << endl;
        return 0;
    }

    ofstream fdst(dst_file, ios::out | ios::binary);
    if(!fdst){
        cout << dst_file << "open error" << endl;
        return 0;
    }

    int c; 
    while((c=fsrc.get())!=EOF){
        fdst.put(c);
    }
    cout << "copy " << src_file << "to " << dst_file << endl;

    fsrc.close();
    fdst.close();
    
}