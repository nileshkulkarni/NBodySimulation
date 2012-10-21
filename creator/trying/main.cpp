#include <QtGui>
#include <math.h>
#include <QGraphicsView>

int main(int argc, char **argv){
QApplication app(argc, argv);


 QGraphicsScene scene;
 scene.addText("Hello, world!");

 QGraphicsView view(&scene);
 view.show();

return app.exec();
 //return 0;
}
