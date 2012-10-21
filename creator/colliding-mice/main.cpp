#include "mouse.h"

 #include <QtGui>

 #include <math.h>

 static const int MouseCount = 10;

 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

     QGraphicsScene scene;
     scene.setSceneRect(-150, -150, 150, 150);
     scene.setItemIndexMethod(QGraphicsScene::NoIndex);


     for (int i = 0; i < MouseCount; ++i) {
         QColor q(0,i%2 * 255,(i+1)%2 * 255);
         Mouse *mouse = new Mouse(q);
        //mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                   //    ::cos((i * 6.28) / MouseCount) * 200);

         //qre

         mouse->setPos(i%2 * (qrand()%200-100) + (i+1)%2 *(((i)%4 * 100) - (i+1)%2 * 100) ,
                       (i+1)%2 *( qrand()%200-100 )  + (i)%2 *(((i+1)%4 * 100) - (i)%2 * 100)
                         );

         scene.addItem(mouse);
     }

     QGraphicsView view(&scene);
     view.setRenderHint(QPainter::Antialiasing);
     view.setBackgroundBrush(QBrush(QColor(255,0,0)));

    // view.setBackgroundBrush(QPixmap(":/images/cheese.jpg"));
     view.setCacheMode(QGraphicsView::CacheBackground);
     view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     view.setDragMode(QGraphicsView::ScrollHandDrag);
     view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "N Body Simulation"));
     view.resize(300, 300);
     view.show();

     QTimer timer;
     QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
     timer.start(1000 / 33);

     return app.exec();
 }
