#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std;

void DoRandomSeed()
{
    srand(time(NULL));
    float r = rand();
    srand(r);
}

int main()
{
    int step = 1;
    const int len = 20;
    const int height = 30;
    string grid[len][height] = {};
    int rTime = 0;
    int bonusCount = 12;
    int debonus = 20;

    cout << "Bonus - recomend 12" << endl;
    cin >> bonusCount;
    cout << "Debuff - recomend 20" << endl;
    cin >> debonus;

    DoRandomSeed();

    while (true)
    {
        cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "step " << step << "\n" << "\n" << "\n" << "\n";
        for (int x = 0; x < len; x++)
        {
            for (int y = 0; y < height; y++)
            {
                if (rTime == 0)
                {
                    int random = rand() % 25;
                    grid[x][y] = (random == 0) ? "[@]" : " ";
                }
                if (grid[x][y] != "[@]")
                {
                    grid[x][y] = " ";
                }
                cout << grid[x][y];
            }
            cout << endl;
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
        for (int x = 1; x < len - 1; x++)
        {
            for (int y = 1; y < height - 1; y++)
            {
                if (grid[x + 1][y] == " " && grid[x - 1][y] == " " && grid[x][y + 1] == " " && grid[x][y - 1] == " " &&
                    grid[x + 1][y + 1] == " " && grid[x + 1][y - 1] == " " && grid[x - 1][y + 1] == " " && grid[x - 1][y - 1] == " ")
                {
                    grid[x][y] = " ";
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {
            cout << endl;
        }

        for (int i = 0; i < bonusCount; i++)
        {
            int rX = rand() % len;
            int rY = rand() % height;
            grid[rX][rY] = "[@]";
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        for (int i = 0; i < debonus; i++)
        {
            int rX = rand() % len;
            int rY = rand() % height;
            grid[rX][rY] = " ";
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        rTime = 1;
        step++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    cin.sync();
    cin.get();
    return 0;
}