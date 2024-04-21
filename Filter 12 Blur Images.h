#include <iostream>
#include <vector>
#include "Image_Class.h" // Make sure this class supports getting and setting pixels

using namespace std;

// Function to apply a box blur on an image
void applyBoxBlur(Image& image) {
    // Create a copy of the original image to store the blurred version
    Image blurredImage = image;

    // Define the size of the blur box
    int blurSize = 3;

    // Iterate over each pixel in the image
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            int redTotal = 0, greenTotal = 0, blueTotal = 0;
            int count = 0;

            // Iterate over the box surrounding the current pixel
            for (int ky = -blurSize; ky <= blurSize; ++ky) {
                for (int kx = -blurSize; kx <= blurSize; ++kx) {
                    int currentX = x + kx;
                    int currentY = y + ky;

                    // Check if the current position is within the image boundaries
                    if (currentX >= 0 && currentX < image.width && currentY >= 0 && currentY < image.height) {
                        unsigned char red = image.getPixel(currentX, currentY, 0);
                        unsigned char green = image.getPixel(currentX, currentY, 1);
                        unsigned char blue = image.getPixel(currentX, currentY, 2);

                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                        count++;
                    }
                }
            }

            // Calculate the average color value for the blur box
            unsigned char redAverage = redTotal / count;
            unsigned char greenAverage = greenTotal / count;
            unsigned char blueAverage = blueTotal / count;

            // Set the blurred pixel color
            blurredImage.setPixel(x, y, 0, redAverage);
            blurredImage.setPixel(x, y, 1, greenAverage);
            blurredImage.setPixel(x, y, 2, blueAverage);
        }
    }

    // Replace the original image with the blurred image
    image = blurredImage;
}

int main() {
    // Load your image here
    // ...

    // Apply the blur filter to the image
    applyBoxBlur(image);

    // Save the blurred image or display it
    // ...

    return 0;
}
