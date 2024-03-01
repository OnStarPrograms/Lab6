//
// Created by lukea on 2/23/2024. 
// Finally got working on Aidens machine 2/23/2024 at 7:12 pm
// programming by Aiden
//
// This was Painful

#include <iostream>
#include "ConsoleGfx.h"
#include "Image.h"
using namespace std;

bool load_file(Image &image, ConsoleGfx* bruh);
unsigned char *scaledImage(unsigned char *imageData, int orders);

int main()
{
    int Choice;
    bool keep = true;
    bool check;
    // make instance
    ConsoleGfx* bruh = ConsoleGfx::getInstance();

    // initialize with a nullptr for the Error checking
    Image image(nullptr);

    cout << "Welcome to the Image Scaler!" << endl << endl;
    cout << "Displaying Spectrum Image:\n";
    bruh->displayImage(bruh->testRainbow);

    // The main loop
    while (keep){
        cout << "\nScaler Menu\n";
        cout << "-----------\n";
        cout << "0. Exit\n";
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
            // set the flag to stop the while loop and break the switch case
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
                // attempts to display the image safely
                bruh->displayImage(image.getImageData());
                cout << endl;
            }
            else
            {
                cout << "Error no image loaded." << endl;
            }
            break;
        case 4:
        {
            // Image enlargment

            // Size
            // Have data string pointer
            // orginal char array, break it down into 2d array
            // expand the width to a max of 16
            // expand the height to a max of 16
            // add up to 4 to width and height  

            // this was created when I had no clue what I was supposed to do
            // I still have no clue what I am supposed to do
            // but its not this ^

            int choice;
            cout << "Enter orders of magnatude for enlargement: ";
            cin >> choice;
            if (choice > 4 || choice < -4)
            {
                //add some error
                cout << "Hello"; 
            }
            else
            {
                //crazy that this is all in one line
                image.setImageData(scaledImage(image.getImageData(), choice+1));
            }

            break;
            //Ill get to this later
        }
        case 5:
            // Image Reducer
            cout << "Image Reducer";
            break;
            //You wanna take this?


        case 6:
            //fix six to give an error (Fixed)
            // Pull and print image.width and height in a human readable format
            if (image.getImageData() != nullptr)
            {
                cout << "Image Dimensions: (" << (int)image.getWidth() << ", "<< (int)image.getHeight() << ")" << endl << endl;
            }
            else
            {
                cout << "Error: no image loaded." << endl;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

bool load_file(Image &image, ConsoleGfx* bruh)
{
    //pull file path -> fileRead() -> add the file data to image -> return if it was a success
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

unsigned char *scaledImage(unsigned char *imageData, int orders)
{
    // bruh please forgive the comments designing this scaler, I have gone through so many iterations that there are old comments
    unsigned char *NewImage = nullptr;
    unsigned char *NewestImage = nullptr;
    int widthd = (int)imageData[0];
    int heightd = (int)imageData[1];
    // NewImage = new char[length];
    NewImage = new unsigned char[(widthd*orders)*(heightd*orders)];
    NewestImage = new unsigned char[(widthd*orders)*(heightd*orders)];
    if (orders > 0)
    {
        //Enlarge

        // This checks on if its above 256
        while (widthd*orders >256 || heightd*orders>256)
        {
            orders -= 1;
        }
        
        int track = 2;
        // remind me to turn the i = 2 into i = 0 when Im done with the code
        for (int i = 0; i < widthd*orders*heightd*orders; i+=orders)
        {
            for (int j = 0; j < orders; j++)
            {
                NewImage[i+j] = imageData[track];
            }
            track++;
        }
        //Must build a line builder for the height maybe do:
        /*

        take the hight*order (:D)
        then create a new char array to signify the current row (:D)
        then copy that into a newer char array the amount of time order occurs
        return the newer array
        
        */
        unsigned char* Row = new unsigned char[widthd*orders];

        // comment here to design row tracking thingy
        // yes Im designing shut up
        // please forgive my previous comment even designnig I failed miserably
        int basetrack = 0;
        int arrTrack = 0;
        for (int j = 0; j < heightd; j++)
        {
            for (int i = 0; i < widthd*orders; i++)
            {
                    //This Row is holding a current row of the image
                    // need to figure out a way to manipulate and multiply the row into a char[arr]
                Row[i] = NewImage[basetrack];
                basetrack++;
            }
            for (int i = 0; i < widthd*orders*orders; i++)
            {
                    //This should build the current row to the multiplicity of orders

                    // normal if we are not on the 1st row cause 1st row has the width and height in [0] and [1]
                    //
                    // Basically the way its running we lose [0] and [1] so this way we get [0] and [1] back
                    if (arrTrack == 0)
                    {
                        NewestImage[arrTrack] = Row[i%(widthd*orders)];
                        arrTrack++;
                        NewestImage[arrTrack] = Row[i%(widthd*orders)];
                        arrTrack++;
                    }

                    //Idk why I chose to put this there, but it works so dont touch it
                    if (j == 0 && (i%(widthd*orders) == 0 || i%(widthd*orders) == 1) && i > 0)
                    {
                        i+=2;
                        NewestImage[arrTrack] = Row[i%(widthd*orders)];
                        i-=2;
                    }

                    // normal setup
                    else
                    {
                        NewestImage[arrTrack] = Row[i%(widthd*orders)];
                    }

                    
                    arrTrack ++;
                    // Checks if this is the first multiplicity of the first row
                    // else if (i == 0)
                    // {
                    //     Orders_Row[i*widthd+k] = Row[k];
                    // }
                    // // if this isnt the first multiplicity then we do some weird consolodation shit
                    // else
                    // {
                    //     if(k+2 <= widthd*orders)
                    //     {
                    //         Orders_Row[i*widthd+k] = Row[k+2];
                    //     }
                    // }
                // }
            }
            // REMIND ME TO UNALLOCATE SPACE
            // maybe 
                /*
            for(int i = basetrack; i < basetrack+orders; i++)
            {
                ./Unimplimented ROW adding code with multiplicity of orders

                basetrack += width;
            }
                
                */ 
        }
        delete NewImage;

        // New Goal, in the orders[all] - 1 , take the last value and put it to front and push everything back.
        // Get this done then Im done :D
        // Edit: Nvrm I got it fixed using programming voodoo 
        NewestImage[0] = (unsigned char)(widthd*orders);
        NewestImage[1] = (unsigned char)(heightd*orders);
        return NewestImage;
    }
    else
    {
        //de-enlarge
        while((widthd+orders)*(heightd+orders)<1)
        {
            orders += 1;
        }
        ;
    }
    return NewestImage;
}