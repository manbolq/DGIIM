#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

enum Arrow { Left, Up, LeftUp, Void};

struct LengthArrow {
    int value ;
    Arrow arrow ;
};

string printArrow(Arrow &arrow) {

    switch (arrow) {
        case(Arrow::Void):
            return "";
        case(Arrow::Left):
            return "<-- " ;
        case(Arrow::LeftUp):
            return ">-- " ;
        case(Arrow::Up):
            return "/\\ " ;
        default:
            return "ERROR" ;
    }
}



void printMatrix (vector<vector<LengthArrow>> &matrix, string &cadena1, string &cadena2) {

    cout << "\t\t" ;
    for (int i=1; i<cadena2.length(); i++) 
        cout << cadena2[i] << "\t";

    cout << endl;

    for (int i=0 ; i<matrix.size(); i++) {
        cout << cadena1[i] ;
        for (int j=0; j<matrix[i].size(); j++) 
            cout << "\t" << printArrow(matrix[i][j].arrow) << matrix[i][j].value ;
        cout << endl;
    }

}

string buildSubsequence (vector<vector<LengthArrow>> &matrix, string &cadena1, string& cadena2) {

    int row_index = cadena1.size()-1 ;
    int col_index = cadena2.size()-1 ;

    LengthArrow element_to_check = matrix[row_index][col_index] ;
    bool stop = element_to_check.value == 0 ;
    string result ;

    while (!stop) {

        switch (element_to_check.arrow) {

            case (Arrow::LeftUp):
                result += cadena1[row_index] ;
                row_index -- ;
                col_index -- ;
                stop = element_to_check.value == 1 ;
                break;

            case (Arrow::Left):
                col_index -- ;
                break;

            case (Arrow::Up):
                row_index -- ;
                break ;

        }

        element_to_check = matrix[row_index][col_index] ;
    }

    reverse(result.begin(),result.end()) ;
    return result ;


}

string longest_subsequence (string &cadena1, string &cadena2) {

    vector<vector<LengthArrow>>  matrix ;

    matrix.resize(cadena1.length()) ;

    for (int i=0; i<cadena1.length(); i++)
        matrix[i].resize(cadena2.length()) ;
    
    for (int j=0; j<matrix[0].size(); j++)
        matrix[0][j].value = 0 , matrix[0][j].arrow = Arrow::Void ;
    
    for (int i=0; i<matrix.size();i++)
        matrix[i][0].value = 0 , matrix[i][0].arrow = Arrow::Void ;


    for (int i=1 ; i<matrix.size(); i++)
        for (int j=1; j<matrix[i].size(); j++) {

            if (cadena1[i] == cadena2[j]) {
                matrix[i][j].value = 1 + matrix[i-1][j-1].value ;
                matrix[i][j].arrow = Arrow::LeftUp ;
            }

            else {

                if (matrix[i][j-1].value >= matrix[i-1][j].value) {
                    matrix[i][j].value = matrix[i][j-1].value ;
                    matrix[i][j].arrow = Arrow::Left ;
                }
                else {
                    matrix[i][j].value = matrix[i-1][j].value ;
                    matrix[i][j].arrow = Arrow::Up ;
                }
            }
        } 


    printMatrix(matrix, cadena1,cadena2) ;

    return buildSubsequence(matrix,cadena1,cadena2);

}

int main() {

    string cadena1 = " " ;
    string cadena2 = " " ;

    cadena1 += "abbcdefabcdxzyccd" ;
    cadena2 += "abbcdeafbcdzxyccd" ;

    string resultado = longest_subsequence (cadena1,cadena2) ;
    cout << endl << "Subsecuencia: " << resultado ;
}

