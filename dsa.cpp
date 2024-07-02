#include<iostream>
#include<fstream>
#define Maxlines 1000
using namespace std;

int main ()
{
    string filename;
    ifstream file;
    int array[Maxlines];

    cout << "Enter filename ";
    cin >> filename;

    file.open(filename);
    if (!file.is_open()){
        cout << "File failed to open, please try again" << endl;
        return 1;
    }

    int lines=0;
    string var;

    while (lines < Maxlines && getline(file,var)){
        array[lines] = stoi(var);
        lines++;
    }
    file.close();

    int key;
    bool found = false;

    cout << "Enter Key: ";
    cin >> key;

    for (int j=0;j<lines; j++){
        if (array[j] == key){
            found = true;
            cout << "The index of the key is: " << j << endl;

        }
    }

    if (!found){
        cout << "The element is not present" << endl;
    }
    return 0;
}