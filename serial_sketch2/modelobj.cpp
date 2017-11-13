#include "modelobj.h"
#include <QTextStream>
#include <QFile>
#include <QStringList>
#include <QString>
#include <QDataStream>
#include <QByteArray>
#include <QOpenGLFunctions>

ModelObj::ModelObj()
{

}

ModelObj::ModelObj(const char *szFilename)
{
    Load(szFilename);
}

bool ModelObj::Load(const char *szFilename)
{
    QTextStream out(stdout,QIODevice::WriteOnly);

    QFile modelFile(szFilename);
    if (modelFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&modelFile);

        while (!in.atEnd())
        {
            QString data=in.readLine(128);

            if (data.at(0)=='v')
            {
                data=data.right(data.size()-2);
                QStringList splitdata=data.split(' ', QString::SkipEmptyParts);
                m_vVertex.push_back(QVector3D(splitdata[0].toFloat(),
                                    splitdata[1].toFloat(),
                        splitdata[2].toFloat()));
                m_vColor.push_back(QVector3D(splitdata[3].toFloat(),
                                   splitdata[4].toFloat(),
                       splitdata[5].toFloat())/255);

                //out<<m_vVertex.last().x()<<','<<m_vVertex.last().y()<<','<<m_vVertex.last().z()<<' '
              //  <<m_vColor.last().x()<<','<<m_vColor.last().y()<<','<<m_vColor.last().z()<<'\n';
            }
            else if (data.at(0)=='f')
            {
                data=data.right(data.size()-2);
                QStringList splitdata=data.split(' ', QString::SkipEmptyParts);
                m_vFace.push_back(SObjFace(splitdata[0].toUInt(),
                                    splitdata[1].toUInt(),
                        splitdata[2].toUInt()));
            }
        }

        return true;
    }
    else
    {
        out<<"Failed to open file.";
        return false;
    }
}
