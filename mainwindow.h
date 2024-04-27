#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

#include <string>
#include <vector>
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

    std::vector<std::string> colors_list{
                                        "#800000", "#0095FF", "#808000", "#469990", "#000075", "#500055", "#e6194B",
                                        "#f58231", "#ffe119", "#3cb44b", "#42d4f4", "#4363d8", "#911eb4", "#f032e6",
                                        "#fabed4", "#ffd8b1", "#aaffc3", "#dcbeff", "#8F2323", "#BFFF00", "#00EAFF"};
};
void smooth_easy_(std::vector<int>& arr);

void smooth_(std::vector<int>& arr);
#endif // MAINWINDOW_H
