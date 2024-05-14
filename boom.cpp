#include "boom.h"

Boom::Boom()
{
  for(int i=1;i<=BOOM_MAX;i++)
  {
      QString str=QString(BOOM_PATH).arg(i);
      m_pixArr.push_back(QPixmap(str));
  }

  m_X=0;
  m_Y=0;

  m_Free=true;
  m_index=0;

  m_Recoder=0;
}

void Boom::updateInfo()
{
    if(m_Free)
    {
        return;
    }

    m_Recoder++;
     if(m_Recoder<BOOM_INTERVAL)
     {
         return;
     }

     m_Recoder=0;

     m_index++;

     if(m_index>BOOM_MAX-1)
     {
        m_index=0;
        m_Free=true;
     }
}
