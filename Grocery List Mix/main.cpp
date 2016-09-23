#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    /*
    Jesus Alatorre A00819508
    Grocery List Access Exercise: Goal is to select different grocery lists and select items in them to form one final grocery list.
    */
    string response;
    string filename;
    string line;
    ifstream input;
    ofstream output;
    int num, pos;

    output.open("mylist.txt");

    while (response!="E"&&response!="e"){
    cout << "Please select a number from the following product types to browse: " <<  endl << "[1] Fruits - [2] Vegetables - [3] Deli - [E] Finish List" << endl;
    cin >> response;

    if(response=="1"||response=="2"||response=="3"){

        filename="list"+response+".txt";

        input.open(filename.c_str());


        while (!input.eof()){
            getline(input, line);
            cout << line << endl;
        }
        input.close();

        cout << "Select option numbers from the list, enter 0 (zero) to quit this list: " << endl;
        num=1;



        while (num!=0){
            input.open(filename.c_str());
            cin >> num;
            for (int i=0; i<num; i++){
                getline(input, line);
                if (input.eof()){
                    cout << "Option not available - please try again." << endl;
                    input.close();
                    break;
                }
                if (num==(i+1)){
                    output << line << endl;
                    cout << line << " added to list." << endl;
                    input.close();
                }

            }
        }

        input.close();

    }

    else if(response!="E"&&response!="e"){
        cout << "Specified grocery list not found - Please try again." << endl;
    }

    }

    output.close();



    return 0;
}
