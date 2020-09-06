/*

using namespace std;

class Semantico{
  public:
    Semantico();
    
  private:
    void parse(vector<Token>);
    void parseS(vector<Token>);
    bool match(vector<Token>, Token t);
};

Semantico::Semantico(){

}

void Semantico::(vector<Token> tokens){
	parseS(tokens);
	cout<<"The input is a well formed expresssion."<<endl;
}

void Semantico::parseS(vector<Token> tokens){
  if(tokens.isEmpty()){
    cout << "SYNTACTIC ERROR: Expecting a token, found nothing." << endl;
    cout << "The system will halt." << endl;
    return;
  }
  
  if(tokens[0].getType() == eof){
    Token eof(Type.eof, ";");
    match(token, eof);
    break;
  }

  switch(tokens[0].getType()){
    case Operation:
        Token op(Type.eof, ";");
      cout << "OPERATION" << endl;
      match(tokens, )
  }

}


bool Semantico:: match(vector<Token> tokens,Token expectedToken){
  if(!tokens.empty() && tokens[0] == expectedToken ){
    tokens.erase(tokens.begin());
    return true;
  }else{
    if(tokens.empty()){
      cout<<"ERROR: Expecting \'" 
					<< expectedToken.getType()
          << "\', found nothing."
					<< endl;
    }else{
      cout<<"ERROR: Expecting \'" 
					<< expectedToken.getType() 
					<< "\', found \'" 
					<<tokens.getValue() << "\'");
    }
		cout<<"The system will halt."<<endl;
		return;
		///system.exit ????
  }
	return false;
}

*/