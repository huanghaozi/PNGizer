#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    solveImage();
}


void Widget::on_chooseBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"选择图片",
                                                        "",
                                                        "图片文件(*.bmp *.jpg *.jpeg *.png *.ppm *.xpm *.xbm);;");
    if(!fileName.isEmpty())
    {
        ui->fileURLEdit->setText(fileName);
    }
}

void Widget::on_colorChooseBtn_clicked()
{
    bgColor = QColorDialog::getColor(Qt::white, this);
    ui->colorLabel->setStyleSheet(QString("background-color: rgb(%1, %2, %3);"
                                          "border: 5px solid rgb(236, 240, 241);").arg(bgColor.red()).arg(bgColor.green()).arg(bgColor.blue()));
    solveImage();
}

void Widget::on_saveBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"),
                                                    "",
                                                    tr("PNG图像 (*.png)"));
    if(!fileName.isEmpty())
        solvedImg->save(fileName);
}

void Widget::on_fileURLEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    filePath = ui->fileURLEdit->text();
    filePath.replace('\\','/');
    QFileInfo fileInfo(filePath);
    if(fileInfo.isFile())
    {
        img->load(filePath);
        solvedImg = new QImage(img->width(), img->height(), QImage::Format_RGBA8888);
        solveImage();
    }
}

void Widget::solveImage()
{
    int r, g, b, a;
    int rb = bgColor.red();
    int gb = bgColor.green();
    int bb = bgColor.blue();
    int intervalr = ui->rSpin->value();
    int intervalg = ui->gSpin->value();
    int intervalb = ui->bSpin->value();
    bool flag = false;
    QColor oColor;
    solvedImg->fill(QColor(0,0,0,0));
    //qDebug()<<solvedImg->pixelColor(20,20);
    painter.begin(solvedImg);
    for(int x=0;x<img->width();x++)
    {
        for(int y=0;y<img->height();y++)
        {
            oColor = img->pixelColor(x, y);
            for(int i=1;i<=1;i++)
            {
                if(oColor.red()<rb)
                    r = 255*(oColor.red()-rb+intervalr)/intervalr;
                else
                    r = -255*(oColor.red()-rb-intervalr)/intervalr;
                if(r<=0)
                {
                    flag = true;
                    break;
                }
                if(oColor.green()<gb)
                    g = 255*(oColor.green()-gb+intervalg)/intervalg;
                else
                    g = -255*(oColor.green()-gb-intervalg)/intervalg;
                if(g<=0)
                {
                    flag = true;
                    break;
                }
                if(oColor.blue()<bb)
                    b = 255*(oColor.blue()-bb+intervalb)/intervalb;
                else
                    b = -255*(oColor.blue()-bb-intervalb)/intervalb;
                if(b<=0)
                {
                    flag = true;
                    break;
                }
            }
            a = 255 - int((r+g+b)/3);
            if(flag)
            {
                a = 255;
                flag = false;
            }
            //painter.setPen(QColor(255,0,0,50));
            //painter.setBrush(QColor(255,0,0,50));
            painter.fillRect(x, y, 1, 1, QColor(oColor.red(),oColor.green(),oColor.blue(),a));
        }
    }
    painter.end();
    *pix = pix->scaled(solvedImg->width(), solvedImg->height());
    *pix = QPixmap::fromImage(solvedImg->scaled(pix->width(), pix->height()));
    ui->previewLabel->setPixmap(pix->scaled(ui->previewLabel->size(),
                                            Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

void Widget::on_applyBtn_clicked()
{
    solveImage();
}
