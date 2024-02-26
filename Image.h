//
// Created by lukea on 2/23/2024.
// Public and privates created by Aiden 2/23/2024

#ifndef LAB6_IMAGE_H
#define LAB6_IMAGE_H


class Image {
    public:
        Image(unsigned char* imageData);
        unsigned char* getImageData();
        unsigned char* getPixelData();
        unsigned char getWidth();
        unsigned char getHeight();
        void setImageData(unsigned char* newData);
    private:
        unsigned char* ImageData;
        unsigned char* PixelData;
};


#endif //LAB6_IMAGE_H
