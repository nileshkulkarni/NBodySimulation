    
    
    
    
    
  //mouse ka advance  
    
    
    // Don't move too far away
    /*QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));
    if (lineToCenter.length() > 150)
    //if(0)
    {
        qreal angleToCenter = acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }
    */

    // Try not to crash with any other mice
    QList<QGraphicsItem *> dangerMice = scene()->items(QPolygonF()
                                                       << mapToScene(0, 0)
                                                       << mapToScene(-10, -10)
                                                       << mapToScene(10, 10));
    foreach (QGraphicsItem *item, dangerMice) {
        if (item == this)
            continue;

        QLineF lineToMouse(QPointF(0, 0), mapFromItem(item, 0, 0));
        qreal angleToMouse = ::acos(lineToMouse.dx() / lineToMouse.length());
        if (lineToMouse.dy() < 0)
            angleToMouse = TwoPi - angleToMouse;
        angleToMouse = normalizeAngle((Pi - angleToMouse) + Pi / 2);

        if (angleToMouse >= 0 && angleToMouse < Pi / 2) {
            // Rotate right
            angle += 0.5;
        } else if (angleToMouse <= TwoPi && angleToMouse > (TwoPi - Pi / 2)) {
            // Rotate left
            angle -= 0.5;
        }
    }



    //Add some random movement
   // if (dangerMice.size() > 1 && (qrand() % 10) == 0)
    if (dangerMice.size() > 1 ){

        if (qrand() % 1)
            angle += (qrand() % 100) / 500.0;
        else
            angle -= (qrand() % 100) / 500.0;
    }

    //speed += (-50 + qrand() % 100) / 100.0;
      //speed += 1/10;


    qreal dx = ::sin(angle) * 70;
    qreal dy = ::cos(angle) * 70;

    //mouseEyeDirection = (qAbs(dx / 5) < 1) ? 0 : dx / 5;
   // QPointF p1 = mapFromScene(600,0);
    //QPointF p2 = mapFromScene(0,600);
   // QPointF p3 = mapFromScene(600,600);
   // QPointF p4 = mapFromScene(600,600);
    //setRotation(rotation() + dx +45);

    qreal currentx = (mapToParent( 0 ,0 ).x());
    qreal currenty = (mapToParent( 0 ,0 ).y());

    qreal currentAngle = atan(currentx/currenty);
    //qreal radius =  sqrt(currentx*currentx + currenty*currenty);

   qreal radius = 100;
     qreal angle_change;
   if(angle>(Pi+0.3))
        angle_change= (1/(TwoPi)) ;
    else
        angle_change= (1/(4*TwoPi)) ;


    angle = normalizeAngle(angle + angle_change);



    qreal newX  = radius*cos(angle);
    qreal newY  = radius*sin(angle);


/*
    if(currentx > 100) currentx=100;
    if(currentx < -100) currentx=-100;
    if(currenty > 100) currenty=100;
    if(currenty < -100) currenty=-100;


   qreal myspeed = 5;

    if(currentx == 100)
    {
        //currentx=100;
        currenty+=myspeed;
    }
    if (currentx == -100)
    {
        //currentx =-100;
        currenty-=myspeed;
    }


    if(currenty == 100)
    {
        //currenty=100;
        currentx-=myspeed;
    }
    if (currenty == -100)
    {
        //currenty =-100;
        currentx+=myspeed;
    }
*/


/*
    if(currentx > 100) currentx=100;
    if(currentx < -100) currentx=-100;
    if(currenty > 100) currenty=100;
    if(currenty < -100) currenty=-100;
*/



   qreal newX=currentx;
   qreal newY=currenty;










/////////////////////////////////////////////////////////Drawing mouse****************************
  
    // Eyes
    painter->setBrush(Qt::white);
    painter->drawEllipse(-10, -17, 8, 8);
    painter->drawEllipse(2, -17, 8, 8);

    // Nose
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-2, -22, 4, 4));-

    // Pupils
    painter->drawEllipse(QRectF(-8.0 + mouseEyeDirection, -17, 4, 4));
    painter->drawEllipse(QRectF(4.0 + mouseEyeDirection, -17, 4, 4));

    // Ears
    painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : Qt::red);
    painter->drawEllipse(-17, -12, 16, 16);
    painter->drawEllipse(1, -12, 16, 16);

    // Tail
    QPainterPath path(QPointF(0, 20));
    path.cubicTo(-5, 22, -5, 22, 0, 25);
    path.cubicTo(5, 27, 5, 32, 0, 30);
    path.cubicTo(-5, 32, -5, 42, 0, 35);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path);
    
    







