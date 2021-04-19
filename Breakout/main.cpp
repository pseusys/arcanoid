#include "arcanoid.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Arcanoid window;
    window.resize(300, 400);
    window.setWindowTitle("Arcanoid");
    window.show();

    return app.exec();
}
