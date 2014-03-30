#include "mainpage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;

    MainPage mp;
    mp.show();
    return app.exec();
}

