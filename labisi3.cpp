#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void gemiYerlestir(vector<vector<int>>& grid, int gemiSayi) {
    int satir = grid.size();
    int sutun = grid[0].size();
    int gemiYerlestirilen = 0;
    
    while (gemiYerlestirilen < gemiSayi) {
        int x = rand() % satir;
        int y = rand() % sutun;
        
        
        if (grid[x][y] == 0) {
            grid[x][y] = 1;
            gemiYerlestirilen++;
        }
    }
}


void gridYazdir(const vector<vector<int>>& grid) {
    for (const auto& satir : grid) {
        for (int hucre : satir) {
            
            if (hucre == 1) {
                cout << "0 ";  
            } else {
                cout << hucre << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); 

    
    int satirSayi, sutunSayi, gemiSayi, cehdSayi;

    cout << "Satir sayini daxil edin: ";
    cin >> satirSayi;
    cout << "Sutun sayini daxil edin: ";
    cin >> sutunSayi;
    cout << "Gemi sayini daxil edin: ";
    cin >> gemiSayi;
    cout << "Cehd sayini daxil edin: ";
    cin >> cehdSayi;

    
    vector<vector<int>> grid(satirSayi, vector<int>(sutunSayi, 0));

    
    gemiYerlestir(grid, gemiSayi);

    
    cout << "Gridin baslangic durumu (gemiler gozelmeyecek):" << endl;
    gridYazdir(grid);

    int c?h?d = 0;
    int tapilanGemiler = 0;
    while (c?h?d < cehdSayi && tapilanGemiler < gemiSayi) {
        int x, y;
        cout << "Cehd #" << c?h?d + 1 << " - Koordinat daxil edin (satir sutun): ";
        cin >> x >> y;

        
        if (x >= 0 && x < satirSayi && y >= 0 && y < sutunSayi) {
            if (grid[x][y] == 1) {
                cout << "Tebrikler! Gemi tapdiniz!" << endl;
                grid[x][y] = 2; 
                tapilanGemiler++;
            } else {
                cout << "Bu yer bosdur!" << endl;
            }
        } else {
            cout << "Daxil etdiyiniz koordinatlar yanlisdir!" << endl;
        }

        c?h?d++;
    }

   
    if (tapilanGemiler == gemiSayi) {
        cout << "Tebrikler! Butun gemileri tapdiniz!" << endl;
    } else {
        cout << "Cehdler bitti. " << tapilanGemiler << " gemi tapdiniz. Uduzdunuz!" << endl;
    }

    return 0;
}

