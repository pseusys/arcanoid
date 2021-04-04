#include "platform.h"
#include <QDebug>


Platform::Platform() {
    dx = 0;
    image.load("platform.png");

    rect = image.rect();
    resetState();
}


Platform::~Platform() {
    qDebug() << ("Paddle deleted");
}


void Platform::setDx(int x) {
    dx = x;
}


void Platform::move() {
    int x = rect.x() + dx;
    int y = rect.top();

    rect.moveTo(x, y);
}


void Platform::resetState() {
    rect.moveTo(INITIAL_X, INITIAL_Y);
}


QRect Platform::getRect() {
    return rect;
}


QImage& Platform::getImage() {
    return image;
}
