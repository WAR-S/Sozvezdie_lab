    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;
     
    const int dx[] = {-2, -2, 2, 2, 1, -1, 1, -1};
    const int dy[] = {-1, 1, -1, 1, 2, -2, -2, 2};
    
    int main()
    {
       bool pole[8][8]; // доска
     
       for (int i = 0; i < 8; i++)
          for (int j = 0; j < 8; j++)
                pole[i][j] = 0;             // заполняем доску нулями
       int x1, y1;                          // координаты начальной позиции коня
       cin >> x1 >> y1;                  
       pole[x1-1][y1-1] = 1;      //получить координаты и поставить на доске 1
       int x2, y2;                // координаты конечной позиции
       cin >> x2 >> y2;
     
      
       return 0;
    }
