#include "MyEditDistance_c766d913.hpp"
#include <fstream>
void ReadInput(const char* fname, std::string& str1, std::string& str2)
{
  std::ifstream fin(fname);
  if(!fin.is_open()) {std::cout << fname << " not exist!\n"; return;}
  std::getline(fin, str1);
  std::getline(fin, str2);
  fin.close();
}

int main(int argc, char* argv[])
{
  std::string operations, seq1, seq2;
  ReadInput(argv[1], seq1, seq2);
  std::cout << EditDistance(seq1, seq2, operations) << "\n";
  PrintAlignment(seq1, seq2, operations);
	return 0;
}
