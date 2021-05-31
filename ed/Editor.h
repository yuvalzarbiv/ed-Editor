#include <iostream>
#include <string>
#include <vector>
#include "Document.h"

using namespace std;

class Editor{

private:

    Document doc;
   

public:

    Editor(){
     doc = Document();
    }
    Editor(string file_Name){
        doc = Document(file_Name);
    }
    void loop();

  
};
