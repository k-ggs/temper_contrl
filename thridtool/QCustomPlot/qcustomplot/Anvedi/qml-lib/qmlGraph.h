#pragma once
#include <QObject>
#include "qcustomplot.h"
#include "qmlScatterStyle.h"
#include "qmlAxis.h"
#include"axistag.h"
class qmlGraph : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName)
	Q_PROPERTY(qmlAxis* xAxis READ getXAxis WRITE setXAxis)
	Q_PROPERTY(qmlAxis* yAxis READ getYAxis WRITE setYAxis)
	Q_PROPERTY(qmlScatterStyle* scatter READ getScatter WRITE setScatter)
	Q_PROPERTY(qmlPen* pen READ getPen WRITE setPen)	
	Q_PROPERTY(QCPGraph::LineStyle style READ getLineStyle WRITE setLineStyle)

    Q_PROPERTY(bool tagvisible READ istagVisible WRITE setTagVisible)
public:
	const QString& getName() const;
	void setName(const QString& arg);

	qmlAxis* getXAxis() const;
	void setXAxis(qmlAxis* axis);

	qmlAxis* getYAxis() const;
	void setYAxis(qmlAxis* axis);

	qmlScatterStyle* getScatter();
	void setScatter(qmlScatterStyle* s);

	qmlPen* getPen();
	void setPen(qmlPen* p);

	QCPGraph::LineStyle getLineStyle() const;
	void setLineStyle(QCPGraph::LineStyle l);

    bool istagVisible() const;
    void setTagVisible(bool d);


 AxisTag *Tag=nullptr;
private:
	QString name;
	qmlScatterStyle* scatter = nullptr;
	qmlPen* pen = nullptr;
	QCPGraph::LineStyle lineStyle = QCPGraph::lsLine;
	qmlAxis* xAxis = nullptr;
	qmlAxis* yAxis = nullptr;


    bool visible = true;
};
