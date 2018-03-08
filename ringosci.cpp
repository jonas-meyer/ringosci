#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int circuitStyleInput;
    unsigned int numNotGates;
    string circuitStyle;
    vector<int> notGates;

    cout << "Enter the circuit style you want (#):\n"
            "1. European\n"
            "2. American" << endl;
    cin >> circuitStyleInput;
    while (circuitStyleInput != 1 && circuitStyleInput != 2) {
        cout << "Enter a valid circuit style" << endl;
        cin >> circuitStyleInput;
    }

    if (circuitStyleInput == 1) {
        circuitStyle = "european";
    } else {
        circuitStyle = "american";
    }
        
    cout << "Enter the number of NOT gates (odd number and more than 1):" << endl;
    cin >> numNotGates;

    while (numNotGates <= 1 || numNotGates % 2 == 0) { 
        cout << "Enter a valid number of NOT gates" << endl;
        cin >> numNotGates;
    }

    for (unsigned int i = 0; i != numNotGates; ++i) {
        notGates.push_back(i); 
    }

    int numTopBottom = numNotGates/(log(numNotGates + 1));
    int numRight = (numNotGates - numTopBottom*2)/2;
    int numLeft = numRight + 1;
    cout << numTopBottom << endl;
    cout << numRight << endl;

    ofstream myfile;
    myfile.open ("ringosci.tex");
    myfile << "\\documentclass{article}\n"
              "\\usepackage[utf8]{inputenc}\n"
              "\\usepackage[" << circuitStyle <<"]{circuitikz}\n\n"
              "\\begin{document}\n\n"
              "\\begin{figure}\n"
              "\\centering\n\n"
              "\\begin{circuitikz} \\draw\n";

    for (unsigned int i =1; i <= numTopBottom; ++i) {
        myfile << "("<< 2*i <<",0) node[american not port] ("<< i <<") {}\n";
    }

    for (int i =1; i <= numRight; ++i) {
        myfile << "("<< 2*(numTopBottom) <<","<< -3*(i) <<") node[american not port] ("<< numTopBottom + i <<") {}\n";
    }

    for (int i = numTopBottom, z =1; i >= 1, z <= numTopBottom; --i,++z) {
        myfile << "("<< (2*i) << "," << -4*numRight << ") node[rotate=180, american not port] ("<< numTopBottom+numRight+z <<") {}\n";
    }

    for (int i = numLeft, z =1; i>=1,z <= numLeft; --i,++z) {
        myfile << "("<< 2 <<"," << -2*i <<") node[rotate=180, american not port] ("<< numTopBottom+numRight+numTopBottom+z <<") {}\n";
    }

    for (int i = 1; i != numNotGates; ++i) {
        myfile << "("<< i <<".out) -- (" << i+1 <<".in)";
    }
    myfile <<
              "\\end{circuitikz}\n"
              "\\end{figure}\n"
              "\\end{document}\n";
    myfile.close();

}
