#include <QPainter>
#include <QApplication>
#include "arcanoid.h"


Arcanoid::Arcanoid(QWidget* parent) : QWidget(parent) {
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    platform = new Platform();

    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            bricks[k] = new Brick(j * 40 + 30, i * 10 + 50);
            k++;
        }
    }
}


Arcanoid::~Arcanoid() {
    delete ball;
    delete platform;

    for (int i = 0; i < N_OF_BRICKS; i++) {
        delete bricks[i];
    }
}


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
    painter->drawImage(platform->getRect(), platform->getImage());

    for (int i = 0; i < N_OF_BRICKS; i++) {
        if (!bricks[i]->isDestroyed()) {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}


void Arcanoid::timerEvent(QTimerEvent* e) {
    Q_UNUSED(e);

    moveObjects();
  //  checkCollision();
    repaint();
}


void Arcanoid::startGame() {
    if (!gameStarted) {
        ball->resetState();
        platform->resetState();

        for (int i = 0; i < N_OF_BRICKS; i++) {
            bricks[i]->setDestroyed(false);
        }

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        timerId = startTimer(DELAY);
    }
}


void Arcanoid::pauseGame() {
    if (paused) {
        timerId = startTimer(DELAY);
        paused = false;
    } else {
        paused = true;
        killTimer(timerId);
    }
}


void Arcanoid::stopGame() {
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;
}


void Arcanoid::victory() {
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}


void Arcanoid::finishGame(QPainter* painter, QString message) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);

 //   int textWidth = fm.width(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w / 2, h / 2));
 //   painter->drawText(-textWidth / 2, 0, message);
}


void Arcanoid::moveObjects() {
    ball->autoMove();
    platform->move();
}


void Arcanoid::keyReleaseEvent(QKeyEvent* e) {
    int dx = 0;
    switch (e->key()) {
    case Qt::Key_Left:
        dx = 0;
        platform->setDx(dx);
        break;
    case Qt::Key_Right:
        dx = 0;
        platform->setDx(dx);
        break;
    }
}


void Arcanoid::keyPressEvent(QKeyEvent* e) {
    int dx = 0;
    switch (e->key()) {
    case Qt::Key_Left:
        dx = -1;
        platform->setDx(dx);
        break;
    case Qt::Key_Right:
        dx = 1;
        platform->setDx(dx);
        break;
    case Qt::Key_P:
        pauseGame();
        break;
    case Qt::Key_Space:
        startGame();
        break;
    case Qt::Key_Escape:
        qApp->exit();
        break;
    default:
        QWidget::keyPressEvent(e);
    }
}

