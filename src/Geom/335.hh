#include "../../include/common.hh"

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int num = distance.size();
        if (num <= 3) return false;
        int X1=0,X2=0,Y1=0,Y2=0;             // -1
        int x1=0,x2=0,y1=0,y2=0;             
        y2 = distance[0];            // 0
        x1 = - distance[1];  x2 = 0; // 1
        int is_out = 0;
        int xc,yc;
        for (int i=2; i<num; i++) {
            // cout << i%4 << ": " << X1 << ' ' << X2 << ' ' << Y1 << ' ' << Y2 << endl;
            // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << endl;
            switch (i%4)
            {
                case 2: // ↓
                {
                    yc = y2 - distance[i];
                    switch (is_out)
                    {
                        case 2:
                            if (yc>y1) {  // 6
                                y1 = yc;
                            } else {
                                return true;                                
                            }
                            break;
                        case 1:
                            if (yc > Y2) {  // 6
                                is_out++;
                                Y1 = y1;
                                y1 = yc;
                            } else if (x1<X2 && yc>y1) {
                                is_out++;
                                Y1 = y1;
                                y1 = yc;                                
                            } else {
                                return true;
                            }
                            break;
                        case 0:
                            if (yc < y1) {  // 2 6
                                Y1 = y1;
                                y1 = yc;
                            } else {
                                is_out++;
                                Y1 = y1;
                                y1 = yc;                                
                            }
                            break;
                    }
                    break;
                }        
                case 3: // →
                {
                    int xc = x1 + distance[i];
                    switch (is_out)
                    {
                        case 2:
                            if (xc < x2) {  // 7
                                x2 = xc; 
                            } else {
                                return true;
                            }
                            break;
                        case 1:
                            if (xc < X1) {  // 3 7
                                is_out++;
                                X2 = x2;
                                x2 = xc; 
                            } else if (y1>Y2 && xc<x2) {
                                is_out++;
                                X2 = x2;
                                x2 = xc;                               
                            } else {
                                return true;
                            }
                            break;
                        case 0:
                            if (xc > x2) {  // 3 7
                                X2 = x2;
                                x2 = xc;
                            } else {
                                is_out++;
                                X2 = x2;
                                x2 = xc;                                
                            }
                            break;
                    }
                    break;
                }
                case 0: // ↑
                {
                    yc = y1 + distance[i];
                    switch (is_out)
                    {
                        case 2:
                            if (yc < y2) {  // 4
                                Y2 = y2;
                                y2 = yc;
                            } else {
                                return true;                                
                            }
                            break;
                        case 1:
                            if (yc < Y1) {  // 4
                                is_out++;
                                Y2 = y2;
                                y2 = yc;
                            } else if (x2<X1 && yc<y2) {
                                is_out++;
                                Y2 = y2;
                                y2 = yc;                                
                            } else {
                                return true;
                            }
                            break;
                        case 0:
                            if (yc > y2) {  // 4
                                Y2 = y2;
                                y2 = yc;
                            } else {
                                is_out++;
                                Y2 = y2;
                                y2 = yc;                                
                            }
                            break;
                    }
                    break;
                }
                case 1: // ←
                {
                    xc = x2 - distance[i];
                    switch (is_out)
                    {
                        case 2:
                            if (xc > x1) {  // 5
                                X1 = x1;
                                x1 = xc;
                            } else {
                                return true;                                
                            }
                            break;
                        case 1:
                            if (xc > X2) {  // 5
                                is_out++;
                                X1 = x1;
                                x1 = xc;
                            } else if (y2<Y1 && xc>x1) {
                                is_out++;
                                X1 = x1;
                                x1 = xc;                              
                            } else {
                                return true;
                            }
                            break;
                        case 0:
                            if (xc < x1) {  // 5
                                X1 = x1;
                                x1 = xc;
                            } else {
                                is_out++;
                                X1 = x1;
                                x1 = xc;                                
                            }
                            break;
                    }                    
                    break;
                }    
            }
            // cout << xc << ' ' << yc << endl;
        }
        return false;
    }
};