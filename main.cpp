#include <iostream>
#include <fstream>

int solve(int N, int A, int B, int C)
{
    int* floors = new int[N];

    for (int i = 0; i < N; i++)
    {
        floors[i] = 0;
    }

    floors[0] = 1;

    for (int i = 0; i < N - 1; i++)
    {
        if (floors[i] == 1)
        {
            if (i + A < N)
                floors[i + A] = 1;
            if (i + B < N)
                floors[i + B] = 1;
            if (i + C < N)
                floors[i + C] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += floors[i];
    }

    delete[] floors;

    return result;
}

int main()
{
    int N, A, B, C;

    std::ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> N >> A >> B >> C;

        fin.close();

        int result = solve(N, A, B, C);

        std::fstream fout;
        fout.open("output.txt", std::ios::out);
        fout << result;
        fout.close();
    }

    return 0;
}