/* 
 * File:   BMPImage.h
 * Author: Davide Aversa
 *
 * Created on April 6, 2011, 4:47 PM
 */

#ifndef BMPIMAGE_H
#define	BMPIMAGE_H

#include <string>


using namespace std;

class BMPImage {
public:
    BMPImage();
    BMPImage(const BMPImage& orig);
    virtual ~BMPImage();
    
    /**
     * Load a bitmap image.
     *
     * ARGS:
     *  * filename : Path to file.
     */
    int loadImage(string strfilename);
    
    /**
     * Get Image Data
     */
    unsigned char* getData();

    // Get height and width.
    int getX();
    int getY();
    
private:
    int sizeX;
    int sizeY;
    unsigned char *data;

};

#endif	/* BMPIMAGE_H */

