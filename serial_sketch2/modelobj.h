#ifndef MODELOBJ_H
#define MODELOBJ_H
#include <QVector>
#include <QVector3D>

//-------------------------------------------------------------
//- SObjFace
//- Indices for each face of the OBJ file
class SObjFace
{
public:
    SObjFace()
    {
        SObjFace(0,0,0);
    }

    SObjFace(unsigned int vi1,unsigned int vi2,unsigned int vi3)
    {
        //copy the data;
        m_uiVertIdx[0] = vi1-1;
        m_uiVertIdx[1] = vi2-1;
        m_uiVertIdx[2] = vi3-1;
    }
    unsigned int m_uiVertIdx[3];
};

class ModelObj
{
public:
    ModelObj();
    ModelObj(const char * szFilename);
    //Load the model
    bool Load(const char * szFilename);

    QVector<QVector3D> m_vVertex;
    QVector<QVector3D> m_vColor;
    QVector<SObjFace> m_vFace;
};

#endif // MODELOBJ_H
