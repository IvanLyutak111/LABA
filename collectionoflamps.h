#ifndef COLLECTIONOFLAMPS_H
#define COLLECTIONOFLAMPS_H
#include <fstream>
#include "lamps.h"
#include "ledlamps.h"
class CollectionOfLamps
{
public:
    int check=0;
    static const float minHeight;
    static const float defaultHeight;
    static const float maxHeight;
    CollectionOfLamps();
    CollectionOfLamps(int n, int m, Lamps &pur);
    CollectionOfLamps(const CollectionOfLamps &other);
    CollectionOfLamps& operator=(const CollectionOfLamps &other) = delete;
    
    double getIlluminance(const float x, const float y, const float z, const float height = defaultHeight) const;
    double getNowForce(const int i=0,const int j=0) const;
    void setLamp(const int x, const int y, Lamps &lamp);
    void setLampLED(const int x, const int y, LEDLamps &lamp);
    Lamps &getLamp(const int x, const int y) const;
    LEDLamps &getLampLED(const int x, const int y) const;
    void outputCollect(int x, int y);
     void outputCollectFile(int x, int y);
    int getLength() const;
    int getWidth() const;
    void getFile(std::string Str) const;
    void getFileLED(std::string StrLED) const;
    void giveFile(int n, int m,double g, CollectionOfLamps square, int x, int y, int z, int height) const;
    ~CollectionOfLamps();
private:
    Lamps **collect;
    LEDLamps **collectLED;
    int nn, mm;
};

#endif // COLLECTIONOFLAMPS_H
