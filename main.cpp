#include <iostream>
#include <vector>

#define blue "\033[1;34m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define white "\033[1;37m"
#define reset "\033[0m"

const int height = 27;
const int width = 21;
std::vector<std::pair<int, int> > spots;
int grid[27][21] =
  {
      {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
      {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2},
      {2, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 2},
      {2, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2},
      {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2},
      {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2},
      {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
  };

void checkAllDirections(int y, int x, int tmp_y, int tmp_x, int &walls)
{
    int count = 0;
    for (tmp_y = y; tmp_y < height - 1;)
    {
        spots.push_back(std::make_pair(tmp_y, x));
        tmp_y++;
        count++;
        if ((grid[tmp_y][x] == 1) && ++walls)
            break;
        if (grid[tmp_y][x] != 2)
            grid[tmp_y][x] = 0;
    }
   
    for (tmp_y = y; tmp_y > 1;)
    {
        spots.push_back(std::make_pair(tmp_y, x));
        tmp_y--;
        count++;
        if ((grid[tmp_y][x] == 1) && ++walls)
            break;
        if (grid[tmp_y][x] != 2)
            grid[tmp_y][x] = 0;
    }

    for (tmp_x = x; tmp_x < width - 1;)
    {
        spots.push_back(std::make_pair(y, tmp_x));
        tmp_x++;
        count++;
        if ((grid[y][tmp_x] == 1) && ++walls) 
            break;
       if (grid[y][tmp_x] != 2)
            grid[y][tmp_x] = 0;
    }

    for (tmp_x = x; tmp_x > 1;)
    {
        spots.push_back(std::make_pair(y, tmp_x));
        tmp_x--;
        count++;
        if ((grid[y][tmp_x] == 1) && ++walls)
            break;
        if (grid[y][tmp_x] != 2)
            grid[y][tmp_x] = 0;
    }
}

void findClosedRooms()
{
    int walls, tmp_y, tmp_x;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (grid[y][x] == 0)
            {
                walls = 0;
                spots.clear();
                checkAllDirections(y, x, tmp_y, tmp_x, walls);
                std::vector<std::pair<int, int> >::iterator it;
                for (it = spots.begin(); it != spots.end(); ++it)
                {              
                    if (walls == 3)
                    {
                        if (it->first == 25)
                            if (grid[it->first + 1][it->second] == 2)
                                grid[it->first][it->second] = 3;
                        if (it->first == 1)
                            if (grid[it->first - 1][it->second] == 2)
                                grid[it->first][it->second] = 3;
                        if (it->second == 19)
                            if (grid[it->first][it->second + 1] == 2)
                                grid[it->first][it->second] = 3;
                        if (it->second == 1)
                            if (grid[it->first][it->second - 1] == 2)
                                grid[it->first][it->second] = 3;
                    }
                    else if (walls == 4)
                    {
                        if (grid[it->first][it->second] == 0)
                            grid[it->first][it->second] = 3;
                    }
                 }
            }
        }
    }
}

void displayResult()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (grid[y][x] == 1)
                std::cout << green << grid[y][x] << " " << reset;
            else if (grid[y][x] == 2)
                std::cout << blue << grid[y][x] << " " << reset;
            else if (grid[y][x] == 3)
                std::cout << red << grid[y][x] << " " << reset;
            else
                std::cout << white << grid[y][x] << " " << reset;
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    findClosedRooms();
    displayResult();
    return (0);
}
