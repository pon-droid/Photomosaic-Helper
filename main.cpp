
#include <iostream>
#include <filesystem>
#include <Magick++.h>
#include<sstream>
using namespace std;
using namespace Magick;
namespace fs = std::filesystem;

int main(int argc,char **argv) {
    InitializeMagick(*argv);
    Image image;
    /*
    try{
        image.read("source.png");
        Pixels pixel_cache(image);
        PixelPacket *pixel

        for(unsigned long y = 0; y<image.columns()-50; y+=50 ){
            for(unsigned long x = 0; x<image.rows()-50; x+=50 ){
                Image sub_image(image);
                image.chop(geo);
                for(int sub_y = 0; sub_y<50; sub_y++){
                    for(int sub_x = 0; sub_x<50; sub_x++){

                        ColorRGB colour =
                    }
                }


            }
        }
*/

    string filename = "FILE_NUMBER_";
    string file_ext = ".jpg";

    int i = 0;
    stringstream ss;


    fs::create_directory("./output/");
    std::string doc = fs::current_path();
    for (const auto & entry : fs::directory_iterator(doc)){
        try{
        i++;
        image.read(entry.path());
        int rows = image.rows();
        Geometry geo = Geometry(rows,rows);
        geo.aspect(true);
        image.resize(geo);
        ss << "./output/" << filename << i << file_ext;
        image.write(ss.str());
        ss.str("");
        }
        //These below exceptions occur if the file is not an image, it will skip if the file is not an image
        catch(Magick::ErrorMissingDelegate &error){
            continue;
        }
        catch(Magick::ErrorCorruptImage &error){
            continue;
        }

}

}
