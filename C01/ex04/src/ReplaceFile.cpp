#include "../incl/ReplaceFile.hpp"

Replace::Replace(char **argv)
: in_name(argv[1]), out_name(std::string(argv[1]) + ".replace"), 
  s1(argv[2]), s2(argv[3]){};

Replace::~Replace(){
  infile.close();
  outfile.close();
}

bool Replace::isRegularFile(){
    struct stat s;
    if (stat(in_name.c_str(), &s) != 0){
        perror("File status checkup fail");
        return false;
    }
    if (S_ISDIR(s.st_mode)){
        std::cerr << "Input file is a directory\n";
        return false;
    }
    if (S_ISLNK(s.st_mode)){
       std::cerr << "INput file is a symbolic link\n";
    }
    return true;
}

int Replace::ifStreamCheck(){
    if (!isRegularFile()){
        return 1;
    }
    infile.open(in_name);
    if (!infile.is_open()){
        perror("Unable to open infile");
        return 1;
    }
    if (infile.peek() == std::ifstream::traits_type::eof()){
        infile.close();
        std::cerr << "Empty File, Nothing to replace\n";
        return 1;
    }
    return 0;
};

int Replace::ofStreamCheck(){
    outfile.open(out_name);
    if (!outfile.is_open()){
        infile.close();
        perror("Unable to open outfile");
        return 1;
    }
    return 0;
};

void Replace::replaceStrings(){
    std::string line;
    while (getline(infile, line)){
      if (line == s1){
          outfile << s2 << "\n";
          continue ;
      }
      outfile << line << "\n";
    }
    if (infile.bad()){
        perror("Error while reading file");
    }
}
