#include "qmlPlotPaintedItem.h"
#include "qcustomplot.h"
#include "qmlLabel.h"
#include "qmlTick.h"
#include <QDebug>

qmlPlotPaintedItem::qmlPlotPaintedItem(QQuickItem* parent) : QQuickPaintedItem(parent)
{
	setFlag(QQuickItem::ItemHasContents, true);
	setAcceptedMouseButtons(Qt::AllButtons);

	connect(this, &QQuickPaintedItem::widthChanged, this, &qmlPlotPaintedItem::onUpdateCustomPlotSize);
	connect(this, &QQuickPaintedItem::heightChanged, this, &qmlPlotPaintedItem::onUpdateCustomPlotSize);

	m_CustomPlot.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	connect(&m_CustomPlot, SIGNAL(plottableClick(QCPAbstractPlottable*, QMouseEvent*)), this, SLOT(onGraphClicked(QCPAbstractPlottable*)));
	connect(&m_CustomPlot, &QCustomPlot::afterReplot, this, &qmlPlotPaintedItem::onCustomReplot);


    connect(&mDataTimer,SIGNAL(timeout()),this,SLOT(timerSlot()));
    m_listInfo.plot = &m_CustomPlot;


   // m_CustomPlot.xAxis->grid()->setVisible(false);
   // m_CustomPlot.xAxis->setSubTicks(false);
   // m_CustomPlot.yAxis2->setSubTicks(false);
   // m_CustomPlot.yAxis->grid()->setVisible(false);
   // m_CustomPlot.yAxis->setVisible(false);
     m_CustomPlot.yAxis2->setVisible(true);
}

void qmlPlotPaintedItem::addData(int index, QVariantList x, QVariantList y)
{
	auto g = m_CustomPlot.graph(index);
	QVector<qreal> xx, yy;
	for (auto i = 0; i < x.size(); ++i)
	{
		xx.push_back(x[i].toReal());
		yy.push_back(y[i].toReal());
          m_listInfo.m_graphs[index]->Tag->updatePosition(y[i].toReal());
        m_listInfo.m_graphs[index]->Tag->setText(QString::number(y[i].toReal(), 'f', 2));
	}
    g->addData(xx, yy);

    g->rescaleAxes();
	m_CustomPlot.replot();
}
void qmlPlotPaintedItem::addData(int index, qreal x, qreal  y)
{
    auto g = m_CustomPlot.graph(index);
    //QVector<qreal> xx, yy;
    //for (auto i = 0; i < x.size(); ++i)
    //{
    //	xx.push_back(x[i].toReal());
    //	yy.push_back(y[i].toReal());
    //      m_listInfo.m_graphs[index]->Tag->updatePosition(y[i].toReal());
    //    m_listInfo.m_graphs[index]->Tag->setText(QString::number(y[i].toReal(), 'f', 2));
    //}
    g->addData(x, y);

        m_listInfo.m_graphs[index]->Tag->updatePosition(y);
        m_listInfo.m_graphs[index]->Tag->setText(QString::number(y, 'f', 2));
    g->rescaleAxes();
   //     qDebug()<<"addData_single";
    m_CustomPlot.replot();
}



void qmlPlotPaintedItem::timerSlot()
{
  // calculate and add a new data point to each graph:
    int ct=m_CustomPlot.graph()->dataCount();
    for(int i=0;i<ct;i++)
    {
 m_CustomPlot.graph(i)->addData( m_CustomPlot.graph(i)->dataCount(), qSin( m_CustomPlot.graph(i)->dataCount()/50.0)+qSin( m_CustomPlot.graph(i)->dataCount()/50.0/0.3843)*0.25);

  // make key axis range scroll with the data:
 m_CustomPlot.xAxis->rescale();
   m_CustomPlot.graph(i)->rescaleValueAxis(false, true);

 m_CustomPlot.xAxis->setRange( m_CustomPlot.xAxis->range().upper, 100, Qt::AlignRight);

  // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
  double graph1Value =  m_CustomPlot.graph(i)->dataMainValue( m_CustomPlot.graph(i)->dataCount()-1);

   m_listInfo.m_graphs[i]->Tag->updatePosition(graph1Value);

   m_listInfo.m_graphs[i]->Tag->setText(QString::number(graph1Value, 'f', 2));

  m_CustomPlot.replot();
    }
}

void SetRange(QCustomPlot& plot, int index, QVariantMap range, QCPAxis::AxisType type)
{
	auto g = plot.graph(index);
	
	auto it = range.find("lo");
	if (it != range.end())
	{
		switch (type)
		{
		case QCPAxis::atLeft:
			g->valueAxis()->setRangeLower(it->toReal());
			break;
		case QCPAxis::atBottom:
			g->keyAxis()->setRangeLower(it->toReal());
			break;

        case QCPAxis::atRight:
            g->valueAxis()->setRangeLower(it->toReal());
            break;
        case QCPAxis::atTop:
            g->keyAxis()->setRangeLower(it->toReal());
            break;
		}
	}
	it = range.find("up");
	if (it != range.end())
	{
		switch (type)
		{
		case QCPAxis::atLeft:
			g->valueAxis()->setRangeUpper(it->toReal());
			break;
		case QCPAxis::atBottom:
			g->keyAxis()->setRangeUpper(it->toReal());
			break;

        case QCPAxis::atRight:
            g->valueAxis()->setRangeUpper(it->toReal());
            break;
        case QCPAxis::atTop:
            g->keyAxis()->setRangeUpper(it->toReal());
            break;
		}
	}
}


void SetRange(QCustomPlot& plot,  QVariantMap range, QCPAxis::AxisType type)
{
    //auto g = plot.graph(index);

    auto it = range.find("lo");
    if (it != range.end())
    {
        switch (type)
        {
        case QCPAxis::atLeft:
            plot.yAxis->setRangeLower(it->toReal());
            break;
        case QCPAxis::atBottom:
            plot.xAxis->setRangeLower(it->toReal());
            break;

        case QCPAxis::atRight:
           plot.yAxis2->setRangeLower(it->toReal());
            break;
        case QCPAxis::atTop:
           plot.xAxis2->setRangeLower(it->toReal());
            break;
        }
    }
    it = range.find("up");
    if (it != range.end())
    {
        switch (type)
        {
        case QCPAxis::atLeft:
            plot.yAxis->setRangeUpper(it->toReal());
            break;
        case QCPAxis::atBottom:
            plot.xAxis->setRangeUpper(it->toReal());
            break;

        case QCPAxis::atRight:
           plot.yAxis2->setRangeUpper(it->toReal());
            break;
        case QCPAxis::atTop:
           plot.xAxis2->setRangeUpper(it->toReal());
            break;
        }
    }
}


void qmlPlotPaintedItem::setXRange(int index, QVariantMap range)
{
	SetRange(m_CustomPlot, index, range, QCPAxis::atBottom);
}
void qmlPlotPaintedItem::setRange_tpe( QVariantMap range,int typ)
{
    SetRange(m_CustomPlot, range, (QCPAxis::AxisType)typ);
}

void qmlPlotPaintedItem::setYRange(int index, QVariantMap range)
{
	SetRange(m_CustomPlot, index, range, QCPAxis::atLeft);
}

void qmlPlotPaintedItem::paint(QPainter* painter)
{
	QPixmap    picture(boundingRect().size().toSize());
	QCPPainter qcpPainter(&picture);
	m_CustomPlot.toPainter(&qcpPainter);
	painter->drawPixmap(QPoint(), picture);
}

void qmlPlotPaintedItem::setBackground(QColor c)
{
	m_backgroundColor = c;
	m_CustomPlot.setBackground(c);

}

QColor qmlPlotPaintedItem::getBackground() const
{
	return m_backgroundColor;
}

QQmlListProperty<qmlGraph> qmlPlotPaintedItem::getGraphs()
{
	return QQmlListProperty<qmlGraph>(
		this, 
		&m_listInfo, 
		&qmlPlotPaintedItem::appendGraph,
		&qmlPlotPaintedItem::graphSize,
		&qmlPlotPaintedItem::graphAt,
		&qmlPlotPaintedItem::clearGraphs
	);
}

qmlLegend* qmlPlotPaintedItem::getLegend() const
{
	return nullptr;
}

void qmlPlotPaintedItem::setLegend(qmlLegend* g)
{
    m_CustomPlot.legend->setVisible(false);
	m_CustomPlot.legend->setFont(g->getFont());
    m_CustomPlot.legend->setWrap(0);
}

inline ListInfo& Info(QQmlListProperty<qmlGraph> *list)
{
	return *static_cast<ListInfo*>(list->data);
}

void qmlPlotPaintedItem::appendGraph(QQmlListProperty<qmlGraph> *list, qmlGraph *pdt)
{
	auto& info = Info(list);
	auto& m_CustomPlot = *info.plot;
	info.m_graphs.append(pdt);



	auto makeAxis = [&](QCPAxis* ref, QCPAxis::AxisType type, qmlAxis* qmlAx){
		if (qmlAx)
		{
			if (!qmlAx->isDefault())
				ref = m_CustomPlot.axisRect(0)->addAxis(type);

			ref->setVisible(qmlAx->isVisible());

			if (auto label = qmlAx->getLabel())
			{
				if (!label->getText().isEmpty())
					ref->setLabel(label->getText());
				if (label->getColor().isValid())
					ref->setLabelColor(label->getColor());
				if (!label->getFont().isEmpty())
				{
					QFont axFont; axFont.fromString(label->getFont());
					ref->setLabelFont(axFont);
				}
			}
			
			if (auto tick = qmlAx->getTick())
			{
				if (!tick->getFont().isEmpty())
					ref->setTickLabelFont(tick->getFont());
				const auto& tickVec = tick->getTickVector();
				if (!tickVec.empty())
				{
                    //ref->setAutoTicks(false);
                  //  ref->settic
                    //ref->settick
                    //ref->setTickVector(tickVec);
				}
				const auto& tickLab = tick->getTickLabels();
				if (!tickLab.empty())
				{
                    //ref->setAutoTickLabels(false);
                    //ref->setTickVectorLabels(tickLab);
				}
			}
		}
		return ref;
	};


    //show tag
    if(pdt->istagVisible()){
        if(m_CustomPlot.graphCount()<=0){
      auto  graph = m_CustomPlot.addGraph(
           makeAxis(m_CustomPlot.xAxis, QCPAxis::atBottom, pdt->getXAxis()),
           makeAxis(m_CustomPlot.yAxis, QCPAxis::atLeft, pdt->getYAxis()));
 m_CustomPlot.axisRect()->axis(QCPAxis::atRight,0)->setPadding(90);

       graph->setName(pdt->getName());
       graph->setPen(pdt->getPen()->getPen());
       graph->setLineStyle(pdt->getLineStyle());


          pdt->Tag=new AxisTag(graph->valueAxis());
          pdt->Tag->setTitle(graph->name());
          pdt->Tag->setPen(graph->pen());
        if (auto scatterInfo = pdt->getScatter())
        {
            graph->setScatterStyle(scatterInfo->getStyle());
        }

            }else{
            m_CustomPlot.axisRect()->addAxis(QCPAxis::atRight);
        //     m_CustomPlot.axisRect()->axis(QCPAxis::atRight,m_CustomPlot.graphCount())->setVisible(false);
            auto  graph = m_CustomPlot.addGraph(
                 makeAxis(m_CustomPlot.xAxis, QCPAxis::atBottom, pdt->getXAxis()),
            m_CustomPlot.axisRect()->axis(QCPAxis::atRight,m_CustomPlot.graphCount()));
 m_CustomPlot.axisRect()->axis(QCPAxis::atRight,m_CustomPlot.graphCount()-1)->setPadding(90); //

             graph->setName(pdt->getName());
             graph->setPen(pdt->getPen()->getPen());
             graph->setLineStyle(pdt->getLineStyle());


                pdt->Tag=new AxisTag(graph->valueAxis());
                pdt->Tag->setTitle(graph->name());
                pdt->Tag->setPen(graph->pen());
              if (auto scatterInfo = pdt->getScatter())
              {
                  graph->setScatterStyle(scatterInfo->getStyle());
              }


               //
        }

    }else{


       auto  graph = m_CustomPlot.addGraph(
            makeAxis(m_CustomPlot.xAxis, QCPAxis::atBottom, pdt->getXAxis()),
            makeAxis(m_CustomPlot.yAxis, QCPAxis::atLeft, pdt->getYAxis()));

        graph->setName(pdt->getName());
        graph->setPen(pdt->getPen()->getPen());
        graph->setLineStyle(pdt->getLineStyle());
        if (auto scatterInfo = pdt->getScatter())
        {
            graph->setScatterStyle(scatterInfo->getStyle());
        }
    }


}

void qmlPlotPaintedItem::clearGraphs(QQmlListProperty<qmlGraph> *p)
{
	auto& info = Info(p);
	info.m_graphs.clear();
	info.plot->clearGraphs();
}

int qmlPlotPaintedItem::graphSize(QQmlListProperty<qmlGraph> *p)
{
	return Info(p).m_graphs.size();
}

qmlGraph * qmlPlotPaintedItem::graphAt(QQmlListProperty<qmlGraph> *p, int index)
{
	return Info(p).m_graphs.at(index);
}

void qmlPlotPaintedItem::mousePressEvent(QMouseEvent* event)
{
	routeMouseEvents(event);
}

void qmlPlotPaintedItem::mouseReleaseEvent(QMouseEvent* event)
{
	routeMouseEvents(event);
}

void qmlPlotPaintedItem::mouseMoveEvent(QMouseEvent* event)
{
	routeMouseEvents(event);
}

void qmlPlotPaintedItem::mouseDoubleClickEvent(QMouseEvent* event)
{
	routeMouseEvents(event);
}

void qmlPlotPaintedItem::routeWheelEvents(QWheelEvent* event)
{
	QWheelEvent* newEvent = new QWheelEvent(event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation());
	QCoreApplication::postEvent(&m_CustomPlot, newEvent);
}

void qmlPlotPaintedItem::wheelEvent(QWheelEvent *event)
{
	routeWheelEvents(event);
}

void qmlPlotPaintedItem::onGraphClicked(QCPAbstractPlottable* plottable)
{
}

void qmlPlotPaintedItem::routeMouseEvents(QMouseEvent* event)
{
	QMouseEvent* newEvent = new QMouseEvent(event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers());
	QCoreApplication::postEvent(&m_CustomPlot, newEvent);
}

void qmlPlotPaintedItem::onUpdateCustomPlotSize()
{
	m_CustomPlot.setGeometry(0, 0, width(), height());
	m_CustomPlot.setViewport(QRect(0, 0, (int) width(), (int) height()));
}

void qmlPlotPaintedItem::onCustomReplot()
{
	update();
}

void qmlPlotPaintedItem::exportPDF(const QString& name, int w/*=0*/, int h/*=0*/)
{
    m_CustomPlot.savePdf(name, w, h);
}


void qmlPlotPaintedItem::startdemo(){

    mDataTimer.start(40);
}
