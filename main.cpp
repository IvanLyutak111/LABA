#include <iostream>
#include "lamps.h"
#include "collectionoflamps.h"
#include <assert.h>
#include <typeinfo>
#include <string>
using namespace std;

void testLamps() {
    //Тестирование класса Лампа
    Lamps lamp;
    assert(0 == lamp.getPower());
    assert(0 == lamp.getIntensity());

    Lamps lamp2(80);
    assert(80 == lamp2.getPower());
    assert(0 == lamp2.getIntensity());

    Lamps lamp3(120, 150);
    assert(120 == lamp3.getPower());
    assert(150 == lamp3.getIntensity());

    Lamps lamp41(30, 90);
    Lamps lamp42(lamp41);
    assert(30 == lamp42.getPower());
    assert(90 == lamp42.getIntensity());

    Lamps lamp5;
    lamp5.setPower(90);
    assert(90 == lamp5.getPower());
    lamp5.setPower(-1);
    assert(0 == lamp5.getPower());
    lamp5.setPower(201);
    assert(200 == lamp5.getPower());

    Lamps lamp6;
    lamp6.setIntensity(300);
    assert(300 == lamp6.getIntensity());
    lamp6.setIntensity(-1);
    assert(0 == lamp6.getIntensity());
    lamp6.setIntensity(501);
    assert(500 == lamp6.getIntensity());

    Lamps lamp7(201, 501);
    assert(200 == lamp7.getPower());
    assert(500 == lamp7.getIntensity());
    lamp7.setPower(0);
    lamp7.setIntensity(0);
    assert(0 == lamp7.getPower());
    assert(0 == lamp7.getIntensity());
    cout << "testLamps Success" << endl;
}
int change(){
    ifstream f1("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/Laba1_OPP.txt");
    if(!f1)
    {
    cout << "Unable to open file 1.\n";
    return 1;
    }
    ifstream f2("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/newFile.txt");
    if(!f2)
    {
    cout << "Unable to open file 2.\n";
    return 1;
    }
    std::string line1="";
    std::string line2="";
    while(line1==line2&& line2!="/") {
      getline(f1,line1);
      getline(f2,line2);
      if (line1!=line2){
          cout << "Files are difference"<<endl;
          return 0;
      }
    }
    cout << "Files are the same.\n";
    f1.close();
    f2.close();
}
void testCollectionOfLamps(){
     auto pur1 = new Lamps();
    CollectionOfLamps lamp(2,2, *pur1);
    assert(lamp.getLength()*lamp.getWidth() == 4 );
    //CollectionOfLamps copylamp(lamp);
    //assert(copylamp.getLength()*copylamp.getWidth() == lamp.getLength()*lamp.getWidth());
    Lamps Lamps(60, 80);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            lamp.setLamp(i,j,Lamps);
            lamp.outputCollect(i,j);
         }
    lamp.~CollectionOfLamps();
    cout << "Next Test\n"<< "-------------" << endl;
}

int main()
{
   testLamps();
    testCollectionOfLamps();
    CollectionOfLamps lamp8;
    change();
    cout << "testCollectionOfLamps Success\n" << "---------------" << endl;
    CollectionOfLamps l;
    l.getFile("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/Laba1_OPP.txt");
    CollectionOfLamps led;
    led.getFileLED("C:/Users/Dima/Desktop/Laba1_OPP_Lamp/FileLED.txt");
    return 0;
}
