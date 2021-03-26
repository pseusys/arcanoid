#include "platform.h"
#include <iostream>


Platform::Platform() {
    dx = 0;
    image.load("paddle.png");

    rect = image.rect();
    resetState();
}


Platform::~Platform() {
    std::cout << ("Paddle deleted") << std::endl;
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


QImage & Platform::getImage() {
    return image;
}
