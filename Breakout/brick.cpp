#include "brick.h"
#include <QDebug>


Brick::Brick(int x, int y) {
    image.load("brickie.png");
    destroyed = false;
    rect = image.rect();
    rect.translate(x, y);
}


Brick::~Brick() {
    qDebug() << ("Brick deleted");
}


QRect Brick::getRect() {
    return rect;
}


void Brick::setRect(QRect rect) {
    this->rect = rect;
}


QImage& Brick::getImage() {
    return image;
}


bool Brick::isDestroyed() {
    return destroyed;
}


void Brick::setDestroyed(bool destroyed) {
    this->destroyed = destroyed;
}
