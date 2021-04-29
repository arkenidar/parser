#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void parse_lines(istream& input_stream){
    string line,statement="";
    bool closing_statement;
    while (getline(input_stream,line)){
        closing_statement = line.back()==';';
        string spacer = statement.size()!=0 ? " " : "";
        statement += spacer + line;
        if(closing_statement){
            cout << "=> " << statement << endl;
            statement="";
        }
    }
}

void parse(int argc, char *argv[]){
    argv++; argc--;
    string skip_standard_input="-";
    bool use_standard_input=true;
    for(int i=0; i<argc; i++){
        printf("parse [%s]\n",argv[i]);
        if(argv[i]==skip_standard_input){
            use_standard_input=false;
            continue;
        }
        ifstream input_file(argv[i]);
        if(input_file.is_open()==false){
            cout << "unable to open file" << endl;
            continue;
        }
        parse_lines(input_file);
    }
    if(use_standard_input){
        cout << "parse [standard input]" << endl;
        parse_lines(cin);
    }
}

int main(int argc, char *argv[]){
    parse(argc,argv);
    return 0;
}
