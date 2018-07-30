#include "aboutmynote.h"
#include "ui_aboutmynote.h"

AboutMyNote::AboutMyNote(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AboutMyNote)
{
  ui->setupUi(this);
}

AboutMyNote::~AboutMyNote()
{
  delete ui;
}
