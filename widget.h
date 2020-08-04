#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_chooseBtn_clicked();

    void on_colorChooseBtn_clicked();

    void on_saveBtn_clicked();

    void on_fileURLEdit_textChanged(const QString &arg1);

    void on_applyBtn_clicked();

private:
    Ui::Widget *ui;
    QPixmap *pix = new QPixmap(100,100);
    QImage *img = new QImage;
    QImage *solvedImg = new QImage(100, 100, QImage::Format_ARGB32);
    QPainter painter;
    QString filePath;
    QColor bgColor = Qt::white;

    void solveImage();
};
#endif // WIDGET_H
