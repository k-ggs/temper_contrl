#include "qcustom_api.h"

qcustom_api::qcustom_api(QQuickItem *parent) : QQuickPaintedItem(parent)
  , m_CustomPlot( nullptr ) ,mTag1(0)
{
  m_CustomPlot = new QCustomPlot();
  m_CustomPlot->axisRect()->setBackground(QBrush(Qt::white));//背景黑色

     m_CustomPlot->setNotAntialiasedElement(QCP::AntialiasedElement::aeAll);
     m_CustomPlot->setNoAntialiasingOnDrag(true);
     setFlag( QQuickItem::ItemHasContents, true );
     setAcceptedMouseButtons( Qt::AllButtons );



  connect( this, &QQuickPaintedItem::widthChanged, this, &qcustom_api::updateCustomPlotSize );
 connect( this, &QQuickPaintedItem::heightChanged, this, &qcustom_api::updateCustomPlotSize );


 connect(m_CustomPlot,&QCustomPlot::plottableClick, this, &qcustom_api::graphClicked);
 connect(m_CustomPlot,&QCustomPlot::selectionChangedByUser, this, &qcustom_api::selectionChanged);
 connect(m_CustomPlot, &QCustomPlot::legendDoubleClick, this, &qcustom_api::legendDoubleClick);

 connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &qcustom_api::onCustomReplot );



 connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(timerSlot()));
}

void qcustom_api::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
  // Rename a graph by double clicking on its legend item
  Q_UNUSED(legend)
/* if (item) // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
  {
 QCPGraph *graph ;
    for (int i=0; i<m_CustomPlot->graphCount(); ++i)
    {
    graph = m_CustomPlot->graph(i);

      QCPPlottableLegendItem *item2 = m_CustomPlot->legend->itemWithPlottable(graph);
      if (item2->selected())
      {
          if(graph->visible())
        { item->setSelectedTextColor(QColor(0,0,0,50));
              graph->setVisible(false);}
          else
          {

              item->setSelectedTextColor(QColor(0,0,0));
              graph->setVisible(true);

          }
      }




    }

  }
 */
//qDebug()<<"intidx"<<
if(m_CustomPlot->selectedGraphs().length()>0)
{
    if( m_CustomPlot->selectedGraphs()[0]->visible())
    {
      item->setTextColor(QColor(0,0,0,50));
    m_CustomPlot->selectedGraphs()[0]->setVisible(false);
    }
    else
    {    item->setTextColor(QColor(0,0,0));
        m_CustomPlot->selectedGraphs()[0]->setVisible(true);}
}

}
void qcustom_api::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
  // since we know we only have QCPGraphs in the plot, we can immediately access interface1D()
  // usually it's better to first check whether interface1D() returns non-zero, and only then use it.
  double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
 // QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);

  //获取鼠标坐标，相对父窗体坐标
  QPointF f= plottable->interface1D()->dataPixelPosition(dataIndex);
     int x_pos = f.x();
     int y_pos = f.y();

     //鼠标坐标转化为CustomPlot内部坐标
  //   float x_val = m_CustomPlot->xAxis->pixelToCoord(x_pos);
    // float y_val = m_CustomPlot->yAxis->pixelToCoord(y_pos);
        double x_val = dataIndex;
        double y_val = plottable->interface1D()->dataMainValue(dataIndex);

     QString str,strToolTip;
     str = QString::number(x_val,'g',17);
     strToolTip += QString("时间(μs): ");
     strToolTip += str;
     strToolTip += "\n";
     strToolTip +=plottable->name()+ ":  ";
      str = QString::number(y_val);
     strToolTip += str;
     strToolTip += "\n";

strToolTip += "_______";
strToolTip += "\n";
     for (int i = 0;i <m_CustomPlot->xAxis->graphs().count();i++) {
         //获得x轴坐标位置对应的曲线上y的值
         double y = m_CustomPlot->graph(i)->data()->at(x_val)->value;

         str = QString::number(y);
         strToolTip +=  m_CustomPlot->graph(i)->name() + ": ";
         strToolTip += str;
         strToolTip += "\n";
     }
     QToolTip::showText(cursor().pos(), strToolTip, m_CustomPlot);


}

void qcustom_api::selectionChanged()
{
  /*
   normally, axis base line, axis tick labels and axis labels are selectable separately, but we want
   the user only to be able to select the axis as a whole, so we tie the selected states of the tick labels
   and the axis base line together. However, the axis label shall be selectable individually.

   The selection state of the left and right axes shall be synchronized as well as the state of the
   bottom and top axes.

   Further, we want to synchronize the selection of the graphs with the selection state of the respective
   legend item belonging to that graph. So the user can select a graph by either clicking on the graph itself
   or on its legend item.
  */

  // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (m_CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || m_CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels))
  {

   m_CustomPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }
  // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (m_CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || m_CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels)
     )
  {

   m_CustomPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }

  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<m_CustomPlot->graphCount(); ++i)
  {
    QCPGraph *graph = m_CustomPlot->graph(i);
    QCPPlottableLegendItem *item = m_CustomPlot->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);

      graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
    }
  }
}

qcustom_api::~qcustom_api(){
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
}
void qcustom_api::initCustomPlot()
{
  m_CustomPlot->clearGraphs();
  m_CustomPlot->clearPlottables();
  m_CustomPlot->clearItems();
  m_CustomPlot->clearMask();
m_CustomPlot->xAxis->grid()->setVisible(false);
  m_CustomPlot->xAxis->setSubTicks(false);
  m_CustomPlot->yAxis2->setSubTicks(false);
m_CustomPlot->yAxis->grid()->setVisible(false);


  connect(m_CustomPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), m_CustomPlot->yAxis, SLOT(setRange(QCPRange)));

  m_CustomPlot->yAxis2->setVisible(true);

   updateCustomPlotSize();

// m_CustomPlot->axisRect()->addAxis(QCPAxis::atRight);
 // add some padding to have space for tags
  m_CustomPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); //

    mGraph1 = m_CustomPlot->addGraph(m_CustomPlot->xAxis, m_CustomPlot->axisRect()->axis(QCPAxis::atRight, 0));
mGraph1->setPen(QPen(Qt::black));
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());


    m_CustomPlot->xAxis->setLabel(QString("μs") );

    m_CustomPlot->yAxis->setLabel( "V" );

    m_CustomPlot->graph(0)->setName(QString("传感器1"));
   m_CustomPlot->legend->setVisible(true);
  m_CustomPlot->yAxis->setVisible(false);

   // first we create and prepare a text layout element:
  // QCPTextElement *title = new QCPTextElement(m_CustomPlot);
  // title->setText(QString::fromLocal8Bit("传感器1"));
  // title->setFont(QFont("sans", 8, QFont::Bold));
   // then we add it to the main plot layout:
  // m_CustomPlot->plotLayout()->insertRow(0); // insert an empty row above the axis rect

  // m_CustomPlot->plotLayout()->addElement(0, 0, title);



    m_CustomPlot ->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);



   m_CustomPlot->replot();
  mDataTimer.start(40);

}

void qcustom_api::updateCustomPlotSize()
{
    if (m_CustomPlot)
    {
        m_CustomPlot->setGeometry(0, 0, (int)width(), (int)height());
        m_CustomPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));



     //   m_CustomPlot->setFont(QFont("宋体",10));
    }
}
void qcustom_api::routeMouseEvents( QMouseEvent* event )
{
    if (m_CustomPlot)
    {
        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );

    }
}

void qcustom_api::routeWheelEvents( QWheelEvent* event )
{
    if (m_CustomPlot)
    {
        QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );
    }
}
void qcustom_api::wheelEvent( QWheelEvent *event )
{
    if (m_CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
          m_CustomPlot->axisRect()->setRangeZoom(m_CustomPlot->xAxis->orientation());
         else if (m_CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
           m_CustomPlot->axisRect()->setRangeZoom(m_CustomPlot->yAxis->orientation());
         else
          m_CustomPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
       routeWheelEvents( event );
}
void qcustom_api::mouseDoubleClickEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}
void qcustom_api::mouseMoveEvent( QMouseEvent* event )
{qDebug() << Q_FUNC_INFO;
     routeMouseEvents( event );




}
void qcustom_api::mouseReleaseEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}
void qcustom_api::mousePressEvent( QMouseEvent* event )
{
    if (m_CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
     m_CustomPlot->axisRect()->setRangeDrag(m_CustomPlot->xAxis->orientation());
    else if (m_CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
      m_CustomPlot->axisRect()->setRangeDrag(m_CustomPlot->yAxis->orientation());
    else
     m_CustomPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
    routeMouseEvents( event );
}
void qcustom_api::paint( QPainter* painter )
{
    if (m_CustomPlot)
    {
        QPixmap    picture( boundingRect().size().toSize() );
        QCPPainter qcpPainter( &picture );

        m_CustomPlot->toPainter( &qcpPainter );
        setRenderTarget(QQuickPaintedItem::FramebufferObject);

        painter->drawPixmap( QPoint(), picture );
    }
}
void qcustom_api::updateData(double *data,int len)
{//QList<double> qdata;
for(int i=0;i<len/6;i++)
{









}
 double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
 mTag1->updatePosition(graph1Value);
 mTag1->setText(QString::number(graph1Value, 'f', 2));
m_CustomPlot->replot(QCustomPlot::rpQueuedReplot);
}
void qcustom_api::onCustomReplot()
{
   // qDebug() << Q_FUNC_INFO;
    update();
}
void qcustom_api::timerSlot()
{
  // calculate and add a new data point to each graph:
  mGraph1->addData(mGraph1->dataCount(), qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);

  // make key axis range scroll with the data:
  m_CustomPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false, true);

  m_CustomPlot->xAxis->setRange(m_CustomPlot->xAxis->range().upper, 100, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
  double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);

  mTag1->updatePosition(graph1Value);

  mTag1->setText(QString::number(graph1Value, 'f', 2));

  m_CustomPlot->replot();
}
