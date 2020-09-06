using namespace std;

class Semantico{
  public:
    Semantico();
    
    void parseS(vector<Token>);
    void parse(vector<Token>);
  private:
    vector<Token> tokens;
    
    bool match(string, string);
	
};

Semantico::Semantico(){

}

void Semantico::parse(vector<Token> newTokens){
  tokens = newTokens;
	parseS(tokens);
}

void Semantico::parseS(vector<Token> tokens){
  bool matched = false;
  if(tokens.empty()){
    return;
  }
  
  if(tokens[0].getType() == "EOF"){
    match(tokens[0].getType(), "EOF");
    return;
  }

	else if(tokens[0].getType() == "OPERATION"){
      cout << "OPERATION" << endl;
      matched = match(tokens[1].getType(), "REGISTER");
      if(!matched){
        cout << "SEMANTIC ERROR. EXPECTED TOKEN: REGISTER. RECEIVED TOKEN: " << tokens[1].getType() << endl;
      }
      else{
        matched = match(tokens[2].getType(), "REGISTER");
        if(!matched){
          cout << "SEMANTIC ERROR. EXPECTED TOKEN: REGISTER. RECEIVED TOKEN: " << tokens[1].getType() << endl;
        }
        else{
          cout << "The expression is well formed!" << endl; 
        }
      }
  }
	else if(tokens[0].getType() == "ASSIGNMENT"){
		cout <<" ASSIGNMENT " << endl;
		matched = match(tokens[1].getType(), "REGISTER");
    if(!matched){
      matched = match(tokens[1].getType(), "INTEGER");
      if(matched){
        matched = match(tokens[2].getType(), "REGISTER");
        if(matched){
          cout << "The expression is well formed!" << endl;
        }
      }
      else{
        matched = match(tokens[2].getType(), "REGISTER");
        if(matched){
          cout << "The expression is well formed!" << endl;
        }
        else{
          cout << "SEMANTIC ERROR. EXPECTED TOKEN: REGISTER OR INTEGER. RECEIVED TOKEN: " << tokens[1].getType() << endl;
        }
      }
    }
    else{
      matched = match(tokens[2].getType(), "REGISTER");
      if(!matched){
         cout << "SEMANTIC ERROR. EXPECTED TOKEN: REGISTER. RECEIVED TOKEN: " << tokens[2].getType() << endl;
      }
      else{
        cout << "The expression is well formed!" << endl;
      }
    }
	}

}


bool Semantico:: match(string received, string expectedToken){
  if(received == expectedToken){
    tokens.erase(tokens.begin());
    return true;
  }else{
    if(tokens.empty()){
      cout<<"ERROR: Expecting \'" 
					<< expectedToken
          << "\', found nothing."
					<< endl;
    }else{
      cout<<"ERROR: Expecting \'" 
					<< expectedToken
					<< "\', found \'" 
					<< received << "\'"
					<<endl;
    }
		cout<<"The system will halt."<<endl;
		return false;
		///system.exit ????
  }
	return false;
}