#include <math.h>
#include <iostream>
#include "collectionoflamps.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <assert.h>
#include "ledlamps.h"
#include "lamps.h"
const float CollectionOfLamps::minHeight = 1;
const float CollectionOfLamps::defaultHeight = 2.6;
const float CollectionOfLamps::maxHeight =4;
using namespace std;
CollectionOfLamps::CollectionOfLamps(){
}
CollectionOfLamps::CollectionOfLamps(const int n,const int m, Lamps &pur) {
    if (n > 0 && m > 0) {
       cout << &pur << endl;
       collect = new Lamps *[n];
        //collectLED = new LEDLamps *[n];
        for (int i = 0; i < n; i++) {
            collect[i] = new Lamps [m];
        //  collectLED[i] = new LEDLamps [m];
            for (int j = 0; j < m; j++)
            {
               collect[i][j] = pur;
           //   collectLED[i][j] = LEDLamps();
            }
        }
        nn = n;
        mm = m;
    }
else
        throw 1;
};

CollectionOfLamps::CollectionOfLamps(const CollectionOfLamps &other) {
    if (other.nn > 0 && other.mm > 0) {

        collect = new Lamps *[other.nn];
      // collectLED = new LEDLamps *[other.nn];
        for (int i = 0; i < other.nn; i++) {
           collect[i] = new Lamps [other.mm];
        //    collectLED[i] = new LEDLamps [other.mm];
            for (int j = 0; j < other.mm; j++)
            {
               collect[i][j] = other.collect[i][j];
      //         collectLED[i][j] = other.collectLED[i][j];
            }
        }
        nn = other.nn;
        mm = other.mm;
    }
    else
        throw 1;
     }
Lamps &CollectionOfLamps::getLamp(const int x, const int y) const {
    if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
        return collect[x][y];
    }
    else
        throw 1;
};
LEDLamps &CollectionOfLamps::getLampLED(const int x, const int y) const {
    if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
        return collectLED[x][y];
    }
    else
        throw 1;
};
void CollectionOfLamps::setLamp(const int x, const int y, Lamps &lamps) {
    if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
        collect[x][y] = lamps;
    }
    else
        throw 1;
};
void CollectionOfLamps::setLampLED(const int x, const int y, LEDLamps &lamps1) {
    if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
        collect[x][y]=lamps1;
    }
    else
        throw 1;
};
void CollectionOfLamps::outputCollect(int x, int y){
    cout << "Power: " << collect[x][y].getPower() << endl;
    cout << "Intensity: " << collect[x][y].getIntensity() << endl;
}
void CollectionOfLamps::outputCollectFile(int x,int y){
    std::ofstream fout("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/newFile.txt", ios::app);
    if (collect[x][y].getPower()!=0 && collect[x][y].getIntensity()!=0 ){
    fout << collect[x][y].getPower() << endl;
    fout << collect[x][y].getIntensity()<<endl;
    fout << x << endl;
    fout << y << endl;
    }
}
int CollectionOfLamps::getLength() const {
    return nn;
};

int CollectionOfLamps::getWidth() const {
    return mm;
};
void CollectionOfLamps:: giveFile(int n, int m, double g, CollectionOfLamps square, int x, int y, int z, int height) const{
    std::ofstream ofs;
    ofs.open("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/newFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    ofstream fout("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/newFile.txt", std::ios::app);
    fout << n << endl;
    fout << m << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            square.outputCollect(i,j);
            square.outputCollectFile(i,j);
         }
    fout << "/\n" << x << " "<< y<<" " << z<< " " << height << endl;
    fout <<"/" <<endl;
    fout << g << endl;
    fout.close();
};
void CollectionOfLamps:: getFileLED(string StrLED) const{
    string line;
    int n,m, powerLED, x, y;
    int intensityRed, intensityGreen, intensityBlue;
    std::ifstream in(StrLED); // окрываем файл для чтения
    if (in.is_open())
    {
        getline(in, line);
        n = atoi(line.c_str());
       getline(in, line);
       m = atoi(line.c_str());
       auto pur = new LEDLamps();
        CollectionOfLamps room(n, m, *pur);
        while (getline(in, line))
        {
            if (line == "/") break;
            powerLED = atoi(line.c_str());
            getline(in, line);
            x = atoi(line.c_str());
            getline(in, line);
            y = atoi(line.c_str());
            getline(in, line);
            intensityRed = atoi(line.c_str());
            getline(in, line);
            intensityGreen = atoi(line.c_str());
            getline(in, line);
            intensityBlue = atoi(line.c_str());
            cout << powerLED << endl;
             cout << x << endl;
              cout << y << endl;
               cout << intensityRed << endl;
                cout << intensityBlue << endl;
                 cout << intensityGreen << endl;
            LEDLamps LEDLamps(powerLED, intensityRed, intensityGreen, intensityBlue);
            room.setLampLED(x,y, LEDLamps);
        }
        for (int i=0; i<n; i++)
               for (int j=0; j<m; j++)
                        {
                           cout<<"Force="<< room.getNowForce(i,j)<< endl;
                        }
        in.close();
    }
}
void CollectionOfLamps:: getFile(string Str) const{
    string line;
    int n,m, power,intensitive;
    double x, y, z, height;
        std::ifstream in(Str); // окрываем файл для чтения
        if (in.is_open())
        {
            getline(in, line);
            n = atoi(line.c_str());
           getline(in, line);
           m = atoi(line.c_str());
           auto pur = new Lamps();
            CollectionOfLamps square(n, m, *pur);
            cout << "begin" << endl;
            while (getline(in, line))
            {
                if (line == "/") break;
                power = atoi(line.c_str());
                getline(in, line);
                intensitive = atoi(line.c_str());
                getline(in, line);
                x = atoi(line.c_str());
                getline(in, line);
                y = atoi(line.c_str());

                Lamps Lamps(power, intensitive);
                square.setLamp(x, y,Lamps);
            }
            in >> x >> y >> z >> height;
            giveFile(n,m,square.getIlluminance(x,y,z,height), square, x, y, z, height);
            cout << "Illuminance: " << square.getIlluminance(x,y,z,height) << endl;
        }
        in.close(); // закрываем файл


};

double CollectionOfLamps::getNowForce(const int i, const int j) const{
    return 0.299*collect[i][j].getIntensityRed()+0.587*collect[i][j].getIntensityGreen()+0.114*collect[i][j].getIntensityBlue();
}
double CollectionOfLamps::getIlluminance(const float x, const float y, const float z, const float height) const {
    double illuminance = 0;
    if (((x < nn) && (x >= 0)) && ((y < mm) && (y >= 0)) && ((z < height) && (z >= 0)) && ((height >= minHeight) && (height <= maxHeight)))
        for (int i=0; i<nn; i++)
            for (int j=0; j<mm; j++)
            {

                double r = sqrt((x-i)*(x-i) + (y-j)*(y-j) + (height-z)*(height-z));
                double cos_a = (height - z)/r;
                if (cos_a ==0) {
                    cos_a = 1;
                }
                illuminance += collect[i][j].getIntensity()*cos_a/(r*r);
            }
    return illuminance;
};

CollectionOfLamps::~CollectionOfLamps() {
     if (collect) {
        for (int i = 0; i < nn; i++){
            delete [] collect[i];
        }
        delete [] collect;
    }
};
