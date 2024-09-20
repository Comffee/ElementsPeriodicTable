#include "ElementsPeriodicTable.h"
#include <qlayout.h>


ElementInfo::ElementInfo(const SElementInfo& seleinfo, QWidget *parent) : QWidget(parent)
{
    InitCtrl(seleinfo);
}

void ElementInfo::InitCtrl(const SElementInfo& seleinfo)
{
    m_pgrbAtomic = new QGroupBox(this);
    auto& clrbkgd = seleinfo.clrBackground;
    auto& clrfrgd = seleinfo.clrForeground;
    m_pgrbAtomic->setStyleSheet(m_cqsBackGround.arg(clrbkgd.red()).arg(clrbkgd.green()).arg(clrbkgd.blue()));
    m_plabAtomicNumber = new QLabel(seleinfo.AtomicNumber, m_pgrbAtomic);
    m_plabAtomicNumber->setStyleSheet((seleinfo.ArtificialFlag)?m_cqsStyle1:m_cqsStyle0);
    m_plabRadiationFlag = new QLabel(m_pgrbAtomic);
    if (seleinfo.RadiationFlag)
    {
        QPixmap pixsl(":/img/img/radiation.png");
        m_plabRadiationFlag->setPixmap(pixsl.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    m_plabAtomicTitle = new QLabel(seleinfo.AtomicTitle, m_pgrbAtomic);
    m_plabAtomicTitle->setStyleSheet(m_cqsStyle2.arg(clrfrgd.red()).arg(clrfrgd.green()).arg(clrfrgd.blue()));
    m_plabAtomicSymbol = new QLabel(seleinfo.AtomicSymbol, m_pgrbAtomic);
    m_plabAtomicSymbol->setStyleSheet(m_cqsStyle2.arg(clrfrgd.red()).arg(clrfrgd.green()).arg(clrfrgd.blue()));
    m_plabAtomicFullName = new QLabel(seleinfo.AtomicFullName, m_pgrbAtomic);
    m_plabAtomicFullName->setStyleSheet(m_cqsStyle3);
    m_plabAtomicRelativeMass1 = new QLabel(seleinfo.AtomicRelativeMass1, m_pgrbAtomic);
    m_plabAtomicRelativeMass1->setStyleSheet(m_cqsStyle3);
    m_plabAtomicRelativeMass2 = new QLabel(seleinfo.AtomicRelativeMass2, m_pgrbAtomic);
    m_plabAtomicRelativeMass2->setStyleSheet(m_cqsStyle4);
    m_plabElectronicLayerLayout = new QLabel(seleinfo.ElectronicLayerLayout, m_pgrbAtomic);
    m_plabElectronicLayerLayout->setStyleSheet(m_cqsStyle4);
    m_plabElectronicLayerLayout->setAlignment(Qt::AlignRight);
    //
    int row = 0;
    int col = 0;
    QGridLayout* gdlay1 = new QGridLayout;
    gdlay1->setMargin(0);
    gdlay1->setVerticalSpacing(0);
    gdlay1->setHorizontalSpacing(2);
    gdlay1->addWidget(m_plabAtomicNumber, row, col++);
    gdlay1->addWidget(m_plabRadiationFlag, row, col++);
    ++row;
    col = 0;
    gdlay1->addWidget(m_plabAtomicTitle, row, col++);
    gdlay1->addWidget(m_plabAtomicSymbol, row, col++);
    //
    QVBoxLayout* verlay1 = new QVBoxLayout;
    verlay1->setMargin(0);
    verlay1->setSpacing(2);
    verlay1->addStretch(1);
    verlay1->addLayout(gdlay1);
    verlay1->addWidget(m_plabAtomicFullName);
    verlay1->addWidget(m_plabAtomicRelativeMass1);
    verlay1->addWidget(m_plabAtomicRelativeMass2);
    verlay1->addStretch(1);
    //
    QHBoxLayout* horlay1 = new QHBoxLayout;
    horlay1->setMargin(2);
    horlay1->setSpacing(2);
    horlay1->addStretch(1);
    horlay1->addLayout(verlay1);
    horlay1->addStretch(2);
    horlay1->addSpacing(2);
    horlay1->addWidget(m_plabElectronicLayerLayout, 0, Qt::AlignCenter);
    horlay1->addStretch(1);
    m_pgrbAtomic->setLayout(horlay1);
    //
    QHBoxLayout* horlay = new QHBoxLayout;
    horlay->setMargin(0);
    horlay->addWidget(m_pgrbAtomic);
    setLayout(horlay);
}


ElementsPeriodicTable::ElementsPeriodicTable(QWidget *parent) : QWidget(parent)
{
    InitCtrl();
}

void ElementsPeriodicTable::InitCtrl(void)
{
#if 1
    m_plabElementsPeriodicTable = new QLabel("<font style='color:#00007F;font-size:60px;font-weight:bold;font-family:黑体;'>元素周期表</font>", this);
    for (int i=0;i<18;++i)
    {
        m_plabAtomicFamily[i] = new QLabel(m_cqsAtomicFamily[i], this);
        m_plabAtomicFamily[i]->setStyleSheet("QLabel{font-size:20px;font-weight:bold;border:1px solid rgb(0,0,0);background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #89C1E5,stop:1 #C4E5F0);}");
        m_plabAtomicFamily[i]->setAlignment(Qt::AlignCenter);
    }
    int row = 0;
    int col = 0;
    QGridLayout* gdlay1 = new QGridLayout;
    gdlay1->setMargin(0);
    gdlay1->setSpacing(0);
    int ind = 0;
    gdlay1->addWidget(m_plabAtomicFamily[0], row, 0, Qt::AlignBottom);
    gdlay1->addWidget(m_plabAtomicFamily[17], row, 17, Qt::AlignBottom);
    ++row;
    gdlay1->addWidget(m_plabAtomicFamily[1], row, 1, Qt::AlignBottom);
    for (int i=12;i<18;++i)
    {
        gdlay1->addWidget(m_plabAtomicFamily[i], row, i, Qt::AlignBottom);
    }
    for (;ind<1;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    col = 17;
    for (;ind<2;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    ++row;
    col = 0;
    for (;ind<4;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    col = 12;
    for (;ind<10;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    ++row;
    for (int i=2;i<12;++i)
    {
        gdlay1->addWidget(m_plabAtomicFamily[i], row, i, Qt::AlignBottom);
    }
    col = 0;
    for (;ind<12;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    col = 12;
    for (;ind<18;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        gdlay1->addWidget(pele, row, col++);
    }
    //
    for (;ind<90;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        if ((ind % 18)==0)
        {
            ++row;
            col = 0;
        }
        gdlay1->addWidget(pele, row, col++);
    }
    QSpacerItem* pspisapce = new QSpacerItem(20, 10);
    gdlay1->addItem(pspisapce, ++row, 0);
    for (;ind<120;++ind)
    {
        m_peleAtomicInfo[ind] = new ElementInfo(m_arsElementInfo[ind], this);
        auto pele = m_peleAtomicInfo[ind];
        if ((ind % 15)==0)
        {
            ++row;
            col = 2;
        }
        gdlay1->addWidget(pele, row, col++);
    }
    //
    m_peleAtomicLegend = new ElementInfo(m_sElementLegend, this);
    m_plabAtomicLegend[0][0] = new QLabel(QString("<h3>\"%1\"</h3>").arg(m_sElementLegend.AtomicNumber), this);
    m_plabAtomicLegend[0][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[0][1] = new QLabel("-原子序数(<font color=red>红色</font>为人造元素)", this);
    m_plabAtomicLegend[1][0] = new QLabel(QString("<h3>\"%1\"</h3>").arg(m_sElementLegend.AtomicTitle), this);
    m_plabAtomicLegend[1][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[1][1] = new QLabel("-元素中文名称", this);
    m_plabAtomicLegend[2][0] = new QLabel(QString("<h3>\"%1\"</h3>").arg(m_sElementLegend.AtomicSymbol), this);
    m_plabAtomicLegend[2][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[2][1] = new QLabel("-元素符号", this);
    m_plabAtomicLegend[3][0] = new QLabel(QString("\"%1\"").arg(m_sElementLegend.AtomicFullName), this);
    m_plabAtomicLegend[3][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[3][1] = new QLabel("-元素英文名称", this);
    //
    QGridLayout* gdlay2 = new QGridLayout;
    gdlay2->setMargin(0);
    gdlay2->setVerticalSpacing(5);
    gdlay2->setHorizontalSpacing(10);
    gdlay2->addWidget(m_plabAtomicLegend[0][0], 0, 0);
    gdlay2->addWidget(m_plabAtomicLegend[0][1], 0, 1);
    gdlay2->addWidget(m_plabAtomicLegend[1][0], 1, 0);
    gdlay2->addWidget(m_plabAtomicLegend[1][1], 1, 1);
    gdlay2->addWidget(m_plabAtomicLegend[2][0], 2, 0);
    gdlay2->addWidget(m_plabAtomicLegend[2][1], 2, 1);
    gdlay2->addWidget(m_plabAtomicLegend[3][0], 3, 0);
    gdlay2->addWidget(m_plabAtomicLegend[3][1], 3, 1);
    //
    m_plabAtomicLegend[4][0] = new QLabel(this);
    QPixmap pixsl(":/img/img/radiation.png");
    m_plabAtomicLegend[4][0]->setPixmap(pixsl.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    m_plabAtomicLegend[4][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[4][1] = new QLabel("-放射性标志", this);
    m_plabAtomicLegend[5][0] = new QLabel(QString("<h3>\"%1\"</h3>").arg(m_sElementLegend.AtomicRelativeMass1), this);
    m_plabAtomicLegend[5][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[5][1] = new QLabel("-惯用相对原子质量", this);
    m_plabAtomicLegend[6][0] = new QLabel(QString("\"%1\"").arg(m_sElementLegend.AtomicRelativeMass2), this);
    m_plabAtomicLegend[6][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[6][1] = new QLabel("-标准原子量", this);
    m_plabAtomicLegend[7][0] = new QLabel(QString("\"%1\"").arg(m_sElementLegend.ElectronicLayerLayout.replace('\n', ',')), this);
    m_plabAtomicLegend[7][0]->setAlignment(Qt::AlignCenter);
    m_plabAtomicLegend[7][1] = new QLabel("-电子层排布", this);
    //
    QGridLayout* gdlay3 = new QGridLayout;
    gdlay3->setMargin(0);
    gdlay3->setVerticalSpacing(5);
    gdlay3->setHorizontalSpacing(10);
    gdlay3->addWidget(m_plabAtomicLegend[4][0], 0, 0);
    gdlay3->addWidget(m_plabAtomicLegend[4][1], 0, 1);
    gdlay3->addWidget(m_plabAtomicLegend[5][0], 1, 0);
    gdlay3->addWidget(m_plabAtomicLegend[5][1], 1, 1);
    gdlay3->addWidget(m_plabAtomicLegend[6][0], 2, 0);
    gdlay3->addWidget(m_plabAtomicLegend[6][1], 2, 1);
    gdlay3->addWidget(m_plabAtomicLegend[7][0], 3, 0);
    gdlay3->addWidget(m_plabAtomicLegend[7][1], 3, 1);
    //
    //m_plabAtomicLegend[0][0] = new QLabel("<p>原子序数(<font color=red>红色</font>标记的为人造元素)</p><p>元素中文名称 元素符号</p><p>元素英文名称</p>", this);
    //m_plabAtomicLegend[0][1] = new QLabel("<p>放射性标志</p><p>电子层排布</p><p>惯用相对原子质量</p><p>标准原子量</p>", this);
    m_plabAtomicLegend[8][0] = new QLabel("1~18", this);
    m_plabAtomicLegend[8][1] = new QLabel("-族序号", this);
    m_plabAtomicLegend[9][0] = new QLabel("I<font color=red>A</font>~VII<font color=red>A</font>", this);
    m_plabAtomicLegend[9][1] = new QLabel("-主族序号", this);
    m_plabAtomicLegend[10][0] = new QLabel("I<font color=#00C000>B</font>~VI<font color=#00C000>B</font>", this);//2DCB5D
    m_plabAtomicLegend[10][1] = new QLabel("-附族序号", this);
    m_plabAtomicLegend[11][0] = new QLabel("VIII", this);
    m_plabAtomicLegend[11][1] = new QLabel("-第VIII族", this);
    //
    QGridLayout* gdlay4 = new QGridLayout;
    gdlay4->setMargin(0);
    gdlay4->setVerticalSpacing(5);
    gdlay4->setHorizontalSpacing(10);
    gdlay4->addWidget(m_plabAtomicLegend[8][0], 0, 0);
    gdlay4->addWidget(m_plabAtomicLegend[8][1], 0, 1);
    gdlay4->addWidget(m_plabAtomicLegend[9][0], 1, 0);
    gdlay4->addWidget(m_plabAtomicLegend[9][1], 1, 1);
    gdlay4->addWidget(m_plabAtomicLegend[10][0], 2, 0);
    gdlay4->addWidget(m_plabAtomicLegend[10][1], 2, 1);
    gdlay4->addWidget(m_plabAtomicLegend[11][0], 3, 0);
    gdlay4->addWidget(m_plabAtomicLegend[11][1], 3, 1);
    //
    m_plabAtomicExample[0][0] = new QLabel("\"<font color=#FFFFFF style='background:#000;'>元素名称</font>\"", this);
    m_plabAtomicExample[0][0]->setFixedSize(90,25);
    m_plabAtomicExample[0][1] = new QLabel("-该元素的单质在常温常压下为<font color=#FFFFFF style='font-size:20px;font-weight:bold;background:#000;'> 气态 </font>", this);//A0A0A0
    m_plabAtomicExample[1][0] = new QLabel("\"<font color=#405CFF>元素名称</font>\"", this);
    m_plabAtomicExample[1][0]->setFixedSize(90,25);
    m_plabAtomicExample[1][1] = new QLabel("-该元素的单质在常温常压下为<font color=#405CFF style='font-size:20px;font-weight:bold;'> 液态 </font>", this);
    m_plabAtomicExample[2][0] = new QLabel("\"<font color=#000000>元素名称</font>\"", this);
    m_plabAtomicExample[2][0]->setFixedSize(90,25);
    m_plabAtomicExample[2][1] = new QLabel("-该元素的单质在常温常压下为<font color=#000000 style='font-size:20px;font-weight:bold;'> 固态 </font>", this);
    //
    QGridLayout* gdlay5 = new QGridLayout;
    gdlay5->setMargin(0);
    gdlay5->setVerticalSpacing(2);
    gdlay5->setHorizontalSpacing(3);
    gdlay5->addWidget(m_plabAtomicExample[0][0], 0, 0);
    gdlay5->addWidget(m_plabAtomicExample[0][1], 0, 1);
    gdlay5->addWidget(m_plabAtomicExample[1][0], 1, 0);
    gdlay5->addWidget(m_plabAtomicExample[1][1], 1, 1);
    gdlay5->addWidget(m_plabAtomicExample[2][0], 2, 0);
    gdlay5->addWidget(m_plabAtomicExample[2][1], 2, 1);
    //
    m_plabAtomicExample[3][0] = new QLabel(this);
    m_plabAtomicExample[3][0]->setFixedSize(25,25);
    m_plabAtomicExample[3][0]->setStyleSheet("QLabel{background:rgb(45,203,93);border:1px solid rgb(0,0,0);}");
    m_plabAtomicExample[3][1] = new QLabel("非金属元素(除稀有气体元素)", this);
    m_plabAtomicExample[4][0] = new QLabel(this);
    m_plabAtomicExample[4][0]->setFixedSize(25,25);
    m_plabAtomicExample[4][0]->setStyleSheet("QLabel{background:rgb(160,160,160);border:1px solid rgb(0,0,0);}");
    m_plabAtomicExample[4][1] = new QLabel("非金属元素(稀有气体元素)", this);
    m_plabAtomicExample[5][0] = new QLabel(this);
    m_plabAtomicExample[5][0]->setFixedSize(25,25);
    m_plabAtomicExample[5][0]->setStyleSheet("QLabel{background:rgb(252,252,81);border:1px solid rgb(0,0,0);}");
    m_plabAtomicExample[5][1] = new QLabel("碱金属元素", this);
    m_plabAtomicExample[6][0] = new QLabel(this);
    m_plabAtomicExample[6][0]->setFixedSize(25,25);
    m_plabAtomicExample[6][0]->setStyleSheet("QLabel{background:rgb(244,214,84);border:1px solid rgb(0,0,0);}");
    m_plabAtomicExample[6][1] = new QLabel("碱士金属元素", this);
    m_plabAtomicExample[7][0] = new QLabel(this);
    m_plabAtomicExample[7][0]->setFixedSize(25,25);
    m_plabAtomicExample[7][0]->setStyleSheet("QLabel{background:rgb(252,157,73);border:1px solid rgb(0,0,0);}");
    m_plabAtomicExample[7][1] = new QLabel("主族其它金属元素", this);
    m_plabAtomicExample[8][0] = new QLabel(this);
    m_plabAtomicExample[8][0]->setFixedSize(25,25);
    m_plabAtomicExample[8][0]->setStyleSheet("QLabel{background:rgb(145,150,255);border:1px solid rgb(0,0,0);}");//
    m_plabAtomicExample[8][1] = new QLabel("准金属元素", this);
    m_plabAtomicExample[9][0] = new QLabel(this);
    m_plabAtomicExample[9][0]->setFixedSize(25,25);
    m_plabAtomicExample[9][0]->setStyleSheet("QLabel{background:rgb(204,255,83);border:1px solid rgb(0,0,0);}");//
    m_plabAtomicExample[9][1] = new QLabel("附族元素(过渡金属元素)", this);
    m_plabAtomicExample[10][0] = new QLabel(this);
    m_plabAtomicExample[10][0]->setFixedSize(25,25);
    m_plabAtomicExample[10][0]->setStyleSheet("QLabel{background:rgb(108,209,251);border:1px solid rgb(0,0,0);}");//145,150,255
    m_plabAtomicExample[10][1] = new QLabel("附族元素(稀有金属元素)", this);
    //
    QGridLayout* gdlay7 = new QGridLayout;
    gdlay7->setMargin(0);
    gdlay7->setVerticalSpacing(5);
    gdlay7->setHorizontalSpacing(3);
    gdlay7->addWidget(m_plabAtomicExample[3][0], 0, 0);
    gdlay7->addWidget(m_plabAtomicExample[3][1], 0, 1);
    gdlay7->addWidget(m_plabAtomicExample[4][0], 1, 0);
    gdlay7->addWidget(m_plabAtomicExample[4][1], 1, 1);
    gdlay7->addWidget(m_plabAtomicExample[5][0], 2, 0);
    gdlay7->addWidget(m_plabAtomicExample[5][1], 2, 1);
    gdlay7->addWidget(m_plabAtomicExample[6][0], 3, 0);
    gdlay7->addWidget(m_plabAtomicExample[6][1], 3, 1);
    gdlay7->addWidget(m_plabAtomicExample[7][0], 4, 0);
    gdlay7->addWidget(m_plabAtomicExample[7][1], 4, 1);
    gdlay7->addWidget(m_plabAtomicExample[8][0], 5, 0);
    gdlay7->addWidget(m_plabAtomicExample[8][1], 5, 1);
    gdlay7->addWidget(m_plabAtomicExample[9][0], 6, 0);
    gdlay7->addWidget(m_plabAtomicExample[9][1], 6, 1);
    gdlay7->addWidget(m_plabAtomicExample[10][0], 7, 0);
    gdlay7->addWidget(m_plabAtomicExample[10][1], 7, 1);
    //
    gdlay1->addWidget(m_plabElementsPeriodicTable, 0, 3, 1, 8, Qt::AlignCenter);
    gdlay1->addLayout(gdlay2, 2, 2, 1, 3, Qt::AlignRight);
    gdlay1->addWidget(m_peleAtomicLegend, 2, 5);
    gdlay1->addLayout(gdlay3, 2, 6, 1, 3, Qt::AlignLeft);
    gdlay1->addLayout(gdlay4, 1, 2, 1, 2, Qt::AlignTop|Qt::AlignHCenter);
    gdlay1->addLayout(gdlay5, 1, 6, 1, 3, Qt::AlignCenter);
    gdlay1->addLayout(gdlay7, 1, 9, 3, 3, Qt::AlignTop|Qt::AlignHCenter);
    setLayout(gdlay1);
#else
    const int cicnt = 15;
    QGridLayout* gdlay1 = new QGridLayout;
    gdlay1->setMargin(0);
    gdlay1->setSpacing(0);
    for (int i=0;i<m_sciElementCount;++i)
    {
        m_peleAtomicInfo[i] = new ElementInfo(m_arsElementInfo[i], this);
        auto pele = m_peleAtomicInfo[i];
        //pele->setFixedSize(200, 200);
        gdlay1->addWidget(pele, i/cicnt, i%cicnt);
    }
    setLayout(gdlay1);
#endif
}
