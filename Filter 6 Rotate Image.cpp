#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Function to read a PPM (P3) image file into a 3D vector representing pixels
std::vector<std::vector<std::vector<int>>> readPPM(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return {};
  }

  std::string type;
  int width, height, max_val;
  file >> type >> width >> height >> max_val;

  if (type != "P3") {
    std::cerr << "Error: Unsupported image format. Only PPM (P3) is supported." << std::endl;
    return {};
  }

  std::vector<std::vector<std::vector<int>>> image(height, std::vector<std::vector<int>>(width, std::vector<int>(3)));

  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      int r, g, b;
      file >> r >> g >> b;
      image[y][x] = {r, g, b}; // Store RGB values in a vector
    }
  }

  return image;
}

// Function to write a PPM image file from a 3D vector representing pixels
bool writePPM(const std::string& filename, const std::vector<std::vector<std::vector<int>>>& image) {
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Could not open file for writing " << filename << std::endl;
    return false;
  }

  file << "P3\n";
  file << image[0].size() << " " << image.size() << "\n";
  file << 255 << "\n"; // Maximum value for RGB channels

  for (const auto& row : image) {
    for (const auto& pixel : row) {
      file << pixel[0] << " " << pixel[1] << " " << pixel[2] << "\n";
    }
  }

  return true;
}

// Function to rotate an image clockwise by a given angle
std::vector<std::vector<std::vector<int>>> rotateImage(const std::vector<std::vector<std::vector<int>>>& image, int angle) {
  if (angle % 90 != 0) {
    std::cerr << "Error: Invalid rotation angle. Only 90, 180, or 270 degrees supported." << std::endl;
    return {};
  }

  int newWidth, newHeight;
  switch (angle) {
    case 90:
      newWidth = image.size(); // Height becomes width
      newHeight = image[0].size(); // Width becomes height
      break;
    case 180:
      newWidth = image[0].size();
      newHeight = image.size();
      break;
    case 270:
      newWidth = image.size();
      newHeight = image[0].size();
      break;
  }

  std::vector<std::vector<std::vector<int>>> rotatedImage(newHeight, std::vector<std::vector<int>>(newWidth, std::vector<int>(3)));

  for (int y = 0; y < image.size(); ++y) {
    for (int x = 0; x < image[0].size(); ++x) {
      int newX, newY;
      switch (angle) {
        case 90:
          newX = y;
          newY = newWidth - x - 1; // Reverse order for horizontal access
          break;
        case 180:
          newX = newHeight - y - 1; // Reverse order for vertical access
          newY = newWidth - x - 1;
          break;
        case 270:
          newX = newHeight - y - 1;
          newY = x;
          break;
      }
      rotatedImage[newY][newX] = image[y][x]; // Copy pixel to rotated position
    }
  }

  return rotatedImage;
}
