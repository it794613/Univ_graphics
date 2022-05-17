#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector <int> x_cor;
vector <int> y_cor;
int x1=0;
int y1=0;
int x2=0;
int y2=0;

void midPoint(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
	int dy = y2 - y1;

    if(dy<=dx){
	    int p = dy - (dx/2);
	    int x = x1, y = y1;
        x_cor.push_back(x);
        y_cor.push_back(y);
	    cout << x << "," << y << "\n";

        while (x < x2){
            x++;

            if (p < 0){
                p = p + dy;
            }
            else{
                p += (dy - dx);
                y++;
            }
            x_cor.push_back(x);
            y_cor.push_back(y);
            cout << x << "," << y << "\n";

        }
    }
    else if(dx<dy){
        int p = dx - (dy/2);
        int x = x1, y = y1;

        x_cor.push_back(x);
        y_cor.push_back(y);
        cout << x << "," << y << "\n";


        while (y < y2){
            y++;
            if (p < 0){
                p = p + dx;
            }
            else{
                p += (dx - dy);
                x++;
            }
            x_cor.push_back(x);
            y_cor.push_back(y);            
            cout << x << "," << y << "\n";

        }
    }
}

void translation(int a, int b){
    int size = x_cor.size();
    int ee=0;
    while(ee!=size){
        cout << x_cor.front() + a << ',' << y_cor.front() + b << endl;
        y_cor.erase(y_cor.begin());
        x_cor.erase(x_cor.begin());
        size++;
    }
}

int main()
{
    int i=0, j=0;
    cout << "enter x1, y1 : " << endl;
    cin >> x1 >> y1;
    cout << "enter x2, y2 : " << endl;
    cin >> x2 >> y2;
    cout << "selected x,y pixel" << endl;
	midPoint(x1, y1, x2, y2);
	cout << "enter translation x,y : " << endl;
    cin >> i >> j;
    cout << "translated x,y " << endl;
    translation(i,j);
    return 0;
}
