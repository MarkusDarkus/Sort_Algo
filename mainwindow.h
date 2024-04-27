#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include <string>

// #include "algorithms/Cocktail.cpp"
// #include "algorithms/Heap.cpp"
// #include "algorithms/Quick.cpp"
//#include "algorithms/Bubble.cpp"
// TODO: fix and implement others

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ChoiceTableButtons_cellClicked(int row, int column);

    void on_SelectBtn_clicked();

    void on_BeginBtn_clicked();

    void on_CancelBtn_clicked();

    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;

    QChart *chart = new QChart();
    QChartView *chartView = new QChartView(chart);
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();

    std::map<std::string, bool> button_activation_info;
    int disabled_count = 0;
    bool stop_called = false;

    QBrush my_brush;
    QColor clr_gray = QColor("gray");
    QColor clr_white = QColor("white");

    std::string get_str_from_table(int row, int col) {return ui->ChoiceTableButtons->item(row, col)->text().toStdString();}
    void calculate();

};
#endif // MAINWINDOW_H
