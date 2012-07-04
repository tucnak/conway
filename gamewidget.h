#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QColor>
#include <QWidget>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    
signals:
    
public slots:
    void startGame(const int &number = -1);
    void stopGame();
    void clear();

    int cellNumber();
    void setCellNumber(const int &s);

    int interval();
    void setInterval(int msec);

    QColor masterColor();
    void setMasterColor(const QColor &color);

    QString dump();
    void setDump(const QString &data);

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    bool universe[102][102]; // map
    int universeSize;
    bool isAlive(int k, int j); // return true if universe[k][j] accept rules
    
};

#endif // GAMEWIDGET_H
