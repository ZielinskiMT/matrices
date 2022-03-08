#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

#include "matrix.h"


Matrix char2matrix(char * argv);


int main(int argc, char **argv){

    const char * info = "Invalid number of arguments\nUse:\n   matrices matrix_A matrix_B operator\n matrix definition format: \" row_values ; row_values; ... last_row_values\"\n operator: + addition, - subtraction, x - multiplication\n";

    if(argc != 4){
        std::cout << info;
        return -1;
    }

    /* get matrices */
    Matrix A = char2matrix(argv[1]);
    Matrix B = char2matrix(argv[2]);

    std::cout << "A = \n" << A << "\n";
    std::cout << "B = \n" << B << "\n";
    /* operation */
    switch (argv[3][0])
    {
    case '+':
        std::cout << "A+B = \n" << A + B << "\n";
        break;

    case '-':
        std::cout << "A-B = \n" << A - B << "\n";   
        break;

    case 'x':
        std::cout << "AxB = \n" << A * B << "\n";   
        break;
    
    default:
        std::cout << info;
        return -1;
    }
    return 0;
}


Matrix char2matrix(char * argv){

    std::string arg(argv);
    /* regexes to check the string */
    std::regex const regx("^[[:space:]]*(((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?)(([[:space:]]|;[[:space:]]+)(((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?))+$");
    std::regex const numregex("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
    if(std::regex_match(arg, regx) == false)    /*  check if matrix string format is correct */
        throw std::invalid_argument("char2matrix(arg): arg does not contain matrix or its format is faulty");

    int rows = std::count(arg.begin(), arg.end(), ';') + 1; /* get number of rows */
    std::ptrdiff_t cols(std::distance(std::sregex_iterator(arg.begin(), arg.end(), numregex), /* get number of all values */
                                            std::sregex_iterator()));

    if((cols % rows) > 0){
        throw std::invalid_argument("char2matrix(arg): arg does not contain matrix or its format is faulty");
    }

    cols /= rows;
    /* read data from matrixstring */
    Matrix m_matrix(rows, static_cast<int>(cols));  

    std::stringstream ss(arg);
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            ss >> m_matrix[r * cols + c];
        }
        char dump;
        ss >> dump;
    }

    return std::move(m_matrix);
}