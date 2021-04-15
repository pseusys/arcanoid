#include <QPainter>
#include <QApplication>
#include "arcanoid.h"


void Arcanoid::paintEvent(QPaintEvent* e) {
    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver) {
        finishGame(&painter, "Game lost");
    } else if (gameWon) {
        finishGame(&painter, "Victory");
    } else {
        drawObjects(&painter);
    }
}


void Arcanoid::drawObjects(QPainter* painter) {
    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for (int i=0; i<N_OF_BRICKS; i++) {
        if (!bricks[i]->isDestroyed()) {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}


void Arcanoid::timerEvent(QTimerEvent* e) {
    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}
