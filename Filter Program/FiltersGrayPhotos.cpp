#include <bits/stdc++.h>
#include "bmplib.cpp"
#include "bmplib.h"
#include <unistd.h>

using namespace std;

unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

void readImage();
void readImage2 ();
void menu();
void saveImage(); // to write image as output
void saveImage2(); // to write image2 as output
void black_and_white_filter();
void cropImage_filter();
void mirrorHalfImage_filter();
void detectImage_Edges_filter();
void merge_filter();
void rotateImage_filter();
void invert_filter();
void darker_or_lighter_filter();
void flipImage_filter();
void blur_filter();
void shrinkImage_filter();
void enlargeImage_filter();
void shuffleImage_filter();
void skewImageRight_filter();
void skewImageUp_filter();

int main()
{
    readImage();
    menu();
}

//==============================================================================================================

void readImage()
{
    char imageFileName[100], cwd[PATH_MAX];
    string path = getcwd(cwd, sizeof(cwd)); // path = path of project in pc for ex: "F:\CS213-2023-20220407-20221150-20221244-A1-Part1.cpp".
    path += "\\Images\\"; // to add path of images which user can choose from them to path of project.

    cout << "Please, enter name of image to process!\n" << "Your choice >> ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp"); // convert image formula to bmp form
    path += imageFileName;

    readGSBMP(path.c_str(), image); // read grayscale image from the file specified by filename, into inputImage
}

//==============================================================================================================

void readImage2() // similar to readImage() function but use it to read second input image to merge
{
    char imageFileName[100], cwd[PATH_MAX];
    string path = getcwd(cwd, sizeof(cwd));
    path += "\\Images\\";

    cout << "Please, enter name of image to process!\n" << "Your choice >> ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    path += imageFileName;

    readGSBMP(path.c_str(), image2);
}

//==============================================================================================================

void saveImage_to_file() // similar to saveImage() function but use it to change image name file from default to which user need
{
    cout << "Please, enter name of file which you need!\n" << "choice >> ";
    char imageFileName[100], cwd[PATH_MAX];
    string path = getcwd(cwd, sizeof(cwd));
    path += "\\After_edit\\";

    cin >> imageFileName;

    strcat (imageFileName, ".bmp");
    path += imageFileName;

    writeGSBMP(path.c_str(), image); // write grayscale image to the file specified by filename, from outputImage
    shown(imageFileName); // to show output image after end code

    cout << "Done! Thank you for using our program!\n";
}

//==============================================================================================================

void saveImage2_to_file() // similar to saveImage_to_file() function but write image2 instead of image
{
    cout << "Please, enter name of file which you need!\n" << "choice >> ";
    char imageFileName[100];
    cin >> imageFileName;

    strcat (imageFileName, ".bmp");

    writeGSBMP(imageFileName, image2);
    shown(imageFileName);
    cout << "Done! Thank you for using our program!\n";
}

//==============================================================================================================

void saveImage() // write image and show it
{
    showGSBMP(image); // write grayscale image to the file specified by filename, from outputImage and show it after end code
    cout << "Done! Thank you for using our program!\n";
}

//==============================================================================================================

void saveImage2() // similar to saveImage() function but write image2 instead of image
{
    showGSBMP(image2);
    cout << "Done! Thank you for using our program!\n";
}

//==============================================================================================================

void black_and_white_filter()
{
    for (auto & i : image)
    {
        for (unsigned char & j : i)
        {
            if (j > 127) // if integer of pixel > average
            {
                j = 255; // make this pixel white
            }
            else // if integer of pixel <= average
            {
                j = 0; // make this pixel white
            }
        }
    }
}

//==============================================================================================================

void merge_filter()
{
    readImage2(); // use it to read second input image to merge

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (image[i][j] + image2[i][j]) / 2; // take average of each pixel in same index
        }
    }
}

//==============================================================================================================

void flipImage_filter()
{
    cout << "Please, enter 'v' for vertical or 'h' for horizontal!\n" << "Your choice >> ";

    char user_input;
    cin >> user_input;

    if (user_input == 'h')
    {
        int a = 0, b = 0;
        for (auto & i : image)
        {
            for (int j = SIZE - 1; j >= 0; j--)
            {
                image2[a][b] = i[j]; // swap colums mean that the last be first
                b++;
            }
            a++;
            b = 0;
        }
    }

    else if (user_input == 'v')
    {
        int a = 0, b = 0;
        for (int i = SIZE-1; i >= 0; i--)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[a][b] = image[i][j]; // swap rows mean that the last be first
                b++;
            }
            a++;
            b = 0;
        }
    }
}

//==============================================================================================================

void rotateImage_filter()
{
    cout << "Please, enter degree of rotate 90, 180 or 270\n" << "Your choice >> ";

    int user_input;
    cin >> user_input;

    if (user_input == 90)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[255-j][i]; // make rows colums, make colums rows and swap them
            }
        }
    }
    else if (user_input == 180)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[255-i][255-j]; // make the last row and last colums be first and opposite
            }
        }
    }
    else if (user_input == 270)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[j][255-i]; // swap colums mean that the last be first
            }
        }
    }
}

//==============================================================================================================

void darker_or_lighter_filter()
{
    cout << "Please, enter 'l' for lighten and 'd' for darken!\n" << "Your choice >> ";

    char user_input;
    cin >> user_input;

    if(user_input == 'l')
    {
        for (auto & i : image)
        {
            for (unsigned char & j : i)
            {
                j = min(255, j * 3/2); // add 50% by multiplication 3/2 to be 150% but use min() function not to increase over 255
            }
        }
    }
    if(user_input == 'd')
    {
        for (auto & i : image)
        {
            for (unsigned char & j : i)
            {
                j /= 2; // subtract 50% by Division 2 to decrease it from 100% to 50%
            }
        }
    }
}

//==============================================================================================================

void invert_filter()
{
    for (auto & i : image)
    {
        for (unsigned char & j : i)
        {
            j = 255 - j; // subtract from 255 to get invert color
        }
    }
}

//==============================================================================================================

void blur_filter()
{
    unsigned char tmpImage[SIZE][SIZE];
    int blur_intensity = 4;
    int kernel[5][5] = {
            {1, 4, 6, 4, 1},
            {4, 16, 24, 16, 4},
            {6, 24, 36, 24, 6},
            {4, 16, 24, 16, 4},
            {1, 4, 6, 4, 1}
    };

    // iterate over the pixels and multiply it with the kernel
    while(blur_intensity--)
    {
        for (int i = 2; i < SIZE - 1; i++)
        {
            for (int j = 2; j < SIZE - 1; j++)
            {
                int sum = 0;
                for (int x = -2; x <= 2; x++)
                {
                    for (int y = -2; y <= 2; y++)
                    {
                        sum += image[i + x][j + y] * kernel[x + 2][y + 2];
                    }
                }
                tmpImage[i][j] = sum / 256;
            }
        }

        // copy the image back to original image
        for (int i = 2; i < SIZE - 1; i++)
        {
            for (int j = 2; j < SIZE - 1; j++)
            {
                image[i][j] = tmpImage[i][j];
            }
        }
    }
}

//==============================================================================================================

void shrinkImage_filter()
{
    cout << "Please, enter the factor of shrink => 1/2, 1/3 or 1/4\n" << "Your choice >> 1/";

    int factor;
    cin >> factor; // user input size new image / input image

    for (auto & i : image2)
    {
        for (unsigned char & j : i)
        {
            j = 255; // make image 256 * 256 all of this pixels are white to put shrink photo and other still white
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image2[i/factor][j/factor] = image[i][j]; // write number of factor which user input in  one pixel to shrink input image
        }
    }
}

//==============================================================================================================

void detectImage_Edges_filter()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (abs(image[i][j] - image[i+1][j+1]) <= 30) // if the difference between any pixel and next to it 30 to detect noticeable difference
                image2[i][j] = 255;
            else
                image2[i][j] = 0;
        }
    }
}

//==============================================================================================================

void mirrorHalfImage_filter()
{
    cout << "Please, enter 'l' for left 1/2, 'r' for right 1/2, 'u' for upper 1/2 or 'w' for lower 1/2\n" << "Your choice >> ";

    char user_input;
    cin >> user_input;

    if (user_input == 'w')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[255-i][j];
            }
        }
    }

    else if (user_input == 'l')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][255-j] = image[i][j];
            }
        }
    }

    else if (user_input == 'u')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[255-i][j] = image[i][j];
            }
        }
    }

    else if (user_input == 'r')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][255-j];
            }
        }
    }
}

//==============================================================================================================

void cropImage_filter()
{
    int a, b, c, d;
    cout << "Please, enter x, y for width: ";
    cin >> a >> c;
    cout << "Please, enter l, w for height: ";
    cin >> b >> d;

    for (auto & i : image2)
    {
        for (unsigned char & j : i)
        {
            j = 255; // make all pixels are white
        }
    }

    for (int i = min(a, c); i < max(a, c); i++) // start with smaller index of pixel to bigger index of pixel
    {
        for (int j = min(b, d); j < max(b, d); j++) // start with smaller index of pixel to bigger index of pixel
        {
            image2[i][j] = image[i][j]; // to take only range which user input from input image
        }
    }
}

//==============================================================================================================

void enlargeImage_filter()
{
    cout << "Which quarter to enlarge 1, 2, 3 or 4?\n" << "Your choice >> ";

    int q;
    cin >> q;

    // to enlarge 128 * 128 pixels to 256 * 256 pixels we need to represent 1 pixel in 2 pixel
    if (q == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[i][j] = image[i / 2][j / 2];
            }
        }
    }
    else if (q == 2)
    {
        int a = 0, b = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE; j < 512; j++)
            {
                image2[a][b] = image[i/2][j/2];
                b++;
            }
            a++;
            b = 0;
        }
    }

    else if (q == 3)
    {
        int a = 0, b = 0;
        for (int i = SIZE; i < 512; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image2[a][b] = image[i/2][j/2];
                b++;
            }
            a++;
            b = 0;
        }
    }

    else if (q == 4)
    {
        int a = 0, b = 0;
        for (int i = SIZE; i < 520; i++)
        {
            for (int j = SIZE; j < 520; j++)
            {
                image2[a][b] = image[i/2][j/2];
                b++;
            }
            a++;
            b = 0;
        }
    }
}
//==============================================================================================================

void  shuffleImage_filter()
{
    cout<<"Enter your order: ";
    int ord[4];
    // take the order from the user
    for (int & i : ord) {
        cin>>i;
    }
    // copy the original image
    for (int i = 0; i < SIZE ; i++) {
        for (int j = 0; j< SIZE ; j++) {
            image2[i][j]=image[i][j];
        }
    }
    int x=0,y=0;
    // to load the new image
    for (int i = 0; i < 4; ++i) {
        if (i==0){
            x=0,y=0;
        }
        if (i==1){
            x=0,y=SIZE/2-1;
        }
        if (i==2){
            x=SIZE/2-1;
            y=0;
        }
        if (i==3){
            x=SIZE/2-1;
            y=SIZE/2-1;
        }
        int n=x,m=y;
        // to load the image based on the users order
        switch (ord[i]) {
            case 1:
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for (int k = 0; k <SIZE/2 ; ++k) {
                        image[n][m]=image2[j][k];
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 2:
                for (int j = 0; j <SIZE/2 ; ++j) {
                    for (int k = SIZE/2-1; k <SIZE ; ++k) {
                        image[n][m]=image2[j][k];
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 3:
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for (int k = 0; k <SIZE/2 ; ++k) {
                        image[n][m]=image2[j][k];
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;
            case 4:
                for (int j = SIZE/2-1; j <SIZE ; ++j) {
                    for (int k = SIZE/2-1; k <SIZE ; ++k) {
                        image[n][m]=image2[j][k];
                        m++;
                    }
                    m=y;
                    n++;
                }
                break;

            default:
                break;
        }
    }
}
void skewImageRight_filter()
{
    cout << "Please, enter the degree of skew: ";

    double rad ; cin >> rad ;
    rad = ( rad * 22 ) / ( 180 * 7 ) ;
    double mov = tan(rad) * 256 ;
    double step = mov / SIZE ; // عدد الخطوات
    unsigned char img_in[SIZE][SIZE+(int)mov]  ;
    for ( int i = 0 ; i < SIZE ; i++ )
        for ( int j = 0 ; j < SIZE ; j++ )
            img_in[i][j] = 255 ;
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE ; j++ ){
            img_in[i][j+(int)mov] = image[i][j] ;
        }
        mov -= step ;
    }
    for ( int i = 0 ; i < SIZE ; i++ ){
        for ( int j = 0 ; j < SIZE; j++ ){
            image[i][j] = img_in[i][j] ;
        }
    }
}

//==============================================================================================================

void skewImageUp_filter()
{
    cout<<"enter the degree of skew: ";
    double degree;
    cin>>degree;
    double radians=degree*M_PI/180;
    int required_length=(256*tan(radians));

    int area_of_triangle=required_length*256;
    int height_of_the_potot=256/cos(radians);


    int area_of_the_photo=65536-area_of_triangle;

    int factor = ceil(65536/area_of_the_photo);
    factor+=1;


    int newWidth = SIZE;
    int newHeight = SIZE/factor;

    unsigned char shrunkImage[newHeight][newWidth];

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int sum = 0;

            for (int y = 0; y < factor; y++) {
                sum += image[j*factor+y][i];
            }


            shrunkImage[j][i] = (sum / (factor));
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255;
        }
    }


//int cnt2=0;
    double number_of_minuses=256-required_length;
    double every=ceil(256/number_of_minuses);
    required_length+=number_of_minuses;

    int x=tan(radians)*256;
    int rt=256;

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < newHeight; j++){
            image[j+x][i] = shrunkImage[j][i];
        }

        --rt;
        x=rt*tan(radians);

    }
}

//==============================================================================================================

void menu()
{
    cout << "Please, select a filter by choosing its number to apply or 0 to exit: \n"
            "1- Black & White Filter\n"
            "2- Invert Filter\n"
            "3- Merge Filter\n"
            "4- Flip Image\n"
            "5- Darken and Lighten Image\n"
            "6- Rotate Image\n"
            "7- Detect Image Edges\n"
            "8- Enlarge Image\n"
            "9- Shrink Image\n"
            "a- Mirror 1/2 Image\n"
            "b- Shuffle Image\n"
            "c- Blur Image\n"
            "d- Crop Image\n"
            "e- Skew Image Right\n"
            "f- Skew Image Up\n"
            "0- Exit\n";

    char user_input;
    cin >> user_input;

    if (int(user_input) == int('1'))
        black_and_white_filter();

    else if (int(user_input) == int('2'))
        invert_filter();

    else if (int(user_input) == int('3'))
        merge_filter();

    else if (int(user_input) == int('4'))
        flipImage_filter();

    else if (int(user_input) == int('5'))
        darker_or_lighter_filter();

    else if (int(user_input) == int('6'))
        rotateImage_filter();

    else if (int(user_input) == int('7'))
        detectImage_Edges_filter();

    else if (int(user_input) == int('8'))
        enlargeImage_filter();

    else if (int(user_input) == int('9'))
        shrinkImage_filter();

    else if (int(user_input) == int('a'))
        mirrorHalfImage_filter();

    else if (int(user_input) == int('b'))
        shuffleImage_filter();

    else if (int(user_input) == int('c'))
        blur_filter();

    else if (int(user_input) == int('d'))
        cropImage_filter();

    else if (int(user_input) == int('e'))
        skewImageRight_filter();

    else if (int(user_input) == int('f'))
        skewImageUp_filter();

    else if (user_input == '0')
    {
        cout << "Are you sure?\n" << "'1' for yes\n" << "'0' for no\n" << "Your choice >> ";

        char i;
        cin >> i;

        if (i == '0')
            menu();
    }

    int yes_or_no;
    if (user_input != '0')
    {
        cout << "Do you need to save the image by using your name?\n" << "'1' for yes!\n" << "'0' for default!\n"
             << "Your choice >> ";
        cin >> yes_or_no;
    }

    if (user_input == '6' || user_input == '4' || user_input == 'd' || user_input == '7' || user_input == '8' || user_input == '9')
    {
        if (yes_or_no == 0)
            saveImage2();
        else if (yes_or_no == 1)
            saveImage2_to_file();
        else
            cout << "Something wrong, please try again!\n";
    }

    else if (user_input != '0')
    {
        if (yes_or_no == 0)
            saveImage();
        else if (yes_or_no == 1)
            saveImage_to_file();
        else
            cout << "Something wrong, please try again!\n";
    }
    cout << "Do you need to continue or exit?\n" << "'1' for continue\n" << "'0' for exit\n" << "Your choice >> ";
    cin >> user_input;

    if (user_input == '1')
        menu();
}