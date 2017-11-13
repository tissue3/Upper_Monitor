#ifndef QUADGLWIDGET_H
#define QUADGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include "modelobj.h"

class quadGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    quadGLWidget(QWidget *parent = 0);
    ~quadGLWidget();

protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent *e) Q_DECL_OVERRIDE;

    void initializeGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;

    void initShaders();

private:
    QOpenGLShaderProgram program;

    QOpenGLBuffer vertexBuf;
    QOpenGLBuffer colorBuf;
    QOpenGLBuffer indexBuf;

    ModelObj quadrotor;

    QMatrix4x4 projection;
    QMatrix4x4 ModelView;

    Qt::KeyboardModifiers keyModifier;
    QPointF mousePos;
    Qt::MouseButton pressedButton;

    qreal zoomRate;
    QQuaternion rotation;

};

#endif // QUADGLWIDGET_H
