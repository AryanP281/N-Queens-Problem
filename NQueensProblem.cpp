// NQueensProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

std::vector<char> Solve(int currentQueen, int n, std::vector<char> board);
bool IsSafe(int row, int col, int n,std::vector<char>& board);

int main()
{
    int n = 4;
    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::vector<char> board;
    for (int a = 0; a < n*n; ++a)
    {
        board.push_back(0);
    }
    
    std::vector<char> res = Solve(0, n, board);

    //Displaying the solution
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (res[row * n + col] == 0)
                std::cout << "| ";
            else
                std::cout << "|Q";
        }
        std::cout << "|\n";
    }
}

std::vector<char> Solve(int currentQueen, int n, std::vector<char> board)
{
    //Returning the solution as all the queens have been placed
    if (currentQueen == n)
        return board;

    //Finding ideal location for the next queen
    for (int a = 0; a < n; ++a)
    {
        if (IsSafe(currentQueen, a, n, board))
        {
            board[currentQueen * n + a] = 1;
            std::vector<char> res = Solve(currentQueen + 1, n, board);
            if (res.size() != 0)
                return res;
            board[currentQueen * n + a] = 0;
        }
    }

    //Returning empty vector as no solution is found
    return std::vector<char>();
}

bool IsSafe(int row, int col, int n, std::vector<char>& board)
{

    //Checking if column is safe
    for (int r = 0; r < row; ++r)
    {
        if (board[r * n + col] == 1)
            return false;
    }

    //Checking if upper-left diagonal is safe
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c)
    {
        if (board[r*n + c] == 1)
            return false;
    }

    //Checking if upper-right diagonal is safe
    for (int r = row - 1, c = col + 1; r >= 0 && c < n; --r, ++c)
    {
        if (board[r * n + c] == 1)
            return false;
    }

    return true;
}