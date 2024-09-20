#pragma once

#include <QWidget>
#include <qgroupbox.h>
#include <qlabel.h>


struct SElementInfo
{
    QString AtomicNumber;
    bool RadiationFlag;
    bool ArtificialFlag;
    QString AtomicTitle;
    QString AtomicSymbol;
    QString AtomicFullName;
    QString AtomicRelativeMass1;
    QString AtomicRelativeMass2;
    QString ElectronicLayerLayout;
    QColor clrBackground;
    QColor clrForeground;
    //
    SElementInfo(const QString& num, bool rad, bool art, const QString& tit, const QString& sym
                 , const QString& fun, const QString& relm1, const QString& relm2
                 , const QString& elelay, const QColor& bkgd, const QColor& frgd)
        : AtomicNumber(num)
        , RadiationFlag(rad)
        , ArtificialFlag(art)
        , AtomicTitle(tit)
        , AtomicSymbol(sym)
        , AtomicFullName(fun)
        , AtomicRelativeMass1(relm1)
        , AtomicRelativeMass2(relm2)
        , ElectronicLayerLayout(elelay)
        , clrBackground(bkgd)
        , clrForeground(frgd)
    {
    }
};

class ElementInfo : public QWidget
{
    Q_OBJECT
public:
    explicit ElementInfo(const SElementInfo& seleinfo, QWidget *parent = nullptr);

private:
    QGroupBox* m_pgrbAtomic = nullptr;
    QLabel* m_plabAtomicNumber = nullptr;
    QLabel* m_plabRadiationFlag = nullptr;
    QLabel* m_plabAtomicTitle = nullptr;
    QLabel* m_plabAtomicSymbol = nullptr;
    QLabel* m_plabAtomicFullName = nullptr;
    QLabel* m_plabAtomicRelativeMass1 = nullptr;
    QLabel* m_plabAtomicRelativeMass2 = nullptr;
    QLabel* m_plabElectronicLayerLayout = nullptr;
    //
    QColor m_clrBackground;
    QColor m_clrForeground;
    //
    const QString m_cqsBackGround = "QGroupBox{background:rgb(%1,%2,%3);border:1px solid rgb(0,0,0);}";
    const QString m_cqsStyle0 = "QLabel{font-size:24px;font-weight:bold;color:rgb(0,0,0);}";
    const QString m_cqsStyle1 = "QLabel{font-size:24px;font-weight:bold;color:rgb(255,0,0);}";
    const QString m_cqsStyle2 = "QLabel{font-size:32px;color:rgb(%1,%2,%3);}";
    const QString m_cqsStyle3 = "QLabel{font-size:16px;}";
    const QString m_cqsStyle4 = "QLabel{font-size:12px;}";

private:
    void InitCtrl(const SElementInfo& seleinfo);
};


class ElementsPeriodicTable : public QWidget
{
    Q_OBJECT
public:
    explicit ElementsPeriodicTable(QWidget *parent = nullptr);

public:
    static const int m_sciElementCount = 120;
    SElementInfo m_arsElementInfo[m_sciElementCount] = {
        {"1", false, false, "氢", "H", "Hydrogen", "1.008", "1.0078-1.0082", "1", QColor(45,203,93), QColor(255,255,255)}
        , {"2", false, false, "氦", "He", "Hellum", "4.0026", "4.002602", "2", QColor(160,160,160), QColor(255,255,255)}
        , {"3", false, false, "锂", "Li", "Lithium", "6.94", "6.938-6.997", "2\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"4", false, false, "铍", "Be", "Beryllium", "9.0122", "9.0122", "2\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"5", false, false, "硼", "B", "Boron", "10.81", "10.806-10.821", "2\n3", QColor(45,203,93), QColor(0,0,0)}
        , {"6", false, false, "碳", "C", "Carbon", "12.011", "12.009-12.012", "2\n4", QColor(45,203,93), QColor(0,0,0)}
        , {"7", false, false, "氮", "N", "Nitrogen", "14.007", "4.002602", "2\n5", QColor(45,203,93), QColor(255,255,255)}
        , {"8", false, false, "氧", "O", "Oxygen", "15.999", "15.999-16.000", "2\n6", QColor(45,203,93), QColor(255,255,255)}
        , {"9", false, false, "氟", "F", "Fluorine", "18.998", "18.998", "2\n7", QColor(45,203,93), QColor(255,255,255)}
        , {"10", false, false, "氖", "Ne", "Neon", "20.180", "20.180", "2\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"11", false, false, "钠", "Na", "Sodium", "22.990", "22.990", "2\n8\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"12", false, false, "镁", "Mg", "Magnesium", "24.305", "24.304-24.307", "2\n8\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"13", false, false, "铝", "Al", "Aluminium", "26.982", "26.982", "2\n8\n3", QColor(252,157,73), QColor(0,0,0)}
        , {"14", false, false, "硅", "Si", "Silicon", "28.085", "28.084-28.086", "2\n8\n4", QColor(45,203,93), QColor(0,0,0)}
        , {"15", false, false, "磷", "P", "Phosphorus", "30.974", "30.974", "2\n8\n5", QColor(45,203,93), QColor(0,0,0)}
        , {"16", false, false, "硫", "S", "Sulfur", "32.06", "32.059-32.076", "2\n8\n6", QColor(45,203,93), QColor(0,0,0)}
        , {"17", false, false, "氯", "Cl", "Chlorine", "35.45", "35.446-35.457", "2\n8\n7", QColor(45,203,93), QColor(255,255,255)}
        , {"18", false, false, "氩", "Ar", "Argon", "39.95", "39.792-39.963", "2\n8\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"19", false, false, "钾", "K", "Potassium", "39.098", "39.098", "2\n8\n8\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"20", false, false, "钙", "Ca", "Calcium", "40.078(4)", "40.078(4)", "2\n8\n8\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"21", false, false, "钪", "Sc", "Scandium", "44.956", "44.956", "2\n8\n9\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"22", false, false, "钛", "Ti", "Titanium", "47.867", "47.867", "2\n8\n10\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"23", false, false, "钒", "V", "Vanadium", "50.942", "50.942", "2\n8\n11\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"24", false, false, "铬", "Cr", "Chromium", "51.996", "51.996", "2\n8\n8\n13\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"25", false, false, "锰", "Mn", "Manganese", "54.938", "54.938", "2\n8\n13\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"26", false, false, "铁", "Fe", "Iron", "55.845(2)", "55.845(2)", "2\n8\n14\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"27", false, false, "钴", "Co", "Cobalt", "58.933", "58.933", "2\n8\n15\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"28", false, false, "镍", "Ni", "Nickel", "58.693", "58.693", "2\n8\n16\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"29", false, false, "铜", "Cu", "Copper", "63.546(3)", "63.546(3)", "2\n8\n8\n18\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"30", false, false, "锌", "Zn", "Zinc", "65.38(2)", "65.38(2)", "2\n8\n18\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"31", false, false, "镓", "Ga", "Gallium", "69.723", "69.723", "2\n8\n18\n3", QColor(252,157,73), QColor(0,0,0)}
        , {"32", false, false, "锗", "Ge", "Germanium", "72.630(8)", "72.630(8)", "2\n8\n18\n4", QColor(145,150,255), QColor(0,0,0)}
        , {"33", false, false, "砷", "As", "Arsenic", "74.922", "74.922", "2\n8\n18\n5", QColor(45,203,93), QColor(0,0,0)}
        , {"34", false, false, "硒", "Se", "Selenium", "78.971(8)", "78.971(8)", "2\n8\n8\n18\n6", QColor(45,203,93), QColor(0,0,0)}
        , {"35", false, false, "溴", "Br", "Bromine", "79.904", "79.901-79.907", "2\n8\n8\n18\n7", QColor(45,203,93), QColor(64,92,255)}
        , {"36", false, false, "氪", "Kr", "Krypton", "83.798(2)", "83.798(2)", "2\n8\n18\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"37", false, false, "铷", "Rb", "Rubidium", "85.468", "85.468", "2\n8\n18\n8\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"38", false, false, "锶", "Sr", "Strontium", "87.62", "87.62", "2\n8\n18\n8\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"39", false, false, "钇", "Y", "Yttrium", "88.906", "88.906", "2\n8\n18\n9\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"40", false, false, "锆", "Zr", "Zirconium", "91.224(2)", "91.224(2)", "2\n8\n18\n10\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"41", false, false, "铌", "Nb", "Niobium", "92.906", "92.906", "2\n8\n18\n12\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"42", false, false, "钼", "Mo", "Molybdenum", "95.95", "95.95", "2\n8\n18\n13\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"43", true, true, "锝", "Tc", "Technetium", "98", "98", "2\n8\n18\n13\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"44", false, false, "钌", "Ru", "Ruthenium", "101.07(2)", "101.07(2)", "2\n8\n18\n15\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"45", false, false, "铑", "Rh", "Rhodium", "102.91", "102.91", "2\n8\n18\n16\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"46", false, false, "钯", "Pd", "Palladium", "106.42", "106.42", "2\n8\n18\n18\n0", QColor(204,255,83), QColor(0,0,0)}
        , {"47", false, false, "银", "Ag", "Silver", "107.87", "107.87", "2\n8\n18\n18\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"48", false, false, "镉", "Cd", "Cadmium", "112.41", "112.41", "2\n8\n18\n18\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"49", false, false, "铟", "In", "Indium", "114.82", "114.82", "2\n8\n18\n18\n3", QColor(252,157,73), QColor(0,0,0)}
        , {"50", false, false, "锡", "Sn", "Tin", "118.71", "118.71", "2\n8\n18\n18\n4", QColor(252,157,73), QColor(0,0,0)}
        , {"51", false, false, "锑", "Sb", "Antimony", "121.76", "121.76", "2\n8\n18\n18\n5", QColor(145,150,255), QColor(0,0,0)}
        , {"52", false, false, "碲", "Te", "Tellurium", "127.60(3)", "127.60(3)", "2\n8\n18\n18\n6", QColor(45,203,93), QColor(0,0,0)}
        , {"53", false, false, "碘", "I", "Iodine", "126.90", "126.90", "2\n8\n18\n18\n7", QColor(45,203,93), QColor(0,0,0)}
        , {"54", false, false, "氙", "Xe", "Xenon", "131.29", "131.29", "2\n8\n18\n18\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"55", false, false, "铯", "Cs", "Caesium", "132.91", "132.91", "2\n8\n18\n18\n8\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"56", false, false, "钡", "Ba", "Barium", "137.33", "137.33", "2\n8\n18\n18\n8\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"57-71", false, false, "镧系", "", "Lanthanoids", "La-Lu", "15 elements", "*", QColor(108,209,251), QColor(0,0,0)}//255,190,0
        , {"72", false, false, "铪", "Hf", "Hafnium", "178.49(2)", "178.49(2)", "2\n8\n18\n32\n10\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"73", false, false, "钽", "Ta", "Tantalum", "180.95", "180.95", "2\n8\n18\n32\n11\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"74", false, false, "钨", "W", "Tungsten", "183.84", "183.84", "2\n8\n18\n32\n12\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"75", false, false, "铼", "Re", "Rhenium", "186.21", "186.21", "2\n8\n18\n32\n13\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"76", false, false, "锇", "Os", "Osmium", "190.23(3)", "190.23(3)", "2\n8\n18\n32\n14\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"77", false, false, "铱", "Ir", "Iridium", "192.22", "192.22", "2\n8\n18\n32\n15\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"78", false, false, "铂", "Pt", "Platinum", "195.08", "195.08", "2\n8\n18\n32\n17\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"79", false, false, "金", "Au", "Gold", "196.97", "196.97", "2\n8\n18\n32\n18\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"80", false, false, "汞", "Hg", "Mercury", "200.59", "200.59", "2\n8\n18\n32\n18\n2", QColor(204,255,83), QColor(64,92,255)}
        , {"81", false, false, "铊", "Tl", "Thallium", "204.38", "[204.38, 204.39]", "2\n8\n18\n32\n18\n3", QColor(252,157,73), QColor(0,0,0)}
        , {"82", false, false, "铅", "Pb", "Lead", "207.2", "207.2", "2\n8\n18\n32\n18\n4", QColor(252,157,73), QColor(0,0,0)}
        , {"83", false, false, "铋", "Bi", "Bismuth", "208.98", "208.98", "2\n8\n18\n32\n18\n5", QColor(252,157,73), QColor(0,0,0)}
        , {"84", true, false, "钋", "Po", "Polonium", "209", "209", "2\n8\n18\n32\n18\n6", QColor(145,150,255), QColor(0,0,0)}
        , {"85", true, false, "砹", "At", "Astatine", "210", "210", "2\n8\n18\n32\n18\n7", QColor(45,203,93), QColor(0,0,0)}
        , {"86", true, false, "氡", "Rn", "Radon", "222", "222", "2\n8\n18\n32\n18\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"87", true, false, "钫", "Fr", "Francium", "223", "223", "2\n8\n18\n32\n18\n8\n1", QColor(252,252,81), QColor(0,0,0)}
        , {"88", true, false, "镭", "Ra", "Radium", "226", "226", "2\n8\n18\n32\n18\n8\n2", QColor(244,214,84), QColor(0,0,0)}
        , {"89-103", false, false, "锕系", "", "Actinoids", "Ac-Lr", "15 elements", "*", QColor(108,209,251), QColor(0,0,0)}//255,180,0
        , {"104", true, true, "𬬻", "Rf", "Rutherfordium", "261", "261", "2\n8\n18\n32\n32\n10\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"105", true, true, "𬭊", "Db", "Dubnium", "262", "262", "2\n8\n18\n32\n32\n11\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"106", true, true, "𬭳", "Sg", "Seaborgium", "266", "266", "2\n8\n18\n32\n32\n12\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"107", true, true, "𬭛", "Bh", "Bohrium", "264", "264", "2\n8\n18\n32\n32\n13\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"108", true, true, "𬭶", "Hs", "Hassium", "269", "269", "2\n8\n18\n32\n32\n14\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"109", true, true, "鿏", "Mt", "Meitnerium", "268", "268", "2\n8\n18\n32\n32\n15\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"110", true, true, "𫟼", "Ds", "Darmstadtium", "271", "271", "2\n8\n18\n32\n32\n17\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"111", true, true, "𬬭", "Rg", "Roentgenium", "272", "272", "2\n8\n18\n32\n32\n18\n1", QColor(204,255,83), QColor(0,0,0)}
        , {"112", true, true, "鿔", "Cn", "Copernicium", "277", "277", "2\n8\n18\n32\n32\n18\n2", QColor(204,255,83), QColor(0,0,0)}
        , {"113", true, true, "鿭", "Nh", "Nihonium", "284", "284", "2\n8\n18\n32\n32\n18\n3", QColor(252,157,73), QColor(0,0,0)}
        , {"114", true, true, "𫓧", "Fl", "Flerovium", "289", "289", "2\n8\n18\n32\n32\n18\n4", QColor(252,157,73), QColor(0,0,0)}
        , {"115", true, true, "镆", "Mc", "Moscovium", "288", "288", "2\n8\n18\n32\n32\n18\n5", QColor(252,157,73), QColor(0,0,0)}
        , {"116", true, true, "𫟷", "Lv", "Livermorium", "292", "292", "2\n8\n18\n32\n32\n18\n6", QColor(252,157,73), QColor(0,0,0)}
        , {"117", true, true, "鿬", "Ts", "Tennessine", " ", " ", "2\n8\n18\n32\n32\n18\n7", QColor(252,157,73), QColor(0,0,0)}
        , {"118", true, true, "鿫", "Og", "Oganesson", "293", "293", "2\n8\n18\n32\n32\n18\n8", QColor(160,160,160), QColor(255,255,255)}
        , {"57", false, false, "镧", "La", "Lanthanum", "138.91", "138.91", "2\n8\n18\n18\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"58", false, false, "铈", "Ce", "Cerium", "140.12", "140.12", "2\n8\n18\n19\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"59", false, false, "镨", "Pr", "Praseodymium", "140.91", "140.91", "2\n8\n18\n21\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"60", false, false, "钕", "Nd", "Neodymium", "144.24", "144.24", "2\n8\n18\n22\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"61", true, true, "钷", "Pm", "Promethium", "145", "145", "2\n8\n18\n23\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"62", false, false, "钐", "Sm", "Samarium", "150.36(2)", "150.36(2)", "2\n8\n18\n24\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"63", false, false, "铕", "Eu", "Europium", "151.96", "151.96", "2\n8\n18\n25\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"64", false, false, "钆", "Gd", "Gadolinium", "157.25(3)", "157.25(3)", "2\n8\n18\n25\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"65", false, false, "铽", "Tb", "Terbium", "158.93", "158.93", "2\n8\n18\n27\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"66", false, false, "镝", "Dy", "Dysprosium", "162.50", "162.50", "2\n8\n18\n28\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"67", false, false, "钬", "Ho", "Holmium", "164.93", "164.93", "2\n8\n18\n29\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"68", false, false, "铒", "Er", "Erbium", "167.26", "167.26", "2\n8\n18\n30\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"69", false, false, "铥", "Tm", "Thulium", "168.93", "168.93", "2\n8\n18\n31\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"70", false, false, "镱", "Yb", "Ytterbium", "173.05", "173.05", "2\n8\n18\n32\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"71", false, false, "镥", "Lu", "Lutetium", "174.97", "174.97", "2\n8\n18\n32\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"89", true, false, "锕", "Ac", "Actinium", "227", "227", "2\n8\n18\n32\n18\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"90", true, false, "钍", "Th", "Thorium", "232.04", "232.04", "2\n8\n18\n32\n18\n10\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"91", true, false, "镤", "Pa", "Protactinium", "231.04", "231.04", "2\n8\n18\n32\n20\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"92", true, false, "铀", "U", "Uranium", "238.02891", "234.0409-238.0508", "2\n8\n18\n32\n21\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"93", true, false, "镎", "Np", "Neptunium", "237", "237", "2\n8\n18\n32\n22\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"94", true, false, "钚", "Pu", "Plutonium", "244", "244", "2\n8\n18\n32\n24\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"95", true, true, "镅", "Am", "Americium", "243", "243", "2\n8\n18\n32\n25\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"96", true, true, "锔", "Cm", "Curium", "247", "247", "2\n8\n18\n32\n25\n9\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"97", true, true, "锫", "Bk", "Berkelium", "247", "247", "2\n8\n18\n32\n27\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"98", true, true, "锎", "Cf", "Californium", "251", "251", "2\n8\n18\n32\n28\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"99", true, true, "锿", "Es", "Einsteinium", "252", "252", "2\n8\n18\n32\n29\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"100", true, true, "镄", "Fm", "Fermium", "257", "257", "2\n8\n18\n32\n30\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"101", true, true, "钔", "Md", "Mendelevium", "258", "258", "2\n8\n18\n32\n31\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"102", true, true, "锘", "No", "Nobelium", "259", "259", "2\n8\n18\n32\n32\n8\n2", QColor(108,209,251), QColor(0,0,0)}
        , {"103", true, true, "铹", "Lr", "Lawrencium", "262", "262", "2\n8\n18\n32\n32\n9\n2", QColor(108,209,251), QColor(0,0,0)}
    };
    //
    SElementInfo m_sElementLegend = {"92", true, false, "铀", "U", "Uranium", "238.02891", "234.0409-238.0508", "2\n8\n18\n32\n21\n9\n2", QColor(108,209,251), QColor(0,0,0)};

private:
    QLabel* m_plabElementsPeriodicTable = nullptr;
    QLabel* m_plabAtomicFamily[18] = {nullptr};
    const QString m_cqsAtomicFamily[18] = {
        "<p>1</p><p>I<font color=red>A</font></p>", "<p>2</p><p>II<font color=red>A</font></p>"
        , "<p>3</p><p>III<font color=#00C000>B</font></p>", "<p>4</p><p>IV<font color=#00C000>B</font></p>"
        , "<p>5</p><p>V<font color=#00C000>B</font></p>", "<p>6</p><p>VI<font color=#00C000>B</font></p>"
        , "<p>7</p><p>VII<font color=#00C000>B</font></p>", "<p>8</p><p>VIII</p>"
        , "<p>9</p><p>VIII</p>", "<p>10</p><p>VIII</p>"
        , "<p>11</p><p>I<font color=#00C000>B</font></p>", "<p>12</p><p>II<font color=#00C000>B</font></p>"
        , "<p>13</p><p>III<font color=red>A</font></p>", "<p>14</p><p>IV<font color=red>A</font></p>"
        , "<p>15</p><p>V<font color=red>A</font></p>", "<p>16</p><p>VI<font color=red>A</font></p>"
        , "<p>17</p><p>VII<font color=red>A</font></p>", "<p>18</p><p>VIII<font color=red>A</font></p>"
    };
    ElementInfo* m_peleAtomicInfo[m_sciElementCount] = {nullptr};
    ElementInfo* m_peleAtomicLegend = nullptr;
    QLabel* m_plabAtomicLegend[12][2] = {nullptr};
    QLabel* m_plabAtomicExample[11][2] = {nullptr};

private:
    void InitCtrl(void);

public:

signals:

};

