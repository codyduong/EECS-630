# include <iostream>
# include <vector>
# include <fstream>
# include <string>

# include "MyQuicksort_c766d913.hpp"
// # include "MyQuicksort_Template.hpp"

using namespace std;

void parseInstance(const std::string& line, std::vector<std::string> & res)
{
    int p = 0, q = 0;
    while(q < line.size())
    {
        if(line[q] ==',')
        {
            res.push_back(line.substr(p,q-p));
            p=q+1;
        }
        q++;
    }
}


int main(int argc, char* argv[])
{
  std::ifstream fin;
  std::vector<std::string> data;
  fin.open(argv[1]);	    // open file
  if (!fin.is_open())	    // fail to open
  {
      std::cout << "Cannot open the test instance file. Abort." << std::endl;
      return 0;
  }
  else
  {
    std::string line;
    while(std::getline(fin, line))
    {
      parseInstance(line,data);
    }
  }
  std::vector<int> data2;
  for(auto x : data) data2.push_back(std::stoi(x));
  PrintArray(data2);
  // sort INTEGER array in ascending order
  Quicksort(data2);
  IsSorted(data2);
  PrintArray(data2);
  // sort INTEGER array in descending order
  Quicksort(data2, true);
  IsSorted(data2, true);
  PrintArray(data2);

  return 0;
}
