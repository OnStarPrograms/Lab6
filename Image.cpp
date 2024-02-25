//
// Created by lukea on 2/23/2024.
// made placehlder Class functions for now (Aiden T.)

#include "Image.h"

Image::Image(unsigned char *imageData)
{
    ImageData = imageData;
}
unsigned char* Image::getImageData()
{
    return ImageData;
}
unsigned char* Image::getPixelData()
{
    return PixelData;
}
unsigned char Image::getWidth()
{
    unsigned char width = ImageData[0];
    return width;
}
unsigned char Image::getHeight()
{
    unsigned char height = ImageData[1];
    return height;
}
void Image::setImageData(unsigned char *newData)
{
    ImageData = newData;
}