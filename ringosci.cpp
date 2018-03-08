#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int circuitStyleInput;
    int numNotGates;
    string circuitStyle;
    cout << "Enter the circuit style you want (#):\n"
            "1. European\n"
            "2. American\n" << endl;
    cin >> circuitStyleInput;
    
    if (circuitStyleInput == 1 || circuitStyleInput == 2) {
        if (circuitStyleInput == 1) {
            circuitStyle = "european";
        } else {
            circuitStyle = "american";
        }
    } else {
        while(circuitStyleInput != 1 || circuitStyleInput ==2) {
        cout << "Enter a valid circuit style" << endl;
        cin >> circuitStyleInput;
        }
    }

    cout << "Enter the number of NOT gates (odd number and more than 1):" << endl;
    cin >> numNotGates;

    if (numNotGates > 1 && numNotGates % 2 !=0) {
    ofstream myfile;
    myfile.open ("ringosci.tex");
    myfile << "\\documentclass{article}\n"
              "\\usepackage[utf8]{inputenc}\n"
              "\\usepackage[" << circuitStyle <<"]{circuitikz}\n\n"
              "\\begin{document}\n\n"
              "\\begin{figure}\n"
              "\\centering\n\n"
              "\\begin{circuitikz} \\draw\n"
              "(0,0) node[american not port] (1) {}\n"
              "(3,0) node[american not port] (2) {}\n"
              "(1.out) to (2.in);\n"
              "\\end{circuitikz}\n"
              "\\end{figure}\n"
              "\\end{document}";
    myfile.close();
    return 0;

    } else {
        while (numNotGates <= 1 || numNotGates % 2 == 0) {
        cout << "Please enter a valid number of NOT gates!\n" << endl;
        cin >> numNotGates;
        }
    }
}
