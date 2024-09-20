#pragma once

#include <QMainWindow>


class ElementsPeriodicTable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    ElementsPeriodicTable* m_pElementsPeriodicTable = nullptr;
};
