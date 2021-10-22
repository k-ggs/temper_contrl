#ifndef QCUSTOM_API_H
#define QCUSTOM_API_H

#include <QtQuick>
#include <QObject>
#include"qcustomplot.h"
#include"axistag.h"
class QCPAbstractPlottable;
class qcustom_api : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit qcustom_api(QQuickItem *parent = nullptr);
    ~qcustom_api();
  void paint( QPainter* painter );
protected:
    void routeMouseEvents( QMouseEvent* event );
    void routeWheelEvents( QWheelEvent* event );

    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );
    virtual void wheelEvent( QWheelEvent *event );
private:
  QCustomPlot*         m_CustomPlot;
  QPointer<QCPGraph> mGraph1;
  AxisTag *mTag1;
 QTimer mDataTimer;
public slots:
   void onCustomReplot();
   void initCustomPlot();
   void updateCustomPlotSize();
   void updateData(double *data,int len);

   void legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item);
   void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
   void selectionChanged();

     void timerSlot();
signals:

};

#endif // QCUSTOM_API_H
