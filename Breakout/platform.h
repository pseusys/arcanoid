#ifndef PLATFORM_H
#define PLATFORM_H


#include <QImage>
#include <QRect>


class Platform {
public:
    Platform();
    ~Platform();

public:
    void resetState();
    void move();
    void setDx(int);
    QRect getRect();
    QImage& getImage();

private:
    QImage image;
    QRect rect;
    int dx;
    static const int INITIAL_X = 0;
    static const int INITIAL_Y = 0;
};

#endif // PLATFORM_H
