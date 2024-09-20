#include "MainWindow.h"
#include "ElementsPeriodicTable.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_pElementsPeriodicTable = new ElementsPeriodicTable(this);
    setCentralWidget(m_pElementsPeriodicTable);
}

MainWindow::~MainWindow()
{
}

