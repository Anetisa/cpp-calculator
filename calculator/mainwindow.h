#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Operation {
    NO_OPERATION,
    MULTIPLICATION,
    DIVISION,
    SUBTRACTION,
    ADDITION,
    POWER,
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_tb_mc_clicked();
    void on_tn_mr_clicked();
    void on_tb_ms_clicked();

    void on_tb_power_clicked();
    void on_tb_reset_clicked();
    void on_tb_negate_clicked();

    void on_tb_divide_clicked();
    void on_tb_multiplicate_clicked();
    void on_tb_add_clicked();
    void on_tb_substract_clicked();

    void on_tb_equal_clicked();

    void on_tb_backspace_clicked();

    void on_tb_comma_clicked();

    void on_tb_zero_clicked();
    void on_tb_one_clicked();
    void on_tb_two_clicked();
    void on_tb_three_clicked();
    void on_tb_four_clicked();
    void on_tb_five_clicked();
    void on_tb_six_clicked();
    void on_tb_seven_clicked();
    void on_tb_eight_clicked();
    void on_tb_nine_clicked();

private:
    Ui::MainWindow* ui;

    Calculator calculator_;//экземпляр класса Calculator

    Operation current_operation_;
    QString input_number_;// вводимое число в виде строки
    double active_number_;// = 0.0;//число, которое сейчас отображается в l_result в виде double. Это может быть результат предыдущего вычисления либо введённое число.

    Number memory_cell_;// число, сохранённое в память
    bool memory_saved_;// флаг, показывающий, что память не пуста
    bool waiting_for_new_number_;

    void SetOperation(Operation op);
    QString OpToString(Operation op);

    QString RemoveTrailingZeroes(const QString &text);
    QString NormalizeNumber(const QString &text);
    void SetText(const QString& text);
    void AddText(const QString& suffix);
};





