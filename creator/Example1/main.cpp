#include <QtGui>
class  myMainWindow:public QMainWindow
{
public:
    myMainWindow():
    QMainWindow()
    {}
    ~myMainWindow(){}

    void paintEvent(QPaintEvent*)
    {
        QPainterPath circlePath;
        QPen myPen;
        QRectF mybound(50,50,20,20);

        //circlePath.moveTo(100.0, 100.0);
        //circlePath.arcTo(0, 0, 100.0, 100.0, 0.0, 600.0);
         circlePath.addEllipse(mybound);

        //Do Filling with Some Style
        QPainter painter(this);
        QLinearGradient gradient(0,0 ,50, 50);
        gradient.setColorAt(0.0, Qt::blue);
        gradient.setColorAt(1.0, Qt::green);
        painter.setPen(myPen);

        painter.setBrush(gradient);
        painter.drawPath(circlePath);

         QPropertyAnimation animation(&circlePath, "geometry");
         animation.setDuration(3000);
         animation.setStartValue(QRect(50, 50, 70, 70));
         animation.setEndValue(QRect(100, 100, 120,120));

         animation.setEasingCurve(QEasingCurve::OutBounce);

         animation.start();

    }
};

int main(int argc, char **argv)
{
        QApplication app(argc, argv);
        myMainWindow *window = new myMainWindow();

        window->setWindowTitle(QString::fromUtf8("Qt Fill Circle Gradient in QMainWindow"));
        window->resize(500, 227);
        window->show();
        return app.exec();
}
