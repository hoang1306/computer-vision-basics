#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<vector<int>>> vectors;
    vectors.push_back({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    for (int i = 0; i < vectors.size(); i++)
    {
        for (int j = 0; j < vectors[i].size(); j++)
        {
            for (int k = 0; k < vectors[i][j].size(); k++)
            {
                cout << vectors[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}