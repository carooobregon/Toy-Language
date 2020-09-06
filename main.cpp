/*
To compile, run: "g++ main.cpp -std=c++11 -o main"

	Ana Carolina Arellano Alvarez   	A01650945
	Ricardo Gabriel Ramirez Arriaga 	A01338143
	Carolina Obregon Barrenechea    	A01251983
	Gabriela Corona Garza 				A01282529
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "scanner/Token.h"
#include "scanner/Lexico.h"
#include "parser/Semantico.h"

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
         Lexico myScan;
         tokens = myScan.scan(lista[i]);
        
         for(int j = 0; j < tokens.size(); j++){
           cout << "Token #" << j+1 << ": " << tokens[j].getType() << " " << tokens[j].getValue() << endl;
         }
         Semantico mySemantic;
         mySemantic.parse(tokens);
     }
    return 0;
}
