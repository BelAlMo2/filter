#include <iostream>
#include <vector>
#include "Image_Class.h" // Your custom image class header
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // stb_image header for loading images
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" // stb_image_write header for saving images

using namespace std;

// Assuming Image_Class.h defines the Image class and its methods

void addFrame(Image& image, int frameWidth, const unsigned char frameColor[3]) {
    int newWidth = image.width + 2 * frameWidth;
    int newHeight = image.height + 2 * frameWidth;
    Image framedImage(newWidth, newHeight);

    // Fill the frame with the specified color
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Check if the pixel is within the frame boundaries
            if (x < frameWidth || y < frameWidth || x >= image.width + frameWidth || y >= image.height + frameWidth) {
                for (int k = 0; k < 3; ++k) {
                    framedImage.setPixel(x, y, k, frameColor[k]);
                }
            } else {
                // Copy the pixel from the original image
                for (int k = 0; k < 3; ++k) {
                    framedImage.setPixel(x, y, k, image.getPixel(x - frameWidth, y - frameWidth, k));
                }
            }
        }
    }

    // Replace the original image with the framed image
    image = framedImage;
}

int main() {
    // Load your image using stb_image
    int width, height, channels;
    unsigned char* imgData = stbi_load("path_to_your_image.jpg", &width, &height, &channels, 0);
    if(imgData == NULL) {
        cout << "Error in loading the image" << endl;
        return -1;
    }
    Image image(width, height, imgData); // Create an Image object with the loaded data

    // Add a frame to the image
    unsigned char frameColor[3] = {255, 0, 0}; // Red color for the frame
    int frameWidth = 30; // Width of the frame
    addFrame(image, frameWidth, frameColor);

    // Save the framed image using stb_image_write
    stbi_write_jpg("framed_image.jpg", image.width, image.height, channels, image.data(), 100);

    // Free the image data
    stbi_image_free(imgData);

    return 0;
}
#include <iostream>
#include <vector>
#include "Image_Class.h" // Your custom image class header
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h" // stb_image header for loading images
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h" // stb_image_write header for saving images

using namespace std;

// Assuming Image_Class.h defines the Image class and its methods

void addFrame(Image& image, int frameWidth, const unsigned char frameColor[3]) {
    int newWidth = image.width + 2 * frameWidth;
    int newHeight = image.height + 2 * frameWidth;
    Image framedImage(newWidth, newHeight);

    // Fill the frame with the specified color
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Check if the pixel is within the frame boundaries
            if (x < frameWidth || y < frameWidth || x >= image.width + frameWidth || y >= image.height + frameWidth) {
                for (int k = 0; k < 3; ++k) {
                    framedImage.setPixel(x, y, k, frameColor[k]);
                }
            } else {
                // Copy the pixel from the original image
                for (int k = 0; k < 3; ++k) {
                    framedImage.setPixel(x, y, k, image.getPixel(x - frameWidth, y - frameWidth, k));
                }
            }
        }
    }

    // Replace the original image with the framed image
    image = framedImage;
}

int main() {
    // Load your image using stb_image
    int width, height, channels;
    unsigned char* imgData = stbi_load("path_to_your_image.jpg", &width, &height, &channels, 0);
    if(imgData == NULL) {
        cout << "Error in loading the image" << endl;
        return -1;
    }
    Image image(width, height, imgData); // Create an Image object with the loaded data

    // Add a frame to the image
    unsigned char frameColor[3] = {255, 0, 0}; // Red color for the frame
    int frameWidth = 30; // Width of the frame
    addFrame(image, frameWidth, frameColor);

    // Save the framed image using stb_image_write
    stbi_write_jpg("framed_image.jpg", image.width, image.height, channels, image.data(), 100);

    // Free the image data
    stbi_image_free(imgData);

    return 0;
}
