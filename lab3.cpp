#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Zehmet olmasa arrayin uzunlugunu daxil edin: \n";
    cin >> n;

    int numbers[n];
    cout << "Zehmet olmasa " << n << " qeder eded daxil edin: \n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Tekrarlanan ededler ve onlarin tekrarlanma sayi: \n";

    int saygac = 0; 
    for (int i = 0; i < n; i++) {
        int count = 1;
        if (numbers[i] != -1) { 
            for (int j = i + 1; j < n; j++) {
                if (numbers[i] == numbers[j]) {
                    count++;
                    numbers[j] = -1; 
                }
            }
            if (count > 1) {
                cout << "Eded: " << numbers[i] << " - Tekrar sayi: " << count << endl;
                saygac++; 
            }
        }
    }

    if (saygac == 0) { 
        cout << "Hec bir tekrarlanan element yoxdur.\n";
    }

    return 0;
}

