/*
To compile, run: "g++ main.cpp -std=c++11 -o main"

Ricardo Gabriel Ramirez Arriaga A01338143
Carolina Obregon Barrenechea  A01251983

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Token.h"
//#include "Lexico.h"
#include "Semantico.h"
#include "LexicoCaro.h"


using namespace std;
// ㅇㅅㅇ ㅇㅊㅇ ㅠㅡㅠ  ㅇㅗㅇ ㅎㅅㅎ ㅁㅡㅁ 
// hewwo world uwu ^_^
int main() {
    vector<string> lista;
     vector<Token> tokens;
     Token newToken;
     string linea = "";
     ifstream myFile;

     myFile.open("archivo.txt");
     do{
         getline(myFile, linea);
         lista.push_back(linea);
     } while ( linea != ";");
    
     myFile.close();
     
     for(int i = 0; i < lista.size(); i++){
         LexicoCaro myScan;
         tokens = myScan.scan(lista[i]);

         for(int j = 0; j < tokens.size(); j++){
           cout << "Token #" << j+1 << ": " << tokens[j].getType() << " " << tokens[j].getValue() << endl;
         }
         //parse tokens
     }
    return 0;
}
