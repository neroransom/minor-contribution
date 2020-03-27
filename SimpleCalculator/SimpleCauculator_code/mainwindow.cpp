/*
Copyright 2019, neroransom, CUG, All rights reserved.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

static bool lbks[50] = {0};          //储存操作
static bool rbks[50] = {0};
static bool nums[50] = {0};
static bool ops[50];
static int bno = 0;          //不等于零不允许enter
static int lbk = 0;
static int rbk = 0;
static int num =0;   //按了就=1
static int op = 0;   //按了就=1
static bool decimal;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("   :-)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num1_clicked()
{
      ui->textEdit->clear();
      ui->lineEdit->insert("1");
      lbks[++lbk] = 0;
      rbks[++rbk] = 0;
      nums[++num] = 1;
      ops[++op] = 0;
}


void MainWindow::on_num2_clicked()
{
      ui->textEdit->clear();
      ui->lineEdit->insert("2");
      lbks[++lbk] = 0;
      rbks[++rbk] = 0;
      nums[++num] = 1;
      ops[++op] = 0;
}

void MainWindow::on_num3_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("3");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num4_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("4");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num5_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("5");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num6_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("6");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num7_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("7");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num8_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("8");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num9_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("9");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}

void MainWindow::on_num0_clicked()
{
       ui->textEdit->clear();
       ui->lineEdit->insert("0");
       lbks[++lbk] = 0;
       rbks[++rbk] = 0;
       nums[++num] = 1;
       ops[++op] = 0;
}


void MainWindow::on_backspace_clicked()
{
      ui->statusbar->showMessage("   :-)");
      ui->textEdit->clear();
      ui->lineEdit->backspace();
      if(lbks[lbk]){--bno;};
      if(rbks[rbk]){++bno;};
      lbk--;
      rbk--;
      num--;
      op--;
      decimal = 0;
}

void MainWindow::on_pnt_clicked()
{
     ui->textEdit->clear();
    if((lbks[lbk]==0&&nums[num]==0&&ops[op]==0&&rbks[rbk]==0)||lbks[lbk]==1||(decimal&&!ops[op])){ui->statusbar->showMessage("   :-S"); ui->textEdit->setText("ILLEGAL INPUT");}
    else {if(ops[op]==1){on_backspace_clicked();}
    ui->lineEdit->insert(".");
    lbks[++lbk] = 0;
    rbks[++rbk] = 0;
    nums[++num] = 0;
    ops[++op] = 1;
    decimal = 1;
    }
}

void MainWindow::on_clear_clicked()
{
      ui->statusbar->showMessage("   :-)");
      ui->lineEdit->clear();
      ui->textEdit->clear();
      s1.MakeEmpty();
      s2.MakeEmpty();
      memset(lbks, 0, 50);
      memset(rbks, 0, 50);
      memset(nums, 0, 50);
      memset(ops, 0, 50);
      num =0;
      lbk = 0;
      rbk = 0;
      bno = 0;
      op = 0;
}


void MainWindow::on_sub_clicked()
{
    ui->textEdit->clear();
    if(lbks[lbk]==0&&nums[num]==0&&ops[op]==0&&rbks[rbk]==0){ui->statusbar->showMessage("   :-S"); ui->textEdit->setText("ILLEGAL INPUT");}
    else {if(ops[op]==1){on_backspace_clicked();}
    ui->lineEdit->insert("-");
    lbks[++lbk] = 0;
    rbks[++rbk] = 0;
    nums[++num] = 0;
    ops[++op] = 1;
    decimal = 0;
    }
}

void MainWindow::on_add_clicked()
{
    ui->textEdit->clear();
    if((lbks[lbk]==0&&nums[num]==0&&ops[op]==0&&rbks[rbk]==0)||lbks[lbk]==1){ui->statusbar->showMessage("   :-S"); ui->textEdit->setText("ILLEGAL INPUT");}
    else {if(ops[op]==1){on_backspace_clicked();}
    ui->lineEdit->insert("+");
    lbks[++lbk] = 0;
    rbks[++rbk] = 0;
    nums[++num] = 0;
    ops[++op] = 1;
    decimal = 0;
    }
}

void MainWindow::on_mul_clicked()
{
     ui->textEdit->clear();
    if((lbks[lbk]==0&&nums[num]==0&&ops[op]==0&&rbks[rbk]==0)||lbks[lbk]==1){ui->statusbar->showMessage("   :-S"); ui->textEdit->setText("ILLEGAL INPUT");}
    else {if(ops[op]==1){on_backspace_clicked();}
    ui->lineEdit->insert("*");
    lbks[++lbk] = 0;
    rbks[++rbk] = 0;
    nums[++num] = 0;
    ops[++op] = 1;
    decimal = 0;
    }
}

void MainWindow::on_divide_clicked()
{
     ui->textEdit->clear();
    if((lbks[lbk]==0&&nums[num]==0&&ops[op]==0&&rbks[rbk]==0)||lbks[lbk]==1){ui->statusbar->showMessage("   :-S"); ui->textEdit->setText("ILLEGAL INPUT");}
    else {if(ops[op]==1){on_backspace_clicked();}
    ui->lineEdit->insert("÷");
    lbks[++lbk] = 0;
    rbks[++rbk] = 0;
    nums[++num] = 0;
    ops[++op] = 1;
    decimal = 0;
    }
}

void MainWindow::on_enter_clicked()
{
   ui->textEdit->clear();
   if(!bno&&!ops[op])
   {ui->textEdit->setTextColor(QColor(0,0,0));
   Run();
   ui->textEdit->setTextColor(QColor(255,0,0));}
   else {
       ui->statusbar->showMessage("   :-)");
       ui->textEdit->clear();
       ui->textEdit->setText("INCOMPLETE INPUT");
   }
}

void MainWindow::on_lbraket_clicked()
{
     ui->textEdit->clear();
    if(rbks[rbk]||nums[num]){ui->statusbar->showMessage("   :-S");ui->textEdit->setText("INPUT OPERATE BEFORE BRAKET");}
    else{
     ui->lineEdit->insert("(");
     lbks[++lbk] = 1;
     rbks[++rbk] = 0;
     nums[++num] = 0;
     ops[++op] = 0;
     ++bno;
    }
}

void MainWindow::on_rbraket_clicked()
{
     ui->textEdit->clear();
    if(lbks[lbk] ==1){
            ui->statusbar->showMessage("   :-S");
            ui->textEdit->clear();
            ui->textEdit->setText("VOID BRAKET");}
    else if(ops[op] ==1){
        ui->statusbar->showMessage("   :-S");
        ui->textEdit->setText("ILLEGAL INPUT");}
    else if(bno>0){
        ui->lineEdit->insert(")");
        lbks[++lbk] = 0;
        rbks[++rbk] = 1;
        nums[++num] = 0;
        ops[++op] = 0;
        --bno;
       }
    else{
        ui->statusbar->showMessage("   :-S");
        ui->textEdit->clear();
        ui->textEdit->setText("NO \"(\"CAN MATCH IT");
    }
}

inline void MainWindow::Run()
{
     ui->lineEdit->insert("#");
     s = ui->lineEdit->text();
     for(int i = 0;i<s.size();++i)
     {
         if(s[i]=="÷"){s[i]='/';}
     }
     ui->lineEdit->backspace();
        Clear();
        Operate();
        QString data = QString("%1").arg(s2.elements[0]);
        ui->textEdit->setText(data);
}

inline void MainWindow::Clear()
{
    s1.MakeEmpty();
    s2.MakeEmpty();
}

inline bool MainWindow::RPNCalculating(SeqStack<char>& s1, SeqStack<double>& s2) //TODO 对象的析构 ?
{
    double left, right;
    char op;
    s2.Pop(right);
    s2.Pop(left);
    s1.Pop(op);
    switch (op) {
    case('#'):s2.Push(right);break;
    case('\n'):break;
    case('/'):s2.Push(left / right); break;
    case('*'):s2.Push(left * right); break;
    case('+'):s2.Push(left + right); break;
    case('-'):s2.Push(left - right); break;
    case('%'):s2.Push((int)left % (int)right); break;
    default:
        ui->statusbar->showMessage("   :-)");
        ui->textEdit->setText("UNKNOW ERROR: OPERATION CANNOT BE RECOGNIZED");
    }                 //TODO 格式
    return true;
}

inline void MainWindow::Operate()
{
    char ch = '#', cht, op;
    s1.Push(ch);
   // static bool finish = 0;
    int i = 0;
    ch = 0;
    while (s1.isEmpty() == false && ch != '#')
    {
        ch = s[i].toLatin1();
        if (isdigit(ch))
        {
            double temp = 0, count = 0;
            do {
                ch = ch - 48;
                temp = temp * 10 + ch;   //mark
               if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}  //弹出时i = size
            } while (isdigit(ch));
            if (ch == '.')
            {
                if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}
                do {
                    ch = ch - 48;
                    temp += ch * pow(10, --count);   //mark
               if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}
                } while (isdigit(ch));
            }
            s2.Push(temp);
        }
        else {
            s1.getTop(cht);
            if (isp(cht) < icp(ch))
            {
                if (ch == '(')
                {
                    s1.Push(ch);
                    if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}
                    if (ch == '-')                //负数
                    {
                        s2.Push(0);
                    }
                    continue;
                }
              s1.Push(ch);
              if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}
            }
            else if (isp(cht) > icp(ch))
            {
                RPNCalculating(s1, s2);
            }
            else
            {
                s1.Pop(op);
                if (op == '(')
                {
                  if(i+1<s.size()){ch = s[++i].toLatin1();}else{break;}
                }
            }
        }
    }
    do {
        RPNCalculating(s1, s2);
    } while (s2.top != 0);
   }


int MainWindow::isp(char ch)  //in stcak priority
{
    switch (ch) {
    case('\n'):return 0;
    case('#'):return 0;
    case('('):return 1;
    case('*'):return 5;
    case('/'):return 5;
    case('%'):return 5;
    case('+'):return 3;
    case('-'):return 3;
    case(')'):return 6;
    default: exit(-1);
    }
}

int MainWindow::icp(char ch) //in coming priority
{
    switch (ch) {
    case('\n'):return 0;
    case('#'):return 0;
    case('('):return 6;
    case('+'):return 2;
    case('-'):return 2;
    case('*'):return 4;
    case('/'):return 4;
    case('%'):return 4;
    case(')'):return 1;
    default: exit(0);
    }
}



