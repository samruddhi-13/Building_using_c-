#include <iostream>
#include <iomanip>
#include <ios>
using namespace std;
bool checkTheMatrix(int i, int j, int rows, int columns)
{
  bool isMatrix = false;

  int m = 1;
  for (int p = columns; p >= 1; p--)
  {
    for (int k = 1; k <= m; k++)
    {
      if (k == 1)
      {
        if (i == m && j == p)
        {
          isMatrix = true;
        }
      }
    }
    m++;
  }

  return isMatrix;
}

int main()
{
  int n;
  cout << "Enter the number of building sections: ";
  cin >> n;
  int rows = 2 * n;
  int columns = 2 * n + 2;
  int last = columns + 4;
  int lastSecond = columns + 2;
  int m = (last) / 2 + 1;
  int m1 = m + 1;

  cout << setfill(' ') << setw(m) << "/\\" << endl;
  cout << setfill(' ') << setw(m) << "||" << endl;
  cout << setfill(' ') << setw(m) << "||" << endl;
  cout << setfill(' ') << setw(m) << "--" << endl;
  cout << setfill(' ') << setw(m1) << "|++|" << endl;
  cout << setfill(' ') << setw(m1) << "----" << endl;
  cout << setfill(' ') << setw(m1) << "----" << endl;
  for (int p = 1; p <= n; p++)
  {
    int t = p;
    int rows = 2 * p;
    int columns = 2 * p + 2;
    int last = columns + 4;
    int lastSecond = columns + 2;
    for (int i = 1; i <= rows; i++)
    {
      cout << setfill(' ') << setw(m1 - 4) << " ";
      for (int j = 1; j <= columns; j++)
      {
        if (j == 1 || j == columns)
        {
          cout << "|";
        }
        //else if((i==1 && j==2)|| (i==2 && j==3) || (i==3 && j==4) || (i==4 && j==5) || (i==5 && j==6) || (i==6 && j==7) || (i==7 && j==8) || (i==8 && j==9)){
        else if (j == i + 1)
        {
          cout << "\\";
        }
        else if ((i == 1) && (j == columns - 1) || checkTheMatrix(i, j, rows, columns - 1))
        {
          cout << "/";
        }
        else
        {
          cout << ".";
        }
      }
      cout << endl;
    }

    cout << setfill(' ') << setw(m1 - 4) << "";
    for (int i = 1; i <= columns - 1; i++)
    {
      if (i == 1)
      {
        cout << "/";
      }
      if (i == columns - 1)
      {
        cout << "\\";
      }
      else
      {
        cout << "-";
      }
    }
    cout << endl;
    m1 -= 1;
  }

  cout << setw(1) << " ";
  for (int i = 1; i <= lastSecond; i++)
  {
    cout << ".";
  }
  cout << endl;
  for (int i = 1; i <= last; i++)
  {
    cout << "+";
  }
  return 0;
}
