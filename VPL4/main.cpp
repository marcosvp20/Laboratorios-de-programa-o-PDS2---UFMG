#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    string palavra;
    map<string, int> m;
    string chave;
    int t;
    int aux = 0;

    while (cin >> palavra){
        m[palavra]++;
        if(m[palavra] > aux ){
            aux = m[palavra];
            chave = palavra;
        }
    }
    cout << chave;
    return 0;
}