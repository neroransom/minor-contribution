/*
Copyright 2019 Tsuhang_Liang CUG

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"SeqStack.h"
#include<iostream>
#include<math.h>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Run();
    void Clear();
private slots:
    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_add_clicked();

    void on_backspace_clicked();

    void on_clear_clicked();

    void on_divide_clicked();

    void on_enter_clicked();

    void on_lbraket_clicked();

    void on_rbraket_clicked();

    void on_sub_clicked();

    void on_pnt_clicked();

    void on_num0_clicked();

    void on_mul_clicked();

private:
    Ui::MainWindow *ui;
    SeqStack<char> s1;
    SeqStack<double> s2;
    QString  s;
    bool RPNCalculating(SeqStack<char>& s1, SeqStack<double>& s2);   //TODO 对象的析构
    void Operate();
    int icp(char ch);
    int isp(char ch);
    MainWindow* p;
};


#endif // MAINWINDOW_H
