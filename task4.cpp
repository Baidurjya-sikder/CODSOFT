#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main() {
    // Load an image
    Mat originalImage = imread("input.jpg");

    if (originalImage.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    while (true) {
        cout << "Image Processing Menu:" << endl;
        cout << "1. Resize" << endl;
        cout << "2. Crop" << endl;
        cout << "3. Apply Filter" << endl;
        cout << "4. Save Image" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newWidth, newHeight;
                cout << "Enter new width: ";
                cin >> newWidth;
                cout << "Enter new height: ";
                cin >> newHeight;
                resize(originalImage, originalImage, Size(newWidth, newHeight));
                break;
            }
            case 2: {
                int x, y, width, height;
                cout << "Enter x-coordinate of top-left corner: ";
                cin >> x;
                cout << "Enter y-coordinate of top-left corner: ";
                cin >> y;
                cout << "Enter width: ";
                cin >> width;
                cout << "Enter height: ";
                cin >> height;
                Rect regionOfInterest(x, y, width, height);
                originalImage = originalImage(regionOfInterest);
                break;
            }
            case 3: {
                // Apply a filter (e.g., Gaussian blur)
                GaussianBlur(originalImage, originalImage, Size(5, 5), 0);
                break;
            }
            case 4: {
                string outputFileName;
                cout << "Enter the output filename: ";
                cin >> outputFileName;
                imwrite(outputFileName, originalImage);
                cout << "Image saved as " << outputFileName << endl;
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        // Display the modified image
        imshow("Modified Image", originalImage);
        waitKey(0); // Wait until a key is pressed
        destroyWindow("Modified Image");
    }

    return 0;
}