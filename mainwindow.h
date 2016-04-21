/**
* Main view controller for the CountUp game
*
* CS3505, April 2016.
* Team: It's Lit (fire, fire, fire)
*
* @author Adam Sorensen
*         Connor Douglas
*         Johnny Le
*         Michelle Nguyen
*         Steven Sun
*         Trung Le
*         Yu Song
*         Zhi Wong
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamemodel.h>
#include <mathnode.h>
#include <QMouseEvent>
#include <Box2D/Box2D.h>
#include <Box2D/Dynamics/b2World.h>
#include <QTimerEvent>


namespace Ui {
class MainWindow;
}

enum {
    BallObject,
    WallObject,
};

struct Object
{
    int type;
    b2Body *body;
    b2Fixture *fixture;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    GameModel game;
    b2World* World;
    b2Body* groundBody;
    int _timerId = 0;
    QTransform _transform;
    QVector<Object> _objects;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void fillGrid(MathNode model[][10]);
    void start();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_cellEntered(int row, int column);

    bool eventFilter(QObject *obj, QEvent *event);

    void on_entry();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent *);
    Object createWall(float32 x, float32 y, float32 w, float32 h, float32 angle);
    Object createBall(const b2Vec2& pos, float32 radius);
    void drawWall(QPainter *p, const Object& o);
    void drawEllipse(QPainter *p, const Object& o);

};

#endif // MAINWINDOW_H
