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
     vector <pair <int, int> > xod; //сделаные ходы
       queue <pair <pair <int, int>, vector <pair <int, int> > > > way;
       //очередь которая содержит: текущие координаты, количество ходов, чтобы
       //добратся до даной клетки, и список всех проделаных ходов для вывода
       way.push(make_pair(make_pair(x1-1, y1-1), xod));
       //добавляем в очередь текущее положение и никакой ход
       while(!way.empty()) //пока очередь не пуста
       {
          pair <int, int> now = way.front().first; //на какой клетке находимся сейчас
          xod = way.front().second;                //какие ходы были сделаны до этого
          if(now.first == x2-1 && now.second == y2-1) break;
          //если сейчас находимся на конечной клетке - выход из цыкла
          way.pop(); // удалить текущий элемент
          for (int d = 0; d < 8; d++)
          {
                if(now.first+dx[d] < 8 && now.first+dx[d] >= 0 &&
                   now.second+dy[d] < 8 && now.second+dy[d] >= 0 &&
                   pole[now.first+dx[d]][now.second+dy[d]] == 0)
       //если координаты не превышают 8 и не меньше 0, и на этой клетке ещё не был
                   {
                   vector <pair <int, int> > xod2 = xod;
                   xod2.push_back(make_pair(now.first+dx[d], now.second+dy[d]));
                   way.push(make_pair(make_pair(now.first+dx[d], now.second+dy[d]), xod2));
       //заталкиваем в очередь пару из новых координат и проделаных ходов
                   pole[now.first+dx[d]][now.second+dy[d]] = 1;
       
                   }               
          }
       }
       cout << "Необходимое количество ходов: "<< xod.size() << endl;
       cout << "Алгоритм попадания в заданную клетку: " << endl;
       for (int i = 0; i < xod.size(); i++)
          cout << xod[i].first+1 << " " << xod[i].second+1 << endl;
      
       return 0;
    }
