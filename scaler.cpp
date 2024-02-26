//
// Created by lukea on 2/23/2024. 
// Finally got working on Aidens machine 2/23/2024 at 7:12 pm
//

#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"
using namespace std;

bool load_file(Image &image, ConsoleGfx* bruh);

int main()
{
    int Choice;
    bool keep = true;
    bool check;
    // make instance
    ConsoleGfx* bruh = ConsoleGfx::getInstance();
    cout << "Displaying Spectrum Image:\n";
    bruh->displayImage(bruh->testRainbow);
    Image image(nullptr);

    while (keep){
        cout << "Scaler Menu\n";
        cout << "-----------\n";
        cout << "1. Load File\n";
        cout << "2. Load Test Image\n";
        cout << "3. Display Image\n";
        cout << "4. Enlarge Image\n";
        cout << "5. Shrink Image\n";
        cout << "6. Show Image Properties\n";
        cout << endl;
        cout << "Select a Menu Option: ";

        cin >> Choice;
        switch (Choice)
        {
        case 0/* constant-expression */:
            /* code */
            keep = false;
            break;
        
        case 1:
            check = load_file(image, bruh);
            if (check)
            {
                cout << "File loaded" << endl << endl;
            }
            else
            {
                cout << "Error: could not load file." << endl << endl;
            }
            break;
        case 2:
            image.setImageData(bruh->testImage);
            cout << "File loaded." << endl << endl;
            break;
        case 3:
            if (image.getImageData() != nullptr)
            {
                bruh->displayImage(image.getImageData());
                cout << endl;
            }
            else
            {
                cout << "Error no image loaded." << endl;
            }
            break;
        case 4:

            break;
            //Ill get to this later
        case 5:

            break;
            //You wanna take this?
        case 6:
            cout << "Image Dimensions: (" << (int)image.getWidth() << ", "<< (int)image.getHeight() << ")" << endl << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}

bool load_file(Image &image, ConsoleGfx* bruh)
{
    string address;
    cout << "Enter name of file to load: ";
    cin >> address;
    unsigned char* buff;
    buff = bruh->loadFile(address);
    if (buff != nullptr)
    {
        image.setImageData(buff);
        return true;
    }
    else
    {
        return false;
    }
}