#include "Document.h"


// goes to line (int)
   void Document::goToLine(int lineNum){

        CurrentLine = lineNum-1;
        cout<< Doc.at(CurrentLine)<< endl;
     
    }
    

    //skeeps (int) lines
    void Document::skeepLines(int linesToSkeep){
        if(CurrentLine + linesToSkeep > Doc.size()){
            cout<< "?"<< endl;
        }
        else{
            CurrentLine += linesToSkeep;
            cout<< Doc.at(CurrentLine)<< endl;
        }
    }

    //go back (int) lines
    void Document::goBackLines(int linesToGoBack){
         if(CurrentLine + linesToGoBack < 0){
            cout<< "?"<< endl;
        }
        else{
            CurrentLine -= linesToGoBack;
            cout<< Doc.at(CurrentLine)<< endl;
        }
    }

    //$- goes to the last line
    void Document::goToLastLine(){
        CurrentLine = Doc.size()-1;
        cout<< Doc.at(CurrentLine)<< endl;

    }

    //a- add lines after current line 
    void Document::addLinesAfter(){
        string line = "";
        getline(cin,line);
       
        while(line != "."){
            auto iter = Doc.begin()+CurrentLine;
            Doc.insert(iter, line);
            CurrentLine++;
            getline(cin,line);
        }
       
    }

    //i- adds lines before current line
    void Document::addLinesBefore(){

    
        vector<string>::iterator it;
        int location = CurrentLine;
        while(true){
            it=Doc.begin()+(CurrentLine);
            string temp;
           //need lines and with empty lines;
            getline(cin,temp);
            if(!temp.compare(".")) break;
            Doc.insert(it++,temp);
            CurrentLine++;
        }
       
       
    }

    //c- changes the current line for a new line
    void Document::changeLine(){
        string newLine = "";
        getline(cin, newLine);
        Doc[CurrentLine] = newLine;
        
    }

    //d- delet current line
    void Document::deletLine(){
        auto iter = Doc.begin() + CurrentLine;
        Doc.erase(iter);
        CurrentLine--;
    }

    // /text/ searches for the string "text" in the document
    void Document::serchString(string searchString){
     
        bool found = false;
        int start_index = CurrentLine;
        for(int i = start_index+1; i<= Doc.size()-1 ; i++)
        {
            if(Doc.at(i).find(searchString) != string::npos){
                CurrentLine = i;
                found = true;
              
                cout<<Doc.at(CurrentLine)<<endl;
                  break;
            }
        }
         if(!found){
            for(int i = 0; i<= start_index; i++){
                if(Doc.at(i).find(searchString) != string::npos){
                    CurrentLine = i;
                    found = true;
                   
                    cout<<Doc.at(CurrentLine)<<endl;
                     break;
                }
            }
        }
         
      }  
  
    // s/old/new- replaces the old line with the new
    void Document::switchLines (string oldLine, string newLine){
        int is_exist= Doc.at(CurrentLine).find(oldLine);
       
        if(is_exist!= string::npos){
            Doc.at(CurrentLine).replace(is_exist,oldLine.size(),newLine);
        }
       else{
            cout << "no such string found\n" ;
        }
        
    }

    //j- joins the current line with the next line
    void Document::joinLines(){
        Doc.at(CurrentLine) += Doc.at(CurrentLine+1);
        Doc.erase(Doc.begin()+ CurrentLine+1);
    
    }

    // w file- write to a file
    void Document::writeToFile(string newFileName){
        ofstream file;
	    file.open(newFileName);
	    for(int i = 0;i < Doc.size(); ++i){
	    	file<< Doc[i]<< endl;
	    }
	    file.close();
    }

    //q- quit
    void Document::quit(){
         exit(0);
    }

