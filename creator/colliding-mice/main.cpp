#include "mouse.h"
#include "System.h"
#include "AllClasses.h"

 #include <QtGui>

 #include <math.h>

 static const int MouseCount = 3;
#define probe_interval 1000/50
#define particleMass 1
#define particleRadius 10



 int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

     QGraphicsScene scene;
     scene.setSceneRect(Xleft, Ybottom, Xright, Ytop);
     scene.setItemIndexMethod(QGraphicsScene::NoIndex);


     System sys(MouseCount,probe_interval);

     for (int i = 0; i < MouseCount; ++i) {
         QColor q(qrand()%256,qrand()%256,qrand()%256);
           Particle *particle = new Particle(q,particleMass,particleRadius);
        //Particle *particle = new Particle(q,particleMass,particleRadius ,Vector( 0.01* (i%2)  - 0.01 * ((i+1)%2) , 0));

         //mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                   //    ::cos((i * 6.28) / MouseCount) * 200);

         //qre

         /*particle->setPos(i%2 * (qrand()%200-100) + (i+1)%2 *(((i)%4 * 100) - (i+1)%2 * 100) ,
                       (i+1)%2 *( qrand()%200-100 )  + (i)%2 *(((i+1)%4 * 100) - (i)%2 * 100)
                         );

            */

            particle->setPos(qrand()%(2*Xright) -Xright ,qrand()%(2*Ytop) -Ytop);
         //  particle->setPos( -200*(i%2)+ 200*((i+1)%2), 0 );

         scene.addItem(particle);
         sys.addItem(particle,i);

     }
     scene.addRect( Xright-330,Ybottom-30,360,360,QPen(QColor(255,255,255)));

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
     QTimer timer1;
     QObject::connect(&timer,SIGNAL(timeout()), &sys , SLOT(run()));

     QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));

     timer.start(probe_interval);
  //   timer1.start(probe_interval-0.001);


     return app.exec();
 }
