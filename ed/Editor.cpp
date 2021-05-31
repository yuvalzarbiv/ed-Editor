#include "Editor.h"
#include <ctype.h>


using namespace std;

void Editor::loop(){


    bool finish = false;
    string U_input;
    while(!finish){
        getline(cin,U_input);
        if (U_input.size() == 1){
            if(isdigit(U_input[0])){
                 doc.goToLine(stoi(U_input));
            }
            else if(U_input == "$"){
                 doc.goToLastLine();
            }
            else if (U_input == "a") { 
             doc.addLinesAfter();
        }
            else if (U_input == "i"){
              doc.addLinesBefore();
        }
            else if (U_input == "c"){ 
             doc.changeLine();
        }
            else if (U_input == "d"){ 
             doc.deletLine();
        }
            else if(U_input == "j"){
                doc.joinLines();
            }
            else if(U_input == "q"){
                 doc.quit();
            }
        }
        else if (U_input.at(0) == '+'){
            doc.skeepLines(stoi(U_input.substr(1, U_input.length())));
        }
        else if (U_input.at(0) == '-'){
            doc.goBackLines(stoi(U_input.substr(1, U_input.length())));
        }
        else if (U_input.at(0) == '/' && U_input.at(U_input.length()-1 == '/')){
           doc.serchString(U_input.substr(1,U_input.length()-2));
        }
         else if (U_input.at(0) == 's' && U_input.at(1) == '/'){
            
            string old = U_input.substr(2, U_input.find('/',3)-2);
            string new_string = U_input.substr(old.length()+3, U_input.length()-(old.length()+4));
            doc.switchLines(old,new_string);

        }
        else if (U_input.at(0) == 'w'){
             doc.writeToFile(U_input.substr(2, U_input.length()));
        }


    }


}
