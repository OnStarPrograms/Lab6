//
// Created by lukea on 2/23/2024.
// made placehlder Class functions for now (Aiden T.)

#include "Image.h"

// Debugging this, the pointers, and the references were so annoying
Image::Image(unsigned char* imageData)
{
    // set the imaeData to equal the imagedata pointer
    ImageData = imageData;
}
unsigned char* Image::getImageData()
{
    //return the pointer
    return ImageData;
}
unsigned char* Image::getPixelData()
{
    // I forgor that the pointer is based from [0-::] so 3 is actually 2
    return &ImageData[2];
}
unsigned char Image::getWidth()
{
    //value not pointer
    unsigned char width = ImageData[0];
    return width;
}
unsigned char Image::getHeight()
{
    //samesies
    unsigned char height = ImageData[1];
    return height;
}
void Image::setImageData(unsigned char* newData)
{
    //imageData = newData pointer
    // so have to safely delete the pointer
    delete ImageData;
    ImageData = newData;
}