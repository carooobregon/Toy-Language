/*
  This file contains the class Lexico which represents the lexical scanner for
  our proyect.

  Lexico.h
  
*/
#define ERROR 999

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
      Token tokens;
      Token scan(string curr);
};


Lexico::Lexico(){
	//cout <<""<<endl;
}

Token Lexico::scan(string curr){
  char c;
  int state, index=0;
  string value = "";
  Token myToken;
  state = 0;
	int positionOne = 0;
  int positionTwo;


  while(index < curr.length()){
    positionTwo = (int)curr.find(" ", positionOne);
    value = curr.substr(positionOne, positionTwo);
    cout << value << endl;
    do {
      c = curr[index];
      cout << "(" << state << ", \'" << c << "\' => ";
      index++;
      state = transitionMatrix[state][filter(c)];
			cout << " ("<< state << ")) ";
      
      //value+=c;
    } while(index < curr.length() && state < 100);
    
		switch(state){
			case 0:
				return myToken;
        break;
			case 101:
				myToken.setType("INTEGER");
				myToken.setValue(value);
				return myToken;
        break;
      case ERROR:
        //value+=c; 
        cout << "LEXICAL ERROR: the string \'" <<  value << "\' is not a valid element in the language." << endl;
        cout << "The system will halt." << endl;
				myToken.setType("ERROR");
				return myToken;
        break;
      case 102:
				if(value == "#A"|| value == "#B" || value == "#C" || "#D"){
					myToken.setType("REGISTER");
					myToken.setValue(value);
					return myToken;
				}else{
					cout << " LEXICAL ERROR: the string \'" << value << "\' is not a valid element in the language."<< endl;
					cout << "The system will halt." << endl;
					myToken.setType("ERROR");
					return myToken;
				}
        break;
			case 103:
					if(value == "SUM" || value == "SUB" || value == "MUL" || value == "DIV"){
						myToken.setType("OPERATION");
						myToken.setValue(value);
						return myToken;
					}
					if(value == "MOV"){
            myToken.setType("ASSIGNMENT");
					  myToken.setValue(value);
					  return myToken;
					}
          else{
            cout << "LEXICAL ERROR: the string \'" << value << "\' is not a valid element in the language." << endl;
            cout << "The system will halt."<< endl;
						myToken.setType("ERROR");
						}
            break;
          case 104:
            myToken.setType("EOF");
            myToken.setValue("");
            return myToken;
            break; 
			}
		}
	positionOne = positionTwo+1;
	return myToken;
}


int Lexico::filter(char c){
  
	if(c == ' ' || c == '\n'||c=='\t' || c == '\0'){
		cout << c << " in 0" << endl;
		return 0;
	}
	if(c > 47 && c < 58){ // 0 - 9
			cout << c << " in 1" << endl;
		return 1;
	}
		if(c > 64 && c < 91){ // A - Z
		cout << c << " in 3" << endl;
		return 2;
	}
	if(c=='#'){ 
		cout << c << " in 2" << endl;
		return 3;
	}

	if(c==';'){
		cout << c << " in 104" << endl;
		return 4;
	}
	return 5;
}
