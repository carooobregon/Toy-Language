/*
  This file contains the class Lexico which represents the lexical scanner for
  our proyect.

  Lexico.h
  
*/
#define ERROR 999
#include <sstream>
#include <string>
using namespace std;

const int transitionMatrix[4][6] = {
            {0, 1, 3, 2, 104, ERROR},
            {101, 1, ERROR, ERROR, ERROR, ERROR},
            {ERROR, ERROR, 102, ERROR, ERROR, ERROR},
            {103, ERROR, 3, ERROR, ERROR, ERROR}
            };
                                    
class Lexico{
  public:
      Lexico();
            
      int filter(char);
      void validate();
      vector<Token> tokens;
      vector<Token> scan(string curr);
};


Lexico::Lexico(){
    //cout <<""<<endl;
}

vector<Token> Lexico::scan(string curr){
  char c;
  int state, index;
  string value = "";
  Token myToken;
  state = 0;

      vector<string> result;
      vector<Token> tokens;
      stringstream ss (curr);
      string item;

      while ( ss >> item) {
          item+= " ";
          result.push_back (item);
          
      }
    
    for(int i = 0; i < result.size(); i++){
          value = result[i];
          index = 0;
          state = 0;
            do {
              c = value[index];
              cout << "(" << state << ", \'" << c << "\' => ";
              index++;
              state = transitionMatrix[state][filter(c)];
              cout << " ("<< state << ")) " << endl;
              } while(index < value.length() && state < 100);
              cout << endl;
          switch(state){
                  case 0:
                      break;
                  case 101:
                      value = value.substr(0, value.length()-1);
                      myToken.setType("INTEGER");
                      myToken.setValue(value);
                      tokens.push_back(myToken) ;
                      break;
                case ERROR:
                    //value+=c;
                    cout << "LEXICAL ERROR: the string \'" <<  value << "\' is not a valid element in the language." << endl;
                    cout << "The system will halt." << endl;
                    
                    break;
                case 102:
                    value = value.substr(0, value.length()-1);
                    if(value == "#A"|| value == "#B" || value == "#C" || "#D"){
                          myToken.setType("REGISTER");
                          myToken.setValue(value);
                          tokens.push_back(myToken) ;
                      }else{
                          cout << " LEXICAL ERROR: the string \'" << value << "\' is not a valid element in the language."<< endl;
                          cout << "The system will halt." << endl;
                          
                      }
                    break;
                  case 103:
                    value = value.substr(0, value.length()-1);
                          if(value == "SUM" || value == "SUB" || value == "MUL" || value == "DIV"){
                              myToken.setType("OPERATION");
                              myToken.setValue(value);
                              tokens.push_back(myToken) ;
                          }
                          else if(value == "MOV"){
                              myToken.setType("ASSIGNMENT");
                              myToken.setValue(value);
                              tokens.push_back(myToken) ;
                          }
                          else if(value == "#A"|| value == "#B" || value == "#C" || "#D"){
                              myToken.setType("REGISTER");
                              myToken.setValue(value);
                              tokens.push_back(myToken) ;
                          }
                          else{
                              cout << "LEXICAL ERROR: the string \'" << value << "\' is not a valid element in the language." << endl;
                              cout << "The system will halt."<< endl;
                          }
                      break;
                  case 104:
                    myToken.setType("EOF");
                    myToken.setValue("");
                    tokens.push_back(myToken) ;
                    break;
                  }
    }
                    
    return tokens;
}


    int Lexico::filter(char c){
      
        if(c == ' ' || c == '\n'||c=='\t' || c == '\0'){
            return 0;
        }
        if(c > 47 && c < 58){ // 0 - 9
            return 1;
        }
            if(c > 64 && c < 91){ // A - Z
            return 2;
        }
        if(c=='#'){
            return 3;
        }

        if(c==';'){
            return 4;
    }
    return 5;
}
