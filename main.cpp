#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//creates the student object
class Student {
    public:
    string name;
    string grade;
    string courses[];

    Student(string x, string y, string z[]){
        name = x;
        grade = y;
        courses = z;
    }
};

int main(){
    //gets all the students information in a csv file
    cout << "Enter the file you wish to be parsed";
    string input;
    cin >> input;

    ifstream inputFile;
    inputFile.open(input);

    //processes the file
    int numStudents;
    string line;
    
    if(inputFile.is_open()){
        while(getline(inputFile, line)){
            numStudents++;
        }
    
        string *lines = new string[numStudents];
        for(int i = 0; i < sizeof(lines); i++){
            getline(inputFile, line);
            lines[i] = line;
        }

        for(int i = 0; i < sizeof(lines); i++){
            string studentInfo[2];
            string courses[6];  //TODO make it possible to have more or less courses
            for(int j = 0; j < sizeof(lines[i]); j++){
                if(lines[i][j] == ','){
                    if(i < 2){
                        studentInfo[i] = lines[i].substr(0, j);
                    }
                    else{
                        courses[i] = lines[i].substr(0,j);
                    } 
                }
            }
            Student studentToAdd = Student(studentInfo[0], studentInfo[1], courses);


        }



    }
    inputFile.close();

    

}
