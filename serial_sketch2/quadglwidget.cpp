#include "quadglwidget.h"
#include "modelobj.h"
#include <QVector3D>
#include <QMouseEvent>
#include <math.h>
#include <iostream>

static GLfloat Radius=200;

quadGLWidget::quadGLWidget(QWidget *parent):
    QOpenGLWidget(parent),
    vertexBuf(QOpenGLBuffer::VertexBuffer),
    colorBuf(QOpenGLBuffer::VertexBuffer),
    indexBuf(QOpenGLBuffer::IndexBuffer),
    zoomRate(2.5)
{
    quadrotor.Load(":/Quadobj.obj");
    //Set the widget to accepts keyboard focus by both tabbing and clicking.
    this->setFocusPolicy(Qt::StrongFocus);
}

quadGLWidget::~quadGLWidget()
{
    // Make sure the context is current when deleting the texture
    // and the buffers.
    makeCurrent();
    vertexBuf.destroy();
    colorBuf.destroy();
    indexBuf.destroy();
    doneCurrent();
}

void quadGLWidget::keyPressEvent(QKeyEvent *e)
{
    keyModifier=e->modifiers();
    switch (keyModifier)
    {
    case Qt::NoModifier:
        std::cout<<"No modifier pressed.\n";
        break;
    case Qt::ShiftModifier:
        std::cout<<"Shift modifier pressed.\n";
        break;
    case Qt::ControlModifier:
        std::cout<<"Control modifier pressed.\n";
        break;
    case Qt::AltModifier:
        std::cout<<"Alt modifier pressed.\n";
        break;
    default:
        break;
    }
}

void quadGLWidget::keyReleaseEvent(QKeyEvent *e)
{
    keyModifier=e->modifiers();
  /*  std::cout<<"Key release event:";
    switch (keyModifier)
    {
    case Qt::NoModifier:
        std::cout<<"No modifier released.\n";
        break;
    case Qt::ShiftModifier:
        std::cout<<"Shift modifier released.\n";
        break;
    case Qt::ControlModifier:
        std::cout<<"Control modifier released.\n";
        break;
    case Qt::AltModifier:
        std::cout<<"Alt modifier released.\n";
        break;
    default:
        break;
    }*/
}

void quadGLWidget::mousePressEvent(QMouseEvent *e)
{
    // Save mouse press position
    mousePos = e->localPos();
    pressedButton=e->button();

    setCursor(QCursor(Qt::ClosedHandCursor));

    /*if (pressedButton==Qt::LeftButton)
        std::cout<<"LeftButton: ";
    else if (pressedButton==Qt::MiddleButton)
        std::cout<<"MiddleButton: ";
    else if (pressedButton==Qt::RightButton)
        std::cout<<"RightButton: ";
    std::cout<<mousePos.x()<<" "<<mousePos.y()<<std::endl;*/
}

void quadGLWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPointF diff(e->localPos()-mousePos);

    if (keyModifier==Qt::ControlModifier)
    {
        if (pressedButton==Qt::LeftButton)
        {
            qreal tempRate=zoomRate;
            zoomRate*=1-0.01*diff.y();
            zoomRate=(zoomRate<0.1)?0.1:((zoomRate>20)?20:zoomRate);
            std::cout<<"zoomRate: "<<zoomRate<<std::endl;
            tempRate=tempRate/zoomRate;
            // Set perspective projection
            projection.ortho(-tempRate,tempRate,-tempRate,tempRate,1,-1);
        }
        else if (pressedButton==Qt::RightButton)
        {

        }
    }
    else
    {
        if (pressedButton==Qt::LeftButton)
        {
            QVector3D rotVector(diff.y(),diff.x(),0);
            rotVector/=Radius;
            GLfloat length=rotVector.length();
            rotVector.normalize();
            if (length>0.00001)
                rotation=QQuaternion(cos(length/2),sin(length/2)*rotVector);
        }
        else if (pressedButton==Qt::RightButton)
        {
            GLfloat dphy=atan2(this->height()/2.0-e->y(),e->x()-this->width()/2.0)-atan2(this->height()/2.0-mousePos.y(),mousePos.x()-this->width()/2.0);
            rotation=QQuaternion(cos(dphy/2),sin(dphy/2)*QVector3D(0,0,1));
        }
    }

    //std::cout<<'('<<dq.scalar()<<','<<dq.x()<<','<<dq.y()<<','<<dq.z()<<')'<<"   ";
    //std::cout<<'('<<rotation.scalar()<<','<<rotation.x()<<','<<rotation.y()<<','<<rotation.z()<<')'<<std::endl;
    mousePos = e->localPos();
    update();
}

void quadGLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    setCursor(QCursor(Qt::OpenHandCursor));
}

void quadGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0, 0, 0, 1);

    initShaders();

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable back face culling
    glEnable(GL_CULL_FACE);

    // Generate 2 VBOs
    vertexBuf.create();
    colorBuf.create();
    indexBuf.create();

    // Transfer vertex data to VBO 0
    vertexBuf.bind();
    vertexBuf.allocate((void*)(&quadrotor.m_vVertex[0]), quadrotor.m_vVertex.size()* sizeof(QVector3D));

    // Offset for position
    quintptr offset = 0;
    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program.attributeLocation("vPosition");
    program.enableAttributeArray(vertexLocation);
    program.setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, 0);

    colorBuf.bind();
    colorBuf.allocate((void*)(&quadrotor.m_vColor[0]), quadrotor.m_vColor.size()* sizeof(QVector3D));
    // Tell OpenGL programmable pipeline how to locate vertex position data
    int colorLocation = program.attributeLocation("vColor");
    program.enableAttributeArray(colorLocation);
    program.setAttributeBuffer(colorLocation, GL_FLOAT, offset, 3, 0);

    // Transfer index data to VBO 1
    indexBuf.bind();
    indexBuf.allocate((void*)(&quadrotor.m_vFace[0].m_uiVertIdx[0]), quadrotor.m_vFace.size()* 3 * sizeof(GLuint));

    QVector3D center;
    for (int i=0;i<quadrotor.m_vVertex.size();i++)
        center+=quadrotor.m_vVertex[i];

    center/=quadrotor.m_vVertex.size();
    center=-center;

    ModelView.setToIdentity();
    ModelView.translate(center);
}

void quadGLWidget::initShaders()
{
    // Compile vertex shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
        close();

    // Compile fragment shader
    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fshader.glsl"))
        close();

    // Link shader pipeline
    if (!program.link())
        close();

    // Bind shader pipeline for use
    if (!program.bind())
        close();
}

//! [5]
void quadGLWidget::resizeGL(int w, int h)
{
    // Calculate aspect ratio
    qreal aspect = qreal(w) / qreal(h ? h : 1);

    // Set near plane to 0.0, far plane to 10.0
    const qreal zNear = -15.0, zFar = 30.0;

    // Reset projection
    projection.setToIdentity();

    // Set perspective projection
    projection.ortho(-10*aspect,10*aspect,-10,10,zNear,zFar);
}
//! [5]

void quadGLWidget::paintGL()
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Calculate model view transformation
    ModelView.rotate(rotation);
     // Set modelview-projection matrix
    program.setUniformValue("mvp_matrix", projection * ModelView);

    // Draw cube geometry using indices from VBO 1
    glDrawElements(GL_TRIANGLES, quadrotor.m_vFace.size()* 3, GL_UNSIGNED_INT, 0);
}
