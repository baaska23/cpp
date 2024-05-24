#include <iostream>
#include <string>
using namespace std;

class Bird {
public:
    int height;
    int weight;
    string breed;

    static const string bird_names[];

    Bird(int h, int w, const string& b){
        height = h;
        weight = w;
        breed = b;
    }
};

const string Bird::bird_names[] = {"pigeon", "chicken", "hawk", "falcon"};

int main() {
    int n = 4;
    Bird* birds[n];

    for (int i = 0; i < n; i++) {
        birds[i] = new Bird(i + 1, i + 2, Bird::bird_names[i]); 
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << "-r shuvuunii height: " << birds[i]->height 
             << ", weight: " << birds[i]->weight 
             << ", breed: " << birds[i]->breed << endl;
    }

    for (int i = 0; i < n; i++) {
        delete birds[i];
    }

    return 0;
}
