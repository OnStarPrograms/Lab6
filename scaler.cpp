//
// Created by lukea on 2/23/2024.
//

#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"
using namespace std;

int main(){

    ConsoleGfx* bruh = ConsoleGfx::getInstance();

    cout << "Scaler Menu\n";
    cout << "-----------\n";
    cout << "1. Load File\n";
    cout << "2. Load Test Image\n";
    cout << "3. Display Image\n";
    cout << "4. Enlarge Image\n";
    cout << "5. Shrink Image\n";
    cout << "6. Show Image Properties\n";

    return 0;
}