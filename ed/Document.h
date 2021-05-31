#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Document{
private:

    vector<string> Doc;
    int CurrentLine;

public:

    Document(): CurrentLine{0}{};

    Document(string file_Name){
        ifstream cin (file_Name);
        if(!cin)
        {
            std::cerr << "Cannot open the File : "<<file_Name<<std::endl;
        }
        string str;
        // Read the next line from File untill it reaches the end.
        while (getline(cin, str))
        {
            // Line contains string of length > 0 then save it in vector
            if(str.size() > 0)
                Doc.push_back(str);
        }
        //Close The File
        cin.close();
        }
 


    // goes to line (int)
    void goToLine(int lineNum);

    //skeeps (int) lines
    void skeepLines(int linesToSkeep);

    //go back (int) lines
    void goBackLines(int linesToGoBack);

    //$- goes to the last line
    void goToLastLine();

    //a- add lines after current line 
    void addLinesAfter();

    //i- adds lines before current line
    void addLinesBefore();

    //c- changes the current line for a new line
    void changeLine();

    //d- delet current line
    void deletLine();

    // /text/ searches for the string "text" in the document
    void serchString(string searchString);

    // s/old/new- replaces the old line with the new
    void switchLines (string oldLine, string newLine);

    //j- joins the current line with the next line
    void joinLines();

    // w file- write to a file
    void writeToFile(string newfile_Name);

    //q- quit
    void quit();

};



