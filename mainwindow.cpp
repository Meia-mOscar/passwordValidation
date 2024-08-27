#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    pass.setPosition(2);
    stdPassLabel.setText("Minimum 5 characters & no spaces");
    significantDigitLabel.setText("Exactly 5 characters & the third character is either number / letter");
    noLeadingZeroLabel.setText("Between 4 & 6 digits, not starting with 0");
    stdPassCheck.setChecked(false);
    significantDigitCheck.setChecked(false);
    noLeadingZeroCheck.setChecked(false);
    userIn.clear();
    validateBtn.setText("VALIDATE");
    //validateBtn.setDisabled(true);
    btnGroup.addButton(&stdPassCheck, 0);
    btnGroup.addButton(&significantDigitCheck, 1);
    btnGroup.addButton(&noLeadingZeroCheck, 2);
    stdPassLayout.addWidget(&stdPassCheck);
    stdPassLayout.addWidget(&stdPassLabel);
    significantDigitLayout.addWidget(&significantDigitCheck);
    significantDigitLayout.addWidget(&significantDigitLabel);
    noLeadingZeroLayout.addWidget(&noLeadingZeroCheck);
    noLeadingZeroLayout.addWidget(&noLeadingZeroLabel);
    userInputLayout.addWidget(&userIn);
    userInputLayout.addWidget(&validateBtn);
    mainLayout.addLayout(&stdPassLayout);
    mainLayout.addLayout(&significantDigitLayout);
    mainLayout.addLayout(&noLeadingZeroLayout);
    mainLayout.addLayout(&userInputLayout);
    central.setLayout(&mainLayout);
    setCentralWidget(&central);

    connect(&validateBtn, &QPushButton::clicked, this, &MainWindow::validate);
}

MainWindow::~MainWindow() {}

void MainWindow::validate() {
    /*
     * Which checkbox, id?
     * Invoke appropriate method to validate.
     * Display QMessage after
     */
    qDebug() << "Validate";
    valid = false;
    if(stdPassCheck.isChecked()) {
        qDebug() << "std";
        valid = pass.validStd(userIn.text());
    } else if(noLeadingZeroCheck.isChecked()) {
        qDebug() << "zero";
        valid = pass.validNoLeadingZero(userIn.text());
    } else if(significantDigitCheck.isChecked()) {
        qDebug() << "sig";
        valid = pass.validSignificantDigit(userIn.text());
    }

    this->displayResult(valid);
}

void MainWindow::displayResult(bool b) {
    if(valid) {
        QMessageBox::information(this, "Success message", "Horay! Password accepted.");
    } else {
        QMessageBox::critical(this,"Invalid input","Oops! Password doesn't match rules.");
    }

}
