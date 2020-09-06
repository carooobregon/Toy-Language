#pragma once

#include <string>

using namespace std;

class Token{
  public:
    Token();
    Token (string, string);
    string getValue();

    void setType(string t); 
		string getType();
		void setValue(string v); 
		
  private:
    string typeStr;
    string value; 
};

Token::Token(){
  typeStr = "";
  value = "";
}

Token::Token(string t, string v){
  typeStr = t;
  value = v;
}

string Token::getValue() {
  return value;
}

void Token::setValue(string v){
  value = v;
}

string Token::getType(){
  return typeStr;
}

void Token::setType(string t){
  typeStr = t;
}