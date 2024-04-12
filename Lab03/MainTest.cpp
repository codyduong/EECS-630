#include "MyClosestPairOfPoints_c766d913.hpp"

void loadPoints(const char* fname, std::vector<PointType>& points)
{
  std::ifstream fin(fname);
  if (!fin.is_open())	    // fail to open
  {
      std::cout << "Cannot open the test instance file " << fname << ". Abort." << std::endl;
      return;
  }
  else
  {
    while(true)
    {
      unsigned int id; float x, y;
      fin >> id; if(fin.eof()) break;
      fin >> x; if(fin.eof()) break;
      fin >> y; if(fin.eof()) break;
      points.push_back({id, x, y});
    }
  }
  fin.close();
}

int main(int argc, char* argv[]) {
  std::vector<PointType> points;
  loadPoints(argv[1], points);
  PointType ans1{0,0,0}, ans2{0,0,0};
  std::cout << ClosestPairOfPoints(points, ans1, ans2) << " ";
  std::cout << ans1.ID << ": (" << ans1.x << ", " << ans1.y << "), "
            << ans2.ID << ": (" << ans2.x << ", " << ans2.y << ")\n";
	return 0;
}
