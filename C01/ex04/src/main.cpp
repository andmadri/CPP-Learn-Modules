#include "../incl/ReplaceFile.hpp"

int main(int argc, char *argv[]){

    if (argc != 4){
        std::cerr << "Excpected Input: " << argv[0] << " <filename> <string1> <string2>\n";
        return -1;
    }
    Replace file(argv);
    if (file.ifStreamCheck()){
        return -1;
    };
    if (file.ofStreamCheck()){
        return -1;
    };
    file.replaceStrings();
    return 0;
}
