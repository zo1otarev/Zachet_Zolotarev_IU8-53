#include "math.h"
 
#define roundf(x) floor(x + 0.5f)
 
// Золотарев Даниил ИУ8-53 Растеризация треугольника Зачет по КГ
inline void swap(int &a, int &b)
{
      int t;
      t = a;
      a = b;
      b = t;
}
 
void Traingle(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3){
      if (y2 < y1) {
            swap(y1, y2);
            swap(x1, x2);
      } 
      if (y3 < y1) {
            swap(y1, y3);
            swap(x1, x3);
      } 
      if (y2 > y3) {
            swap(y2, y3);
            swap(x2, x3); 
      }
      fixed dx13 = 0, dx12 = 0, dx23 = 0;
      if (y3 != y1) {
            dx13 = int_to_fixed(x3 - x1);
            dx13 /= y3 - y1;
      } else {
            dx13 = 0;
      }
 
      if (y2 != y1) {
            dx12 = int_to_fixed(x2 - x1);
            dx12 /= (y2 - y1);
      } else {
            dx12 = 0;
      }
 
      if (y3 != y2) {
            dx23 = int_to_fixed(x3 - x2);
            dx23 /= (y3 - y2);
      } else {
            dx23 = 0;
      }
      fixed wx1 = int_to_fixed(x1);
      fixed wx2 = wx1;
      int _dx13 = dx13;
 
      if (dx13 > dx12){
            swap(dx13, dx12);
      }
      for (int i = y1; i < y2; i++){
            for (int j = fixed_to_int(wx1); j <= fixed_to_int(wx2); j++){ 
                  SetPixel(hdc, j, i, 0);
            }
            wx1 += dx13;
            wx2 += dx12;
      }
      if (y1 == y2){
            wx1 = int_to_fixed(x1);
            wx2 = int_to_fixed(x2);
      }
      if (_dx13 < dx23)
      {
            swap(_dx13, dx23);
      }
      for (int i = y2; i <= y3; i++){
            for (int j = fixed_to_int(wx1); j <= fixed_to_int(wx2); j++){
                  SetPixel(hdc, j, i, 0);
            }
            wx1 += _dx13;
            wx2 += dx23;
      }
}